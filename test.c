#include <stdio.h>
#include <math.h>
#include <stdlib.h>
// Function to calculate the end-to-end distance delta_l(t)
//double delta_l(double t) {
    // Replace this with your implementation
    // For example:
   // return sin(t); // Example function, replace with your actual function
//}

int main() {
    double dt = 0.0025; // Time step
    int N = 320001; // Number of time points
    int i;
    double *time;
double *eted;
// avearaged end-to-end distance array named as del end-to-end distance
double *deted;
// define dynamic  array to store NACF
double *nacf;
// normalisation constant
double *nf;
FILE *file = fopen("disnct.dat", "r");  // Open the file in read mode

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }
    //double time[N]; // Array to store time points
    double delta_l_values[N]; // Array to store delta_l values
    time = (double*)calloc(N,sizeof(double));
eted = (double*)calloc(N,sizeof(double));
deted = (double*)calloc(N,sizeof(double));
nacf = (double*)calloc(N,sizeof(double));
nf = (double*)calloc(N,sizeof(double));
//reading data from file and storing in array
for( i = 0;i<N;i++)
{
     fscanf(file,"%lf  %lf \n",&time[i],&eted[i]);
}

    // Populate time and delta_l_values arrays with data
    // You should replace this with your own code to read data from file or generate it

    // Trapezoidal rule integration
   for(int j = 1;j<N;j++){
    double C_prime_sum = 0.0;
    for ( i = 0; i < N-j; i++) {
        double delta_t = time[j] - time[j-1];
        double average_delta_l = 0.5 * (eted[0] + eted[i - 1]);
        C_prime_sum += average_delta_l * eted[i] * delta_t;
    }

    // Normalize by (t - Δ)
    double delta_t_total = time[N - 1] - time[i];
    double C_prime = C_prime_sum / delta_t_total;

    printf( "%lf  %lf\n",delta_t_total, C_prime);
}
    return 0;
}

