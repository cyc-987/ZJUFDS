#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define Max 550

int G[Max][Max];//a 2d array to store the edges
int Find[Max];
void readFirstLine(int *s, int *t, int *numOfE);
int find(int number);
int getIdentity(char c1, char c2, char c3);

int main()
{
    //read the s,t,number of edges
    int s, t, numOfE;
    readFirstLine(&s,&t,&numOfE);

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
    printf("s,t= %d, %d\n",*s,*t);//testpoint
}

int find(int number)
{
    int n = 0;
    while(Find[n]){
        if(Find[n] == number) break;
        n++;
    }
    if(Find[n] == 0) Find[n] = number;
    printf("find[%d]:%d\n",n,number);//testpoint
    return n;
}

int getIdentity(char c1, char c2, char c3)
{
    return (c1-'A')*26*26+(c2-'A')*26+(c3-'A')+1;
}