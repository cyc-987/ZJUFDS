# Project2 : **Is It A Red-Black Tree**

> Author: Noname
> Date: 25, Oct. 2023

[toc]

## Chapter 1: Introduction

​	A red-black tree is a self-balancing binary search tree, a type of data structure used in computer science for efficient operations like insertion, deletion, and searching. It is called "red-black" because each node in the tree is assigned one of two colors, either red or black, and it satisfies specific properties to ensure that the tree remains balanced.

​	A red-black tree is a type of balanced binary search tree in data structures. It is characterized by five key properties:

1. Every node is either red or black.
2. The root of the tree is black.
3. Every leaf node (usually represented as NULL) is black.
4. If a node is red, then both of its children must be black.
5. For every node in the tree, all simple paths from that node to its descendant leaves must contain the same number of black nodes.

​	These properties ensure that red-black trees maintain a balance and adhere to specific rules, which helps in achieving efficient searching and insertion operations. The tree in Figure 1 adheres to these properties and is a valid red-black tree. However, the trees in Figures 2 and 3 do not adhere to these properties and are not considered valid red-black trees.

### Fig.1

![c1p1](./assets/c1p1.jpg)

### Fig.2

![c1p2](./assets/c1p2.jpg)

### Fig.3

![c1p3](./assets/c1p3.jpg)

## Chapter 2: Algorithm Specification

### 2.1 Purpose

​	A red-black tree validation algorithm.

### 2.2 Input&output

#### Input

- `Totalcases`: The number of cases listed below. (<=30)
- For each case, it takes two lines:
  - `totalNodes`: The number of nodes in the array below. (<=30)
  - An preorder traversal sequence of the tree, using negative signs to represent red nodes.

#### Output

​	For each test case, print in a line "Yes" if the given tree is a red-black tree, or "No" if not.

### 2.3 Algorithm Logic

#### 2.3.1 Main structure

The `main` function is the entry point of the program, responsible for reading input data, constructing and validating red-black trees, and outputting the results. The following explains the main function's logic step by step:

1. **Input Redirection**:
   - The program starts by redirecting input to read from an external file, typically named "input.txt," using the `freopen` function. This allows the program to read test cases and input data from this file.

2. **Total Cases**:
   - The program reads the total number of test cases, denoted by `totalCases`, from the redirected input. This value indicates how many red-black trees need to be constructed and validated.

3. **Case Loop**:
   - The program enters a loop, iterating through each test case. The loop runs for a total of `totalCases` iterations.

4. **Test Case Data Input**:
   - For each test case, the program performs the following steps:
     - Reads the total number of nodes in the red-black tree, denoted as `totalNodes`.
     - Allocates an array `node` to store the data values for each node in the tree.
     - Reads the data values of each node and stores them in the `node` array.

5. **Red-Black Tree Construction**:
   - After reading the data for a test case, the program calls the `buildBRTree` function to construct the red-black tree. This function uses the `node` array as input and returns the root of the constructed tree.

6. **Red-Black Tree Validation**:
   - The program then calls the `judgeBRTree` function to validate whether the constructed tree is a valid red-black tree. This function checks if the tree adheres to the red-black tree properties:
     - The root node is black.
     - There are no adjacent red nodes.
     - The black heights are consistent along all paths.
   - If the `judgeBRTree` function returns `1`, the program prints "Yes" to indicate that the tree is a valid red-black tree. If it returns `0`, the program prints "No" to indicate that the tree does not meet the red-black tree criteria.

7. **Loop Completion**:
   - The loop continues for each test case, repeating the data input, tree construction, and validation steps.

8. **Input File Closure**:
   - After processing all test cases, the program closes the redirected input file using the `fclose` function.

9. **Program Termination**:
   - The `main` function returns 0 to indicate successful program execution and terminates.

#### 2.3.2 Other functions

