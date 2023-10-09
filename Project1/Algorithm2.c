#include<stdio.h>
#include<time.h>
#define X 1.001
#define N 1000
#define k 20

clock_t start, stop;
clock_t duration;

int main()
{
    double x = X;
    long n = N;

    //run k times to calculate the average time
    clock_t time[k+1];
    long double result = 1;
    for(int i = 0; i < k+1; i++)
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