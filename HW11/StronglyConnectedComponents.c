#include <stdio.h>
#include <stdlib.h>

#define MaxVertices 10  /* maximum number of vertices */
typedef int Vertex;     /* vertices are numbered from 0 to MaxVertices-1 */
typedef struct VNode *PtrToVNode;
struct VNode {
    Vertex Vert;
    PtrToVNode Next;
};
typedef struct GNode *Graph;
struct GNode {
    int NumOfVertices;
    int NumOfEdges;
    PtrToVNode *Array;
};

Graph ReadG(); /* details omitted */

void PrintV( Vertex V )
{
   printf("%d ", V);
}

void StronglyConnectedComponents( Graph G, void (*visit)(Vertex V) );

int main()
{
    Graph G = ReadG();
    StronglyConnectedComponents( G, PrintV );
    return 0;
}

/* Your function will be put here */
int Num[MaxVertices], Low[MaxVertices], visited[MaxVertices], Find[MaxVertices];
int Numcount = 0;
int stack[MaxVertices+1], isInStack[MaxVertices];
int top = 0;

int Min(int n1, int n2){
    if(n1 < n2) return n1;
    else return n2;
}

void tarjan(Graph G, int visitnum, void (*visit)(Vertex V))
{
    //printf("first visit start: %d\n",visitnum);
    //first update num and low
    visited[visitnum] = 1;
    Low[visitnum] = Num[visitnum] = ++Numcount;

    //push into stack
    stack[++top] = visitnum;
    isInStack[visitnum] = 1;

    PtrToVNode temp = G->Array[visitnum];
    while(temp){
        int w = temp->Vert;
        if(visited[w] == 0){
            tarjan(G,w,visit);
            Low[visitnum] = Min(Low[w],Low[visitnum]);
        }else {
            if(isInStack[w] == 1){
                Low[visitnum] = Min(Low[w],Low[visitnum]);
                //printf("update low: %d %d\n",visitnum,Low[visitnum]);
            }
        }
        temp = temp->Next;
    }

    if(Num[visitnum] == Low[visitnum]){
        while(top){
            visit(stack[top]);
            isInStack[stack[top]] = 0;
            if(stack[top--] == visitnum) break;
        }
        printf("\n");
    }
    //printf("first visit end: %d\n",visitnum);
}

void StronglyConnectedComponents( Graph G, void (*visit)(Vertex V) )
{
    int Nv = G->NumOfVertices;
    int i = 0;
    for(;i<Nv;i++){
        if(visited[i] == 0) tarjan(G,i,visit);
    }
}

Graph ReadG()
{
    int Nv, Ne, i;
    Vertex v1, v2;
    Graph G = (Graph)malloc(sizeof(struct GNode));
    scanf("%d %d", &Nv, &Ne);getchar();
    G->NumOfVertices = Nv;
    G->NumOfEdges = Ne;
    G->Array = (PtrToVNode *)malloc(Nv * sizeof(PtrToVNode));
    for (i = 0; i < Nv; i++)
    {
        G->Array[i] = NULL;
    }
    for (i = 0; i < Ne; i++)
    {
        scanf("%d %d", &v1, &v2);getchar();
        PtrToVNode newNode = (PtrToVNode)malloc(sizeof(struct VNode));
        newNode->Vert = v2;
        newNode->Next = G->Array[v1];
        G->Array[v1] = newNode;
    }
    //printf("Graph read!\n");
    return G;
}