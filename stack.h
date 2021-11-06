#pragma once
#ifndef _STACK_H_
#define _STACK_H_
#include "das.h"
#define MAXSIZE 100
#define EXSIZE 0
#define len sizeof(ElemType)
typedef struct Stack
{
	ElemType *base;
	ElemType* top;
	int stacksize;

}Stack,*Sq;

Status InitStack(Sq S);
Status GetTop(Sq S,ElemType *e);
Status Push(Sq S,ElemType e);
Status Pop(Sq S,ElemType *e);
Status ClearStack(Sq S);
Status DestoryStack(Sq S);



#endif 