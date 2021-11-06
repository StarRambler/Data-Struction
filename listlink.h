#pragma once
#include"das.h"
#ifndef _LISTLINK_H_
#define _LISTLINK_H_
#define len sizeof(ListNode)

//链表结构体定义
typedef struct ListLink {
    ElemType Data;
    struct ListLink* next;
}ListNode, * ListLink;


Status IniList(ListLink *L);
//链表初始化
Status Create(ListLink *L, int m);
//创建链表,m为链表长度

void printList(ListLink L);
//打印链表数据

ListLink InsertList(ListLink L, int data);
//头插法插入

ListLink Insert_Byorder(ListLink L, int e);
//按顺序插入数据

ListLink delete_elem(ListLink L, int data);
//删除指定数据

Status Change(ListLink L, int i, int data);
//查找链表第i个数据



Status Judge(ListLink L);
//判断





ListLink Merge(ListLink list1, ListLink list2);
//归并

Status sort(ListLink *L);
//排序

Status GetElem(ListLink L, int i, int* b);
//获得第i个数据

void Reverse(ListLink L);
//逆置链表


#endif