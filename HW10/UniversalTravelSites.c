#include<stdio.h>
#include<stdlib.h>
#define Max 1200

int G[Max][Max];//a 2d array to store the edges
int Find[Max];//an array to store the relationship of identity number and number in order
int used[Max];//an array to store if a vertex has been visited, set to zero in every search


void readFirstLine(int *s, int *t, int *numOfE);
int find(int number);
int getIdentity(char c1, char c2, char c3);
void readALine();
int dfs(int start, int end, int max);
int min(int num1,int num2);

int main()
{
    //read the s,t,number of edges
    int s, t, numOfE;
    readFirstLine(&s,&t,&numOfE);
    //read lines
    for(int i = 0;i<numOfE;i++) readALine();

    //start to find the max flow
    int flow = 0;
    while(1){
        //set used to zero
        for(int i = 0;i<Max;i++) used[i] = 0;

        //dfs
        //printf("--dfs start--\n");//testpoint
        int f = dfs(0,1,32767);
        //printf("--dfs end--\n");//testpoint
        if(f == 0) break;
        flow += f;
    }
    printf("%d",flow);

    return 0;
}

//functions
void readFirstLine(int *s, int *t, int *numOfE)
{
    char cs[3]; char ct[3];
    scanf("%c%c%c %c%c%c",cs,cs+1,cs+2,ct,ct+1,ct+2);
    scanf("%d", numOfE);getchar();

    *s = getIdentity(cs[0],cs[1],cs[2]);
    *t = getIdentity(ct[0],ct[1],ct[2]);
    find(*s);find(*t);//store the relationship
    //printf("s,t= %d, %d\n",*s,*t);//testpoint
}

int find(int number)
{
    int n = 0;
    while(Find[n]){
        if(Find[n] == number) break;
        n++;
    }
    if(Find[n] == 0) Find[n] = number;
    //printf("find[%d]:%d\n",n,number);//testpoint
    return n;
}

int getIdentity(char c1, char c2, char c3)
{
    return (c1-'A')*26*26+(c2-'A')*26+(c3-'A')+1;
}

void readALine()
{
    char cs[3]; char ct[3];
    scanf("%c%c%c %c%c%c",cs,cs+1,cs+2,ct,ct+1,ct+2);
    int dist;
    scanf("%d",&dist);getchar();

    int a = find(getIdentity(cs[0],cs[1],cs[2]));
    int b = find(getIdentity(ct[0],ct[1],ct[2]));

    G[a][b] = dist;
    //printf("add: %d %d dist: %d\n",a,b,dist);//testpoint
}

int dfs(int start, int end, int max)
{
    if(start == end) return max;

    used[start] = 1;
    for(int i = 0; i<Max;i++){
        if(G[start][i] == 0) continue;
        
        if(used[i] == 0){
            int d = dfs(i,end,min(max,G[start][i]));
            if(d>0){
                G[start][i] -= d;
                G[i][start] += d;
                //printf("dfs: %d -> %d : %d\n",start,i,d);//testpoint
                return d;
            }
        }
    }

    return 0;
}

int min(int num1,int num2)
{
    if(num1 <= num2) return num1;
    else return num2;
}