#include<stdio.h>
#include<stdlib.h>
#define maxV 1001
#define infinity 100001

//node of adlist
typedef struct Node* ptrtoNode;
typedef struct Node{
    int ver;
    int weight;
    ptrtoNode Next;
}Node;

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

//add edges for undirected graph
void addEdge(ptrG G, int first, int second, int weight);
//find the min distance in unknown vertix
//find from startpoint to Nv(endPoint), return 0 if not find the required element
int findMin(int Known[],long int Dist[],long int Nv,long int startPoint);
//inquiry function
//read the sequence and pass it to the dijkstra function
//return 1 for success, 0 for failed
int inquiry(long int Nv, ptrG G);
//main dijkstra function
//change the value in flag for inqure result
void dijkstra(int Known[], long int Dist[], int Seq[], int* flag, long int Nv, ptrG G);

int main()
{
    //init
    printf("welcome and select the input mode:\n");
    printf("1:input from file\n");
    printf("2:input from stdin\n");
    printf("3:exit\n");
    //read mode
    int mode;
    scanf("%d",&mode);getchar();
    if(mode == 3) return 0;//exit
    if(mode != 1 && mode != 2){
        printf("wrong input\n");
        return 0;
    }//wrong input

    //input from file
    if(mode == 1){
        freopen("input.txt","r",stdin);
    }else{
        //input from stdin
    }

    //read nv and ne
    long int Nv,Ne;
    scanf("%ld%ld",&Nv,&Ne);getchar();
    ptrG G = (ptrG)malloc(sizeof(Graph));
    if (G == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    G->Nv = Nv;
    G->Ne = Ne;//create and store Nv and Ne;

    //read edges
    int i;
    for(i=0;i<Ne;i++){
        int first,second,weight;
        scanf("%d%d%d",&first,&second,&weight);getchar();
        addEdge(G,first,second,weight);//this add operation will add both two direction
    }

    //inquries
    int k;
    scanf("%d",&k);getchar();//read inquiry number
    for(i=1;i<=k;i++)//i is for big circle
    {
        //print result
        if(inquiry(Nv,G)){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
}

//functions
void addEdge(ptrG G, int first, int second, int weight)
{
    //add edge
    if(G->L[first].FirstEdge == NULL){//if the first edge is null
        ptrtoNode temp = (ptrtoNode)malloc(sizeof(Node));
        if (temp == NULL) {
            printf("Memory allocation failed.\n");
            exit(1);
        }
        temp->Next = NULL;
        temp->ver = second;
        temp->weight = weight;
        G->L[first].FirstEdge = temp;
    }else{//if the first edge is not null
        ptrtoNode temp = G->L[first].FirstEdge;
        while(temp->Next) temp = temp->Next;//find the last node
        temp->Next = (ptrtoNode)malloc(sizeof(Node));
        if (temp == NULL) {
            printf("Memory allocation failed.\n");
            exit(1);
        }
        temp = temp->Next;
        temp->Next = NULL;
        temp->ver = second;
        temp->weight = weight;
    }

    //exchange
    if(G->L[second].FirstEdge == NULL){
        ptrtoNode temp = (ptrtoNode)malloc(sizeof(Node));
        if (temp == NULL) {
            printf("Memory allocation failed.\n");
            exit(1);
        }
        temp->Next = NULL;
        temp->ver = first;
        temp->weight = weight;
        G->L[second].FirstEdge = temp;
    }else{
        ptrtoNode temp = G->L[second].FirstEdge;
        while(temp->Next) temp = temp->Next;
        temp->Next = (ptrtoNode)malloc(sizeof(Node));
        if (temp == NULL) {
            printf("Memory allocation failed.\n");
            exit(1);
        }
        temp = temp->Next;
        temp->Next = NULL;
        temp->ver = first;
        temp->weight = weight;
    }
}

int findMin(int Known[],long int Dist[],long int Nv,long int startPoint)//find the min distance in unknown vertix
{
    int i = startPoint+1;//start from the next element
    long int min = 0;
    for(;i<=Nv;i++){
        if(Known[i] == 1)continue;//if known, continue

        if(min == 0){
            min = i;//if min is not set, set it
        }else{
            if(Dist[min] > Dist[i]) min = i;//if min is set, compare
        }
    }
    return min;
}

int inquiry(long int Nv, ptrG G)
{
    //read sequence into an array
    int Seq[maxV] = {0};
    for(int j = 0;j<Nv;j++) scanf("%d",&Seq[j+1]);
    getchar();

    //start inquiry
    int Known[maxV] = {0};//set known array
    long int Dist[maxV];//set distance array
    for(int j = 1;j<=Nv;j++) Dist[j] = infinity;//set to infinity
    //do not need p[]

    //process first node
    int flag = 1;//record the result
    Dist[Seq[1]] = 0;
    dijkstra(Known,Dist,Seq,&flag,Nv,G);

    return flag;
}

void dijkstra(int Known[], long int Dist[], int Seq[], int* flag, long int Nv, ptrG G)
{
    //main part of dijkstra
    int count = 1;//count the number of known node
    for(;;)
    {
        long int v;
        if(!(v = findMin(Known,Dist,Nv,0))) break;//end situation
        
        //check element
        while(v){
            //check if the element is in the sequence
            if(v != Seq[count]) v = findMin(Known,Dist,Nv,v);
            else break;
        }
        if(v == 0){
            *flag = 0;
            break;
        }else{
            count++;
        }

        Known[v] = 1;
        ptrtoNode temp = G->L[v].FirstEdge;
        while(temp){//update the distance
            if(!Known[temp->ver]){
                if(Dist[v]+temp->weight < Dist[temp->ver])
                {
                    //update w
                    Dist[temp->ver] = Dist[v]+temp->weight;
                }
            }
            temp = temp->Next;
        }
    }
}