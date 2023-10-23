#include<stdio.h>
#include<stdlib.h>
int num[50][50];

//define tree structure
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int level;
};
typedef struct Node *Tree;

Tree creatNode(int data)
{
    Tree T = (Tree)malloc(sizeof(struct Node));
    T->data = data;
    T->left = NULL;
    T->right = NULL;
    T->level = 0;
    return T;
}

int find(int inorder[],int il,int ir,int root)
{
    int i;
    for(i=il;i<=ir;i++)
    {
        if(inorder[i] == root) return i;
    }
    return -1;
}

Tree buildTree(int il,int ir,int pl,int pr,int inorder[],int postorder[])
{
    //find root
    int root = postorder[pr];
    Tree temp = creatNode(root);

    //find root position in inorder
    int k = find(inorder,il,ir,root);
    if(il < k) temp->left = buildTree(il,k-1,pl,pl+k-il-1,inorder,postorder);
    if(ir > k) temp->right = buildTree(k+1,ir,pl+k-il,pr-1,inorder,postorder);
    return temp;
}

void setLevel(Tree T)
{
    if(T == NULL) return;
    if(T->left != NULL) T->left->level = T->level + 1;
    if(T->right != NULL) T->right->level = T->level + 1;
    setLevel(T->left);
    setLevel(T->right);
}

void inorderLevel(Tree T)
{
    if(T == NULL) return;
    inorderLevel(T->left);
    int i = 0;
    while(num[T->level][i] != 0) i++;
    num[T->level][i] = T->data;
    inorderLevel(T->right);
}

void zigzaggingTree(Tree T)
{
    if(T == NULL) return;

    //go through all the levels and store
    inorderLevel(T);
    //print the tree
    int i,j;
    i = j = 0;
    int imstart = 1;
    while(num[i][0] != 0){
        if(i%2 != 0){
            for(j=0;num[i][j] != 0;j++){
                printf(" %d",num[i][j]);
            }
        }
        else{
            j = 0;
            while(num[i][j] != 0) j++;
            j--;
            for(j;j>=0;j--){
                if(imstart == 1){
                    printf("%d",num[i][j]);
                    imstart = 0;
                }
                else printf(" %d",num[i][j]);
            }
        }
        i++;
    }
}

int main()
{
    //scan n
    int n;
    scanf("%d",&n);
    int i;
    //scan inorder
    int inorder[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&inorder[i]);
    }
    //scan postorder
    int postorder[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&postorder[i]);
    }

    //build tree
    Tree resultTree = buildTree(0,n-1,0,n-1,inorder,postorder);
    //set the level of each node
    setLevel(resultTree);
    //print zigzagging tree
    zigzaggingTree(resultTree);
}