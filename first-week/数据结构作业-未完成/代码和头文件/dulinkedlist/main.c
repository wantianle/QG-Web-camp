#include "../head/duLinkedList.h"
#include <stdio.h>
#include <stdlib.h>
int main() {

	int Now;
	LNode* L = (struct LNode*)malloc(sizeof(struct LNode));
	char yes_no = 'y';
	while (yes_no == 'y' || yes_no == 'Y') {                           //ѭ����ʼ
		system("cls");
		printf("\t\t\t|---------------------------------|\n");       //����ʽ����
		printf("\t\t\t|         ˫�������������         |\n");
		printf("\t\t\t|---------------------------------|\n");
		printf("\t\t\t|      1---��������                |\n");
		printf("\t\t\t|      2---��������                |\n");
		printf("\t\t\t|      3---ͷλ�ò���              |\n");
		printf("\t\t\t|      4---βλ�ò���              |\n");
		printf("\t\t\t|      5---ָ��λ��ɾ��            |\n");
		printf("\t\t\t|      6---������ӡ����            |\n");
		printf("\t\t\t|      0---�˳�                   |\n");
		printf("\t\t\t|---------------------------------|\n");
		printf("\t\t\t|                 QGǰ����������^_^|\n");
		printf("\t\t\t|---------------------------------|\n");
		printf("��ѡ�����:\n");
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
			printf("\n\n\n\t\t\t���кܶ಻��֮���������ָ��!");
			exit(0);
			break;
		default:
			printf(" ��������ȷ�����֡�\n\n");    //��������
		}
		printf("\n\n\t\t�Ƿ��������������'Y'��'y'�����������ַ��˳�����\n");  //ѭ��ѡ��
		getchar();
		scanf("%c", &yes_no);
	}
	return 0;
}