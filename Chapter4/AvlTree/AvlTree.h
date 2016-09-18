#ifndef AvlTree_H_
#define AvlTree_H_

#define ElementType int

struct AvlNode;
typedef struct AvlNode* Position;
typedef struct AvlNode* AvlTree;

AvlTree makeEmpty( AvlTree T );
Position find( ElementType X, AvlTree T );
Position findMin( AvlTree T );
Position findMax( AvlTree T );
AvlTree insert( ElementType X, AvlTree T );
AvlTree del( ElementType X, AvlTree T );
ElementType retrieve( Position P );

#endif