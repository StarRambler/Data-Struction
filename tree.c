#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "bintree.h"   //定义数据结构的头文件
#define MAXLEN  100    //定义队列的最大长度
//创建二叉树操作，本操作创建一个由先序顺序输入的字符组成的二叉树。
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
//先序遍历二叉树操作
void PreOrder(BinTreePtr T)
{
    if (T) {
        printf("%c", T->data);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}
//中序遍历二叉树操作
void InOrder(BinTreePtr T)
{
    if (T) {
        InOrder(T->lchild);
        printf("%c", T->data);
        InOrder(T->rchild);
    }
}
//后序遍历二叉树操作
void PostOrder(BinTreePtr T)
{
    if (T) {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        printf("%c", T->data);
    }
}
//层次遍历二叉树操作
void LevelOrder(BinTreePtr T)
{
    
    BinTreeTp* queue[MAXLEN];
    int front, rear;  //定义队列的队头和队尾指针
    BinTreeTp* p;  //定义待处理二叉树结点的指针

    front = rear = 0; //循环队列初始化
    p = T; //指向根结点
    if ((rear + 1) % MAXLEN == front) return; //队列满，返回
    rear = (rear + 1) % MAXLEN;//否则入队列
    queue[rear] = p;
    while (front != rear) {  //当队列非空时，执行循环
        front = (front + 1) % MAXLEN; //修改队头指针
        p = queue[front]; //从队头取得数据

        printf("%c", p->data);  //遍历
        if (p->lchild) { //如果左孩子指针不为空，则入队列
            if ((rear + 1) % MAXLEN == front) return;
            rear = (rear + 1) % MAXLEN;
            queue[rear] = p->lchild;
        }
        if (p->rchild) { //如果右孩子指针不为空，则入队列
            if ((rear + 1) % MAXLEN == front) return;
            rear = (rear + 1) % MAXLEN;
            queue[rear] = p->rchild;
        }
    }
}

void PreOrder2(BinTreeTp* root)     //非递归前序遍历 
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

void InOrder2(BinTreeTp* root)      //非递归中序遍历
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
void PostOrder2(BinTreeTp* root)     //非递归后序遍历
{
    Stack s;
    InitStack(&s);
    BinTreeTp* cur;                      //当前结点 
    BinTreeTp* pre = NULL;                 //前一次访问的结点 
    Push(&s,root);
    while (GetSize(s))
    {
        GetTop(s,&cur);
        if ((cur->lchild == NULL && cur->rchild == NULL) ||
            (pre != NULL && (pre == cur->lchild || pre == cur->rchild)))
        {
            printf("%c", cur->data );  //如果当前结点没有孩子结点或者孩子节点都已被访问过 
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
    }//叶子结点的数目
}
int CountTree(BinTreePtr T)
{
    int lnum, rnum;
    if (!T) return 0;
    else {
        lnum = CountTree(T->lchild);
        rnum = CountTree(T->rchild);
        return lnum + rnum + 1;
    }//所有结点的数目
}
void main(void)
{
    
    BinTreePtr T;
    printf("先序创立二叉树:\n");
    CreatBinTree(&T);
    printf("先序遍历：\n");
    printf("递归：");
    PreOrder(T);
    printf("\n非递归：");
    PreOrder2(T);  //先序遍历
    printf("\n中序遍历：\n");
    printf("递归：");
    InOrder(T);
    printf("\n非递归：");
    InOrder2(T);  //中序遍历
    printf("\n后序遍历：\n");
    printf("递归：");
    PostOrder(T);
    printf("\n非递归：");
    PostOrder2(T);  //后序遍历
    printf("\n层序遍历：");
    LevelOrder(T); //层序遍历
    printf("\n叶子结点数：：");
    int a = LeafTree(T);
    printf("%d", a);
    printf("\n树的结点数：：");
    a = CountTree(T);
    printf("%d", a);
    printf("\n");
}