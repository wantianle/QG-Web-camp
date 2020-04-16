#include<stdio.h>
#include<stdlib.h>
#include "Linkedlist.h"
int main() {
	int num = 0, sizes = 0, elem = 0;
	ElemType data = 0;
	LinkedList* L = (LinkedList*)malloc(sizeof(LinkedList*));
	*L = NULL;
	while (1) {
		system("cls");
		printf("\t\t\t|----------------------------------|\n");
		printf("\t\t\t|         单链表基本操作           |\n");
		printf("\t\t\t|----------------------------------|\n");
		printf("\t\t\t|      1---建立链表                |\n");
		printf("\t\t\t|      2---销毁链表                |\n");
		printf("\t\t\t|      3---指定位置插入            |\n");
		printf("\t\t\t|      4---指定位置删除            |\n");
		printf("\t\t\t|      5---遍历打印链表            |\n");
		printf("\t\t\t|      6---搜索链表元素            |\n");
		printf("\t\t\t|      7---单链表反转              |\n");
		printf("\t\t\t|      8---判断是否为循环链表      |\n");
		printf("\t\t\t|      9---链表奇偶数节点反转      |\n");
		printf("\t\t\t|      10---搜索链表的中间结点     |\n");
		printf("\t\t\t|      11---退出                   |\n");
		printf("\t\t\t|----------------------------------|\n");
		printf("\t\t\t|                 QG前端组万天乐   |\n");
		printf("\t\t\t|----------------------------------|\n");
		printf("\n请选择操作:\n");
		checkinput(&num);
		if (num >= 1 && num <= 11) {
			switch (num) {
			case 1: {
				if (*L) {
					printf("\n已存在一个单链表，请先销毁此链表！\n");
				}
				else {
					printf("请输入初始链表的节点个数：");
					checkinput(&sizes);
					InitList(L, sizes);
				}
				break;
			}
			case 2: {
				DestroyList(L);
				break;
			}
			case 3: {
				int i=InsertList(L, sizes);
				if (i == SUCCESS) {
					++sizes;
					TraverseList(L, sizes);
				}
				break;
			}
			case 4: {
				int i=DeleteList(L, sizes);
				if (i == SUCCESS) {
					--sizes;
					TraverseList(L, sizes);
				}
				break;
			}
			case 5: {
				TraverseList(L,sizes);
				break;
			}
			case 6: {
				SearchList(L, elem, sizes);
				break;
			}
			case 7: {
				ReverseList(L,sizes);
				break;
			}
			case 8: {
				IsLoopList(L);
				break;
			}
			case 9: {
				ReverseEvenList(L,sizes);
				break;
			}
			case 10: {
				FindMidNode(L,sizes);
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