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
		printf("\t\t\t|         ˫�������������        |\n");
		printf("\t\t\t|---------------------------------|\n");
		printf("\t\t\t|      1---��������               |\n");
		printf("\t\t\t|      2---��������               |\n");
		printf("\t\t\t|      3---����ָ��λ��֮ǰ       |\n");
		printf("\t\t\t|      4---����ָ��λ��֮��       |\n");
		printf("\t\t\t|      5---ָ��λ��ɾ��           |\n");
		printf("\t\t\t|      6---������ӡ����           |\n");
		printf("\t\t\t|      7---�˳�                   |\n");
		printf("\t\t\t|---------------------------------|\n");
		printf("\t\t\t|                 QGǰ����������  |\n");
		printf("\t\t\t|---------------------------------|\n");
		printf("��ѡ�����:\n");
		checkinput(&num);
		if (num >= 1 && num <= 11) {
			switch (num) {
			case 1: {
				if (*L) {
					printf("\n�Ѵ���һ��˫�����������ٴ�����\n");
				}
				else {
					printf("�������ʼ����Ľڵ������");
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