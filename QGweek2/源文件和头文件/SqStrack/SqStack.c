#include"SqStack.h"
#include <stdio.h>
#include <stdlib.h>
Status initStack(SqStack* s, int sizes) {//初始化栈
	s->elem = (ElemType*)malloc(sizes * sizeof(ElemType));//分配内存空间
	if (!s->elem)
		return ERROR;//数据指针没有分配到空间，报错
	s->top = -1;//若栈此时为空栈时，栈顶指针 top = -1 
	s->size = sizes;//定义栈的大小
	return SUCCESS;
}
Status isEmptyStack(SqStack* s)//要判断栈是否为空，顺序栈就是看 s->top 是不是等于 -1
{
	if (s->elem==NULL) {//其实可以设计一个判断函数，懒得写了，直接复制粘贴，而且我只能这样去判断你到底有没有创建顺序栈
		printf("请先输入【1】创建顺序栈！\n");
	}
	else if (s->top == -1) {
		printf("这是一个空栈！\n");
		return SUCCESS;
	}
	else {
		printf("这不是一个空栈！\n");
		return ERROR;
	}
}
Status getTopStack(SqStack* s, ElemType* e)
{
	if (s->elem==NULL) {
		printf("请先输入【1】创建顺序栈！\n");
	}
	else if (s->top == -1) {
		printf("这是一个空栈！\n");
		return ERROR;
	}
	else {
		*e = s->elem[s->top];//e指针返回栈顶元素地址
		printf("栈顶元素为：%d\n", *e);
		return SUCCESS;
	}

}
Status clearStack(SqStack* s)
{
	if (s->elem==NULL) {
		printf("请先输入【1】创建顺序栈！\n");
		return ERROR;
	}
	else if (s->top == -1) {
		printf("这是一个空栈！\n");
		return ERROR;
	}
	else {
		s->top = -1;//栈顶指针作为栈的边界
		printf("清空成功！\n");
		return SUCCESS;
	}
}
Status destroyStack(SqStack* s)
{
	if (s->elem==NULL) {
		printf("请先输入【1】创建顺序栈！\n");
		return ERROR;
	}
	else {
		free(s->elem);//申请的空间全释放
		s->elem = NULL;
		printf("销毁成功！\n");
		return SUCCESS;
	}
}
Status stackLength(SqStack* s, int* length)
{
	if (s->elem==NULL) {
		printf("请先输入【1】创建顺序栈！\n");
		return ERROR;
	}
	else {
		*length = s->top + 1;
		printf("你的顺序栈现在的栈长为：%d\n",*length);
		return SUCCESS;
	}
}
Status pushStack(SqStack* s, ElemType data,char c[])
{
	if (s->top == s->size - 1)		//判断栈是否已满
	{
		printf("栈已满！\n");
		return ERROR;
	}
	else if (s->elem==NULL) {
		printf("请先输入【1】创建顺序栈！\n");
		return ERROR;
	}
	else {
		printf("\n你想要增加的数据是：");
		checkinput(&data);
		s->top++;
		s->elem[s->top] = data;
		printf("\n数据【%d】压栈成功\n", data);
		return SUCCESS;
	}
}
Status popStack(SqStack* s)
{
	if (s->top == -1) {
		printf("这是一个空栈！\n");
		return ERROR;
	}
	else if (s->elem==NULL) {
		printf("请先输入【1】创建顺序栈！\n");
		return ERROR;
	}
	else {
		printf("数据【%d】出栈成功！\n", s->elem[s->top]);
		s->top--;
		return SUCCESS;
	}
}
void outStack(SqStack* s) {
	int i;
	if (s->top==-1) {
		printf("\n这是一个空栈！\n");
	}
	else if(!s->elem){
		return;
	}
	else {
		for (i = 0; i <= s->top; i++) {
			printf("\n第%d个数据是：%d\n", i + 1, s->elem[i]);
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
		if (error) printf("输入错误，请重新输入！\n");
	} while (error);
	*r = atoi(c);
}
