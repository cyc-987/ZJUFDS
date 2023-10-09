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
    long double result = 1;
    for(int i = 0; i < 10; i++)
    {
        //set the result
        result = 1;
        x = X;
        n = N;
        start = clock();//start timing
        //main algorithm
        while(n != 0){
            if(n%2){
                result *= x;
            }
            x = x * x;
            n /= 2;
        }
        stop = clock();//end timing
        //calculate time and print
        duration = ((double)(stop - start))/CLOCKS_PER_SEC;
        printf("time%d: %.8f\n",i+1,duration);
        //store
        time[i] = duration;
    }

    //calculate the average time
    double aver = 0;
    for(int i = 0; i<10; i++){
        aver += time[i];
    }
    aver /= 10;
    printf("average time: %.8f\n",aver);
    printf("result:%Lf",result);
}