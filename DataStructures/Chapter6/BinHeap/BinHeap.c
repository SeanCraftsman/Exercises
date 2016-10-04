#include "BinHeap.h"
#include <stdio.h>

struct HeapStruct{
    int Capacity;
    int Size;
    ElementType *Elements;
};


PriorityQueue initQueue( int MaxElements ){
    PriorityQueue H;
    H = malloc( sizeof( struct HeapStruct ) );
    if(H == NULL){
        printf("Out of space!!!\n");
    }
    H->Elements = malloc( (MaxElements+1)
                          *sizeof( ElementType ) );
    if( H->Elements == NULL){
        printf("Out of space!!!\n");
    }
    H->Capacity = MaxElements;
    H->Size = 0;
    H->Elements[0] = MinData;
    return H;
}

void destroy( PriorityQueue H ){
    free(H->Elements);
    free(H);
}

void makeEmpty( PriotiryQueue H ){
    H->Size = 0;
}

void insert( ElementType X, PriorityQueue H ){
    int i;
    if(isFull( H )){
        printf("Priority queue is full\n");
        return;
    }
    for( i = ++H->Size; H->Elements[i / 2] > X; i /= 2)
        H->Elements[i] = H->Elements[i/2];
    H->Elements[i] = X;
}

ElementType deleteMin( PriorityQueue H ){
    int i, Child;
    ElementType MinElement, LastElement;

    if( isEmpty(H) ){
        printf("Priority queue is Empty\n");
        return H->Elements[0];
    }
    MinElement = H->Elements[1];
    LastElement = H->Elements[ H->Size-- ];

    for( i = 1; i * 2 <= H->Size; i = Child){
        Child = i*2;
        if( Child != H->Size &&
            H->Elements[Child + 1] < H->Elements[Child])
            Child ++;
        if( LastElement > H->Elements[Child])
            H->Elements[i] = H->Elements[Child];
        else
            break;
    }
    H->Elements[i] = LastElement;
    return MinElement;
}

ElementType findMin( PriorityQueue H ){
    if( isEmpty(H) ){
        printf("Priority queue is Empty\n");
        return H->Elements[0];
    }
    return H->Elements[1];
}

bool isEmpty( PriorityQueue H ){
    return H->Size == 0;
}

bool isFull( PriorityQueue H ){
    return H->Size == H->Capacity;
}
