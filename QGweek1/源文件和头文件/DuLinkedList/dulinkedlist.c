#include "dulinkedlist.h"
#include <stdio.h>
#include <stdlib.h>
Status InitList_DuL(DuLinkedList* L, int sizes)
{
	*L = (DuLinkedList)malloc(sizeof(DuLNode));
	if (!(*L))
		return ERROR;
	(*L)->next = NULL;
	(*L)->prior = NULL;
	if (sizes >= 0) {
		for (int i = 0; i < sizes; i++) {
			DuLNode* node = (DuLNode*)malloc(sizeof(DuLNode));
			printf("\n请输入你要插入的数据：\n");
			checkinput(&(node->data));
			DuLinkedList head = *L;
			while (head->next) {
				head = head->next;
			}
			node->next = head->next;
			head->next = node;
			node->prior = head;
		}
		printf("\n单链表创建成功\n");
		TraverseList_DuL(L, sizes);
		return SUCCESS;
	}
	else {
		printf("\n双链表初始化失败，节点数输入错误！\n");
		return ERROR;
	}
}

void DestroyList_DuL(DuLinkedList* L)
{
	if (!*L) {
		printf("\n请先输入【1】创建双链表!\n");
		return;
	}
	else {
		while (*L) {
			DuLinkedList head = (*L)->next;
			free(*L);
			*L = head;
		}
		printf("\n链表销毁成功\n");
	}
}

Status InsertBeforeList_DuL(DuLinkedList* L, int sizes)
{
	if (!(*L)) {
		printf("\n请先输入【1】创建双链表！\n");
		return ERROR;
	}
	else
	{
		TraverseList_DuL(L, sizes);
		printf("\n你要插入哪个位置前面：\n");
		int site = 0;
		checkinput(&site);
		if (site > 0 && site <= sizes) {
			DuLNode* node = (DuLNode*)malloc(sizeof(DuLNode));
			DuLinkedList head = *L;
			for (int i = 1; i < site; i++) {
				head = head->next;
			}
			printf("\n请输入你要插入的数据：\n");
			checkinput(&(node->data));
			node->next = head->next;
			head->next = node;
			node->prior = head;
			node->next->prior = node;
			return SUCCESS;
		}
		else {
			printf("\n该位置不存在，请重新操作！\n");
			return ERROR;
		}
	}
}

Status InsertAfterList_DuL(DuLinkedList* L, int sizes)
{
	if (!(*L)) {
		printf("\n请先输入【1】创建双链表！\n");
		return ERROR;
	}
	else
	{
		TraverseList_DuL(L, sizes);
		printf("\n你要插入哪个位置后面：\n");
		int site = 0;
		checkinput(&site);
		if (site > 0 && site <= sizes) {
			DuLNode* node = (DuLNode*)malloc(sizeof(DuLNode));
			DuLinkedList head = *L;
			for (int i = 0; i < site; i++) {
				head = head->next;
			}
			printf("\n请输入你要插入的数据：\n");
			checkinput(&(node->data));
			if (site = sizes) {
				node->next = head->next;
				head->next = node;
				node->prior = head;
			}
			else {
				node->next = head->next;
				head->next = node;
				node->prior = head;
				node->next->prior = node;
			}
			return SUCCESS;
		}
		else {
			printf("\n该位置不存在，请重新操作！\n");
			return ERROR;
		}
	}
}

Status DeleteList_DuL(DuLinkedList* L, int sizes)
{
	if (!(*L)) {
		printf("\n请先输入【1】创建双链表！\n");
		return ERROR;
	}
	else if ((*L)->next == NULL)
	{
		printf("\n这是一个空链表！\n");
		return ERROR;
	}
	else {
		TraverseList_DuL(L, sizes);
		printf("\n请输入你要删除的位置：\n");
		int site = 0;
		checkinput(&site);
		if (site > 0 && site <= sizes) {
			DuLinkedList head = (*L)->next;
			for (int i = 1; i < site; i++) {
				head = head->next;
			}
			if (site == sizes) {
				head->prior->next = head->next;
				free(head);
			}
			else {
				head->prior->next = head->next;
				head->next->prior = head->prior;
				free(head);
			}
			return SUCCESS;
		}
		else {
			printf("\n该位置不存在，请重新操作！\n");
			return ERROR;
		}
	}
}

void TraverseList_DuL(DuLinkedList* L, int sizes)
{
	if (!(*L)) {
		printf("\n请先输入【1】创建双链表！\n");
		return;
	}
	else if ((*L)->next == NULL)
	{
		printf("\n这是一个空链表！\n");
		return;
	}
	else {
		DuLinkedList head=(*L)->next;
		printf("链表为：\nNULL <=>");
		while (head) {
			printf("【%d】 <=> ", head->data);
			head = head->next;
		}
		printf("NULL\n\n");
		printf("\n现在链表长度为：%d\n", sizes);
		return;
	}
}

void checkinput(int* r) {
	int error = 0, i = 0;
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
	*r = atoi(c);
}
