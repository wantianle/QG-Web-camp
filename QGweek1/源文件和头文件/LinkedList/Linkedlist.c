#include "Linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
Status InitList(LinkedList* L,int sizes)
{
    *L = (LinkedList)malloc(sizeof(LNode));//��ͷ�������ռ�
    (*L)->next = NULL;
    if (sizes >= 0) {     
        for (int i = 0; i < sizes; i++) {
            LNode* node = (LNode*)malloc(sizeof(LNode));
            LinkedList head = *L;
            printf("\n��������Ҫ��������ݣ�\n");            
            checkinput(&(node->data));              
            while (head->next) {         
                head = head->next;
            }          
            node->next = head->next;
            head->next = node;         
        }        
        printf("\n���������ɹ�\n");         
        TraverseList(L,sizes);
        return SUCCESS;      
    }       
    else {          
        printf("\n�������ʼ��ʧ�ܣ��ڵ����������\n");
        return ERROR;     
    }
}

void DestroyList(LinkedList* L)
{
    if (!*L) {
        printf("\n�������롾1������������!\n");
        return;
    }
    while (*L) {
        LinkedList head=(LinkedList)malloc(sizeof(LNode));
        head = (*L)->next;
        free(*L);
        *L = head;
        if (!*L) {
            printf("\n�������ٳɹ�\n");
        }
    }
}

Status InsertList(LinkedList* L,int sizes)
{
    if (!(*L)) {
        printf("\n�������롾1������������\n");
        return ERROR;
    }
    else
    {
        TraverseList(L,sizes);
        printf("\n��������Ҫ�����λ�ã�\n");
        int site = 0;
        checkinput(&site);
        if (site > 0 && site <= sizes + 1) {
            LNode* node = (LNode*)malloc(sizeof(LNode));
            LinkedList head = *L;
            for (int i = 1; i < site; i++) {
                 head= head->next;
            }
            printf("\n��������Ҫ��������ݣ�\n");
            checkinput(&(node->data));
            node->next = head->next;
            head->next = node;
            return SUCCESS;
        }
        else {
            printf("\n��λ�ò����ڣ������²�����\n");
            return ERROR;
        }
    }
}

Status DeleteList(LinkedList* L, int sizes)
{
    if (!(*L)) {
        printf("\n�������롾1������������\n");
        return ERROR;
    }
    else if ((*L)->next == NULL)
    {
        printf("\n����һ��������\n");
        return ERROR;
    }
    else {
        TraverseList(L,sizes);
        printf("\n��������Ҫɾ����λ�ã�\n");
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
            printf("\n��λ�ò����ڣ������²�����\n");
            return ERROR;
        }
    }
}

void TraverseList(LinkedList* L,int sizes)
{
    if (!(*L)) {
        printf("\n�������롾1������������\n");
        return;
    }
    else if ((*L)->next == NULL)
    {
        printf("\n����һ��������\n");
        return;
    }
    else {
        LinkedList head = (*L)->next;
        printf("����Ϊ��\n");
        while (head) {
            printf("��%d�� -> ", head->data);
            head = head->next;
        }
        printf("NULL\n\n");
        printf("\n����������Ϊ��%d\n",sizes);
        return;
    }
}
Status SearchList(LinkedList* L, ElemType e, int sizes)
{
    if (!(*L)) {
        printf("\n�������롾1������������\n");
        return;
    }
    else if ((*L)->next == NULL)
    {
        printf("\n����һ��������\n");
        return;
    }
    else {
        printf("��Ҫ������Ԫ���ǣ�");
        checkinput(&e);
        LinkedList head = (*L)->next;
        int i = 1,k=0;
        while (head) {
            if (head->data == e) {
                printf("\n�ڵ�%d��λ�ó�����%d\n", i, e);
                k++;
            }
            head = head->next;
            i++;
        }
        printf("\n�������д���%d��%d\n",k,e);
        TraverseList(L,sizes);
        return SUCCESS;
    }
}

Status ReverseList(LinkedList* L, int sizes)
{
    if (!(*L)) {
        printf("\n�������롾1������������\n");
        return ERROR;
    }
    else if ((*L)->next == NULL)
    {
        printf("\n����һ��������\n");
        return ERROR;
    }
    else {
        TraverseList(L,sizes);
        LNode* pre, * cur, * Next;		//����ǰ�к�����ָ��
        pre = (*L)->next;
        cur = (*L)->next->next;				//�Ƚ���һ������ָ����ָ��NULL
        pre->next = NULL;
        while (cur) {
            Next = cur->next;			//��ָ�����
            cur->next = pre;			//���м��ָ��ָ��ǰһ�����
            pre = cur;					//ǰ��ָ�����
            cur = Next;
        }
        (*L)->next = pre;						//ͷָ��ָ��ԭβ��㡱
        TraverseList(L,sizes);
        return SUCCESS;
    }
}

Status IsLoopList(LinkedList *L)
{
    if (!(*L)) {
        printf("\n�������롾1������������\n");
        return ERROR;
    }
    else if ((*L)->next == NULL)
    {
        printf("\n����һ��������\n");
        return ERROR;
    }
    else {
        LNode* fast, * slow;
        fast = slow = (*L)->next;				//����ָ������ͬ���
        while (fast && fast->next) {
            slow = slow->next;			//slow��һ�����
            fast = fast->next->next;	//fast���������
            if (slow == fast) {
                printf("\n����ѭ������\n");
                return SUCCESS;
            }
        }
        printf("\n�ⲻ��ѭ������\n");
        return ERROR;
    }
}

Status ReverseEvenList(LinkedList* L,int sizes)
{
    if (!(*L)) {
        printf("\n�������롾1������������\n");
        return ERROR;
    }
    else if ((*L)->next == NULL)
    {
        printf("\n����һ��������\n");
        return ERROR;
    }
    else {
        TraverseList(L, sizes);
        LNode* pre, * cur, * Next;		//����ǰ�к�ָ�룬��;�ͷ�ת����
        pre = (*L)->next;
        (*L)->next = pre->next;
        while (pre && pre->next) {
            cur = pre->next;
            Next = cur->next;
            if (cur->next && cur->next->next) {			//���cur->next�����ڣ�������Ϊż��
                pre->next = cur->next->next;			//���cur->next->next�����ڣ�������Ϊ����
            }
            else {										//��������ڣ�����δ����
                pre->next = cur->next;
            }
            cur->next = pre;							//��ż����㷴ת
            pre = Next;
        }
        TraverseList(L, sizes);
        return SUCCESS;
    }
}

Status FindMidNode(LinkedList* L,int sizes)
{
    if (!(*L)) {
        printf("\n�������롾1������������\n");
        return ERROR;
    }
    else if ((*L)->next == NULL)
    {
        printf("\n����һ��������\n");
        return ERROR;
    }
    else {
        if (sizes % 2 == 0) {
            printf("\n������ڵ���Ϊż����û���м�ڵ㣡\n");
        }
        else {
            LinkedList mid = (*L)->next;
            for (int i = 0; i < sizes / 2; i++)
                mid = mid->next;
            printf("�м�ڵ�Ԫ���ǣ�%d\n", mid->data);
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
        if (error) printf("����������������룡\n");
    } while (error);
    *r = atoi(c) ;
}
