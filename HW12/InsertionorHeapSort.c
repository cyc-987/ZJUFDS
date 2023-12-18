#include<stdio.h>
#include<stdlib.h>
#define MaxN 100

int compare(int ol[], int cl[], int start, int end);
int ifmax(int check, int list[], int N);

int main()
{
    //initial some varibles
    int N;
    int originList[MaxN];
    int compareList[MaxN];

    //read N
    scanf("%d",&N);getchar();
    //read two sequences
    int i;
    for(i=0;i<N;i++) scanf("%d",&originList[i]);
    getchar();
    for(i=0;i<N;i++) scanf("%d",&compareList[i]);
    getchar();
    //printf("read complete.\n");

    //search max increase subsequence
    i = 1;
    while(i<N){
        if(compareList[i] < compareList[i-1]) break;
        i++;
    }
    if(i == N) return 0;
    //printf("find max increase until: %d\n",i);
    //compare if the rest is the same as original
    int flag = compare(originList,compareList,i,N-1);

    //print firstline
    if(flag == 1) printf("Insertion Sort\n");
    else printf("Heap Sort\n");
    
    //insertion
    if(flag == 1){
        int temp = compareList[i];
        int k = i-1;
        for(;k>=0;k--){
            if(compareList[k] > temp) compareList[k+1] = compareList[k];
            else{
                compareList[k+1] = temp;
                break;
            }
        }
        if(k == -1) compareList[0] = temp;
    }

    else if(flag == 2){//heap sort
        //find max decreasing sublist from behind
        i = N-2;
        while(i>=0){
            if(compareList[i] < compareList[0]) break;
            i--;
        }
        //update value
        int temp = compareList[i];
        compareList[i] = compareList[0];
        compareList[0] = temp;
        //maintain order
        temp = compareList[i];
        while(i<=N-2){
            if(compareList[i+1] < temp) compareList[i] = compareList[i+1];
            else{
                compareList[i] = temp;
                break;
            }
            i++;
        }
        //maintain heap
        int max = i-1;
        int fakehead = 1;
        int fakechild = 2*fakehead;
        while(fakechild-1 <= max){
            if(fakechild+1-1 <= max && compareList[fakechild+1-1] > compareList[fakechild-1]) fakechild++;
            if(compareList[fakehead-1] < compareList[fakechild-1]){
                int temp = compareList[fakehead-1];
                compareList[fakehead-1] = compareList[fakechild-1];
                compareList[fakechild-1] = temp;
            }
            fakehead = fakechild;
            fakechild = 2*fakehead;
        }
    }

    //print result
    for(i=0;i<N-1;i++) printf("%d ",compareList[i]);
    printf("%d",compareList[N-1]);

    return 0;
}

int compare(int ol[], int cl[], int start, int end)
{
    int flag = 1;
    int i = start;
    while(i<=end){
        if(ol[i] != cl[i]){
            flag = 2;
            break;
        }
        i++;
    }
    return flag;
}