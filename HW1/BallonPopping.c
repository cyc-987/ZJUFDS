#include<stdio.h>
#include<stdlib.h>

int main()
{
    //read the first line
    long long numberOfBalls = 0;
    long long heigt = 0;
    scanf("%lld%lld",&numberOfBalls, &heigt);

    //require a space for the second line
    long long * coordinates = (long long *)malloc(sizeof(long long)*numberOfBalls);
    //long long coordinates[100];

    //read the second line
    for(long long  i = 0; i < numberOfBalls; i++){
        scanf("%lld", &coordinates[i]);
    }

    //set some numbers
    long long  maxNum = 0;
    long long  maxPosition = 0;

    //find the max number
    for(long long  i = 0; i < numberOfBalls; i++){
        long long temp = 0;
        long long k = i;
        for(k; k < numberOfBalls; k++){
            if(coordinates[k] - coordinates[i] <= heigt){
                temp++;
            }else{
                break;
            }
        }
        k--;
        if(maxNum < temp){
            maxNum = temp;
            maxPosition = coordinates[k] - heigt;
        }
    }

    //print the result
    printf("%lld %lld", maxPosition, maxNum);

    return 0;
}