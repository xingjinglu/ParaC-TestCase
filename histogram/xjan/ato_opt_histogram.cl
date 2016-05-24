#define BANK_NUM 32
#define BANK_NUM_LOG2 5
#define PERWORKITEM_PROCESS_INT4 32 
#define PERWORKITEM_PROCESS_INT 256 
#define G 256
#define G_LOG2 8
#define REDUCE_USE_LM_ROW 512
#define REDUCE_USE_LM_ROW_LOG2 9

__kernel void statistics(__global uint * image,__local int * inmyG,__global int * dispersed_result, int image_len)
{
    int group_id = get_group_id(0);
    int local_id = get_local_id(0);
    int local_size = get_local_size(0);
    int global_size = get_global_size(0);

    int low_5 = local_id & (BANK_NUM - 1);
    int high_3 = local_id >> BANK_NUM_LOG2;
    int pro_id = low_5 + (high_3 << BANK_NUM_LOG2 << BANK_NUM_LOG2);
    for(int i = 0; i<BANK_NUM; i++,pro_id+=BANK_NUM)
            inmyG[pro_id] = 0;

    barrier( CLK_LOCAL_MEM_FENCE );

    int global_id = get_global_id(0); 
    int bank_id = local_id & (BANK_NUM - 1);
    int temp,temp1; 
	
    for(int i=0 ; i<PERWORKITEM_PROCESS_INT && global_id < image_len; i++ , global_id+=global_size) 
    {
         temp = image[global_id];
         temp1 = temp & (G - 1); 
         temp1 = (temp1 << BANK_NUM_LOG2) + bank_id;
         (void) atomic_inc(inmyG + temp1);
         //inmyG[temp1]++;

         temp = temp >> G_LOG2;
         temp1 = temp & (G - 1); 
         temp1 = (temp1 << BANK_NUM_LOG2) + bank_id;
         (void) atomic_inc(inmyG + temp1);
         //inmyG[temp1]++;

         temp = temp >> G_LOG2;
         temp1 = temp & (G - 1); 
         temp1 = (temp1 << BANK_NUM_LOG2) + bank_id;
         (void) atomic_inc(inmyG + temp1);
         //inmyG[temp1]++;


         temp = temp >> G_LOG2;
         temp1 = temp & (G - 1); 
         temp1 = (temp1 << BANK_NUM_LOG2) + bank_id;
         (void) atomic_inc(inmyG + temp1);
         //inmyG[temp1]++;
    }

    barrier( CLK_LOCAL_MEM_FENCE );

    int f=local_id<<BANK_NUM_LOG2;
    int t=local_id,sum=0;
    for(int i=0;i<BANK_NUM;i++,t++)
           sum += inmyG[f+(t & (BANK_NUM-1))];
  
    dispersed_result[(group_id<<G_LOG2) + local_id] = sum; 
}
__kernel void reduce_ALL(__global int * dispersed_results,__local int * inmyG,int len, int stride)
{
    //reduce, without using local memory
    int global_id = get_global_id(0);
    int group_id = get_group_id(0);
    int local_id = get_local_id(0);
    int local_size = get_local_size(0);
    int global_size = get_global_size(0);

    int sign = group_id;
    if(local_id < len)
    {
         inmyG[local_id] = dispersed_results[sign + (local_id<<G_LOG2)];
         int r = local_id + local_size;
         while(r<len)
         {
              inmyG[local_id] += dispersed_results[sign + (r<<G_LOG2)];
              r+=local_size;
         }
    }
    else
        inmyG[local_id] = 0;

    while(stride >= 1)
    {
         barrier( CLK_LOCAL_MEM_FENCE );
         if(local_id < stride)
               inmyG[local_id] += inmyG[local_id + stride];
         stride >>= 1;
    }
    barrier( CLK_LOCAL_MEM_FENCE );
    dispersed_results[sign]=inmyG[0];
}
__kernel void ato_statistics(__global unsigned int * image,volatile __global unsigned int * dispersed_results, int image_len)
{
    int global_id = get_global_id(0); 
    int global_size = get_global_size(0); 
    int temp1,temp; 
   
    int step=0;
   
    for(int i=0 ; i<PERWORKITEM_PROCESS_INT && global_id+step < image_len; i++ , step+=global_size) 
    {
         temp = image[global_id+step];
         temp1 = temp & (G - 1); 
         (void) atomic_inc((volatile __global unsigned int*)(&(dispersed_results[temp1])));
         //dispersed_results[temp1]++;

         temp = temp >> G_LOG2;
         temp1 = temp & (G - 1); 
         (void) atomic_inc((volatile __global unsigned int*)(&(dispersed_results[temp1])));
         //dispersed_results[temp1]++;

         temp = temp >> G_LOG2;
         temp1 = temp & (G - 1); 
         (void) atomic_inc((volatile __global unsigned int*)(&(dispersed_results[temp1])));
         //dispersed_results[temp1]++;
         
         temp = temp >> G_LOG2;
         temp1 = temp & (G - 1); 
         (void) atomic_inc((volatile __global unsigned int*)(&(dispersed_results[temp1])));
         //dispersed_results[temp1]++;
    }
}
