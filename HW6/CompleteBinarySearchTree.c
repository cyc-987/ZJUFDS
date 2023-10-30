#include<stdio.h>

void buildTree(int num[], int tree[], int index, int N);

int main()
{
    int N;
    scanf("%d", &N);//read n;
    int num[N+1];

    //read the sequence
    for(int i = 1; i <= N; i++)
    {
        scanf("%d", &num[i]);
    }
    //increase order
    for(int i = 1; i <= N; i++)
    {
        for(int j = i+1; j <= N; j++)
        {
            if(num[i] > num[j])
            {
                int temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
    }

    //build bst
    int tree[N+1];
    buildTree(num, tree, 1, N);

    //print tree
    for(int i = 1; i < N; i++)
    {
        printf("%d ", tree[i]);
    }
    printf("%d\n", tree[N]);

    return 0;
}

void buildTree(int num[], int tree[], int index, int N)
{
    static int count = 1;
    if(index > N) return;
    buildTree(num, tree, index*2, N);
    tree[index] = num[count++];
    buildTree(num, tree, index*2+1, N);
}