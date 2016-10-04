#ifndef BinHeap_H
#define BinHeap_H

typedef int ElementType;
#define MinData 0x80000000

struct HeapStruct;
typedef struct HeapStruct *PriorityQueue;

PriorityQueue initQueue( int MaxElements );
void destroy( PriorityQueue H );
void makeEmpty( PriotiryQueue H );
void insert( ElementType X, PriorityQueue H );
ElementType deleteMin( PriorityQueue H );
ElementType findMin( PriorityQueue H );
bool isEmpty( PriorityQueue H );
bool isFull( PriorityQueue H );

#endif // BinHeap_H
