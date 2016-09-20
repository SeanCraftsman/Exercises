#include <cstdlib>
#include "Stack.h"

struct Node{
	ElementType Element;
	PtrToNode Next;
};

bool isEmpty( Stack S ){
	return S->Next == NULL;
}

Stack createStack( void ){
	Stack S;
	S = (PtrToNode)malloc(sizeof(struct Node));
	makeEmpty( S );
	return S;
}

void makeEmpty( Stack S ){
	while( !isEmpty(S)){
		pop( S );
	}
}

void push( ElementType X, Stack S ){
	PtrToNode tmp;
	tmp = (PtrToNode) malloc(sizeof(struct Node));
	tmp->Element = X;
	tmp->Next = S->Next;
	S->Next = tmp;
}

ElementType Top( Stack S ){
	return S->Next->Element;
}

void pop( Stack S ){
	PtrToNode first;
	first = S->Next;
	S->Next = S->Next->Next;
	free(first);
}
