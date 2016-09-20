#ifndef Queue_H_
#define Queue_H_

#define ElementType int

struct QueueRecord;
typedef struct QueueRecord *Queue;

bool isEmpty( Queue Q);
bool isFull( Queue Q );
Queue createQueue( int maxSize );
void disposeQueue( Queue Q );
void makeEmpty( Queue Q );
void enque( ElementType X, Queue Q );
ElementType front( Queue Q );
void deque( Queue Q );

#endif