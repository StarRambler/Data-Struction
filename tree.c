#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "bintree.h"   //�������ݽṹ��ͷ�ļ�
#define MAXLEN  100    //������е���󳤶�
//��������������������������һ��������˳��������ַ���ɵĶ�������
void CreatBinTree(BinTreePtr* T)
{
    DataType ch;
    if ((ch = getchar()) == '#')
        *T = NULL;
    else {
        *T = (BinTreeTp*)malloc(sizeof(BinTreeTp));
        (*T)->data = ch;
        CreatBinTree(&(*T)->lchild);
        CreatBinTree(&(*T)->rchild);
    }
}
//�����������������
void PreOrder(BinTreePtr T)
{
    if (T) {
        printf("%c", T->data);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}
//�����������������
void InOrder(BinTreePtr T)
{
    if (T) {
        InOrder(T->lchild);
        printf("%c", T->data);
        InOrder(T->rchild);
    }
}
//�����������������
void PostOrder(BinTreePtr T)
{
    if (T) {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        printf("%c", T->data);
    }
}
//��α�������������
void LevelOrder(BinTreePtr T)
{
    
    BinTreeTp* queue[MAXLEN];
    int front, rear;  //������еĶ�ͷ�Ͷ�βָ��
    BinTreeTp* p;  //������������������ָ��

    front = rear = 0; //ѭ�����г�ʼ��
    p = T; //ָ������
    if ((rear + 1) % MAXLEN == front) return; //������������
    rear = (rear + 1) % MAXLEN;//���������
    queue[rear] = p;
    while (front != rear) {  //�����зǿ�ʱ��ִ��ѭ��
        front = (front + 1) % MAXLEN; //�޸Ķ�ͷָ��
        p = queue[front]; //�Ӷ�ͷȡ������

        printf("%c", p->data);  //����
        if (p->lchild) { //�������ָ�벻Ϊ�գ��������
            if ((rear + 1) % MAXLEN == front) return;
            rear = (rear + 1) % MAXLEN;
            queue[rear] = p->lchild;
        }
        if (p->rchild) { //����Һ���ָ�벻Ϊ�գ��������
            if ((rear + 1) % MAXLEN == front) return;
            rear = (rear + 1) % MAXLEN;
            queue[rear] = p->rchild;
        }
    }
}

void PreOrder2(BinTreeTp* root)     //�ǵݹ�ǰ����� 
{
    Stack s;
    InitStack(&s);
    BinTreeTp* p = root;
    while (p != NULL || GetSize(s))
    {
        while (p != NULL)
        {
            printf("%c", p->data);
            Push(&s,p);
            p = p->lchild;
        }
        if (GetSize(s))
        {
            GetTop(s,&p);
            Pop(&s);
            p = p->rchild;
        }
    }
}

void InOrder2(BinTreeTp* root)      //�ǵݹ��������
{
    Stack s;
    InitStack(&s);
    BinTreeTp* p = root;
    while (p != NULL || GetSize(s))
    {
        while (p != NULL)
        {
            Push(&s,p);
            p = p->lchild;
        }
        if (GetSize(s))
        {
            GetTop(s,&p);
            printf("%c", p->data );
            Pop(&s);
            p = p->rchild;
        }
    }
}
void PostOrder2(BinTreeTp* root)     //�ǵݹ�������
{
    Stack s;
    InitStack(&s);
    BinTreeTp* cur;                      //��ǰ��� 
    BinTreeTp* pre = NULL;                 //ǰһ�η��ʵĽ�� 
    Push(&s,root);
    while (GetSize(s))
    {
        GetTop(s,&cur);
        if ((cur->lchild == NULL && cur->rchild == NULL) ||
            (pre != NULL && (pre == cur->lchild || pre == cur->rchild)))
        {
            printf("%c", cur->data );  //�����ǰ���û�к��ӽ����ߺ��ӽڵ㶼�ѱ����ʹ� 
            Pop(&s);
            pre = cur;
        }
        else
        {
            if (cur->rchild != NULL)
                Push(&s,cur->rchild);
            if (cur->lchild != NULL)
                Push(&s,cur->lchild);
        }
    }
}
int LeafTree(BinTreePtr T)
{
    int lnum, rnum;
    if (!T) return 0;
    else if (!T->lchild && !T->rchild) return 1;
    else {
        lnum = LeafTree(T->lchild);
        rnum = LeafTree(T->rchild);
        return lnum + rnum;
    }//Ҷ�ӽ�����Ŀ
}
int CountTree(BinTreePtr T)
{
    int lnum, rnum;
    if (!T) return 0;
    else {
        lnum = CountTree(T->lchild);
        rnum = CountTree(T->rchild);
        return lnum + rnum + 1;
    }//���н�����Ŀ
}
void main(void)
{
    
    BinTreePtr T;
    printf("������������:\n");
    CreatBinTree(&T);
    printf("���������\n");
    printf("�ݹ飺");
    PreOrder(T);
    printf("\n�ǵݹ飺");
    PreOrder2(T);  //�������
    printf("\n���������\n");
    printf("�ݹ飺");
    InOrder(T);
    printf("\n�ǵݹ飺");
    InOrder2(T);  //�������
    printf("\n���������\n");
    printf("�ݹ飺");
    PostOrder(T);
    printf("\n�ǵݹ飺");
    PostOrder2(T);  //�������
    printf("\n���������");
    LevelOrder(T); //�������
    printf("\nҶ�ӽ��������");
    int a = LeafTree(T);
    printf("%d", a);
    printf("\n���Ľ��������");
    a = CountTree(T);
    printf("%d", a);
    printf("\n");
}