#include <cstdlib>
#include <iostream>
#include "AvlTree.h"

static int Max(int a, int b);
static Position SingleRotateWithLeft( Position K2);
static Position SingleRotateWithRight( Position K2);
static Position DoubleRotateWithLeft( Position K3);
static Position DoubleRotateWithRight( Position K3);

struct AvlNode{
	ElementType Element;
	AvlTree Left;
	AvlTree Right;
	int Height;
};

static int Height( Position P ){
	if(P == NULL)
		return -1;
	else
		return P->Height;
}

static int Max(int a, int b){
	return a > b? a : b;
}

static Position SingleRotateWithLeft( Position K2){
	Position K1;
	K1 = K2->Left;
	K2->Left = K1->Right;
	K1->Right = K2;
	
	K2->Height = Max( Height( K2->Left ), Height( K2->Right ) )+1;
	K1->Height = Max( Height( K1->Left ), Height( K1->Right ) )+1;

	return K1;
}

static Position SingleRotateWithRight( Position K2){
	Position K1;
	K1 = K2->Right;
	K2->Right = K1->Left;
	K1->Left = K2;
	
	K2->Height = Max( Height( K2->Left ), Height( K2->Right ) )+1;
	K1->Height = Max( Height( K1->Left ), Height( K1->Right ) )+1;

	return K1;
}

static Position DoubleRotateWithLeft( Position K3){
	K3->Left = SingleRotateWithRight( K3->Left );
	return SingleRotateWithLeft( K3 );
}

static Position DoubleRotateWithRight( Position K3){
	K3->Right = SingleRotateWithLeft( K3->Right );
	return SingleRotateWithLeft( K3 );
}

Position find( ElementType X, AvlTree T ){
	if ( T == NULL ){
		return NULL;
	}
	if ( X < T->Element ){
		return find( X, T->Left );
	}
	else if( X > T->Element){
		return find( X, T->Right );
	}
	else return T;
}
Position findMin( AvlTree T ){
	if( T == NULL){
		return NULL;
	}
	else if(T->Left = NULL){
		return T;
	}
	else 
		return findMin( T->Left );
}
Position findMax( AvlTree T ){
	if ( T == NULL ){
		return NULL;
	}
	else if( T->Right == NULL ){
		return T;
	}
	else 
		return findMax( T->Right );
}

AvlTree insert(ElementType X, AvlTree T ){
	if( T == NULL ){
		T = (AvlTree)malloc(sizeof(struct AvlNode));
		T->Element = X;
		T->Height = 0;
		T->Left = T->Right = NULL;
	}
	else if( X < T->Element){
		T->Left = insert(X, T->Left);
		if( Height(T->Left) - Height(T->Right) == 2){
			if( X < T->Left->Element )
				T = SingleRotateWithLeft( T );
			else
				T = DoubleRotateWithLeft( T );
		}
	}
	else if( X > T->Element){
		T->Right = insert(X, T->Right);
		if( Height(T->Right) - Height(T->Right) == 2){
			if( X > T->Right->Element)
				T = SingleRotateWithRight( T );
			else
				T = DoubleRotateWithRight( T );
		}
	}

	T->Height = Max( Height(T->Left), Height(T->Right))+1;
	return T;
}


AvlTree del( ElementType X, AvlTree T ){
	// Still unimplemented
	//if(T == NULL){
	//	std::cerr << "Element not found" << std::endl;
	//}
	//else if(X < T->Element){
	//	T->Left = del(X, T);
	//	T->Height = Max( Height(T->Left), Height(T->Right))+1;
	//}
	//else if(X > T->Element){
	//	T->Right = del(X, T);
	//	T->Height = Max( Height(T->Left), Height(T->Right))+1;
	//}
	//else{
	//	Position tmp;
	//	if(T->Left && T->Right){ //Two childen
	//		// replace with the smallest in right subtree
	//		tmp = findMin( T->Right );
	//		T->Element = tmp->Element;
	//		T->Right = del(T->Element, T->Right);
	//	}
	//	else{ // one or zero child
	//		tmp = T;
	//		if(T->Left = NULL)
	//			T = T->Right;
	//		else if(T->Right == NULL)
	//			T = T->Left;
	//		free(tmp);
	//	}
	//}
	return T;
}

ElementType retrieve( Position P ){
	return P->Element;
}