#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
#define MinData -1

typedef struct HeapStruct *PriorityQueue;
struct HeapStruct {
    ElementType  *Elements;
    int Capacity;
    int Size;
};

PriorityQueue Initialize( int MaxElements ); /* details omitted */

void PercolateUp( int p, PriorityQueue H );
void PercolateDown( int p, PriorityQueue H );

void Insert( ElementType X, PriorityQueue H ) 
{
    int p = ++H->Size;
    H->Elements[p] = X;
    PercolateUp( p, H );
}

ElementType DeleteMin( PriorityQueue H ) 
{ 
    ElementType MinElement; 
    MinElement = H->Elements[1];
    H->Elements[1] = H->Elements[H->Size--];
    PercolateDown( 1, H );
    return MinElement; 
}

int main()
{
    int n, i, op, X;
    PriorityQueue H;

    scanf("%d", &n);
    H = Initialize(n);
    for ( i=0; i<n; i++ ) {
        scanf("%d", &op);
        switch( op ) {
        case 1:
            scanf("%d", &X);
            Insert(X, H);
            break;
        case 0:
            printf("%d ", DeleteMin(H));
            break;
        }
    }
    printf("\nInside H:");
    for ( i=1; i<=H->Size; i++ )
        printf(" %d", H->Elements[i]);
    return 0;
}

/* Your function will be put here */
void PercolateUp( int p, PriorityQueue H )
{
    int i;
    ElementType temp = H->Elements[p];//store the new value
    for(i = p; H->Elements[i/2] > temp; i /= 2){
        H->Elements[i] = H->Elements[i/2];
    }
    H->Elements[i] = temp;//replace the new value
}

void PercolateDown( int p, PriorityQueue H )
{
    int i, child;
    ElementType temp = H->Elements[p];//store the new value
    for(i = p; i*2 <= H->Size; i = child){
        child = i*2;
        if(child != H->Size && H->Elements[child+1] < H->Elements[child]) child++;
        if(H->Elements[child] < temp){
            H->Elements[i] = H->Elements[child];
        }
        else break;
    }
    H->Elements[i] = temp;//replace the new value
}