#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<CL/cl.h>
#include<sys/time.h>
#include<iostream>
#include<fstream>
#include<sstream> 

#define GMM_MAX_COMPONT 3	
#define GMM_LEARN_ALPHA 0.005  
#define GMM_THRESHOD_SUMW 0.7
#define HEIGHT 1080
#define WIDTH 1920

using namespace std;

void trainGMM(unsigned char *_image, unsigned char *mask, float *modelW, float *modelS, unsigned char *modelM, int height, int width)
{
	/**************************** Train ******************************************/
	for (int i = 0; i < height; i++)
	{
		float *modelWData = modelW + i * width * GMM_MAX_COMPONT;
		float *modelSData = modelS + i * width * GMM_MAX_COMPONT;
		unsigned char *modelMData = modelM + i * width * GMM_MAX_COMPONT;
		const unsigned char *_imageData = _image + i * width;
		for (int j = 0; j < width; j++)
		{
			int num_fit = 0;

			/**************************** Update parameters Start ******************************************/
			for (int k = 0; k < GMM_MAX_COMPONT; k++)
			{
				int delm = abs(_imageData[j] - modelMData[k]);
				long dist = delm * delm;
				if (dist < 3.0 * modelSData[k])
				{
					modelWData[k] += GMM_LEARN_ALPHA * (1 - modelWData[k]);
					modelMData[k] += (GMM_LEARN_ALPHA / modelWData[k]) * delm;
					modelSData[k] += (GMM_LEARN_ALPHA / modelWData[k]) * (dist - modelSData[k]);
				}
				else
				{
					modelWData[k] += GMM_LEARN_ALPHA * (0 - modelWData[k]);
					num_fit++;
				}
			}
			/**************************** Update parameters End ******************************************/

			/*********************** Sort Gaussian component by 'weight / sigma' Start ****************************/
			for (int kk = 0; kk < GMM_MAX_COMPONT; kk++)
			{
				for (int rr = kk; rr< GMM_MAX_COMPONT; rr++)
				{
					if (modelWData[rr] / modelSData[rr] > modelWData[kk] / modelSData[kk])
					{
						float temp_weight = modelWData[rr];
						modelWData[rr] = modelWData[kk];
						modelWData[kk] = temp_weight;

						unsigned char temp_mean = modelMData[rr];
						modelMData[rr] = modelMData[kk];
						modelMData[kk] = temp_mean;

						float temp_sigma = modelSData[rr];
						modelSData[rr] = modelSData[kk];
						modelSData[kk] = temp_sigma;
					}
				}
			}
			/*********************** Sort Gaussian model by 'weight / sigma' End ****************************/

			/*********************** Create new Gaussian component Start ****************************/
			if (num_fit == GMM_MAX_COMPONT && modelWData[GMM_MAX_COMPONT - 1] == 0)
			{
				//if there is no exit component fit,then start a new component
				for (int k = 0; k < GMM_MAX_COMPONT; k++)
				{
					if (0 == modelWData[k])
					{
						if (k == 0)
							modelWData[k] = 1;
						else
							modelWData[k] = GMM_LEARN_ALPHA;
						
            modelMData[k] = _imageData[j];
						modelSData[k] = 15.0;

						//normalization the weight,let they sum to 1
						for (int q = 0; q < GMM_MAX_COMPONT && q != k; q++)
						{
							/****update the other unfit's weight,u and sigma remain unchanged****/
							modelWData[q] *= (1 - GMM_LEARN_ALPHA);
						}
						break;
					}
				}
			}
			else if (num_fit == GMM_MAX_COMPONT && modelWData[GMM_MAX_COMPONT - 1] != 0)
			{
				modelMData[GMM_MAX_COMPONT - 1] = _imageData[j];
				modelSData[GMM_MAX_COMPONT - 1] = 15.0;
			}
			/*********************** Create new Gaussian component End ****************************/

			modelWData += GMM_MAX_COMPONT;
			modelSData += GMM_MAX_COMPONT;
			modelMData += GMM_MAX_COMPONT;
		}
	}
}

