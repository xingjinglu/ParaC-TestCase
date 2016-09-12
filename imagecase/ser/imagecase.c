#include <stdlib.h>
#define ROWS 256
#define COLS 256
#define RATE 0.8
#define M 256
#define N 256
#define MRATE 205
#define NRATE 205 
#define SIZE 3
#define MIN(a,b) ((a)<(b) ? (a):(b))

// M is height, N is width

void rgb2grey(char oimage[M][N*3], char mimage[M][N])
{
  float arg[1][3] = {0.299, 0.587, 0.114};
  for(int i = 0; i < M; i++){
    for(int j = 0; j < N; j++){
      mimage[i][j] = oimage[i][j*3] * arg[0][0] + oimage[i+1][j*3+1] * arg[0][1] + oimage[i+2][j*3+2] * arg[0][2];
    }
  }
}
void resizeImage(char mimage[M][N], char dimage[MRATE][NRATE])
{
  double rotate = 1/RATE;
  for(int i = 0; i < M*RATE; i++){
    for(int j = 0; j < N*RATE; j++){
      int r1 = (int)(i*rotate);
      int r2 = MIN(M-1, r1+1);
      double p = i*rotate-r1;

      int c1 = (int)(j*rotate);
      int c2 = MIN(N-1, c1+1);
      double q = j*rotate-c1;
      //dimage[i][j] = (1-p)*(1-q)*mimage[r1*COLS+c1]+(1-p)*q*mimage[r1*COLS+c2]+p*(1-q)*mimage[r2*COLS+c1]+p*q*mimage[r2*COLS+c2];
      dimage[i][j] = (1-p)*(1-q)*mimage[r1][c1]+(1-p)*q*mimage[r1][c2]+p*(1-q)*mimage[r2][c1]+p*q*mimage[r2][c2];
    }
  }
}
void convolutionImage(char dimage[MRATE][NRATE], char dsmage[MRATE][NRATE], float kernel[SIZE][SIZE])
{
    float sum1=1.0;
    float sum = 0.0;
#if 0
    {  
        Src[][-1] = 0;
        Src[][+1] = 0;
        Src[-1][] = 0;
        Src[+1][] = 0;

        dimage[*][-1] = 0;
        dimage[*][+1] = 0;
        dimage[-1][*] = 0;
        dimage[+1][*] = 0;
    }
#endif

    for(int i = 0; i < M*RATE; i++){
        for(int j = 0; j < N*RATE; j++){
            if(i == 0 || i == M*RATE-1)
          sum1 -= (1/9)*3;

        if(j == 0 ||j == M*RATE-1)
        {
          sum1 -= (1/9) * 3;
          if(i == 0 || i == M*RATE-1)
            sum1+=1/9;
        }
        if(i == 0){         // border condition 1
          if(j == 0){
            sum = kernel[0][0] * 0 + kernel[0][1] * 0 + kernel[0][2] * 0;
            sum += kernel[1][0] * 0 + kernel[1][1] * dimage[0][0] + kernel[1][2] * dimage[0][1];
            sum += kernel[2][0] * 0 + kernel[2][1] * dimage[1][0] + kernel[2][2] * dimage[1][1];
          } else if(j == NRATE-1){
            sum = kernel[0][0] * 0 + kernel[0][1] * 0 + kernel[0][2] * 0;
            sum += kernel[1][0] * dimage[0][NRATE-2] + kernel[1][1] * dimage[0][NRATE-1] + kernel[1][2] * 0;
            sum += kernel[2][0] * dimage[1][NRATE-2] + kernel[2][1] * dimage[1][NRATE-2] + kernel[2][2] * 0;
          } else {
              sum = kernel[0][0] * 0 + kernel[0][1] * 0 + kernel[0][2] * 0;
              sum += kernel[1][0] * dimage[i][j-1] + kernel[1][1] * dimage[i][j] + kernel[1][2] * dimage[i][j+1];
              sum += kernel[2][0] * dimage[i+1][j-1] + kernel[2][1] * dimage[i+1][j] + kernel[2][2] * dimage[i+1][j+1];
          }
        } else if(i == MRATE-1){   // border condition 2
          if(j == 0){
            sum = kernel[0][0] * 0 + kernel[0][1] * dimage[MRATE-2][0] + kernel[0][2] * dimage[MRATE-2][1];
            sum += kernel[1][0] * 0 + kernel[1][1] * dimage[MRATE-1][0] + kernel[1][2] * dimage[MRATE-1][1];
            sum += kernel[2][0] * 0 + kernel[2][1] * 0 + kernel[2][2] * 0;
          } else if(j == NRATE - 1){
            sum = kernel[0][0] * dimage[MRATE-2][NRATE-2] + kernel[0][1] * dimage[MRATE-2][NRATE-1] + kernel[0][2] * 0;
            sum += kernel[1][0] * dimage[MRATE-1][NRATE-2] + kernel[1][1] * dimage[MRATE-1][NRATE-1] + kernel[1][2] * 0;
            sum += kernel[2][0] * 0 + kernel[2][1] * 0 + kernel[2][2] * 0;
          } else {
            sum = kernel[0][0] * dimage[i-1][j-1] + kernel[0][1] * dimage[i-1][j] + kernel[0][2] * dimage[i-1][j+1];
            sum += kernel[1][0] * dimage[i][j-1] + kernel[1][1] * dimage[i][j] + kernel[1][2] * dimage[i][j+1];
            sum += kernel[2][0] * 0 + kernel[2][1] * 0 + kernel[2][2] * 0;
          }
        } else if(i > 0 && i < MRATE-1){   // border condition 3
          if(j == 0){
            sum = kernel[0][0] * 0 + kernel[0][1] * dimage[i-1][0] + kernel[0][2] * dimage[i-1][1];
            sum += kernel[1][0] * 0 + kernel[1][1] * dimage[i][0] + kernel[1][2] * dimage[i][1];
            sum += kernel[2][0] * 0 + kernel[2][1] * dimage[i+1][0] + kernel[2][2] * dimage[i+1][1];
          } else if(j == NRATE - 1){
            sum = kernel[0][0] * dimage[i-1][NRATE-2] + kernel[0][1] * dimage[i-1][NRATE-1] + kernel[0][2] * 0;
            sum += kernel[1][0] * dimage[i][NRATE-2] + kernel[1][1] * dimage[i][NRATE-1] + kernel[1][2] * 0;
            sum += kernel[2][0] * dimage[i+1][NRATE-2] + kernel[2][1] * dimage[i+1][NRATE-1] + kernel[2][2] * 0;
          }
        } else {      // normal
            sum = kernel[0][0] * dimage[i-1][j-1] + kernel[0][1] * dimage[i-1][j] + kernel[0][2] * dimage[i-1][j+1];
            sum += kernel[1][0] * dimage[i][j-1] + kernel[1][1] * dimage[i][j] + kernel[1][2] * dimage[i][j+1];
            sum += kernel[2][0] * dimage[i+1][j-1] + kernel[2][1] * dimage[i+1][j] + kernel[2][2] * dimage[i+1][j+1];
        } 
        dsmage[i][j]= sum1 == 1? sum : sum/sum1;			
      }
    }
}
int main()
{
   
    int rROWS=ROWS*RATE;
    int rCOLS=COLS*RATE;
    int size=3;
    
    char *src=(char *)malloc(sizeof(char)*ROWS*COLS*3);
    char *mid=(char *)malloc(sizeof(char)*ROWS*COLS);
    char *dst=(char *)malloc(sizeof(char)*rROWS*rCOLS);
    char *ddt=(char *)malloc(sizeof(char)*rROWS*rCOLS);

    char *p=src;

    for(int i=0;i<ROWS*COLS*3;i++)
        *p++=rand()%100+1;

    char* oimage = src;
    char* mimage = mid;
    char* dimage = dst;
    char* dsmage = ddt;


    float kernel[3][3]={1,2,1,2,4,2,1,2,1};//waitting for filling

    for(int i=0;i<size;i++)
        for(int j=0;j<size;j++)
        kernel[i][j]=kernel[i][j]/16;


    rgb2grey((char(*)[N*3])oimage,(char(*)[N])mimage);
    resizeImage((char(*)[N])mimage,(char(*)[NRATE])dimage);
    convolutionImage((char(*)[NRATE])dimage,(char(*)[NRATE])dsmage,(float(*)[3])kernel);
    return 0;
}



