#include "listlink.h"
#include <stdio.h>

Status IniList(ListLink* L)
{
	*L = (ListLink)malloc(len);
	if (!*L)exit(OVERLOW);
	(*L)->next = NULL;
	return OK;
}

Status Create(ListLink* L)
{
	int m,n;
	printf("输入链表大小:\n");
	scanf("%d", &m);
	(*L)->Data = m;
	ListLink p1=(*L), p2=NULL;
	for (int i = 0; i < m; i++)
	{
		p2 = (ListLink)malloc(len);
		p1->next = p2;
		printf("请输入数据：\n");
		scanf("%d", &n);
		p2->Data = n;
		p1 = p2;
	}
	p1->next = NULL;
}
void printList(ListLink L)
{
	int n = L->Data;
	for (int i = 0; i < n; i++)
	{
		L = L->next;
		printf("%d\n", L->Data);
	}
}

Status sort(ListLink L)
{
	int m,n=0,temp=0;
	m = L->Data;
	ListLink p1, p2;
	p1 = L->next;
	p2 = L->next->next;
	for (int i = 0; i < m-1; i++)
	{
		for (n = 0; n < m-i-1; n++)
		{
			if (p1->Data > p2->Data)
			{
				temp = p1->Data;
				p1->Data = p2->Data;
				p2->Data = temp;
			}
			p1 = p1->next;
			p2 = p2->next;
		}
		p1 = L->next;
		p2 = L->next->next;
	}
}


void main()
{

	ListLink L;
	IniList(&L);
	Create(&L);
	printf("ok\n");
	printList(L);
	sort(L);
	printf("排序后：\n");
	printList(L);
}