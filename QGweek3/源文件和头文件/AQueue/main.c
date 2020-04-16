#include"AQueue.h"
#include<stdio.h>
#include<stdlib.h>
int main() {
	int num = 0;
	AQueue* Q = (AQueue*)malloc(sizeof(AQueue));
	Q->length=0;
	Q->data[0] = NULL;
	while (1) {
		system("cls");
		printf("\t\t\t|----------------------------------|\n");
		printf("\t\t\t|         循环队列基本操作         |\n");
		printf("\t\t\t|----------------------------------|\n");
		printf("\t\t\t|      1---建立队列                |\n");
		printf("\t\t\t|      2---销毁队列                |\n");
		printf("\t\t\t|      3---判断满队列              |\n");
		printf("\t\t\t|      4---判断空队列              |\n");
		printf("\t\t\t|      5---获得队头元素            |\n");
		printf("\t\t\t|      6---获得队列长度            |\n");
		printf("\t\t\t|      7---入队                    |\n");
		printf("\t\t\t|      8---出队                    |\n");
		printf("\t\t\t|      9---清空队列                |\n");
		printf("\t\t\t|      10---遍历打印队列           |\n");
		printf("\t\t\t|      11---退出                   |\n");
		printf("\t\t\t|----------------------------------|\n");
		printf("\t\t\t|                 QG前端组万天乐   |\n");
		printf("\t\t\t|----------------------------------|\n");
		printf("\n请选择操作:\n");
		checkinput(&num);
		if (num >= 1 && num <= 11) {
			switch (num) {
			case 1: {
				if (Q->data[0] != NULL) {
					printf("\n已存在一个队列，请先销毁此链表！\n");
				}
				else {
					InitAQueue(Q);
				}
				break;
			}
			case 2: {
				DestoryAQueue(Q);
				break;
			}
			case 3: {
				IsFullAQueue(Q);
				break;
			}
			case 4: {
				IsEmptyAQueue(Q);
				break;
			}
			case 5: {
				GetHeadAQueue(Q);
				break;
			}
			case 6: {
				LengthAQueue(Q);
				break;
			}
			case 7: {
				if (Q->data[0] == NULL) {
					printf("\n请先输入【1】创建链队列\n");
				}
				else if (Q->length == MAXQUEUE - 1)
				{
					printf("队列满了！不能再入队了！\n");
				}
				else {
					CheckType(Q);
				}
				break;
			}
			case 8: {
				DeAQueue(Q);
				break;
			}
			case 9: {
				ClearAQueue(Q);
				break;
			}
			case 10: {
				TraverseAQueue(Q);
				break;
			}
			case 11:
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


