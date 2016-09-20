#include <cstdlib>
#include <iostream>
#include <cmath>
#include "HashSep.h"

struct ListNode{
	ElementType Element;
	Position Next;
};

typedef Position List;

struct HashTbl{
	int TableSize;
	List *TheLists;
};

bool isPrime(int i){
	for(int j = 2; j <= sqrt((double) i); j++){
		if( i % j == 0){
			return false;
		}
	}
	return true;
}

static int NextPrime(int i){
	while(!isPrime(i)){
		i++;
	}
	return i;
}

HashTable initTable( int TableSize ){
	HashTable H;

	H = (HashTable)malloc(sizeof( struct HashTbl));
	if( H == NULL){
		std::cerr << "Out of space !!" << std::endl;
	}
	H->TableSize = NextPrime ( TableSize );

	H->TheLists = (List *)malloc(sizeof( List )*H->TableSize);
	if(H->TheLists == NULL){
		std::cerr << "Out of space !!" << std::endl;
	}

	for(int i = 0; i < H->TableSize; i++){
		H->TheLists[i] = (List)malloc( sizeof(struct ListNode));
		if(H->TheLists[i] == NULL){
			std::cerr << "Out of space !!" << std::endl;
		}
		else{
			H->TheLists[i]->Next = NULL;
		}
	}
	return H;
}

static unsigned int Hash(ElementType Key, int TableSize){
	unsigned int HashVal = 0;
	while( *Key != '\0')
		HashVal = (HashVal << 5) + *Key++;
	return HashVal % TableSize;
}

Position find( ElementType Key, HashTable H ){
	Position P;
	List L;

	L = H->TheLists[ Hash( Key, H->TableSize) ];
	P = L->Next;
	while(P != NULL && P->Element != Key){
		P = P->Next;
	}
	return P;
}

void insert( ElementType Key, HashTable H ){
	Position Pos, NewCell;
	List L;

	Pos = find( Key, H );
	if( Pos == NULL){
		NewCell = (Position)malloc( sizeof( struct ListNode));
		if(NewCell == NULL){
			std::cerr << "Out of space !!" << std::endl;
		}
		else{
			L = H->TheLists[ Hash( Key,H->TableSize) ];
			NewCell->Next = L->Next;
			NewCell->Element = Key;
			L->Next = NewCell;
		}
	}
}

ElementType Retrieve( Position P ){
	return P->Element;
}

void del(ElementType Key, HashTable H){
	Position P;
	List L;

	L = H->TheLists[ Hash( Key, H->TableSize) ];
	P = L->Next;
	while(P->Next != NULL && P->Next->Element != Key){
		P = P->Next;
	}
	if(P->Next != NULL){
		Position temp = P->Next;
		P->Next = temp->Next;
		free(temp);
	}
}

static void deleteList( List L ){
	Position P, Tmp;
	P = L->Next;
	L->Next = NULL;
	while( P != NULL ){
		Tmp = P->Next;
		free( P );
		P = Tmp;
	}
}

void destroyTable( HashTable H ){
	for(int i=0; i < H->TableSize; i++){
		deleteList( H->TheLists[i] );
		free(H->TheLists[i]);
	}
	free(H);
}