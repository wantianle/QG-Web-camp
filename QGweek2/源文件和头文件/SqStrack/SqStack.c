#include"SqStack.h"
#include <stdio.h>
#include <stdlib.h>
Status initStack(SqStack* s, int sizes) {//��ʼ��ջ
	s->elem = (ElemType*)malloc(sizes * sizeof(ElemType));//�����ڴ�ռ�
	if (!s->elem)
		return ERROR;//����ָ��û�з��䵽�ռ䣬����
	s->top = -1;//��ջ��ʱΪ��ջʱ��ջ��ָ�� top = -1 
	s->size = sizes;//����ջ�Ĵ�С
	return SUCCESS;
}
Status isEmptyStack(SqStack* s)//Ҫ�ж�ջ�Ƿ�Ϊ�գ�˳��ջ���ǿ� s->top �ǲ��ǵ��� -1
{
	if (s->elem==NULL) {//��ʵ�������һ���жϺ���������д�ˣ�ֱ�Ӹ���ճ����������ֻ������ȥ�ж��㵽����û�д���˳��ջ
		printf("�������롾1������˳��ջ��\n");
	}
	else if (s->top == -1) {
		printf("����һ����ջ��\n");
		return SUCCESS;
	}
	else {
		printf("�ⲻ��һ����ջ��\n");
		return ERROR;
	}
}
Status getTopStack(SqStack* s, ElemType* e)
{
	if (s->elem==NULL) {
		printf("�������롾1������˳��ջ��\n");
	}
	else if (s->top == -1) {
		printf("����һ����ջ��\n");
		return ERROR;
	}
	else {
		*e = s->elem[s->top];//eָ�뷵��ջ��Ԫ�ص�ַ
		printf("ջ��Ԫ��Ϊ��%d\n", *e);
		return SUCCESS;
	}

}
Status clearStack(SqStack* s)
{
	if (s->elem==NULL) {
		printf("�������롾1������˳��ջ��\n");
		return ERROR;
	}
	else if (s->top == -1) {
		printf("����һ����ջ��\n");
		return ERROR;
	}
	else {
		s->top = -1;//ջ��ָ����Ϊջ�ı߽�
		printf("��ճɹ���\n");
		return SUCCESS;
	}
}
Status destroyStack(SqStack* s)
{
	if (s->elem==NULL) {
		printf("�������롾1������˳��ջ��\n");
		return ERROR;
	}
	else {
		free(s->elem);//����Ŀռ�ȫ�ͷ�
		s->elem = NULL;
		printf("���ٳɹ���\n");
		return SUCCESS;
	}
}
Status stackLength(SqStack* s, int* length)
{
	if (s->elem==NULL) {
		printf("�������롾1������˳��ջ��\n");
		return ERROR;
	}
	else {
		*length = s->top + 1;
		printf("���˳��ջ���ڵ�ջ��Ϊ��%d\n",*length);
		return SUCCESS;
	}
}
Status pushStack(SqStack* s, ElemType data,char c[])
{
	if (s->top == s->size - 1)		//�ж�ջ�Ƿ�����
	{
		printf("ջ������\n");
		return ERROR;
	}
	else if (s->elem==NULL) {
		printf("�������롾1������˳��ջ��\n");
		return ERROR;
	}
	else {
		printf("\n����Ҫ���ӵ������ǣ�");
		checkinput(&data);
		s->top++;
		s->elem[s->top] = data;
		printf("\n���ݡ�%d��ѹջ�ɹ�\n", data);
		return SUCCESS;
	}
}
Status popStack(SqStack* s)
{
	if (s->top == -1) {
		printf("����һ����ջ��\n");
		return ERROR;
	}
	else if (s->elem==NULL) {
		printf("�������롾1������˳��ջ��\n");
		return ERROR;
	}
	else {
		printf("���ݡ�%d����ջ�ɹ���\n", s->elem[s->top]);
		s->top--;
		return SUCCESS;
	}
}
void outStack(SqStack* s) {
	int i;
	if (s->top==-1) {
		printf("\n����һ����ջ��\n");
	}
	else if(!s->elem){
		return;
	}
	else {
		for (i = 0; i <= s->top; i++) {
			printf("\n��%d�������ǣ�%d\n", i + 1, s->elem[i]);
		}
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
