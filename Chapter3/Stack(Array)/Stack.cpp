#include <iostream>
#include <cstdlib>
#include "Stack.h"

struct StackRecord{
	int Capacity;
	int TopOfStack;
	ElementType *Array;
};

Stack createStack( int MaxSize ){
	Stack S;
	S = (Stack)malloc(sizeof(struct StackRecord));
	S->Array = (ElementType *)malloc(sizeof(ElementType)*MaxSize);
	S->Capacity = MaxSize;
	S->TopOfStack = 0;
	return S;
}

void disposeStack( Stack S ){
	if(S != NULL){
		free( S->Array );
		free( S );
	}
}

bool isEmpty( Stack S ){
	return S->TopOfStack == 0;
}

bool isFull( Stack S ){
	return S->TopOfStack == S->Capacity;
}

void makeEmpty( Stack S ){
	S->TopOfStack = 0;
}

void push( ElementType X, Stack S ){
	if( !isFull(S) )
		S->Array[S->TopOfStack++] = X;
	else
		std::cerr << "Full Stack";
}

ElementType top( Stack S ){
	if( !isEmpty(S) )
		return S->Array[S->TopOfStack-1];
	std::cerr << "Empty Stack";
	return 0;
}

void pop( Stack S ){
	if( !isEmpty(S) )
		S->TopOfStack--;
	else
		std::cerr << "Empty Stack";
}
