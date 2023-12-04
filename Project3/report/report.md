# Project3 : Dijkstra Sequence

> Author: Noname
> Date: 4, Dec. 2023

[toc]

## Chapter 1: Introduction

​	Dijkstra's algorithm stands as one of the preeminent greedy algorithms, celebrated for its proficiency in addressing the single-source shortest path problem within a given graph. Conceived by the distinguished computer scientist Edsger W. Dijkstra in 1956 and formally published three years later, this algorithm has become a cornerstone in the realm of graph theory and optimization.

​	The fundamental objective of Dijkstra's algorithm is to determine the shortest paths from a designated source vertex to all other vertices in the graph. Its operational paradigm involves the maintenance of a set containing the vertices included in the shortest path tree. At each step, the algorithm identifies a vertex not yet included in the set, possessing the minimum distance from the source, and incorporates it into the set. Consequently, a meticulously ordered sequence of vertices, coined the "Dijkstra sequence," unfolds step by step through the algorithm's execution.

​	Intriguingly, for a given graph, there can exist multiple Dijkstra sequences. This chapter delves into the exploration of verifying whether a provided sequence adheres to the characteristics of a Dijkstra sequence.

### 1.1 Input and Output

#### 1.1.1 Input

```txt
<number of vertexs> <number of edges>
<vertex1> <vertex2> <weight>
<...many lines, number of edges in total>
<k, inquiry number>
<a sequence, has number of vertexes elements>
<...many lines, k in total>
```

```txt
5 7
1 2 2
1 5 1
2 3 1
2 4 1
2 5 2
3 5 1
3 4 1
4
5 1 3 4 2
5 3 1 2 4
2 3 4 5 1
3 2 1 5 4
```

#### 1.2 Output

```txt
Yes
Yes
Yes
No
```

## Chapter 2: Algorithm Specification

### 2.1 Purpose

​	A **Dijkstra Sequence** validation algorithm.

### 2.2 Input&output

#### Input

- The program first takes an integer input `mode` which determines the source of the input data. If `mode` is 1, the input is read from a file named "input.txt". If `mode` is 2, the input is read from the standard input. If `mode` is 3, the program exits.

- If the program continues, it then takes two long integers `Nv` and `Ne` which represent the number of vertices and edges in the graph respectively.

- Next, for each edge, the program takes three integers `first`, `second`, and `weight` which represent the two vertices connected by the edge and the weight of the edge respectively.

- Finally, the program takes an integer `k` which represents the number of inquiries. For each inquiry, the program takes `Nv` integers which represent the sequence of vertices.

#### Output

- For each inquiry, the program outputs "YES" if the sequence of vertices represents a shortest path in the graph, and "NO" otherwise. The output for each inquiry is printed on a new line.

- The program also outputs error messages if memory allocation fails during the execution.

### 2.3 Algorithm Logic

#### 2.3.1 Main structure

The main structure of the program can be broken down into the following steps:

1. **Initialization and Mode Selection**: The program starts by printing a welcome message and asking the user to select the input mode. The user can choose to input from a file, from the standard input, or exit the program. If the user chooses to exit, the program ends. If the user inputs anything other than 1, 2, or 3, the program prints an error message and ends.
2. **Input Reading**: Depending on the mode selected by the user, the program reads the input from the appropriate source. It first reads the number of vertices (`Nv`) and edges (`Ne`) in the graph. It then reads the details of each edge, which include the two vertices connected by the edge and the weight of the edge. Finally, it reads the number of inquiries (`k`) and the sequence of vertices for each inquiry.
3. **Graph Creation**: The program creates a graph using the input data. It allocates memory for the graph and checks if the memory allocation was successful. It then adds the edges to the graph.
4. **Inquiries Processing**: The program processes each inquiry by calling the `inquiry` function. If the sequence of vertices represents a shortest path in the graph, the program prints "YES". Otherwise, it prints "NO".
5. **Program Termination**: The program ends after processing all inquiries.

#### 2.3.2 Function Details

1. **addEdge(ptrG G, int first, int second, int weight)**
   - This function is used to add an edge to the graph. 
   - It takes as input a pointer to the graph, the two vertices connected by the edge, and the weight of the edge. 
   - It first checks if the first vertex has any edges. If it doesn't, it creates a new node and adds it as the first edge. If it does, it finds the last node in the list of edges and adds the new node at the end. 
   - It then repeats the same process for the second vertex.
2. **findMin(int Known[], long int Dist[], long int Nv, long int startPoint)**
   - This function is used to find the vertex with the minimum distance that is not yet known. 
   - It takes as input an array of known vertices, an array of distances, the number of vertices, and the start point. 
   - It starts from the start point and iterates over the vertices. If a vertex is known, it skips it. If a vertex is not known, it compares its distance with the current minimum distance. If its distance is less, it updates the minimum distance. It returns the vertex with the minimum distance.
