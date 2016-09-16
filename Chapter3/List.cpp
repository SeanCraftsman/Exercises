#include <cstdlib>
#include "List.h"

struct Node{
	ElementType Element;
	Position Next;
};

List createANode(){
	PtrToNode node;
	node = (PtrToNode)malloc(sizeof(struct Node));
	node -> Next = NULL;
	return node;
}

List createAList(){
	return createANode();
}

bool isEmpty( List L ){
	return L->Next == NULL;
}

bool isLast( Position P, List L ){
	return P->Next == NULL;
}

Position find ( ElementType X, List L ){
	Position P;
	P = L->Next;
	while( P != NULL && P->Element != X){
		P = P->Next;
	}
	return P;
}

Position findPrevious ( ElementType X, List L ){
	Position P;
	P = L;
	while( P->Next != NULL && P->Next->Element != X){
		P = P->Next;
	}
	return P;
}

void deleteNode( ElementType X, List L ){
	Position P,tmp;

	P = findPrevious( X, L );
	if(!isLast( P, L)){
		tmp = P->Next;
		P->Next = P->Next->Next;
		free(tmp);
	}
}


void insert ( ElementType X, List L , Position P){
	Position tmp = createANode();
	tmp->Element = X;
	tmp->Next = P->Next;
	P->Next = tmp;
}

void deleteList ( List L ){
	Position P,tmp;

	P = L->Next;
	L->Next = NULL;
	while(P != NULL){
		tmp = P->Next;
		free(P);
		P = tmp;
	}
}
