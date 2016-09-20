#include <cstdlib>
#include <iostream>
#include "Queue.h"

struct QueueRecord{
	int Capacity;
	int Front;
	int Rear;
	int Size;
	ElementType *Array;
};

bool isEmpty( Queue Q){
	return Q->Size == 0;
}

bool isFull( Queue Q ){
	return Q->Size == Q->Capacity;
}

void makeEmpty( Queue Q ){
	Q->Size = 0;
	Q->Front = 0;
	Q->Rear = 0;
}

Queue createQueue( int maxSize ){
	Queue Q;
	Q = (Queue)malloc(sizeof(struct QueueRecord));
	Q->Capacity = maxSize;
	Q->Array = (ElementType*)malloc(sizeof(ElementType)*maxSize);
	makeEmpty(Q);
	return Q;
}

void disposeQueue( Queue Q ){
	if( Q != NULL){
		free(Q->Array);
		free(Q);
	}
}

void enque( ElementType X, Queue Q ){
	if( isFull(Q) ){
		std::cerr << "Full Queue" << std::endl;
	}
	else{
		Q->Array[Q->Rear] = X;
		Q->Size ++;
		Q->Rear = (Q->Rear + 1) % Q->Capacity;
	}	
}

ElementType front( Queue Q ){
	if( !isEmpty(Q) ){
		return Q->Array[Q->Front];
	}
	else{
		std::cerr << "Empty Queue" << std::endl;
	}
	return 0;
}

void deque( Queue Q ){
	if( !isEmpty(Q) ){
		Q->Size --;
		Q->Front = (Q->Front + 1) % Q->Capacity;
	}
	else{
		std::cerr << "Empty Queue" << std::endl;
	}
}