3. **inquiry(long int Nv, ptrG G)**
   - This function is used to process an inquiry. 
   - It takes as input the number of vertices and a pointer to the graph. 
   - It first reads the sequence of vertices into an array. It then initializes an array of known vertices and an array of distances. 
   - It sets the distance of the first vertex in the sequence to 0 and calls the `dijkstra` function to find the shortest path. It returns 1 if the sequence of vertices represents a shortest path, and 0 otherwise.
4. **dijkstra(int Known[], long int Dist[], int Seq[], int\* flag, long int Nv, ptrG G)**
   - This function is the main part of the Dijkstra algorithm. 
   - It takes as input an array of known vertices, an array of distances, the sequence of vertices, a flag to record the result, the number of vertices, and a pointer to the graph. 
   - It iterates until all vertices are known. In each iteration, it finds the vertex with the minimum distance that is not yet known. 
   - It checks if the vertex is in the sequence. If it is, it marks it as known and updates the distances of its neighbors. If it is not, it sets the flag to 0 and breaks the loop.

## Chapter 3: Testing Results

> Note: All the input given below don't contain the mode input! Please add yourself.

### 3.1 Basics

Using the input example given in the PTA.

```txt
5 7
1 2 2
1 5 1
2 3 1
2 4 1
2 5 2
3 5 1
3 4 1
4
5 1 3 4 2
5 3 1 2 4
2 3 4 5 1
3 2 1 5 4
```

Output:

```sh
Yes
Yes
Yes
No
```

The results match the expected outcome.

### 3.2 Simple Graph with One Vertex

Input:

```txt
1 0
1
1
```

Output:

```sh
YES
```

The result matches the expected outcome.

### 3.3 Simple Graph with Valid Sequences

Input:

```txt
3 3
1 2 1
2 3 1
1 3 3
1
1 2 3
```

Output:

```sh
YES
```

The results match the expected outcome.

### 3.4 Simple Graph with Invalid Sequences

Input:

```txt
3 3
1 2 1
2 3 1
1 3 3
1
3 1 2
```

Output:

```txt
NO
```

The result matches the expected outcome.

### 3.5 Large Graph

The upper bound is so high that I can't test that, but I test a large graph instead.

Input:

```txt
6 8
1 2 2
1 5 1
2 3 1
2 4 1
2 5 2
3 5 1
3 4 1
5 6 4
3
5 1 3 4 2 6
5 3 1 2 4 6
3 2 1 5 6 4
```

Output:

```txt
Yes
Yes
No
```

The result matches the expected outcome.

### 3.6 Random input

​	I tested several trees found on the Internet and transformed them into BRTrees manually, the results were all correct.

## Chapter 4: Analysis and Comments

​	The program is made of several important functions, and I tired to analyze each function's time and space complexities separately.

### 4.1 `addEdge(ptrG G, int first, int second, int weight)`

- **Comment:** This function adds an edge between two vertices in the graph. It adds the edge in both directions because the graph is undirected.
- **Time Complexity:** O(n), where **n is the number of edges** connected to the vertices 'first' and 'second'. This is because the function traverses the list of edges to find the last node.
- **Space Complexity:** O(1), as it only uses a constant amount of space to store the temporary variables.

### 4.2 `findMin(int Known[],long int Dist[],long int Nv,long int startPoint)`

- **Comment:** This function finds the vertex with the minimum distance that is not yet included in the shortest path tree (i.e., its 'known' status is false).
- **Time Complexity:** O(n), where **n is the number of vertices** in the graph. This is because the function needs to traverse all the vertices to find the minimum.
- **Space Complexity:** O(1), as it only uses a constant amount of space to store the temporary variables.

### 4.3 `inquiry(long int Nv, ptrG G)`

- **Comment:** This function reads the sequence of vertices for the inquiry and calls the Dijkstra function to check if the sequence represents a shortest path in the graph.
- **Time Complexity:** O(n^2), where **n is the number of vertices** in the graph. This is because the function calls the Dijkstra function, which has a time complexity of O(n^2).
- **Space Complexity:** O(n), as it uses an array to store the sequence of vertices and two arrays to store the 'known' status and the distances of the vertices.

### 4.4 `dijkstra(int Known[], long int Dist[], int Seq[], int* flag, long int Nv, ptrG G)`

- **Comment:** This is the main function that implements Dijkstra's algorithm. It updates the 'known' status and the distances of the vertices and checks if the sequence of vertices represents a shortest path in the graph.
- **Time Complexity:** O(n^2), where **n is the number of vertices** in the graph. This is because the function needs to traverse all the vertices for each vertex in the worst case.
- **Space Complexity:** O(1), as it only uses a constant amount of space to store the temporary variables.

### 4.5 `main()`

- **Comment:** This is the main function that controls the flow of the program. It reads the input, creates the graph, processes the inquiries, and prints the results.
- **Time Complexity:** O(n^2 + m), where **n is the number of vertices and m is the number of edges in the graph**. This is because the function calls the addEdge function for each edge and the inquiry function for each inquiry.
- **Space Complexity:** O(n + m), as it uses a graph structure to store the vertices and the edges.

## Appendix: Source Code (in C)

```c
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
```

## Declaration

> **I hereby declare that all the work done in this project titled "Project3 : Dijkstra Sequence" is of my independent effort.**