void testGMM(unsigned char* _image, unsigned char* mask, float* modelW, float* modelS, unsigned char* modelM, int height, int width)
{
	/*********************** Predict ****************************/
	for (int i = 0; i < height; i++)
	{
		float *modelWData = modelW + i * width * GMM_MAX_COMPONT;
		float *modelSData = modelS + i * width * GMM_MAX_COMPONT;
		unsigned char *modelMData = modelM + i * width * GMM_MAX_COMPONT;
		const unsigned char *_imageData = _image + i * width;
		unsigned char *maskData = mask + i * width;
		for (int j = 0; j < width; j++)
		{
			float sum_w = 0.0;
			for (unsigned char k = 0; k < GMM_MAX_COMPONT; k++)
			{
				if (abs(_imageData[j] - modelMData[k]) < (unsigned char)(2.5 * modelSData[k]))
				{
					maskData[j] = 0;
					break;
				}
				sum_w += modelWData[k];
				if (sum_w >= GMM_THRESHOD_SUMW)
				{
					maskData[j] = 255;
					break;
				}
			}
			modelWData += GMM_MAX_COMPONT;
			modelSData += GMM_MAX_COMPONT;
			modelMData += GMM_MAX_COMPONT;
		}
	}
}

// OpenCL

cl_context CreateContext()
{
	cl_int errNum;
	cl_uint numPlatforms;
	cl_platform_id firstPlatformId;
	cl_context context = NULL;

	errNum = clGetPlatformIDs(1, &firstPlatformId, &numPlatforms);
	if (errNum != CL_SUCCESS || numPlatforms <= 0)
	{
		std::cerr << "Failed to find any OpenCL platforms." << std::endl;
		return NULL;
	}

	cl_context_properties contextProperties[] =
	{
		CL_CONTEXT_PLATFORM,
		(cl_context_properties)firstPlatformId,
		0
	};
	context = clCreateContextFromType(contextProperties, CL_DEVICE_TYPE_GPU,
		NULL, NULL, &errNum);

	return context;
}

cl_command_queue CreateCommandQueue(cl_context context, cl_device_id *device)
{
	cl_int errNum;
	cl_device_id *devices;
	cl_command_queue commandQueue = NULL;
	size_t deviceBufferSize = -1;

	errNum = clGetContextInfo(context, CL_CONTEXT_DEVICES, 0, NULL, &deviceBufferSize);

	if (deviceBufferSize <= 0)
	{
		std::cerr << "No devices available.";
		return NULL;
	}

	devices = new cl_device_id[deviceBufferSize / sizeof(cl_device_id)];
	errNum = clGetContextInfo(context, CL_CONTEXT_DEVICES, deviceBufferSize, devices, NULL);

	commandQueue = clCreateCommandQueue(context, devices[0], 0, NULL);

	*device = devices[0];
	delete[] devices;
	return commandQueue;
}

cl_program CreateProgram(cl_context context, cl_device_id device, const char* fileName)
{
	cl_int errNum;
	cl_program program;

	std::ifstream kernelFile(fileName, std::ios::in);
	if (!kernelFile.is_open())
	{
		std::cerr << "Failed to open file for reading: " << fileName << std::endl;
		return NULL;
	}

	std::ostringstream oss;
	oss << kernelFile.rdbuf();

	std::string srcStdStr = oss.str();
	const char *srcStr = srcStdStr.c_str();
	program = clCreateProgramWithSource(context, 1,
		(const char**)&srcStr,
		NULL, NULL);

	errNum = clBuildProgram(program, 0, NULL, NULL, NULL, NULL);

	return program;
}

void Cleanup(cl_context context, cl_command_queue commandQueue,
	cl_program program, cl_kernel kernel, cl_mem memObjects[3])
{
	for (int i = 0; i < 3; i++)
	{
		if (memObjects[i] != 0)
			clReleaseMemObject(memObjects[i]);
	}
	if (commandQueue != 0)
		clReleaseCommandQueue(commandQueue);

	if (kernel != 0)
		clReleaseKernel(kernel);

	if (program != 0)
		clReleaseProgram(program);

	if (context != 0)
		clReleaseContext(context);
}

