#include <stdio.h>
#include "stack.h"
Status InitStack(Sq S) 
{
	S->base = (ElemType*)malloc(MAXSIZE*len);
	if (!S->base)exit(OVERLOW);
	S->top = S->base;
	S->stacksize = MAXSIZE + EXSIZE;
	return OK;
}
Status GetTop(Sq S, ElemType* e) {
	if (S->base == S->top) return ERROR;
	*e =*( S->top - 1);
	return OK;
}
Status Push(Sq S,ElemType e)
{
	if (S->top - S->base > S->stacksize)
	{
		S->base = (ElemType*)realloc(S->base,(S->stacksize + EXSIZE) * len);
	
		if (!S->base)exit(OVERLOW);
		S->top = S->base + S->stacksize;
		S->stacksize = S->stacksize + EXSIZE;
	}
	*(S->top) = e;
	S->top = S->top + 1;
}
Status Pop(Sq S,ElemType *e)
{
	if (S->base == S->top)exit(OVERLOW);
	*e = S->top;
	S->top--;

}
Status ClearStack(Sq S)
{
	S->top = S->base;
	printf("栈已清空");
	return OK;
}
Status DestoryStack(Sq S)
{
	free(S->base);
	printf("栈已销毁");
}
/*
void main()
{
	Sq S = (Sq)malloc(Stack);
	InitStack(S);
	int a = 0;
	scanf("%d", &a);
	Push(S, a);
	scanf("%d", &a);
	Push(S, a);
	int b = 0;
	printf("栈顶元素的值\n");
	GetTop(S, &b);
	printf("%d\n", b);
	Pop(S, &b);
	printf("栈顶元素的值\n");
	GetTop(S, &b);
	printf("%d\n", b);
	ClearStack(S);
	DestoryStack(S);
}
*/