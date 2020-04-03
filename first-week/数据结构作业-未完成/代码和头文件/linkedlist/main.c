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
	while (yes_no == 'y' || yes_no == 'Y') {                           //ѭ����ʼ
		system("cls");
		printf("\t\t\t|----------------------------------|\n");       //����ʽ����
		printf("\t\t\t|         �������������           |\n");
		printf("\t\t\t|----------------------------------|\n");
		printf("\t\t\t|      1---��������                |\n");
		printf("\t\t\t|      2---��������                |\n");
		printf("\t\t\t|      3---ָ��λ�ò���            |\n");
		printf("\t\t\t|      4---ָ��λ��ɾ��            |\n");
		printf("\t\t\t|      5---������ӡ����            |\n");
		printf("\t\t\t|      6---��������Ԫ��            |\n");
		printf("\t\t\t|      7---������ת              |\n");
		printf("\t\t\t|      8---�ж��Ƿ�Ϊѭ������      |\n");
		printf("\t\t\t|      9---������ż���ڵ㷴ת      |\n");
		printf("\t\t\t|      10---����������м���      |\n");
		printf("\t\t\t|      0---�˳�                    |\n");
		printf("\t\t\t|----------------------------------|\n");
		printf("\t\t\t|                 QGǰ����������^_^|\n");
		printf("\t\t\t|----------------------------------|\n");
		printf("\n��ѡ�����:\n");
		scanf_s("%d", &Now);
		switch (Now) {
		case 1: {
			InitList(L);
			printf("\n�������ɹ�\n");
			DisPlay(L);
			break;
		}
		case 2: {
			DestroyList(L);
			printf("\n�������ٳɹ�\n");
			break;
		}
		case 3: {
			printf("��Ҫ���ĸ�λ�ú����ڵ㣺\n");
			scanf_s("%d", &n);
			p = L;
			for (int i = 0; i < n - 1 && p != NULL; i++) {
				p = p->next;
			}
			InsertList(p, q);
			printf("\n��Ҫ����������ǣ�\n");
			scanf_s("%d", &Data);
			q->data = Data;
			printf("\n�ڵ����ɹ�\n");
			DisPlay(L);
			break;
		}
		case 4: {
			DeleteList(p, c);
			printf("\n�ڵ�ɾ���ɹ�\n");
			DisPlay(L);
			break;
		}
		case 5: {
			TraverseList(L, visit(e));
			printf("\n��������ɹ������£�\n");
			DisPlay(L);
			break;
		}
		case 6: {
			printf("����Ҫ������Ԫ�ص�ֵ�ǣ�\n");
			scanf_s("%d", &e);
			SearchList(L, e);
			printf("\nԪ�������ɹ�\n");
			break;
		}
		case 7: {
			ReverseList(L);
			printf("\n����ת�ɹ�\n");
			DisPlay(L);
			break;
		}
		case 8: {
			IsLoopList(L);
			printf("\n����Ϊ��\n");
			break;
		}
		case 9: {
			ReverseEvenList(L);
			printf("\n������ż�ڵ㷴ת�ɹ�\n");
			DisPlay(L);
			break;
		}
		case 10: {
			FindMidNode(L);
			printf("\n�����м�ڵ����Ϊ\n");
			break;
		}
		case 0:
			system("cls");
			printf("\n\n\n\t\t\t���кܶ಻��֮���������ָ��!");
			exit(0);
			break;
		default:
			printf(" ��������ȷ�����֡�\n\n");    //��������
		}
		printf("\n\n�Ƿ��������������'Y'��'y'�����������ַ��˳�����\n");  //ѭ��ѡ��
		getchar();
		scanf_s("%c", &yes_no);
	}
	return 0;
}