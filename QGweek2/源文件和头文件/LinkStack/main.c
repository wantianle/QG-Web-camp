#include"LinkStack.h"
#include <stdio.h>
#include <stdlib.h>
int main() {
	int i, num,sizes;
	int* length = (int*)malloc(sizeof(int));
	ElemType data = 0;
	ElemType* e = (ElemType*)malloc(sizeof(ElemType));
	LinkStack* s = (LinkStack*)malloc(sizeof(LinkStack*));
	s->top = NULL;
	while (1) {
		system("cls");
		printf("\t\t\t|----------------------------------|\n");
		printf("\t\t\t|           ��ջ��������           |\n");
		printf("\t\t\t|----------------------------------|\n");
		printf("\t\t\t|      1---������ջ                |\n");
		printf("\t\t\t|      2---�ж��Ƿ�Ϊ��            |\n");
		printf("\t\t\t|      3---�õ�ջ��Ԫ��            |\n");
		printf("\t\t\t|      4---�����ջ                |\n");
		printf("\t\t\t|      5---������ջ                |\n");
		printf("\t\t\t|      6---��ȡջ��                |\n");
		printf("\t\t\t|      7---ѹջ                    |\n");
		printf("\t\t\t|      8---��ջ                    |\n");
		printf("\t\t\t|      9---�������                |\n");
		printf("\t\t\t|      10---�˳�                   |\n");
		printf("\t\t\t|----------------------------------|\n");
		printf("\t\t\t|                     QGǰ�������� |\n");
		printf("\t\t\t|----------------------------------|\n");
		printf("\n��ѡ�����:\n");
		checkinput(&num);
		if (num >= 1 && num <= 10) {
			switch (num) {
			case 1: {
				if (s->top != NULL) {
					printf("\n�Ѵ���һ����ջ���������ٴ�ջ��\n");
				}
				else {
					printf("���������˳��ջ���ȣ�");
					initLStack(s);
					checkinput(&sizes);
					if (sizes>= 0) {
						for (i = 0; i < sizes; i++) {
							pushLStack(s);
						}
						printf("\n��ջ�����ɹ�\n");
					}
					else {
						printf("\n��ջ��ʼ��ʧ�ܣ������������\n");
					}
				}
				break;
			}
			case 2: {
				isEmptyLStack(s);
				break;
			}
			case 3: {
				getTopLStack(s);
				break;
			}
			case 4: {
				clearLStack(s);
				break;
			}
			case 5: {
				destroyLStack(s);
				break;
			}
			case 6: {
				LStackLength(s);
				break;
			}
			case 7: {
				pushLStack(s);
				break;
			}
			case 8: {
				popLStack(s);
				break;
			}
			case 9: {
				TraverseStack(s);
				break;
			}
			case 10:
				destroyLStack(s);
				system("cls");
				printf("\n\n\n\n\n\n\n\t\t\t\t���кܶ಻��֮���������ָ��!\n\n\n\n\n\n\n");
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
