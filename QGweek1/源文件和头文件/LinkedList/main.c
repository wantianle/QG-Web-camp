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
		printf("\t\t\t|      10---����������м���     |\n");
		printf("\t\t\t|      11---�˳�                   |\n");
		printf("\t\t\t|----------------------------------|\n");
		printf("\t\t\t|                 QGǰ����������   |\n");
		printf("\t\t\t|----------------------------------|\n");
		printf("\n��ѡ�����:\n");
		checkinput(&num);
		if (num >= 1 && num <= 11) {
			switch (num) {
			case 1: {
				if (*L) {
					printf("\n�Ѵ���һ���������������ٴ�����\n");
				}
				else {
					printf("�������ʼ����Ľڵ������");
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
				printf("\n\n\n\n\n\n\t\t\t���кܶ಻��֮���������ָ��!\n\n\n\n\n\n");
				exit(0);
				break;
			}
		}
		else
		{
			printf("\n��������ȷ�����֡�\n");    //��������
		}
		system("pause");
	}
	return 0;
}