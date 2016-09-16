#ifndef Stack_H_
#define Stack_H_

#define ElementType int

struct StackRecord;
typedef struct StackRecord *Stack;

bool isEmpty( Stack S );
bool isFull( Stack S );
Stack createStack( int MaxSize );
void disposeStack( Stack S );
void makeEmpty( Stack S );
void push( ElementType X, Stack S );
ElementType top( Stack S );
void pop( Stack S );

#endif