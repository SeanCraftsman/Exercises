#ifndef HashQuad_H
#define HashQuad_H

typedef char* ElementType;

typedef unsigned int Index;
typedef Index Position;

struct HashTbl;
typedef struct HashTbl* HashTable;

HashTable InitTable( int Tablesize );
void destroyTable( HashTable H );
Position find( ElementType Key, HashTable H );
void insert( ElementType Key, HashTable H );
void del( ElementType Key, HashTable H );
ElementType retrieve( Position P, HashTable H );
HashTable rehash( HashTable H );


#endif