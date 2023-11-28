#include <stdio.h>
#include <stdlib.h>
#define maxnum 201

typedef struct AdjVNode *PtrToAdjVNode; 
struct AdjVNode{
    int AdjV;
    PtrToAdjVNode Next;
};

typedef struct Vnode{
    PtrToAdjVNode FirstEdge;
} AdjList[maxnum];

typedef struct GNode *PtrToGNode;
struct GNode{  
    int Nv;
    int Ne;
    AdjList G;
};
typedef PtrToGNode LGraph;

int main()
{
    //read first line
    int totalV, totalE;
    scanf("%d%d",&totalV,&totalE);
    getchar();

    //create graph
    LGraph Graph = (LGraph)malloc(sizeof(struct GNode));
    Graph->Nv = totalV;
    Graph->Ne = totalE;
    
    //read list
    int i;
    for(i=1;i<=totalE;i++){
        //read two number
        int first, second;
        scanf("%d%d",&first,&second);
        getchar();

        //create node
        PtrToAdjVNode temp = Graph->G[i].FirstEdge;
        //first add;
        if(temp == NULL){
            temp = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));//malloc new node
            temp->AdjV = second;
            temp->Next = NULL;
        }else{//already has node
            while(temp->Next) temp = temp->Next;//locate to last node
            temp->Next = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));//malloc new node
            temp = temp->Next;
            temp->AdjV = second;
            temp->Next = NULL;
        }
    }

    //judge cycle
    //scan number
    int totalCyc;
    scanf("%d",&totalCyc);
    getchar();

    //cycle
    while(totalCyc--)
    {
        //scan data
        int seqNum;
        scanf("%d",&seqNum);
        int scantemp;
        int Seq[maxnum];
        for(scantemp=0;scantemp<seqNum;scantemp++){
            scanf("%d",&Seq[scantemp]);
        }
        getchar();

        //easy judge
        if(seqNum != totalV){
            printf("NO\n");
            return 0;
        }
    }
}