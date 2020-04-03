#include "../First assignment/Linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList* L)
{
    int i, n, goal;
    *L = (LinkedList)malloc(sizeof(LinkedList));		//����һ���������ռ�
    if (!(*L))											//������ʧ�ܷ��ش���
        return ERROR;
    (*L)->next = NULL;
    LNode* p;
    LNode* q = L;
    printf("���������ݵĸ���:\n");
    scanf_s("%d", &n);
    for (i = 0; i < n; i++) {
        printf("�������%d����:\n", i + 1);
        scanf_s("%d", &goal);
        p = (LNode*)malloc(sizeof(LNode));
        p->data = goal;
        q->next = p;
        q = p;
    }
    q->next = NULL;

    return SUCCESS;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList* L)
{
    LinkedList p;
    while (*L) {
        p = (*L)->next;
        free(*L);
        *L = p;
    }
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode* p, LNode* q)
{
    if (!p)					//���p��㲻���ڣ����ش���
        return ERROR;
    else
    {
        q->next = p->next;
        p->next = q;


        return SUCCESS;
    }

}

/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode* p, ElemType* e)
{
    if (!p && !p->next)
        return ERROR;
    LNode* q;
    q = p->next;
    *e = q->data;		//����ǰ���e�Ƿ���ָ��һ����֪���ڴ�ռ�
    p->next = q->next;
    free(q);
    return SUCCESS;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e))
{
    LNode* p;
    p = L;
    while (p != NULL) {
        visit(p->data);
        p = p->next;
    }
}

void visit(ElemType e)
{
    printf("%6d", e);
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e)
{
    LNode* p;
    p = L;
    while (p) {
        if (p->data == e)
            return SUCCESS;
        else
            p = p->next;
    }
    return ERROR;
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList* L)
{
    if (!(*L) && !(*L)->next)
        return ERROR;
    LNode* pre, * cur, * Next;		//����ǰ�к�����ָ��
    pre = *L;
    cur = (*L)->next;				//�Ƚ���һ������ָ����ָ��NULL
    pre->next = NULL;
    while (cur) {
        Next = cur->next;			//��ָ�����
        cur->next = pre;			//���м��ָ��ָ��ǰһ�����
        pre = cur;					//ǰ��ָ�����
        cur = Next;
    }
    *L = pre;						//ͷָ��ָ��ԭβ��㡱
    return SUCCESS;
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L)
{
    LNode* fast, * slow;
    fast = slow = L;				//����ָ������ͬ���
    while (fast && fast->next) {
        slow = slow->next;			//slow��һ�����
        fast = fast->next->next;	//fast���������
        if (slow == fast)
            return SUCCESS;
    }
    return ERROR;
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList* L)
{
    LNode* pre, * cur, * Next;		//����ǰ�к�ָ�룬��;�ͷ�ת����
    pre = *L;
    *L = pre->next;
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
    return *L;
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList* L)
{
    LNode* mid = *L;
    int cnt;
    for (cnt = 0; mid; cnt++)
        mid = mid->next;
    mid = *L;
    for (int i = 0; i < cnt / 2; i++)
        mid = mid->next;
    return mid;
}

void DisPlay(LNode* L) //�������
{
    LNode* p = L->next;
    printf("�����������Ϊ��\n");
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}