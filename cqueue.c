#include<stdio.h>
#include"cqueue.h"

Status InitCQueue(CQu Q)
{
	Q->front = (CQu)malloc(CQlen*CMAXSIZE);
	Q->rear = Q->front;
	Q->size = CMAXSIZE;
	return OK;
}
Status CQueueLength(CQu Q, int* size)
{
	if (Q->rear == Q->front)exit(OVERLOW);
	(*size) = (Q->rear-Q->front+CMAXSIZE)%CMAXSIZE;
	return OK;
}
Status GetHead(CQu Q, ElemType* e);
Status CEnter(CQu Q, ElemType e);
Status COut(CQu Q, ElemType* e);
Status CTraverse(CQu Q);
