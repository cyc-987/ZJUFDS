#include<stdio.h>

//find func with path comp.
int find(int r[], int element)
{
    if(r[element] <= 0) return element;
    else return r[element] = find(r, r[element]);
}

//union with size compare
void myunion(int r[], int root1, int root2)
{
    int size1 = -r[root1];
    int size2 = -r[root2];

    if(size1 >= size2){
        r[root2] = root1;
        r[root1] = -(size1+size2);
    }else{
        r[root1] = root2;
        r[root2] = -(size1+size2);
    }
}

int main()
{
    //read N
    int N;
    scanf("%d",&N);
    getchar();
    //create array
    int computer[N+1];
    for(int i = 0;i<=N;i++) computer[i] = -1;
    computer[0] = 0;
    
    //read operations
    char op;
    int com1,com2;
    scanf("%c",&op);
    while(op != 'S'){
        scanf("%d%d",&com1, &com2);
        switch (op)
        {
        case 'I':
        {
            int root1 = find(computer, com1);
            int root2 = find(computer, com2);
            myunion(computer, root1, root2);
            break;
        }
        case 'C':
        {
            int root1 = find(computer, com1);
            int root2 = find(computer, com2);
            if(root1 == root2) printf("yes\n");
            else printf("no\n");
            break;
        }
        default:
            break;
        }
        getchar();
        scanf("%c",&op);
    }

    //judge operation
    int count[N];
    for(int i = 1; i<=N; i++) count[i] = 0;
    for(int i = 1; i<=N; i++){
        int root = find(computer, i);
        count[root]++;
    }
    int diff = 0;
    for(int i = 1; i<=N; i++){
        if(count[i] > 0) diff++;  
    }
    if(diff == 1){
        printf("The network is connected.\n");
    }else{
        printf("There are %d components.\n",diff);
    }
    return 0;
}