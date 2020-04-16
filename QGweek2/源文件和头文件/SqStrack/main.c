#include"SqStack.h"
#include <stdio.h>
#include <stdlib.h>
int main() {
	int i,num;
	int* length = (int*)malloc(sizeof(int));
	ElemType sizes;
	ElemType data=0;
	ElemType* e = (ElemType*)malloc(sizeof(ElemType));
	SqStack *s=(SqStack*)malloc(sizeof(SqStack));
	s->elem=NULL;
	while (1) {
		system("cls");
		printf("\t\t\t|----------------------------------|\n");
		printf("\t\t\t|         ˳��ջ��������           |\n");
		printf("\t\t\t|----------------------------------|\n");
		printf("\t\t\t|      1---����˳��ջ              |\n");
		printf("\t\t\t|      2---�ж��Ƿ�Ϊ��            |\n");
		printf("\t\t\t|      3---�õ�ջ��Ԫ��            |\n");
		printf("\t\t\t|      4---���˳��ջ              |\n");
		printf("\t\t\t|      5---����˳��ջ              |\n");
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
				if (s->elem!=NULL) {
					printf("\n�Ѵ���һ��˳��ջ���������ٴ�ջ��\n");
				}
				else {
					printf("���������˳��ջ���ȣ�");
					checkinput(&sizes);
					if (sizes >= 0) {
						initStack(s, sizes);
						for (i = 0; i < sizes; i++) {
							pushStack(s, data);
						}
						printf("\n˳��ջ�����ɹ�\n");
						outStack(s);
					}
					else {
						printf("\n˳��ջ��ʼ��ʧ�ܣ������������\n");
					}
				}
				break;
			}
			case 2: {
				isEmptyStack(s);
				break;
			}
			case 3: {
				getTopStack(s, e);
				outStack(s);
				break;
			}
			case 4: {
				clearStack(s);
				break;
			}
			case 5: {
				destroyStack(s);
				break;
			}
			case 6: {
				stackLength(s, length);
				break;
			}
			case 7: {
				pushStack(s, data);
				break;
			}
			case 8: {
				popStack(s);
				break;
			}
			case 9: {
				outStack(s);
				break;
			}
			case 10: 
				destroyStack(s);
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
