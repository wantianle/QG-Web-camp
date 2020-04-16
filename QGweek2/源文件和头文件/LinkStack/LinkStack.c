#include"LinkStack.h"
#include <stdio.h>
#include <stdlib.h>

Status initLStack(LinkStack* s)
{
	s->top = (LinkStackPtr)malloc(sizeof(StackNode));
	s->top->next = NULL;
	s->count = 0;
	return SUCCESS;
}

Status isEmptyLStack(LinkStack* s)
{
	if (!s->top) {
		printf("\n�������롾1��������ջ!\n");
		return ERROR;
	}
	else if (s->count == 0) {
		printf("\n����һ������ջ��\n");
		return SUCCESS;
	}
	else {
		printf("\n�ⲻ��һ������ջ��\n");
		return ERROR;
	}
}

Status getTopLStack(LinkStack* s)
{
	if (!s->top) {
		printf("\n�������롾1��������ջ!\n");
		return ERROR;
	}
	else if (s->count == 0) {
		printf("\n����һ������ջ��\n");
		return ERROR;
	}
	else {
		printf("\nջ��Ԫ��Ϊ��%d\n", s->top->next->data);
		return SUCCESS;
	}
}

Status clearLStack(LinkStack* s)
{
	if (!s->top) {
		printf("\n�������롾1��������ջ!\n");
		return ERROR;
	}
	else if (s->count == 0) {
		printf("\n����һ������ջ��\n");
		return ERROR;
	}
	else {
		LinkStackPtr ptem, p = s->top->next;
		while (p) {
			ptem = p->next;
			free(p);
			p = ptem;
		}
		s->count = 0;
		printf("\n��ջ��ճɹ�\n");
		return SUCCESS;
	}
}

Status destroyLStack(LinkStack* s)
{
	if (!s->top) {
		printf("\n�������롾1��������ջ!\n");
		return ERROR;
	}
	while (s->top) {
		LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
		p = s->top->next;
		free(s->top);
		s->top = p;
		s->count--;
		if(!s->top)
		printf("\n��ջ���ٳɹ�\n");
	}
}

Status LStackLength(LinkStack* s)
{
	if (!s->top) {
		printf("\n�������롾1��������ջ!\n");
		return ERROR;
	}
	else if (s->count == 0) {
		printf("\n����һ������ջ��\n");
		return ERROR;
	}
	else {
		printf("\n��ջ����Ϊ��%d\n", s->count);
		return SUCCESS;
	}
}

Status pushLStack(LinkStack* s)
{
	if (!s->top) {
		printf("\n�������롾1��������ջ!\n");
		return ERROR;
	}
	else {
		StackNode* p;
		p = (StackNode*)malloc(sizeof(StackNode));
		printf("\n������������ݣ�\n");
		checkinput(&(p->data));
		p->next = s->top->next;
		s->top->next = p;
		s->count++;
		printf("\n��ջ�ɹ�\n");
		TraverseStack(s);
		return SUCCESS;
	}
}

Status popLStack(LinkStack* s)
{
	if (!s->top) {
		printf("\n�������롾1��������ջ!\n");
		return ERROR;
	}
	else if (s->count == 0) {
		printf("\n����һ������ջ��\n");
		return ERROR;
	}
	else {
		LinkStackPtr ptem, p = s->top->next;
		ptem = p->next;
		free(p);
		s->top->next = ptem;
		s->count--;
		printf("\n��ջ�ɹ�\n");
		TraverseStack(s);
		return SUCCESS;
	}
}

void TraverseStack(LinkStack* s)
{
	if (!s->top) {
		printf("\n�������롾1��������ջ!\n");
		return;
	}
	else if (s->count == 0) {
		printf("\n����һ������ջ��\n");
		return;
	}
	else {
		LinkStackPtr p = s->top->next;
		printf("\n��ջΪ��\n\n��top�� <-");
		while (p) {
			printf("��%d�� <- ", p->data);
			p = p->next;
		}
		printf("��bottom��\n\n");
		printf("\n������ջ����Ϊ��%d\n", s->count);
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
		if (error) printf("����������������룡\n");
	} while (error);
	*r = atoi(c);
}
