#include"LinkStack.h"
#include <stdio.h>
#include <stdlib.h>
int main() {
	int i, num,sizes;
	int* length = (int*)malloc(sizeof(int));
	ElemType data = 0;
	ElemType* e = (ElemType*)malloc(sizeof(ElemType));
	LinkStack* s = (LinkStack*)malloc(sizeof(LinkStack*));
	s->top = NULL;
	while (1) {
		system("cls");
		printf("\t\t\t|----------------------------------|\n");
		printf("\t\t\t|           链栈基本操作           |\n");
		printf("\t\t\t|----------------------------------|\n");
		printf("\t\t\t|      1---创建链栈                |\n");
		printf("\t\t\t|      2---判断是否为空            |\n");
		printf("\t\t\t|      3---得到栈顶元素            |\n");
		printf("\t\t\t|      4---清空链栈                |\n");
		printf("\t\t\t|      5---销毁链栈                |\n");
		printf("\t\t\t|      6---获取栈长                |\n");
		printf("\t\t\t|      7---压栈                    |\n");
		printf("\t\t\t|      8---出栈                    |\n");
		printf("\t\t\t|      9---遍历输出                |\n");
		printf("\t\t\t|      10---退出                   |\n");
		printf("\t\t\t|----------------------------------|\n");
		printf("\t\t\t|                     QG前端万天乐 |\n");
		printf("\t\t\t|----------------------------------|\n");
		printf("\n请选择操作:\n");
		checkinput(&num);
		if (num >= 1 && num <= 10) {
			switch (num) {
			case 1: {
				if (s->top != NULL) {
					printf("\n已存在一个链栈，请先销毁此栈！\n");
				}
				else {
					printf("请输入你的顺序栈长度：");
					initLStack(s);
					checkinput(&sizes);
					if (sizes>= 0) {
						for (i = 0; i < sizes; i++) {
							pushLStack(s);
						}
						printf("\n链栈创建成功\n");
					}
					else {
						printf("\n链栈初始化失败，长度输入错误！\n");
					}
				}
				break;
			}
			case 2: {
				isEmptyLStack(s);
				break;
			}
			case 3: {
				getTopLStack(s);
				break;
			}
			case 4: {
				clearLStack(s);
				break;
			}
			case 5: {
				destroyLStack(s);
				break;
			}
			case 6: {
				LStackLength(s);
				break;
			}
			case 7: {
				pushLStack(s);
				break;
			}
			case 8: {
				popLStack(s);
				break;
			}
			case 9: {
				TraverseStack(s);
				break;
			}
			case 10:
				destroyLStack(s);
				system("cls");
				printf("\n\n\n\n\n\n\n\t\t\t\t尚有很多不足之处，望多多指教!\n\n\n\n\n\n\n");
				exit(0);
				break;
			}
		}
		else
		{
			printf("\n请输入正确的数字。\n");    //错误提醒
		}
		system("pause");
	}
	return 0;
}
