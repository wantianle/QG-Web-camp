#include"SqStack.h"
#include <stdio.h>
#include <stdlib.h>
int main() {
	int i,num;
	int* length = (int*)malloc(sizeof(int));
	ElemType sizes;
	ElemType data=0;
	ElemType* e = (ElemType*)malloc(sizeof(ElemType));
	SqStack *s=(SqStack*)malloc(sizeof(SqStack));
	s->elem=NULL;
	while (1) {
		system("cls");
		printf("\t\t\t|----------------------------------|\n");
		printf("\t\t\t|         顺序栈基本操作           |\n");
		printf("\t\t\t|----------------------------------|\n");
		printf("\t\t\t|      1---创建顺序栈              |\n");
		printf("\t\t\t|      2---判断是否为空            |\n");
		printf("\t\t\t|      3---得到栈顶元素            |\n");
		printf("\t\t\t|      4---清空顺序栈              |\n");
		printf("\t\t\t|      5---销毁顺序栈              |\n");
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
				if (s->elem!=NULL) {
					printf("\n已存在一个顺序栈，请先销毁此栈！\n");
				}
				else {
					printf("请输入你的顺序栈长度：");
					checkinput(&sizes);
					if (sizes >= 0) {
						initStack(s, sizes);
						for (i = 0; i < sizes; i++) {
							pushStack(s, data);
						}
						printf("\n顺序栈创建成功\n");
						outStack(s);
					}
					else {
						printf("\n顺序栈初始化失败，长度输入错误！\n");
					}
				}
				break;
			}
			case 2: {
				isEmptyStack(s);
				break;
			}
			case 3: {
				getTopStack(s, e);
				outStack(s);
				break;
			}
			case 4: {
				clearStack(s);
				break;
			}
			case 5: {
				destroyStack(s);
				break;
			}
			case 6: {
				stackLength(s, length);
				break;
			}
			case 7: {
				pushStack(s, data);
				break;
			}
			case 8: {
				popStack(s);
				break;
			}
			case 9: {
				outStack(s);
				break;
			}
			case 10: 
				destroyStack(s);
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