void checkErr(cl_int err,const char *name)
{
	if(err != CL_SUCCESS)
	{
		printf("Error: %s %d",name,err);
		switch(err)
		{
			case CL_DEVICE_NOT_FOUND :printf("(CL_DEVICE_NOT_FOUND)");break;
			case CL_DEVICE_NOT_AVAILABLE :printf("(CL_DEVICE_NOT_AVAILABLE)");break;
			case CL_COMPILER_NOT_AVAILABLE :printf("(CL_COMPILER_NOT_AVAILABLE)");break;
			case CL_MEM_OBJECT_ALLOCATION_FAILURE :printf("(CL_MEM_OBJECT_ALIOCATION_FAILURE)");break;
			case CL_OUT_OF_RESOURCES :printf("(CL_OUT_OF_RESOURCES)");break;
			case CL_OUT_OF_HOST_MEMORY :printf("(CL_OUT_OF_HOST_MEMORY)");break;
			case CL_MEM_COPY_OVERLAP :printf("(CL_MEM_COPY_OVERLAP)");break;
			case CL_BUILD_PROGRAM_FAILURE:printf("(CL_BUILD_PROGRAM_FAILURE)");break;
			case CL_INVALID_VALUE:printf("(CL_INVALID_VALUE)");break;
			case CL_INVALID_DEVICE_TYPE:printf("(CL_INVALID_DEVICE_TYPE)");break;
			case CL_INVALID_DEVICE:printf("(CL_INVALID_DEVICE)");break;
			case CL_INVALID_CONTEXT:printf("(CL_INVALID_CONTEXT)");break;
			case CL_INVALID_BINARY:printf("(CL_INVALID_BINARY)");break;
			case CL_INVALID_BUILD_OPTIONS:printf("(CL_INVALID_BUILD_OPTIONS)");break;
			case CL_INVALID_PROGRAM:printf("(CL_INVALID_PROGRAM)");break;
			case CL_INVALID_PROGRAM_EXECUTABLE:printf("(CL_INVALID_PROGRAM_EXECUTABLE)");break;
			case CL_INVALID_KERNEL_DEFINITION:printf("(CL_INVALID_KERNEL_DEFINITION)");break;
			case CL_INVALID_KERNEL:printf("(CL_INVALID_KERNEL)");break;
			case CL_INVALID_KERNEL_ARGS:printf("(CL_INVALID_KERNEL_ARGS)");break;
			case CL_INVALID_OPERATION:printf("(CL_INVALID_OPERATION)");break;
			case CL_INVALID_COMMAND_QUEUE:printf("(CL_INVALID_COMMAND_QUEUE)");break;
			case CL_INVALID_WORK_DIMENSION:printf("(CL_INVALID_WORK_DIMENSION)");break;
			case CL_INVALID_WORK_GROUP_SIZE:printf("(CL_INVALID_WORK_GROUP_SIZE)");break;
			case CL_INVALID_WORK_ITEM_SIZE:printf("(CL_INVALID_WORK_ITEM_SIZE)");break;
			case CL_INVALID_GLOBAL_WORK_SIZE:printf("(CL_INVALID_GLOBAL_WORK_SIZE)");break;
			case CL_INVALID_GLOBAL_OFFSET:printf("(CL_INVALID_GLOBAL_OFFSET)");break;
			case CL_INVALID_IMAGE_SIZE:printf("(CL_INVALID_IMAGE_SIZE)");break;
			case CL_INVALID_EVENT_WAIT_LIST:printf("(CL_INVALID_EVENT_WAIT_LIST)");break;
			case CL_MISALIGNED_SUB_BUFFER_OFFSET:printf("(CL_MISALIGNED_SUB_BUFFER_OFFSET)");break;
			
			default:
			break;
		}
		printf("\n");
		exit(1);
	}
}

int getProgramBuildInfo(cl_program program,cl_device_id device)
{
  size_t log_size;
  char *program_log;
  
  /* Find size of log and print to std output */
  clGetProgramBuildInfo(program, device, CL_PROGRAM_BUILD_LOG, 
            0, NULL, &log_size);
  program_log = (char*) malloc(log_size+1);
  program_log[log_size] = '\0';
  clGetProgramBuildInfo(program, device, CL_PROGRAM_BUILD_LOG, 
            log_size+1, program_log, NULL);
  printf("%s\n", program_log);
  free(program_log);
  return 0;
}

/** convert the kernel file into a string */
int convertToString(const char *filename, std::string& s)
{
  size_t size;
  char*  str;
  std::fstream f(filename, (std::fstream::in | std::fstream::binary));

  if(f.is_open())
  {
    size_t fileSize;
    f.seekg(0, std::fstream::end);
    size = fileSize = (size_t)f.tellg();
    f.seekg(0, std::fstream::beg);
    str = new char[size+1];
    if(!str)
    {
      f.close();
      return 0;
    }

    f.read(str, fileSize);
    f.close();
    str[size] = '\0';
    s = str;
    delete[] str;
    return 0;
  }
  cout<<"Error: failed to open file\n:"<<filename<<endl;
  return -1;
}