1. **Building a Red-Black Tree (`buildBRTree`)**:
   - The algorithm starts by constructing a red-black tree from the given input data. It follows these steps:
     - If the left pointer (lp) exceeds the right pointer (rp), the function returns `NULL` since there are no nodes to construct.
     - If lp equals rp, a new tree node is created with the data value from the `node` array at index lp, and the function returns this node.
     - The algorithm identifies the root node, which is created with the data value from the `node` array at index lp.
     - It searches for a separation point (k) within the `node` array to split it into two subtrees. The separation point k is determined by finding the first index where the absolute value of the node data exceeds the absolute value of the root node's data.
     - Recursion is then used to construct the left and right subtrees of the root node. The left subtree is constructed from indices lp+1 to k-1, and the right subtree is constructed from indices k to rp.
     - The function returns the constructed root node, effectively building the red-black tree.

2. **Validating a Red-Black Tree (`judgeBRTree`)**:
   - The algorithm checks whether the constructed tree is a valid red-black tree. The validation includes:
     - Verifying that the root node is black. If not, the function returns `0`, indicating that it's not a valid red-black tree.
     - Calling the `judgeTwoRed` function to ensure there are no adjacent red nodes within the tree. If it finds any, the function returns `0`.
     - Invoking the `judgeBlackHeight` function to check if the black heights of all paths in the tree are consistent. If they are not, the function returns `0`.
     - If all these conditions are satisfied, the function returns `1`, indicating that the tree is a valid red-black tree.

3. **Checking for Adjacent Red Nodes (`judgeTwoRed`)**:
   - This function checks the entire tree for the presence of adjacent red nodes. It follows these steps:
     - If the current node is `NULL`, it returns `1` (no adjacent red nodes).
     - If the current node's color is red, it checks its left and right children. If any of them are red, the function returns `0` (indicating adjacent red nodes).
     - It recursively traverses the left and right subtrees, repeating these checks for each node in the tree.
     - The function returns `1` if no adjacent red nodes are found within the tree.

4. **Checking Black Height (`judgeBlackHeight`)**:
   - This function verifies that the black height (number of black nodes on any path) of the tree is consistent. The process is as follows:
     - If the current node is `NULL`, it returns a black height of 0.
     - It recursively calculates the black heights of the left and right subtrees.
     - If any subtree returns -1 (indicating an inconsistency), the function also returns -1.
     - If the black heights of both subtrees match, it adds 1 to the black height if the current node is black, or leaves it unchanged if the node is red.
     - The function returns the calculated black height for the current subtree.

5. **Node Creation (`createNode`)**:
   - This function is responsible for creating a new tree node with the specified data value and color. The process is as follows:
     - A new node is allocated in memory.
     - The absolute value of the input data determines the data value for the node.
     - The color of the node is determined by the sign of the input data: negative values represent red nodes, while positive values represent black nodes.
     - The function returns the newly created node.

​	The `judgeBRTree` function orchestrates the entire process, ensuring that the root node is black, there are no adjacent red nodes, and the black heights are consistent. If all conditions are met, it confirms that the tree is a valid red-black tree and returns `1`. Otherwise, it returns `0`, indicating that the tree does not adhere to the red-black tree properties.

## Chapter 3: Testing Results

### 3.1 Basics

Using the input example given in the PTA.

```txt
3
9
7 -2 1 5 -4 -11 8 14 -15
9
11 -2 1 -7 5 -4 8 14 -15
8
10 -7 5 -6 8 15 -11 17
```

Output:

```sh
Yes
No
No
```

The results match the expected outcome.

### 3.2 Empty tree

Input:

```txt
0
```

Output:

```sh
empty input
```

The result matches the expected outcome.

### 3.3 Only one node

Input:

```txt
2
1
5
1
-5
```

Output:

```sh
Yes
No
```

The results match the expected outcome.

### 3.4 Two constant red nodes

A valid red-black tree but containing adjacent red nodes, to test the correctness of the `judgeTwoRed`function.

Input:

```txt
1
9
11 -2 1 -7 5 -4 8 14 -15
```

Output:

```txt
No
```

The result matches the expected outcome.

### 3.5 BlackHeight not equal

A valid red-black tree, but with varying black heights on different paths, to test the correctness of the `judgeBlackHeight` function.

Input:

```txt
1
8
10 -7 5 -6 8 15 -11 17
```

Output:

```txt
No
```

The result matches the expected outcome.

### 3.6 Upper bound

 A tree which has 30 nodes.

Input:

