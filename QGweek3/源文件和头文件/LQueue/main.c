#include"LQueue.h"
#include<stdio.h>
#include<stdlib.h>
int main() {
	int num = 0;
	LQueue* Q= (LQueue*)malloc(sizeof(LQueue));
	Q->length = 0;
	Q->front = NULL;
	Q->rear= NULL;
	while (1) {
		system("cls");
		printf("\t\t\t|----------------------------------|\n");
		printf("\t\t\t|         �����л�������           |\n");
		printf("\t\t\t|----------------------------------|\n");
		printf("\t\t\t|      1---����������              |\n");
		printf("\t\t\t|      2---����������              |\n");
		printf("\t\t\t|      3---�жϿն���              |\n");
		printf("\t\t\t|      4---��ö�ͷԪ��            |\n");
		printf("\t\t\t|      5---��ö��г���            |\n");
		printf("\t\t\t|      6---���                    |\n");
		printf("\t\t\t|      7---����                    |\n");
		printf("\t\t\t|      8---���������              |\n");
		printf("\t\t\t|      9---������ӡ����            |\n");
		printf("\t\t\t|      10---�˳�                   |\n");
		printf("\t\t\t|----------------------------------|\n");
		printf("\t\t\t|                 QGǰ����������   |\n");
		printf("\t\t\t|----------------------------------|\n");
		printf("\n��ѡ�����:\n");
		checkinput(&num);
		if (num >= 1 && num <= 10) {
			switch (num) {
			case 1: {
				if (Q->front) {
					printf("\n�Ѵ���һ�����У��������ٴ�����\n");
				}
				else {
					printf("�������ʼ���г��ȣ�");
					checkinput(&Q->length);
					InitLQueue(Q);
				}
				break;
			}
			case 2: {
				DestoryLQueue(Q);
				break;
			}
			case 3: {
				IsEmptyLQueue(Q);
				break;
			}
			case 4: {
				GetHeadLQueue(Q);
				break;
			}
			case 5: {
				LengthLQueue(Q);
				break;
			}
			case 6: {
				if (!Q->front) {
					printf("\n�������롾1������������\n");
				}
				else {
					CheckType(Q);
					Q->length++;
				}
				break;
			}
			case 7: {
				DeLQueue(Q);
				Q->length--;
				break;
			}
			case 8: {
				ClearLQueue(Q);
				break;
			}
			case 9: {
				TraverseLQueue(Q);
				break;
			}
			case 10:
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