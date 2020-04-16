#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef enum Status 
{
    ERROR = 0, 
	SUCCESS = 1
} Status;

typedef int ElemType;

typedef  struct StackNode
{
	ElemType data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr top;
	int	count;
}LinkStack;

//��ջ
Status initLStack(LinkStack *s);//��ʼ��ջ

Status isEmptyLStack(LinkStack *s);//�ж�ջ�Ƿ�Ϊ��

Status getTopLStack(LinkStack *s);//�õ�ջ��Ԫ��

Status clearLStack(LinkStack *s);//���ջ

Status destroyLStack(LinkStack *s);//����ջ

Status LStackLength(LinkStack *s);//���ջ��

Status pushLStack(LinkStack *s);//��ջ

Status popLStack(LinkStack *s);//��ջ

void TraverseStack(LinkStack* s);

void checkinput(int* r);
#endif 
