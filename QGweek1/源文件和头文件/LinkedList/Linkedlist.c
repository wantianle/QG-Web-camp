#include "Linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
Status InitList(LinkedList* L,int sizes)
{
    *L = (LinkedList)malloc(sizeof(LNode));//给头结点申请空间
    (*L)->next = NULL;
    if (sizes >= 0) {     
        for (int i = 0; i < sizes; i++) {
            LNode* node = (LNode*)malloc(sizeof(LNode));
            LinkedList head = *L;
            printf("\n请输入你要插入的数据：\n");            
            checkinput(&(node->data));              
            while (head->next) {         
                head = head->next;
            }          
            node->next = head->next;
            head->next = node;         
        }        
        printf("\n单链表创建成功\n");         
        TraverseList(L,sizes);
        return SUCCESS;      
    }       
    else {          
        printf("\n单链表初始化失败，节点数输入错误！\n");
        return ERROR;     
    }
}

void DestroyList(LinkedList* L)
{
    if (!*L) {
        printf("\n请先输入【1】创建单链表!\n");
        return;
    }
    while (*L) {
        LinkedList head=(LinkedList)malloc(sizeof(LNode));
        head = (*L)->next;
        free(*L);
        *L = head;
        if (!*L) {
            printf("\n链表销毁成功\n");
        }
    }
}

Status InsertList(LinkedList* L,int sizes)
{
    if (!(*L)) {
        printf("\n请先输入【1】创建单链表！\n");
        return ERROR;
    }
    else
    {
        TraverseList(L,sizes);
        printf("\n请输入你要插入的位置：\n");
        int site = 0;
        checkinput(&site);
        if (site > 0 && site <= sizes + 1) {
            LNode* node = (LNode*)malloc(sizeof(LNode));
            LinkedList head = *L;
            for (int i = 1; i < site; i++) {
                 head= head->next;
            }
            printf("\n请输入你要插入的数据：\n");
            checkinput(&(node->data));
            node->next = head->next;
            head->next = node;
            return SUCCESS;
        }
        else {
            printf("\n该位置不存在，请重新操作！\n");
            return ERROR;
        }
    }
}

Status DeleteList(LinkedList* L, int sizes)
{
    if (!(*L)) {
        printf("\n请先输入【1】创建单链表！\n");
        return ERROR;
    }
    else if ((*L)->next == NULL)
    {
        printf("\n这是一个空链表！\n");
        return ERROR;
    }
    else {
        TraverseList(L,sizes);
        printf("\n请输入你要删除的位置：\n");
        int site = 0;
        checkinput(&site);
        if (site > 0 && site <= sizes) {
            LNode* node = (LNode*)malloc(sizeof(LNode));
            LinkedList head = *L;
            for (int i = 1; i < site; i++) {
                head = head->next;
            }
            node = head->next;
            head->next = head->next->next;
            node->next = NULL;
            free(node);
            return SUCCESS;
        }
        else {
            printf("\n该位置不存在，请重新操作！\n");
            return ERROR;
        }
    }
}

void TraverseList(LinkedList* L,int sizes)
{
    if (!(*L)) {
        printf("\n请先输入【1】创建单链表！\n");
        return;
    }
    else if ((*L)->next == NULL)
    {
        printf("\n这是一个空链表！\n");
        return;
    }
    else {
        LinkedList head = (*L)->next;
        printf("链表为：\n");
        while (head) {
            printf("【%d】 -> ", head->data);
            head = head->next;
        }
        printf("NULL\n\n");
        printf("\n现在链表长度为：%d\n",sizes);
        return;
    }
}
Status SearchList(LinkedList* L, ElemType e, int sizes)
{
    if (!(*L)) {
        printf("\n请先输入【1】创建单链表！\n");
        return;
    }
    else if ((*L)->next == NULL)
    {
        printf("\n这是一个空链表！\n");
        return;
    }
    else {
        printf("你要搜索的元素是：");
        checkinput(&e);
        LinkedList head = (*L)->next;
        int i = 1,k=0;
        while (head) {
            if (head->data == e) {
                printf("\n在第%d个位置出现了%d\n", i, e);
                k++;
            }
            head = head->next;
            i++;
        }
        printf("\n单链表中存在%d个%d\n",k,e);
        TraverseList(L,sizes);
        return SUCCESS;
    }
}

