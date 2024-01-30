//program to read data from dis.dat and calculate Normalise autocorrelation function:
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{

// index variable
int i , j ,k;
// time in unit step--> dt
double dt = 0.0025;
//define dynamic array time and end-to-end distance
double *time;
double *eted;
// avearaged end-to-end distance array named as del end-to-end distance
double *deted;
// define dynamic  array to store NACF
double *nacf;
// normalisation constant
double *nf;
int N = 224001;
int n = 12000;
//initialising the average
double av = 0.0;
double aver ;
// initialise correlation sum 
double csum = 0.0;
 FILE *file = fopen("dis40ns.dat", "r");  // Open the file in read mode

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }
time = (double*)calloc(N,sizeof(double));
eted = (double*)calloc(N,sizeof(double));
deted = (double*)calloc(N,sizeof(double));
nacf = (double*)calloc(N,sizeof(double));
nf = (double*)calloc(N,sizeof(double));
//reading data from file and storing in array
for(i = 0;i<N;i++)
{
     fscanf(file,"%lf  %lf \n",&time[i],&eted[i]);
}
// avarage of the end-to-end distance
for(i = 0;i<N;i++)
{
   av += eted[i];
}
aver = av/(double)N;
printf("avarage of eted %lf \n",aver);
// calculating normalised autocorrelation function
for(i = 0;i<N;i++)
{
   deted[i] = eted[i]-aver;
   printf("%lf \n",deted[i]);
}
// opening file to store nacf data
FILE *pro = fopen("nacf.dat","w") ;
/*for(i =0;i<N;i++)
{
   fprintf(pro," %lf   %lf \n",time[i],nacf[i]);

}*/
// calculating normalised autocorrelation function
for(i=1;i<N;i++) // loop over the time lag
{
     csum = 0.0;
     for(j=0;j<N-i;j++) // loop over the complete time series
     {
          csum += deted[j]*deted[j+i];
     
     }
     k = N-i;
  //   printf("%d  %d  %d  ",i, k,N);
     //printf("%lf\n",(time[k]-time[i]));
    nacf[i] = csum/((double)N*dt - (double)i*dt);
    double nf = nacf[1];
    printf("%lf\n",nf);
     fprintf(pro," %lf   %lf \n",(double)i*dt,(nacf[i]/nf));

   //printf("%lf\n",(time[N]-time[i]));
}

// this code is not working
fclose(pro);
fclose(file);
return 0;
}
