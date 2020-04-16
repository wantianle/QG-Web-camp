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
		printf("\t\t\t|         ѭ�����л�������         |\n");
		printf("\t\t\t|----------------------------------|\n");
		printf("\t\t\t|      1---��������                |\n");
		printf("\t\t\t|      2---���ٶ���                |\n");
		printf("\t\t\t|      3---�ж�������              |\n");
		printf("\t\t\t|      4---�жϿն���              |\n");
		printf("\t\t\t|      5---��ö�ͷԪ��            |\n");
		printf("\t\t\t|      6---��ö��г���            |\n");
		printf("\t\t\t|      7---���                    |\n");
		printf("\t\t\t|      8---����                    |\n");
		printf("\t\t\t|      9---��ն���                |\n");
		printf("\t\t\t|      10---������ӡ����           |\n");
		printf("\t\t\t|      11---�˳�                   |\n");
		printf("\t\t\t|----------------------------------|\n");
		printf("\t\t\t|                 QGǰ����������   |\n");
		printf("\t\t\t|----------------------------------|\n");
		printf("\n��ѡ�����:\n");
		checkinput(&num);
		if (num >= 1 && num <= 11) {
			switch (num) {
			case 1: {
				if (Q->data[0] != NULL) {
					printf("\n�Ѵ���һ�����У��������ٴ�����\n");
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
					printf("\n�������롾1������������\n");
				}
				else if (Q->length == MAXQUEUE - 1)
				{
					printf("�������ˣ�����������ˣ�\n");
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


