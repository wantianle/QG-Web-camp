#include<stdio.h>
#include<stdlib.h>
#include "../First assignment/Linkedlist.h"
int main() {
	LNode* p = NULL;
	LNode* q = NULL;
	int n = 0;
	int Data = 0;
	int e = 0;
	int* c = NULL;
	int Now;
	LNode* L = (struct LNode*)malloc(sizeof(struct LNode));
	char yes_no = 'y';
	while (yes_no == 'y' || yes_no == 'Y') {                           //循坏开始
		system("cls");
		printf("\t\t\t|----------------------------------|\n");       //交互式界面
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
		printf("\t\t\t|      10---搜索链表的中间结点      |\n");
		printf("\t\t\t|      0---退出                    |\n");
		printf("\t\t\t|----------------------------------|\n");
		printf("\t\t\t|                 QG前端组万天乐^_^|\n");
		printf("\t\t\t|----------------------------------|\n");
		printf("\n请选择操作:\n");
		scanf_s("%d", &Now);
		switch (Now) {
		case 1: {
			InitList(L);
			printf("\n链表创建成功\n");
			DisPlay(L);
			break;
		}
		case 2: {
			DestroyList(L);
			printf("\n链表销毁成功\n");
			break;
		}
		case 3: {
			printf("你要在哪个位置后插入节点：\n");
			scanf_s("%d", &n);
			p = L;
			for (int i = 0; i < n - 1 && p != NULL; i++) {
				p = p->next;
			}
			InsertList(p, q);
			printf("\n你要插入的数据是：\n");
			scanf_s("%d", &Data);
			q->data = Data;
			printf("\n节点插入成功\n");
			DisPlay(L);
			break;
		}
		case 4: {
			DeleteList(p, c);
			printf("\n节点删除成功\n");
			DisPlay(L);
			break;
		}
		case 5: {
			TraverseList(L, visit(e));
			printf("\n链表遍历成功，如下：\n");
			DisPlay(L);
			break;
		}
		case 6: {
			printf("你想要搜索的元素的值是：\n");
			scanf_s("%d", &e);
			SearchList(L, e);
			printf("\n元素搜索成功\n");
			break;
		}
		case 7: {
			ReverseList(L);
			printf("\n链表反转成功\n");
			DisPlay(L);
			break;
		}
		case 8: {
			IsLoopList(L);
			printf("\n链表为空\n");
			break;
		}
		case 9: {
			ReverseEvenList(L);
			printf("\n链表奇偶节点反转成功\n");
			DisPlay(L);
			break;
		}
		case 10: {
			FindMidNode(L);
			printf("\n链表中间节点查找为\n");
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
		printf("\n\n是否继续操作（输入'Y'或'y'继续，其它字符退出）？\n");  //循环选择
		getchar();
		scanf_s("%c", &yes_no);
	}
	return 0;
}