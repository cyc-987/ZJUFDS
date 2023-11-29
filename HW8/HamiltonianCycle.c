#include <stdio.h>
#include <stdlib.h>
#define maxnum 201

int edges[maxnum][maxnum]; // Add a 2D array to store the edges

int main()
{
    //read first line
    int totalV, totalE;
    scanf("%d%d",&totalV,&totalE);
    getchar();

    // Initialize the edges array
    for(int i = 1; i <= totalV; i++){
        for(int j = 1; j <= totalV; j++){
            edges[i][j] = 0;
        }
    }

    //read list
    int i;
    for(i=1;i<=totalE;i++){
        //read two number
        int first, second;
        scanf("%d%d",&first,&second);
        getchar();

        // Add the edge to the edges array
        edges[first][second] = 1;
        edges[second][first] = 1;
    }

    //judge cycle
    //scan number
    int totalCyc;
    scanf("%d",&totalCyc);
    getchar();

    //cycle
    int flag = 1;
    while(totalCyc--)
    {
        //scan data
        int seqNum;
        scanf("%d",&seqNum);
        int scantemp;
        int Seq[maxnum];
        int visited[maxnum] = {0}; // Add a visited array to check if a vertex is visited more than once
        for(scantemp=0;scantemp<seqNum;scantemp++){
            scanf("%d",&Seq[scantemp]);
            visited[Seq[scantemp]]++;
        }
        getchar();

        //set flag
        flag = 1;
        //easy judge
        if(seqNum != totalV+1 || seqNum == 1){
            printf("NO\n");
            flag = 0;
            continue;
        }
        if(Seq[0] != Seq[seqNum-1]){
            printf("NO\n");
            flag = 0;
            continue;
        }

        // Check if a vertex is visited more than once
        for(i = 1; i <= totalV; i++){
            if(i != Seq[0] && visited[i] != 1){
                printf("NO\n");
                flag = 0;
                break;
            }
        }

        //formal judge
        int secondnum = 1;
        for(;secondnum<=totalV-1;secondnum++){
            if(flag){
                // Check if there is an edge in the edges array
                if(edges[Seq[secondnum-1]][Seq[secondnum]] == 0){
                    printf("NO\n");
                    flag = 0;
                }
            }
        }

        if(flag){
            printf("YES\n");
        }
    }
}