#include "duLinkedList.h"
#include <stdio.h>
#include <stdlib.h>
int main() {
	int num = 0, sizes = 0, elem = 0;
	ElemType data = 0;
	DuLinkedList* L = (DuLinkedList*)malloc(sizeof(DuLinkedList*));
	*L = NULL;
	while (1) { 
		system("cls");
		printf("\t\t\t|---------------------------------|\n");
		printf("\t\t\t|         双向链表基本操作        |\n");
		printf("\t\t\t|---------------------------------|\n");
		printf("\t\t\t|      1---建立链表               |\n");
		printf("\t\t\t|      2---销毁链表               |\n");
		printf("\t\t\t|      3---插入指定位置之前       |\n");
		printf("\t\t\t|      4---插入指定位置之后       |\n");
		printf("\t\t\t|      5---指定位置删除           |\n");
		printf("\t\t\t|      6---遍历打印链表           |\n");
		printf("\t\t\t|      7---退出                   |\n");
		printf("\t\t\t|---------------------------------|\n");
		printf("\t\t\t|                 QG前端组万天乐  |\n");
		printf("\t\t\t|---------------------------------|\n");
		printf("请选择操作:\n");
		checkinput(&num);
		if (num >= 1 && num <= 11) {
			switch (num) {
			case 1: {
				if (*L) {
					printf("\n已存在一个双链表，请先销毁此链表！\n");
				}
				else {
					printf("请输入初始链表的节点个数：");
					checkinput(&sizes);
					InitList_DuL(L, sizes);
				}
				break;
			}
			case 2: {
				DestroyList_DuL(L);
				break;
			}
			case 3: {
				int i = InsertBeforeList_DuL(L, sizes);
				if (i == SUCCESS) {
					++sizes;
					TraverseList_DuL(L, sizes);
				}
				break;
			}
			case 4: {
				int i = InsertAfterList_DuL(L, sizes);
				if (i == SUCCESS) {
					++sizes;
					TraverseList_DuL(L, sizes);
				}
				break;
			}
			case 5: {
				int i = DeleteList_DuL(L, sizes);
				if (i == SUCCESS) {
					--sizes;
					TraverseList_DuL(L, sizes);
				}
				break;
			}
			case 6: {
				TraverseList_DuL(L, sizes);
				break;
			}
			case 7:
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