#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} bool;
#define MaxVertexNum 10  /* maximum number of vertices */
typedef int Vertex;      /* vertices are numbered from 1 to MaxVertexNum */

typedef struct AdjVNode *PtrToAdjVNode; 
struct AdjVNode{
    Vertex AdjV;
    PtrToAdjVNode Next;
};

typedef struct Vnode{
    PtrToAdjVNode FirstEdge;
} AdjList[MaxVertexNum];

typedef struct GNode *PtrToGNode;
struct GNode{  
    int Nv;
    int Ne;
    AdjList G;
};
typedef PtrToGNode LGraph;

LGraph ReadG(); /* details omitted */

bool IsTopSeq( LGraph Graph, Vertex Seq[] );

int main()
{
    int i, j, N;
    Vertex Seq[MaxVertexNum];
    LGraph G = ReadG();
    scanf("%d", &N);
    for (i=0; i<N; i++) {
        for (j=0; j<G->Nv; j++)
            scanf("%d", &Seq[j]);
        if ( IsTopSeq(G, Seq)==true ) printf("yes\n");
        else printf("no\n");
    }

    return 0;
}

/* Your function will be put here */
bool IsTopSeq( LGraph Graph, Vertex Seq[] )
{
    int totalNumV = Graph->Nv;
    
    int indegree[MaxVertexNum];
    //set zero
    int i = 0;
    for(i = 0;i<totalNumV;i++) indegree[i] = 0;

    //set number
    for(i = 0;i<totalNumV;i++){
        PtrToAdjVNode temp = Graph->G[i].FirstEdge;
        while(temp){
            indegree[temp->AdjV]++;
            temp = temp->Next;
        }
    }

    //judge
    for(i = 0;i<totalNumV;i++)
    {
        if(indegree[Seq[i]-1] != 0) return false;
        //update indegree
        PtrToAdjVNode temp = Graph->G[Seq[i]-1].FirstEdge;
        while(temp){
            indegree[temp->AdjV]--;
            temp = temp->Next;
        }
    }

    return true;
}