#include<stdio.h>
#include<stdlib.h>
#define maxnum 201

int main()
{
    int numV, numE;
    scanf("%d%d",&numV,&numE);getchar();

    int edge[maxnum][maxnum] = {0};//store edges and set to zero
    int i;
    for(i=1;i<=numE;i++){
        int num1,num2;
        scanf("%d%d",&num1,&num2);getchar();
        edge[num1][num2] = edge[num2][num1] = 1;
    }

    //judge part
    int cycle;
    scanf("%d",&cycle);getchar();
    while(cycle--)
    {
        int flag = 1;

        int len;//lenth of path
        int visited[maxnum] = {0};//count times on the path
        scanf("%d",&len);
        int seq[maxnum] = {0};//store path
        for(i=0;i<len;i++){
            scanf("%d",&seq[i]);
            visited[seq[i]]++;//count++
        }

        //check lenth
        if(len != numV+1) flag = 0;
        //check head and tail
        if(seq[0] != seq[len-1] || visited[seq[0]] != 2) flag = 0;
        //check connect
        for(i =1;i<len;i++){
            int first,second;
            first = seq[i-1];
            second = seq[i];
            if(edge[first][second] == 0) flag = 0;
        }

        if(flag){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
}