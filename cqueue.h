#pragma once
#ifndef _CQueue_H_
#define _CQueue_H_
#include "das.h"

#define CMAXSIZE 100
#define CEXSIZE 0
#define CQlen sizeof(ElemType)

typedef struct CQueue
{
	ElemType* rear;
	ElemType* front;
	int size;
}CQueue, * CQu;

Status InitCQueue(CQu Q);
Status CQueueLength(CQu Q, int* size);
Status GetHead(CQu Q, ElemType* e);
Status CEnter(CQu Q, ElemType e);
Status COut(CQu Q, ElemType* e);
Status CTraverse(CQu Q);


#endif // !_CQueue_H_