```txt
2
31
45 -27 19 -17 12 18 -25 21 26 34 -30 29 33 -42 37 43 -62 51 -47 46 48 -60 59 61 77 -68 65 72 -85 80 90
30
45 -27 19 -17 12 18 -25 21 26 34 -30 29 33 -42 37 43 -62 51 -47 46 48 -60 59 61 77 -68 72 -85 80 90
```

Output:

```txt
Yes
No
```

The results match the expected outcome.

### 3.7 Random input

​	I tested several trees found on the Internet and transformed them into BRTrees manually, the results were all correct.

## Chapter 4: Analysis and Comments

​	The program is made of several important functions, and I tired to analyze each function's time and space complexities separately.

### 4.1 `buildBRTree`

​	The source code can be found in Appendix.The function is responsible for constructing a red-black tree based on the input data. 

**Time Complexity:**

1. The function uses a recursive approach to construct the tree. In the worst case, it examines each node in the `node` array exactly once to determine the separation point `k`.
2. The recursive calls create subproblems of size `(k - lp - 1)` for the left subtree and `(rp - k)` for the right subtree.
3. The recursive calls are made for both the left and right subtrees, and the function processes each subtree separately.

​	The time complexity of the `buildBRTree` function is **O(n)**, where "n" is the number of nodes in the red-black tree. This is because each node is examined once to find the separation point.

**Space Complexity:**

1. The function uses additional memory for the `root` node, which is created to represent the current root of the subtree.
2. The recursion depth is determined by the height of the red-black tree, which is bounded by the number of nodes. Therefore, the maximum space used by the call stack is proportional to the tree's height.

​	The space complexity of the `buildBRTree` function is **O(n)** in the worst case, where "n" is the number of nodes. This is due to the space used for the `root` node and the call stack during the recursive calls.

### 4.2 `judgeTwoRed`

​	The source code can be found in Appendix. The function recursively checks a red-black tree for adjacent red nodes. 

**Time Complexity:**

1. The function first checks if the current node `root` is NULL, which is a constant-time operation, O(1).

2. Then, it checks if the color of the current node is red, which is also a constant-time operation, O(1).

3. For each red node, it checks if its left and right children are red, again in constant time, O(1).

4. The function then recursively calls itself on the left and right children, which in the worst case, may traverse the entire tree.

​	Since each node is visited at most once during the recursive traversal, the overall time complexity is **O(n)**, where 'n' is the number of nodes in the tree.

**Space Complexity:**

​	The space complexity of the code is determined by the recursive call stack. In the worst case, if the tree is unbalanced, the space complexity is **O(n)**, where 'n' is the number of nodes in the tree. This is because the function can make recursive calls down one branch of the tree before returning.

​	In practice, for a well-balanced tree, the space complexity is often **O(log n)** because the maximum depth of the recursive call stack is proportional to the logarithm of the number of nodes in a balanced binary tree. So, the space complexity depends on the structure of the input tree and can range from O(log n) to O(n).

### 4.3 `judgeBlackHeight`

​	The source code can be found in Appendix. The function checks the black height of a red-black tree. 

**Time Complexity:**

1. The function operates by recursively traversing the tree from the root to the leaves. In the worst-case scenario, it will visit every node in the tree once.
2. At each node, the function performs constant time operations, including the recursive calls and comparisons.
3. The function checks if the left and right subtrees have consistent black heights by comparing `leftHeight` and `rightHeight`, which are computed during the recursive traversal.

​	The time complexity of this function is **O(n)**, where n is the number of nodes in the tree, as it visits each node once.

**Space Complexity:**

1. The space complexity is determined by the maximum depth of the recursive call stack.

​	In a balanced binary tree, the maximum depth of the recursive call stack will be **log(n)**, where n is the number of nodes. In the worst-case scenario, where the tree is highly unbalanced and resembles a linked list, the maximum depth of the call stack will be **n**. Therefore, the space complexity is O(log(n)) for balanced trees and O(n) for highly unbalanced trees.

## Appendix: Source Code (in C)

```c
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
```

## Declaration

> **I hereby declare that all the work done in this project titled "Project2 : Is It A Red-Black Tree" is of my independent effort.**
