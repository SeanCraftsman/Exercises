#include <cstdlib>
#include <iostream>
#include "HashQuad.h"

enum KindOfEntry { Legitimate, Empty, Deleted };

struct HashEntry{
	ElementType Element;
	enum KindOfEntry Info;
};

typedef struct HashEntry Cell;

struct HashTbl{
	int TableSize;
	Cell *TheCells;
};

static unsigned int Hash(ElementType Key, int TableSize){
	unsigned int HashVal = 0;
	while( *Key != '\0')
		HashVal = (HashVal << 5) + *Key++;
	return HashVal % TableSize;
}

HashTable InitTable( int TableSize ){
	HashTable H;
	H = (HashTable) malloc( sizeof(struct HashTbl ) );
	if( H == NULL ){
		std::cerr << "Out of space !!" << std::endl;
	}
	H->TableSize = TableSize;

	H->TheCells = (Cell*)malloc(sizeof(Cell) * H->TableSize );
	if( H == NULL){
		std::cerr << "Out of space !!" << std::endl;
	}
	for(int i=0; i < H->TableSize; i++){
		H->TheCells[i].Info = Empty;
	}
	return H;
}

void destroyTable( HashTable H ){
	free(H->TheCells);
	free(H);
}

Position find( ElementType Key, HashTable H ){
	Position CurrentPos;
	int CollisionNum;

	CollisionNum = 0;
	CurrentPos = Hash( Key,H->TableSize );
	while( H->TheCells[ CurrentPos ].Info != Empty &&
		H->TheCells[ CurrentPos ].Element != Key ){ // F(i) = F(i-1) + 2i-1
			CurrentPos += 2 * ++CollisionNum - 1;
			if( CurrentPos >= H->TableSize ){
				CurrentPos -= H->TableSize;
			}
	}
	return CurrentPos;
}

void insert( ElementType Key, HashTable H ){
	Position Pos;
	Pos = find( Key,H );
	if( H->TheCells[ Pos ].Info != Legitimate ){
		H->TheCells[ Pos ].Info = Legitimate;
		H->TheCells[ Pos ].Element = Key;
	}
}

void del( ElementType Key, HashTable H ){
	Position Pos;
	Pos = find( Key, H);
	if( H->TheCells[ Pos ].Info == Legitimate ){
		H->TheCells[ Pos ].Info = Deleted;
	}
}

ElementType retrieve( Position P, HashTable H ){
	return H->TheCells[ P ].Element;
}

HashTable rehash( HashTable H ){
	HashTable newHashTable;
	newHashTable = InitTable( H->TableSize * 2);
	for(int i=0; i < H->TableSize; i++){
		if(H->TheCells[i].Info == Legitimate){
			insert(H->TheCells[i].Element, newHashTable);
		}
	}
	destroyTable(H);
	return newHashTable;
}