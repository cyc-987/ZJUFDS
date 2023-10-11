#include<stdio.h>
#include<time.h>
#define X 1.001
#define k 100000

clock_t start, stop;
clock_t duration;

int main()
{
    int N[8] = {1000,5000,10000,20000,40000,60000,80000,100000};
    for(int h = 0; h<8; h++){
    double x = X;
    long n = N[h];

    //run k times to calculate the average time
    clock_t time[k+1];
    long double result = 1;
    for(int i = 0; i < k+1; i++)
    {
        //set the result
        result = 1;
        start = clock();//start timing
        //main algorithm
        long j = 0;
        for(j=0 ; j < n; j++){
            result *= x;
        }
        stop = clock();//end timing
        //calculate time and print
        duration = stop - start;
        //store
        time[i] = duration;
    }

    //calculate the average time
    long double aver = 0;
    clock_t temp = 0;
    for(int i = 1; i<k+1; i++){
        temp += time[i];
    }
    aver = ((long double)temp/CLOCKS_PER_SEC);
    printf("ticks: %.0Lf\n", (long double)temp);
    printf("total time: %.8Lf\n",aver);
    aver /= k;
    printf("average time: %.8Lf\n",aver);
    printf("result: %Lf\n",result);
    }
}