Status ReverseList(LinkedList* L, int sizes)
{
    if (!(*L)) {
        printf("\n请先输入【1】创建单链表！\n");
        return ERROR;
    }
    else if ((*L)->next == NULL)
    {
        printf("\n这是一个空链表！\n");
        return ERROR;
    }
    else {
        TraverseList(L,sizes);
        LNode* pre, * cur, * Next;		//定义前中后三个指针
        pre = (*L)->next;
        cur = (*L)->next->next;				//先将第一个结点的指针域指向NULL
        pre->next = NULL;
        while (cur) {
            Next = cur->next;			//后指针后移
            cur->next = pre;			//将中间的指针指向前一个结点
            pre = cur;					//前中指针后移
            cur = Next;
        }
        (*L)->next = pre;						//头指针指向“原尾结点”
        TraverseList(L,sizes);
        return SUCCESS;
    }
}

Status IsLoopList(LinkedList *L)
{
    if (!(*L)) {
        printf("\n请先输入【1】创建单链表！\n");
        return ERROR;
    }
    else if ((*L)->next == NULL)
    {
        printf("\n这是一个空链表！\n");
        return ERROR;
    }
    else {
        LNode* fast, * slow;
        fast = slow = (*L)->next;				//快慢指针在相同起点
        while (fast && fast->next) {
            slow = slow->next;			//slow走一个结点
            fast = fast->next->next;	//fast走两个结点
            if (slow == fast) {
                printf("\n这是循环链表！\n");
                return SUCCESS;
            }
        }
        printf("\n这不是循环链表！\n");
        return ERROR;
    }
}

Status ReverseEvenList(LinkedList* L,int sizes)
{
    if (!(*L)) {
        printf("\n请先输入【1】创建单链表！\n");
        return ERROR;
    }
    else if ((*L)->next == NULL)
    {
        printf("\n这是一个空链表！\n");
        return ERROR;
    }
    else {
        TraverseList(L, sizes);
        LNode* pre, * cur, * Next;		//定义前中后指针，用途和反转相似
        pre = (*L)->next;
        (*L)->next = pre->next;
        while (pre && pre->next) {
            cur = pre->next;
            Next = cur->next;
            if (cur->next && cur->next->next) {			//如果cur->next不存在，结点个数为偶数
                pre->next = cur->next->next;			//如果cur->next->next不存在，结点个数为奇数
            }
            else {										//如果都存在，遍历未结束
                pre->next = cur->next;
            }
            cur->next = pre;							//将偶数结点反转
            pre = Next;
        }
        TraverseList(L, sizes);
        return SUCCESS;
    }
}

Status FindMidNode(LinkedList* L,int sizes)
{
    if (!(*L)) {
        printf("\n请先输入【1】创建单链表！\n");
        return ERROR;
    }
    else if ((*L)->next == NULL)
    {
        printf("\n这是一个空链表！\n");
        return ERROR;
    }
    else {
        if (sizes % 2 == 0) {
            printf("\n单链表节点数为偶数，没有中间节点！\n");
        }
        else {
            LinkedList mid = (*L)->next;
            for (int i = 0; i < sizes / 2; i++)
                mid = mid->next;
            printf("中间节点元素是：%d\n", mid->data);
            return SUCCESS;
        }
    }
}

void checkinput(int* r) {
    int error, i=0; 
    char c[50] = { 0 };
    do {
        gets(c);
        error = 0;
        for (i = 0; c[i] != '\0'; i++) {
            if (i == 0 && c[i] == '-')
            {
                continue;
            }
            if (c[i] < '0' || c[i]>'9')
                error = 1;
        }
        if (error) printf("输入错误，请重新输入！\n");
    } while (error);
    *r = atoi(c) ;
}
