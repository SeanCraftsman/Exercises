#ifndef Tree_H_
#define Tree_H_

#define ElementType int

struct TreeNode;
typedef struct TreeNode* Position;
typedef struct TreeNode* SearchTree;

SearchTree makeEmpty( SearchTree T );
Position find( ElementType X, SearchTree T );
Position findMin( SearchTree T );
Position findMax( SearchTree T );
SearchTree insert( ElementType X, SearchTree T );
SearchTree del( ElementType X, SearchTree T );

#endif