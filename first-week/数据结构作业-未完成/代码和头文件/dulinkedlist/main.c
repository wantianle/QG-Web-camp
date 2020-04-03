#include "../head/duLinkedList.h"
#include <stdio.h>
#include <stdlib.h>
int main() {

	int Now;
	LNode* L = (struct LNode*)malloc(sizeof(struct LNode));
	char yes_no = 'y';
	while (yes_no == 'y' || yes_no == 'Y') {                           //循坏开始
		system("cls");
		printf("\t\t\t|---------------------------------|\n");       //交互式界面
		printf("\t\t\t|         双向链表基本操作         |\n");
		printf("\t\t\t|---------------------------------|\n");
		printf("\t\t\t|      1---建立链表                |\n");
		printf("\t\t\t|      2---销毁链表                |\n");
		printf("\t\t\t|      3---头位置插入              |\n");
		printf("\t\t\t|      4---尾位置插入              |\n");
		printf("\t\t\t|      5---指点位置删除            |\n");
		printf("\t\t\t|      6---遍历打印链表            |\n");
		printf("\t\t\t|      0---退出                   |\n");
		printf("\t\t\t|---------------------------------|\n");
		printf("\t\t\t|                 QG前端组万天乐^_^|\n");
		printf("\t\t\t|---------------------------------|\n");
		printf("请选择操作:\n");
		scanf("%d", &Now);
		switch (Now) {
		case 1: {

			break;
		}
		case 2: {

			break;
		}
		case 3: {

			break;
		}
		case 4: {

			break;
		}
		case 5: {

			break;
		}
		case 6: {

			break;
		}
		case 0:
			system("cls");
			printf("\n\n\n\t\t\t尚有很多不足之处，望多多指教!");
			exit(0);
			break;
		default:
			printf(" 请输入正确的数字。\n\n");    //错误提醒
		}
		printf("\n\n\t\t是否继续操作（输入'Y'或'y'继续，其它字符退出）？\n");  //循环选择
		getchar();
		scanf("%c", &yes_no);
	}
	return 0;
}