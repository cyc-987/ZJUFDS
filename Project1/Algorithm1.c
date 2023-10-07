#include<stdio.h>
#include<time.h>
#define X 1.001
#define N 1000

clock_t start, stop;
double duration;

int main()
{
    double x = X;
    long n = N;

    //run 10 times to calculate the average time
    double time[10];
    for(int i = 0; i < 10; i++)
    {
        //set the result
        long double result = 1;
        start = clock();//start timing
        //main algorithm
        long j = 0;
        for(j=0 ; j < n; j++){
            result *= x;
        }
        stop = clock();//end timing
        //calculate time and print
        duration = ((double)(stop - start))/CLOCKS_PER_SEC;
        printf("time%d: %lf\n",i+1,duration);
        //store
        time[i] = duration;
    }

    //calculate the average time
    double aver = 0;
    for(int i = 0; i<10; i++){
        aver += time[i];
    }
    aver /= 10;
    printf("average time: %lf\n",aver);
}