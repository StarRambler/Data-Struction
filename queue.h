#pragma once
#ifndef _QUEUE_H_
#define _QUEUE_H_
#include "das.h"

#define MAXSIZE 100
#define EXSIZE 0
#define Qlen sizeof(ElemType)

typedef struct Queue
{
	ElemType* rear;
	ElemType* front;
	int size;
}Queue,*Qu;

Status InitQueue(Qu Q);
Status QueueLength(Qu Q, int *size);
Status GetHead(Qu Q, ElemType *e);
Status Enter(Qu Q, ElemType e);
Status Out(Qu Q, ElemType* e);
Status Traverse(Qu Q);


#endif // !_QUEUE_H_
