#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
struct Node {
    ElementType Element;
    Position Next;
};

List Read(); /* details omitted */
void Print( List L ); /* details omitted */
List Reverse( List L );

int main()
{
    List L2;   
    struct Node L13 = {3,NULL};
    struct Node L12 = {2,&L13};
    struct Node L11 = {1,&L12};
    struct Node L10 = {0,&L11};
    
    List L1 = &L10;
    L2 = Reverse(L1);
    //Print(L1);
    //Print(L2);
    return 0;
}

/* Your function will be put here */
List Reverse( List L )
{
    //create result head and dummy header
    List resultHead = NULL;
    List resultTemp = (List)malloc(sizeof(PtrToNode));
    resultTemp->Element = 0; resultTemp->Next = NULL;
    resultHead = resultTemp;

    //calculate the length of the list
    List temp = L;
    int length = 0;
    while(temp != NULL){
        temp = temp->Next;
        length++;
    }//include the first dummy header
    temp = L;

    //make the new reversed list
    int i = 0;
    List ptr = NULL;
    for(i = length-1; i >= 1; i--){//do not read the dummy header
        //move
        for(int j = 1; j <= i; j++){
            temp = temp->Next;
        }
        //creat and copy
        ptr = (List)malloc(sizeof(PtrToNode));
        ptr->Element = temp->Element;
        ptr->Next = NULL;
        //link and reset
        resultTemp->Next = ptr;
        resultTemp = resultTemp->Next;
        temp = L;
    }

    //copy L2 to L1
    temp = resultHead;
    for(i = 1; i <= length-1; i++){
        L = L->Next;
        temp = temp->Next;
        L->Element = temp->Element;
    }
    return resultHead;
}