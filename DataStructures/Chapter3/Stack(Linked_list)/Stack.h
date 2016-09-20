#ifndef Stack_H_
#define Stack_H_

#define ElementType int

struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode Stack;

bool isEmpty( Stack S );
Stack createStack( void );
void makeEmpty( Stack S );
void push( ElementType X, Stack S );
ElementType Top( Stack S );
void pop( Stack S );

#endif