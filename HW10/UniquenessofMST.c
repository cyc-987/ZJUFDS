#include<stdio.h>
#include<stdlib.h>
#define Max 1000
#define Maxe 1000000

struct node{
    int v1;
    int v2;
    long long weight;
};
typedef struct node edge;

long long Ematrix[Max][Max];
int Union[Max];//an array for union-find
edge E[Maxe];//an array of struct edge to store edges
edge UsedE[Maxe];
int used = 0;

void Exchange(int num1, int num2);
void buildMinHeap(long long Ne);
edge getTopAndMaintainHeap(int n);
int findWithCompress(int v);
void unionH(int h1, int h2);
int judgeIFconnected(int Nv);
int judgeIFunique(int v1, int v2, long long weight,long long ne);
int dfs(int start, int end, long long* weightlog, int* usedlog, long long ne);


int main()
{
    int Nv;
    long long Ne;
    scanf("%d%lld",&Nv,&Ne);getchar();

    //read edges
    for(int i = 1;i<=Ne;i++){
        scanf("%d %d %lld",&(E[i].v1),&(E[i].v2),&(E[i].weight));
        Ematrix[E[i].v1][E[i].v2] = Ematrix[E[i].v2][E[i].v1] = E[i].weight;
        getchar();
        //printf("read: %d -- %d : %lld\n",E[i].v1,E[i].v2,E[i].weight);//testpoint
    }

    buildMinHeap(Ne);//build a min heap

    //find start
    int flag = 1;//to log if the path is uniqe
    int count = 0;//to log the vertex deleted
    long long total = 0;//count the total lenth of MST
    edge temp;//log the last edge
    temp.weight = temp.v1 = temp.v2 = 0;

    for(int i = 1;i<=Nv;i++) Union[i] = -1;//initialize union

    while(Ne-count){
        edge min = getTopAndMaintainHeap(Ne-count);//take one from top
        count++;
        //printf("pop min: %d -- %d : %lld  ",min.v1,min.v2,min.weight);//tp

        int root1 = findWithCompress(min.v1);
        int root2 = findWithCompress(min.v2);//find root

        if(root1 == root2){
            //printf("not taken\n");
            if(temp.weight == min.weight){
                if(judgeIFunique(min.v1,min.v2,min.weight,Ne)) flag = 0;
                //printf("find conflict here\n");//tp
            }
        }else{
            unionH(root1,root2);
            //printf("taken\n");//tp 
            temp = min;//update temp
            UsedE[used++] = min;
            total += min.weight;//update total
        }
    }

    if(!judgeIFconnected(Nv)){
        printf("%lld\n",total);
        if(flag) printf("Yes");
        else printf("No");
    }
    else{
        printf("No MST\n");
        printf("%d",judgeIFconnected(Nv));
    }

    return 0;
}

void Exchange(int num1, int num2)
{
    int tempv1 = E[num1].v1;
    int tempv2 = E[num1].v2;
    long long tempweight = E[num1].weight;

    E[num1].v1 = E[num2].v1;
    E[num1].v2 = E[num2].v2;
    E[num1].weight = E[num2].weight;

    E[num2].v1 = tempv1;
    E[num2].v2 = tempv2;
    E[num2].weight = tempweight;
}

void buildMinHeap(long long Ne)
{
    for(int i = Ne/2+1;i>=1;i--){
        int child = 2*i;
        int temp = i;
        while(child <= Ne){
            if(child+1 <= Ne && E[child+1].weight && E[child].weight > E[child+1].weight) child ++;
            if(E[temp].weight > E[child].weight){
                Exchange(temp,child);
                temp = child;
                child = 2*child;
            }else{
                break;
            }
        }
    }
    //printf("min-heap build complete.\n");//testpoint
    //for(int i = 1;i<=Ne;i++) printf("%lld ",E[i].weight);
    //printf("\n");
}

edge getTopAndMaintainHeap(int n)
{
    edge min;
    min.v1 = E[1].v1;
    min.v2 = E[1].v2;
    min.weight = E[1].weight;

    Exchange(1,n);//move the last one to the first
    E[n].v1 = E[n].v2 = E[n].weight = 0;//clear

    //maintain min heap
    int child = 2;
    int temp = 1;
    while(child < n){
        if(child+1 < n && E[child+1].weight && E[child].weight > E[child+1].weight) child ++;
        if(E[temp].weight > E[child].weight) Exchange(temp,child);
        temp = child;
        child = 2*child;
    }

    return min;
}

int findWithCompress(int v)
{
    if(Union[v] <= 0) return v;
    else return Union[v] = findWithCompress(Union[v]);
}

void unionH(int h1, int h2)
{
    if(Union[h2] < Union[h1]) Union[h1] = h2;
    else{
        if(Union[h1] == Union[h2]) Union[h1]--;
        Union[h2] = h1;
    }
}

int judgeIFconnected(int Nv)
{
    int i = 1;
    int count = 1;
    int root = findWithCompress(i);
    for(;i<=Nv;i++){
        if(findWithCompress(i) != root) count++;
    }
    
    if(count == 1) return 0;
    else return count;
}

int judgeIFunique(int v1, int v2, long long weight,long long ne)
{
    int used[Max] = {0};
    long long weightlog[Maxe] = {0};
    //printf("--dfs search start--\n");
    int flag = dfs(v1,v2,weightlog,used,ne);
    
    int j = 0;
    while(weightlog[j]){
        if(weightlog[j] == weight) break;
        j++;
    }

    if(weightlog[j] == weight) return 1;
    else return 0;
}

int dfs(int start, int end, long long* weightlog, int* usedlog, long long ne)
{
    if(start == end) return 1;
    int flag = 0;

    usedlog[start] = 1;
    int j = 1;
    for(;j<=ne;j++){
        if(Ematrix[start][j] == 0) continue;
        if(usedlog[j] == 1) continue;
        int flag = dfs(j,end,weightlog,usedlog,ne);
        if(flag == 1){
            int k = 0;
            while(weightlog[k])k++;
            weightlog[k] = Ematrix[start][j];
            //printf("find: %d -> %d : %lld\n",start,j,Ematrix[start][j]);
            return 1;
        }
    }
    return 0;
}