#include<CL/cl.h>
#include<stdio.h>

static inline char* ReadSources(const char* fileName)
{
  FILE *file=fopen(fileName,"rb");
  if(!file)
  {
    printf("ERROR:Failed to open file '%s'\n",fileName);
    return NULL;
  }
	
  if(fseek(file,0,SEEK_END))
  {
    printf("ERROR: Failed to open file '%s'\n",fileName);
    fclose(file);
    return NULL;
  }
	
  long size=ftell(file);
  if(size==0)
  {
    printf("ERROR: Failed to check position on file '%s'\n",fileName);
    fclose(file);
    return NULL;
  }
	
  rewind(file);
	
  char *src=(char *)malloc(sizeof(char)*size+1);
  if(!src)
  {
    printf("ERROR: Failed to allocate memory for file '%s'\n",fileName);
    fclose(file);
    return NULL;
  }
	
  size_t res=fread(src,1,sizeof(char) *size,file);
  if(res !=sizeof (char) * size)
  {
    printf("ERROR: Failed to read file '%s'\n",fileName);
    fclose(file);
    free(src);
    return NULL;
  }
	
  src[size]='\0';/*NULL terminated */
  fclose(file);
	
  return src;
}



int main()
{
  int WidthA = 256, HeightA = 256;
  int WidthB = 256, HeightB = 256;

  int *A = (int*) malloc(sizeof(int)*HeightA *WidthA);
  int *B = (int*) malloc(sizeof(int)*HeightB *WidthB);
  int *C = (int*) malloc(sizeof(int)*HeightA *WidthB);

  cl_int ciErrNum;
  cl_platform_id platform;

  // Use the first platform.
  ciErrNum = clGetPlatformIDs(1, &platform, NULL);

  // Use the first device.
  cl_device_id device;
  ciErrNum = clGetDeviceIDs(platform,
      CL_DEVICE_TYPE_ALL,
      1,
      &device,
      NULL);

  cl_context_properties cps[3] = {
    CL_CONTEXT_PLATFORM,
    (cl_context_properties)platform, 
    0};

  // Create the context.
  cl_context ctx = clCreateContext(
      cps,
      1,
      &device,
      NULL,
      NULL,
      &ciErrNum);


  // Create the command queue.
  cl_command_queue myqueue = clCreateCommandQueue(
      ctx,
      device,
      0,
      &ciErrNum);


  // Allocate space for matrix a on the device.
  cl_mem bufferA = clCreateBuffer( ctx, CL_MEM_READ_ONLY, 
      WidthA*HeightA*sizeof(int),
      NULL,
      &ciErrNum);

  // Copy matrix a to the device.
  ciErrNum = clEnqueueWriteBuffer(
      myqueue,
      bufferA,
      CL_TRUE,
      0,
      WidthA*HeightA*sizeof(int),
      (void*)A,
      0, 
      NULL,
      NULL);

  // 
  cl_mem bufferB = clCreateBuffer( ctx, CL_MEM_READ_ONLY, 
      WidthB*HeightB*sizeof(int),
      NULL,
      &ciErrNum);

  // Copy matrix a to the device.
  ciErrNum = clEnqueueWriteBuffer(
      myqueue,
      bufferB,
      CL_TRUE,
      0,
      WidthA*HeightA*sizeof(int),
      (void*)B,
      0, 
      NULL,
      NULL);

  cl_mem bufferC = clCreateBuffer( ctx, CL_MEM_READ_ONLY, 
      WidthB*HeightA*sizeof(int),
      NULL,
      &ciErrNum);
  char inputfile[] = "matrixmul.cl";
  char *source = ReadSources((const char*)inputfile);
  cl_program myprog = clCreateProgramWithSource(
      ctx,
      1,
      (const char**)&source,
      NULL,
      &ciErrNum);

  ciErrNum = clBuildProgram(myprog, 0, NULL, NULL, NULL, NULL);

  cl_kernel mykernel = clCreateKernel(
      myprog,
      "SimpleMultiply",
      &ciErrNum);

  clSetKernelArg(mykernel, 0, sizeof(cl_mem), (void*)C); 
  clSetKernelArg(mykernel, 1, sizeof(cl_mem), (void*)A); 
  clSetKernelArg(mykernel, 2, sizeof(cl_int), (void*)&WidthA); 
  clSetKernelArg(mykernel, 3, sizeof(cl_int), (void*)&HeightA); 
  clSetKernelArg(mykernel, 4, sizeof(cl_mem), (void*)B); 
  clSetKernelArg(mykernel, 5, sizeof(cl_int), (void*)&WidthB); 
  clSetKernelArg(mykernel, 6, sizeof(cl_int), (void*)&HeightB); 

  size_t localws[2] = {16, 16};
  size_t globalws[2] = {HeightA, WidthB};

  // Execute the kernel.
  ciErrNum = clEnqueueNDRangeKernel(
       myqueue,
       mykernel,
       2,
       NULL,
       globalws,
       localws,
       0,
       NULL,
       NULL);


  // Read the output data back to the host.
  ciErrNum = clEnqueueReadBuffer(
      myqueue,
      bufferC,
      CL_TRUE,
      0,
      HeightA*WidthB*sizeof(int),
      (void*)C,
      0,
      NULL,
      NULL);

  return 0;

}
