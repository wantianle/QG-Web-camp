#include"LQueue.h"
#include<stdio.h>
#include<stdlib.h>
int main() {
	int num = 0;
	LQueue* Q= (LQueue*)malloc(sizeof(LQueue));
	Q->length = 0;
	Q->front = NULL;
	Q->rear= NULL;
	while (1) {
		system("cls");
		printf("\t\t\t|----------------------------------|\n");
		printf("\t\t\t|         链队列基本操作           |\n");
		printf("\t\t\t|----------------------------------|\n");
		printf("\t\t\t|      1---建立链队列              |\n");
		printf("\t\t\t|      2---销毁链队列              |\n");
		printf("\t\t\t|      3---判断空队列              |\n");
		printf("\t\t\t|      4---获得队头元素            |\n");
		printf("\t\t\t|      5---获得队列长度            |\n");
		printf("\t\t\t|      6---入队                    |\n");
		printf("\t\t\t|      7---出队                    |\n");
		printf("\t\t\t|      8---清空链队列              |\n");
		printf("\t\t\t|      9---遍历打印队列            |\n");
		printf("\t\t\t|      10---退出                   |\n");
		printf("\t\t\t|----------------------------------|\n");
		printf("\t\t\t|                 QG前端组万天乐   |\n");
		printf("\t\t\t|----------------------------------|\n");
		printf("\n请选择操作:\n");
		checkinput(&num);
		if (num >= 1 && num <= 10) {
			switch (num) {
			case 1: {
				if (Q->front) {
					printf("\n已存在一个队列，请先销毁此链表！\n");
				}
				else {
					printf("请输入初始队列长度：");
					checkinput(&Q->length);
					InitLQueue(Q);
				}
				break;
			}
			case 2: {
				DestoryLQueue(Q);
				break;
			}
			case 3: {
				IsEmptyLQueue(Q);
				break;
			}
			case 4: {
				GetHeadLQueue(Q);
				break;
			}
			case 5: {
				LengthLQueue(Q);
				break;
			}
			case 6: {
				if (!Q->front) {
					printf("\n请先输入【1】创建链队列\n");
				}
				else {
					CheckType(Q);
					Q->length++;
				}
				break;
			}
			case 7: {
				DeLQueue(Q);
				Q->length--;
				break;
			}
			case 8: {
				ClearLQueue(Q);
				break;
			}
			case 9: {
				TraverseLQueue(Q);
				break;
			}
			case 10:
				system("cls");
				printf("\n\n\n\n\n\n\t\t\t尚有很多不足之处，望多多指教!\n\n\n\n\n\n");
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