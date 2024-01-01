#include<stdio.h>
#define Max 50

int hash(int key, int N);
int find(int table[], int N, int key);
void insert(int table[], int N, int key);
void topSort(int table[], int N);
int pickMin(int stack[], int sTop, int table[]);

void printStack(int stack[], int sTop);

int graph[Max][Max] = {0};
int indegree[Max] = {0};
int NumValid = 0;

int main()
{
    int N;//the number of hash table
    int table[Max];

    //input
    scanf("%d",&N);getchar();
    NumValid = N;//store the actuall numbers stored
    int i;
    for(i=0;i<N;i++){
        int temp;
        scanf("%d",&temp);
        if(temp >= 0){
            table[i] = temp;
        }
        else{
            table[i] = -1;
            NumValid--;
        }
    }

    for(i=0;i<N;i++) insert(table,N,table[i]);

    topSort(table,N);
    return 0;
}

int hash(int key, int N)
{
    if(key < 0) return -1;
    else return key%N;
}

int find(int table[], int N, int key)
{
    for(int i = 0;i<N;i++){
        if(table[i] == key) return i;
    }
    return -1;
}

void insert(int table[], int N, int key)
{
    if(key <= -1) return;
    int hashValue = hash(key,N);
    int realPos = find(table,N,key);
    int pos = hashValue;

    //printf("--checking %d --\n",key);//tp
    while(pos != realPos){
        if(table[pos] <= -1){
            pos = (pos+1)%N;
            continue;
        }
        indegree[realPos]++;
        graph[find(table,N,table[pos])][realPos] = 1;
        //printf("find indegree: %d(%d) -> %d(%d)\n",find(table,N,table[pos]),table[pos],realPos,table[realPos]);//tp
        pos = (pos+1)%N;
    }
   // printf("total indegree: %d\n",indegree[realPos]);//tp
    //printf("--end check--\n");
}

void topSort(int table[], int N)
{
    int stack[Max];
    int sTop = 0;
    int topNum[Max];
    int counter = 0;
    //printf("\n--start Topsort--\n");

    int i;
    for(i=0;i<N;i++){
        if(indegree[i] == 0 && table[i] >= 0){
            stack[sTop++] = i;
            //printf("push: %d(%d)\n",i,table[i]);
            //printStack(stack,sTop);
        }
    }

    while(sTop){
        int minindex = pickMin(stack,sTop,table);
        sTop--;
        //printf("pop: %d(%d)\n",minindex,table[minindex]);
        //printStack(stack,sTop);

        topNum[minindex] = ++counter;
        for(i=0;i<N;i++){
            if(graph[minindex][i] == 1){
                if(--indegree[i] == 0){
                    stack[sTop++] = i;
                    //printf("push: %d(%d)\n",i,table[i]); 
                    //printStack(stack,sTop);
                }
            }
        }
    }

    //print the sequence
    for(i = 1;i<=NumValid;i++){
        int j;
        for(j=0;j<N;j++){
            if(topNum[j] == i)break;
        }
        if(i<NumValid) printf("%d ",table[j]);
        else printf("%d",table[j]);
    }
}

int pickMin(int stack[], int sTop, int table[])
{
    int min = table[stack[0]];
    int minindex = 0;
    for(int i=0;i<sTop;i++){
        if(table[stack[i]]<min){
            minindex = i;
            min = table[stack[i]];
        }
    }

    int result = stack[minindex];
    for(int i=minindex;i<sTop-1;i++) stack[i] = stack[i+1];
    return result;
}

void printStack(int stack[], int sTop)
{
    for(int i=0;i<sTop;i++) printf("%d ",stack[i]);
    printf("\n");
}