#pragma once
#include"das.h"
#ifndef _LISTLINK_H_
#define _LISTLINK_H_
#define len sizeof(ListNode)

//����ṹ�嶨��
typedef struct ListLink {
    ElemType Data;
    struct ListLink* next;
}ListNode, * ListLink;


Status IniList(ListLink *L);
//�����ʼ��
Status Create(ListLink *L, int m);
//��������,mΪ������

void printList(ListLink L);
//��ӡ��������

ListLink InsertList(ListLink L, int data);
//ͷ�巨����

ListLink Insert_Byorder(ListLink L, int e);
//��˳���������

ListLink delete_elem(ListLink L, int data);
//ɾ��ָ������

Status Change(ListLink L, int i, int data);
//���������i������



Status Judge(ListLink L);
//�ж�





ListLink Merge(ListLink list1, ListLink list2);
//�鲢

Status sort(ListLink *L);
//����

Status GetElem(ListLink L, int i, int* b);
//��õ�i������

void Reverse(ListLink L);
//��������


#endif