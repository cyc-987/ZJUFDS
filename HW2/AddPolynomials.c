#include <stdio.h>
#include <stdlib.h>
typedef struct Node *PtrToNode;
struct Node  {
    int Coefficient;
    int Exponent;
    PtrToNode Next;
};
typedef PtrToNode Polynomial;

Polynomial Read(); /* details omitted */
void Print( Polynomial p ); /* details omitted */
Polynomial Add( Polynomial a, Polynomial b );

int main()
{
    Polynomial a, b, s;
    a = Read();
    b = Read();
    s = Add(a, b);
    Print(s);
    return 0;
}

/* Your function will be put here */
Polynomial Add( Polynomial a, Polynomial b )
{
    //creat a new list
    Polynomial resultHead= (Polynomial)malloc(sizeof(PtrToNode));
    resultHead->Coefficient = resultHead->Exponent = 0;
    resultHead->Next = NULL;
    Polynomial resultTemp = resultHead;
    //jump the head node
    a = a->Next; b = b->Next;

    //start while and compare
    while(a != NULL && b != NULL){
        //request a new node
        Polynomial temp = (Polynomial)malloc(sizeof(PtrToNode));
        //compare
        if(a->Exponent == b->Exponent){
            //add and store
            temp->Coefficient = a->Coefficient + b->Coefficient;
            temp->Exponent = a->Exponent;
            //jump next
            a = a->Next; b = b->Next;
        }else if(a->Exponent > b->Exponent){
            //copy, store and jump
            temp->Coefficient = a->Coefficient;
            temp->Exponent = a->Exponent;
            a = a->Next;
        }else{
            temp->Coefficient = b->Coefficient;
            temp->Exponent = b->Exponent;
            b = b->Next;
        }
        //make temp safe and connect
        if(temp->Coefficient != 0){
            temp->Next = NULL;
            resultTemp->Next = temp;
            resultTemp = resultTemp->Next;
        }else free(temp);
    }

    //link the last nodes
    if(a != NULL){
        resultTemp->Next = a;
    }else{
        resultTemp->Next = b;
    }
    return resultHead;
}