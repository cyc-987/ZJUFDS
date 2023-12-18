#include <stdio.h>

#define ElementType int
#define MAXN 100

void merge_pass( ElementType list[], ElementType sorted[], int N, int length );

void output( ElementType list[], int N )
{
    int i;
    for (i=0; i<N; i++) printf("%d ", list[i]);
    printf("\n");
}

void  merge_sort( ElementType list[],  int N )
{
    ElementType extra[MAXN];  /* the extra space required */
    int  length = 1;  /* current length of sublist being merged */
    while( length < N ) { 
        merge_pass( list, extra, N, length ); /* merge list into extra */
        output( extra, N );
        length *= 2;
        merge_pass( extra, list, N, length ); /* merge extra back to list */
        output( list, N );
        length *= 2;
    }
} 


int main()
{
    int N, i;
    ElementType A[MAXN];

    scanf("%d", &N);
    for (i=0; i<N; i++) scanf("%d", &A[i]);
    merge_sort(A, N);
    output(A, N);

    return 0;
}

/* Your function will be put here */
void merge_pass_temp(ElementType list[], ElementType sorted[],int leftstart, int leftend,int rightstart,int rightend)
{
    int ltemp = leftstart;
    int rtemp = rightstart;
    int storetemp = ltemp;
    while(ltemp <= leftend && rtemp <= rightend){
        if(list[ltemp] < list[rtemp]) sorted[storetemp++] = list[ltemp++];   
        else sorted[storetemp++] = list[rtemp++];
    }
    while(ltemp<=leftend) sorted[storetemp++] = list[ltemp++];
    while(rtemp<=rightend) sorted[storetemp++] = list[rtemp++];
}


void merge_pass( ElementType list[], ElementType sorted[], int N, int length )
{
    if(length >= N){
        for(int i = 0; i < N; i++){
            sorted[i] = list[i];
        }
        return;
    }

    int i = 0;
    while(i<=N-1){
        int leftstart = i;
        int leftend = i+length-1;
        if(leftend>=N-1) break;
        int rightstart = i+length;
        int rightend = i+length*2-1;
        if(rightend>=N) rightend = N-1;
        merge_pass_temp(list,sorted,leftstart,leftend,rightstart,rightend);

        //update i
        i = rightend+1;
    }

    if(i<N && i+length-1 >= N-1){
        while(i<N){
            sorted[i] = list[i];
            i++;
        }
    }
}