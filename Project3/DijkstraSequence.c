#include<stdio.h>
#include<stdlib.h>
#define maxV 1001

//node of adlist
typedef struct Node{
    int ver;
    int weight;
    ptrtoNode Next;
}Node;
typedef Node* ptrtoNode;
//a list of ver
typedef struct Ver{
    ptrtoNode FirstEdge;
}List[maxV];
//struct of graph
typedef struct Graph{
    long int Nv;
    long int Ne;
    List L;
}Graph;
typedef Graph* ptrG;

//some functions
void addEdge(ptrG G, int first, int second, int weight);

int main()
{
    //read nv and ne
    long int Nv,Ne;
    scanf("%ld%ld",&Nv,&Ne);getchar();
    ptrG G = (ptrG)malloc(sizeof(Graph));
    G->Nv = Nv;
    G->Ne = Ne;//create and store Nv and Ne;

    //read edges
    int i;
    for(i=0;i<Ne;i++){
        int first,second,weight;
        scanf("%d%d%d",&first,&second,&weight);getchar();
        addEdge(G,first,second,weight);
    }

    //inquries
    int k;
    scanf("%d",&k);getchar();
    for(i=1;i<=k;i++)//i is for big circle
    {
        //read sequence into an array
        int Seq[maxV] = {0};
        for(int j = 0;j<k;j++) scanf("%d",&Seq[j+1]);
        getchar();

        //start inquiry
        int Known[maxV] = {0};//set known array
        long int Dist[maxV];//set distance array
        for(int j = 1;j<=Nv;j++) Dist[j] = 100000;//set to infinity
        //do not need p[]

        //process first node
        Known[Seq[1]] = 1;
        Dist[Seq[1]] = 0;
    }
}

//functions
void addEdge(ptrG G, int first, int second, int weight)
{
    if(G->L[first].FirstEdge == NULL){
        ptrtoNode temp = (ptrtoNode)malloc(sizeof(Node));
        temp->Next = NULL;
        temp->ver = second;
        temp->weight = weight;
        G->L[first].FirstEdge = temp;
    }else{
        ptrtoNode temp = G->L[first].FirstEdge;
        while(temp) temp = temp->Next;
        temp = (ptrtoNode)malloc(sizeof(Node));
        temp->Next = NULL;
        temp->ver = second;
        temp->weight = weight;
    }
}