#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdbool.h>

typedef struct Queue Queue;
typedef void (*print_fcptr)(void*);

Queue *InitQueue();

void Enqueue(Queue *q, void* data);

void* Dequeue(Queue *q);

void PrintQueue(Queue *q, print_fcptr printData);

void DestroyQueue(Queue *q);

bool IsEmpityQueue(Queue *q);

#endif // !_QUEUE_H_
