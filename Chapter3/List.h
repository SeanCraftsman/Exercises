#ifndef List_H_
#define List_H_

#define ElementType int

struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List createAList();
bool isEmpty( List L );
bool isLast( Position P, List L);
Position find ( ElementType X, List L);
void deleteNode( ElementType X, List L );
Position findPrevious ( ElementType X, List L );
void insert ( ElementType X, List L , Position P);
void deleteList ( List L );


#endif