int main(int argc, char** argv)
{
	// data  
  unsigned char *frame = new unsigned char[HEIGHT * WIDTH];

  float *dev_modelW = new float[HEIGHT * GMM_MAX_COMPONT * WIDTH];
  float *dev_modelS = new float[HEIGHT * GMM_MAX_COMPONT * WIDTH];
  unsigned char *dev_modelM = new unsigned char[HEIGHT * GMM_MAX_COMPONT * WIDTH];;
  unsigned char *dev_mask = new unsigned char[HEIGHT * WIDTH];
  
  float *modelW = new float[HEIGHT * GMM_MAX_COMPONT * WIDTH];
  float *modelS = new float[HEIGHT * GMM_MAX_COMPONT * WIDTH];
  unsigned char *modelM = new unsigned char[HEIGHT * GMM_MAX_COMPONT * WIDTH];;
  unsigned char *mask = new unsigned char[HEIGHT * WIDTH];
  
  int height = HEIGHT;
  int width = WIDTH;  

  memset(dev_modelW, 0, sizeof(dev_modelW));
  memset(dev_modelS, 0, sizeof(dev_modelM));
  memset(dev_modelM, 0, sizeof(dev_modelS));
  memset(dev_mask, 0, sizeof(dev_mask));

  memset(modelW, 0, sizeof(modelW));
  memset(modelS, 0, sizeof(modelM));
  memset(modelM, 0, sizeof(modelS));
  memset(mask, 0, sizeof(mask));

  clock_t start_train, end_train, start_test, end_test;
  clock_t start2_train, end2_train, start2_test, end2_test;
	double sum_t_train = 0;
  double sum_t_test = 0;
	double sum_t2_train = 0;
  double sum_t2_test = 0;
	 
  srand(unsigned(time(0)));  
 
  cl_context context = 0;
  cl_command_queue commandQueue = 0;
  cl_program program = 0;
  cl_device_id device = 0;
  cl_kernel kernel_test = 0;
  cl_kernel kernel_train = 0;
  cl_mem memObjects[5] = {0, 0, 0, 0, 0};
  cl_int errNum;
  cl_int status;

  context = CreateContext();
  commandQueue = CreateCommandQueue(context, &device);

  const char *filename = "gmm_cl.cl";
  string sourceStr;
  status = convertToString(filename, sourceStr);
  const char *source = sourceStr.c_str();
  size_t sourceSize[] = {strlen(source)};
  program = clCreateProgramWithSource(context, 1, &source, sourceSize, NULL);

  status = clBuildProgram(program, 1, &device, NULL, NULL, NULL);
  if(status < 0)    //get the build info
    getProgramBuildInfo(program, device);
  else
    printf("Build Success\n");

  kernel_train = clCreateKernel(program, "train_kernel", &errNum);
  checkErr(errNum, "clCreateKernel():train");  
  kernel_test = clCreateKernel(program, "test_kernel", &errNum); 
  checkErr(errNum, "clCreateKernel():test");  

  memObjects[0] = clCreateBuffer(context, CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR,
		sizeof(unsigned char) * HEIGHT * WIDTH, frame, NULL);
  memObjects[1] = clCreateBuffer(context, CL_MEM_READ_WRITE | CL_MEM_COPY_HOST_PTR,
		sizeof(unsigned char) * HEIGHT * WIDTH, dev_mask, NULL);
  memObjects[2] = clCreateBuffer(context, CL_MEM_READ_WRITE | CL_MEM_COPY_HOST_PTR,
		sizeof(float) * HEIGHT * GMM_MAX_COMPONT * WIDTH, dev_modelW, NULL);
  memObjects[3] = clCreateBuffer(context, CL_MEM_READ_WRITE | CL_MEM_COPY_HOST_PTR,
		sizeof(float) * HEIGHT * GMM_MAX_COMPONT * WIDTH, dev_modelS, NULL); 
  memObjects[4] = clCreateBuffer(context, CL_MEM_READ_WRITE | CL_MEM_COPY_HOST_PTR,
		sizeof(unsigned char) * HEIGHT * GMM_MAX_COMPONT * WIDTH, dev_modelM, NULL);
 
  errNum = clSetKernelArg(kernel_train, 0, sizeof(cl_mem), &memObjects[0]);
  errNum |= clSetKernelArg(kernel_train, 1, sizeof(cl_mem), &memObjects[1]);
  errNum |= clSetKernelArg(kernel_train, 2, sizeof(cl_mem), &memObjects[2]);
  errNum |= clSetKernelArg(kernel_train, 3, sizeof(cl_mem), &memObjects[3]);
  errNum |= clSetKernelArg(kernel_train, 4, sizeof(cl_mem), &memObjects[4]);
  errNum |= clSetKernelArg(kernel_train, 5, sizeof(int), (void *) &height);
  errNum |= clSetKernelArg(kernel_train, 6, sizeof(int), (void *) &width);
    
  errNum = clSetKernelArg(kernel_test, 0, sizeof(cl_mem), &memObjects[0]);
  errNum |= clSetKernelArg(kernel_test, 1, sizeof(cl_mem), &memObjects[1]);
  errNum |= clSetKernelArg(kernel_test, 2, sizeof(cl_mem), &memObjects[2]);
  errNum |= clSetKernelArg(kernel_test, 3, sizeof(cl_mem), &memObjects[3]);
  errNum |= clSetKernelArg(kernel_test, 4, sizeof(cl_mem), &memObjects[4]);
  errNum |= clSetKernelArg(kernel_test, 5, sizeof(int), (void *) &height);
  errNum |= clSetKernelArg(kernel_test, 6, sizeof(int), (void *) &width); 
	
  int diff_count;
  int frame_num = 50;
  for (int t = 0; t < frame_num; t++)
  { 
    for (int i = 0; i < height; i++)
      for (int j = 0; j < width; j++)
        *(frame + i * width + j) = rand() % 255;

    start_train = clock();  
    
    trainGMM(frame, mask, modelW, modelS, modelM, height, width);
    
    end_train = clock();
    sum_t_train += end_train - start_train;          
  
    start_test = clock();
    
    testGMM(frame, mask, modelW, modelS, modelM, height, width);
    
    end_test = clock();
    sum_t_test += end_test - start_test;

    size_t local_work_size[2];
    size_t global_work_size[2];
    global_work_size[0] = WIDTH;
    global_work_size[1] = HEIGHT;
     
    errNum = clEnqueueWriteBuffer(commandQueue, memObjects[0], CL_TRUE, 0, 
               sizeof(unsigned char) * HEIGHT * WIDTH, frame, 0, NULL, NULL);
    checkErr(errNum, "clEnqueueWriteBuffer():frame");  

    start2_train = clock();    
    errNum = clEnqueueNDRangeKernel(commandQueue, kernel_train, 2, NULL, 
                                    global_work_size, NULL, 0, NULL, NULL);
    checkErr(errNum, "clEnqueueNDRandgeKernel():train");  
    clFinish(commandQueue);
    
    end2_train = clock();
    sum_t2_train += end2_train - start2_train;

    start2_test = clock();
    
    errNum = clEnqueueNDRangeKernel(commandQueue, kernel_test, 2, NULL, 
                                    global_work_size, NULL, 0, NULL, NULL);
    checkErr(errNum, "clEnqueueNDRandgeKernel():test");  
    clFinish(commandQueue);

    end2_test = clock();
    sum_t2_test += end2_test - start2_test;  
  
    errNum = clEnqueueReadBuffer(commandQueue, memObjects[1], CL_TRUE,
  		   0, sizeof(unsigned char) * HEIGHT * WIDTH, dev_mask,
  		   0, NULL, NULL);	
    checkErr(errNum, "clEnqueueReadBuffer():mask");  
    
 
    // TEST
    diff_count = 0;
    for (int i = 0; i < height * width; i++)
      if (mask[i] != dev_mask[i])
      {
        diff_count++;
        //cout << (int) mask[i] << " " << (int)dev_mask[i] << endl;
      }
 
    //cout << "Diff: " << diff_count << endl;
  }
	cout << "CPU Train: " << (sum_t_train / frame_num) / CLOCKS_PER_SEC << endl;
	cout << "CPU Test: " << (sum_t_test / frame_num) / CLOCKS_PER_SEC << endl;
	cout << "GPU Train: " << (sum_t2_train / frame_num) / CLOCKS_PER_SEC << endl;
	cout << "GPU Test: " << (sum_t2_test / frame_num) / CLOCKS_PER_SEC << endl;
}

