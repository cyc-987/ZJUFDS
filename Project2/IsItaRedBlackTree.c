#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//define red and black
#define RED 0
#define BLACK 1

//define the node
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int color;//0 for red, 1 for black
};
typedef struct Node* Tree;

Tree buildBRTree(int lp, int rp, int node[]);
int judgeBRTree(Tree root);
int judgeTwoRed(Tree root);
int judgeBlackHeight(Tree root);
Tree createNode(int data);

int main()
{
    //input redirection
    freopen("input.txt", "r", stdin);
    //scan total number of the cases
    int totalCases;
    scanf("%d", &totalCases);
    if(totalCases == 0){
        printf("empty input\n");
        return 0;
    }

    //start big loop
    int bigloop;
    for(bigloop = 0; bigloop < totalCases; bigloop++)
    {
        //scan total number of the cases
        int totalNodes;
        scanf("%d", &totalNodes);

        //scan all the nodes
        int scanNumber;
        int node[totalNodes];
        for(scanNumber = 0; scanNumber < totalNodes; scanNumber++)
        {
            scanf("%d", &node[scanNumber]);
        }

        //rebuild the tree
        Tree treeHead = buildBRTree(0, totalNodes-1, node);

        //judge the tree

        if(judgeBRTree(treeHead) == 1) printf("Yes\n");
        else printf("No\n");
    }
    fclose(stdin);
    return 0;
}

Tree buildBRTree(int lp, int rp, int node[])
{
    //end condition
    if(lp > rp) return NULL;
    if(lp == rp){
        Tree temp = createNode(node[lp]);
        return temp;
    }
    //find the root
    Tree root = createNode(node[lp]);
    //find the separation place
    int k = lp;
    for(; k <= rp; k++)
    {
        if(abs(node[k]) > abs(node[lp])) break;
    }
    //recursion
    root->left = buildBRTree(lp+1, k-1, node);
    root->right = buildBRTree(k, rp, node);
    return root;
}

int judgeBRTree(Tree root)
{
    //judge the root node
    if(root == NULL) return 1;
    if(root->color == RED) return 0;

    //judge whether there exists two red nodes
    if(judgeTwoRed(root) == 0) return 0;

    //judge the black height
    if(judgeBlackHeight(root) == -1) return 0;

    //if all the conditions are satisfied, return 1
    return 1;
}

int judgeTwoRed(Tree root)
{
    if(root == NULL) return 1;
    if(root->color == RED)
    {
        if(root->left != NULL && root->left->color == RED) return 0;
        if(root->right != NULL && root->right->color == RED) return 0;
    }
    return judgeTwoRed(root->left) && judgeTwoRed(root->right);
}

int judgeBlackHeight(Tree root)
{
    if(root == NULL) return 0;
    int leftHeight = judgeBlackHeight(root->left);
    int rightHeight = judgeBlackHeight(root->right);
    if(leftHeight == -1 || rightHeight == -1) return -1;
    if(leftHeight != rightHeight) return -1;
    if(root->color == BLACK) return leftHeight+1;
    else return leftHeight;
}

Tree createNode(int data)
{
    Tree newNode = (Tree)malloc(sizeof(struct Node));
    newNode->data = abs(data);
    newNode->left = NULL;
    newNode->right = NULL;
    if(data < 0) newNode->color = RED;
    else newNode->color = BLACK;
    return newNode;
}