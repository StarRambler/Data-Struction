#include <stdio.h>
#include "queue.h"

Status InitQueue(Qu Q)
{
	Q->front = (ElemType*)malloc(Qlen * MAXSIZE);
	if (!Q->front)exit(OVERLOW);
	Q->rear = Q->front;
	Q->size = MAXSIZE;
	return OK;
}
Status QueueLength(Qu Q, int* size)
{
	*size = Q->size;
	return OK;
}
Status GetHead(Qu Q, ElemType* e)
{
	if (Q->rear == Q->front)exit(ERROR);
	*e = *Q->front;
	return OK;
}

Status Enter(Qu Q, ElemType e)
{
	if (Q->rear - Q->front > Q->size)
	{
		Q->front = (ElemType*)realloc(Q->front, (MAXSIZE + EXSIZE) * Qlen);
		if (!Q->front)exit(OVERLOW);
		Q->size = Q->size + EXSIZE;
	}
	printf("normal\n");
	*(Q->rear) = e;
	Q->rear++;
	return OK;
}
Status Out(Qu Q, ElemType* e)
{
	if (Q->rear == Q->front)exit(ERROR);
	*e = *(Q->front);
	Q->front++;
	return OK;

}
Status Traverse(Qu Q)
{
	if (Q->front == Q->rear)exit(ERROR);
	for (int i = 0; i <= Q->rear-Q->front; i++)
	{
		printf("%d\n", *(Q->front));
		Q->front++;
	}
}
/*
void main()
{
	Qu Q = (Qu)malloc(sizeof(Queue));
	InitQueue(Q);
	ElemType e=0;
	scanf("%d", &e);
	Enter(Q, e);
	scanf("%d", &e);
	Enter(Q, e);
	int a=0;
	Out(Q,&a);
	printf("%d\n", a);
	printf("±éÀú½á¹û£º\n");
	Traverse(Q);
	
}*/