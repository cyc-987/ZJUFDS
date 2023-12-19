#include<stdio.h>
#include<stdlib.h>
#define MaxN 100

void sortMin(int list[], long long N);
void maintainSort(int list[], long long N, long long index);
void deleteIndex(int list[], long long *N, long long index);

int main()
{
    //read firstline
    long long totalNum,maxRam;
    scanf("%lld%lld",&totalNum,&maxRam);getchar();

    //read numbers
    int list[MaxN];
    int run[MaxN];
    long long runCount = 0;
    long long i = 0;
    for(;i<totalNum;i++) scanf("%d",&list[i]);

    //start rank
    long long readCount = 0;
    int lastnumber = -32766;
    int ram[maxRam];
    for(i=0;i<maxRam;i++) ram[i] = list[readCount++];//read first list of numbers
    sortMin(ram,maxRam);

    while(maxRam){
        long long index = 0;
        while(index < maxRam && ram[index] < lastnumber) index++;
        if(index == maxRam){//start a new line and reset
            for(long long k = 0;k<runCount-1;k++) printf("%d ",run[k]);
            printf("%d",run[runCount-1]);
            runCount = 0;
            printf("\n");
            lastnumber = -32766;
            continue;
        }

        run[runCount++] = ram[index];
        lastnumber = ram[index];//update lastnumber
        if(readCount < totalNum){
            ram[index] = list[readCount++];
            maintainSort(ram,maxRam,index);
            continue;
        }else{
            deleteIndex(ram,&maxRam,index);
            continue;
        }
    }

    for(long long k = 0;k<runCount-1;k++) printf("%d ",run[k]);
    printf("%d",run[runCount-1]);
}

void sortMin(int list[], long long N)
{
    long long j,p;
    int temp;
    for(p=1;p<N;p++){
        temp = list[p];
        for(j=p;j>0 && list[j-1]>temp;j--) list[j] = list[j-1];
        list[j] = temp;
    }
}

void deleteIndex(int list[], long long *N, long long index)
{
    long long i = index;
    for(;i<*N-1;i++) list[i] = list[i+1];
    (*N)--;
}

void maintainSort(int list[], long long N, long long index)
{
    if(index == -1) return;

    int flag;
    if(index == N) flag = 1;
    else if(index == 0) flag = 2;
    else if(list[index-1] > list[index]) flag = 1;
    else if(list[index+1] < list[index]) flag = 2;

    if(flag == 1){
        int temp = list[index];
        while(index > 0){
            if(list[index-1] > temp) list[index] = list[index-1];
            else break;
            index--;
        }
        list[index] = temp;
    }else if(flag == 2){
        int temp = list[index];
        while(index<N-1){
            if(list[index+1] < temp) list[index] = list[index+1];
            else break;
            index++;
        }
        list[index] = temp;
    }
}