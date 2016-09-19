#ifndef HashSep_H
#define HashSep_H

#define ElementType char*

struct ListNode;
typedef struct ListNode* Position;
struct HashTbl;
typedef struct HashTbl* HashTable;

HashTable initTable( int TableSize );
void destroyTable( HashTable H );
Position find( ElementType Key, HashTable H );
void insert( ElementType Key, HashTable H );
ElementType Retrieve( Position P );

#endif