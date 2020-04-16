#include"LQueue.h"
#include<stdio.h>
#include<stdlib.h>
void InitLQueue(LQueue* Q) {
	Node* head = (Node*)malloc(sizeof(Node));
	head->next = NULL;
	Q->front = head;
	Q->rear = head;
	if (Q->length >= 0) {
		for (int i = 0; i < Q->length; i++) {
			CheckType(Q);
		}
		printf("\n�����д����ɹ�\n");
		TraverseLQueue(Q);
	}
	else {
		printf("\n�����г�ʼ��ʧ�ܣ��ڵ����������\n");
	}
	return;
}

void DestoryLQueue(LQueue* Q) {
	if (!Q->front) {
		printf("\n�������롾1������������\n");
		return;
	}
	else {
		ClearLQueue(Q);
		free(Q->front);
		Q->front = NULL;
		printf("\n���������ٳɹ���\n");
		return;
	}
}

Status IsEmptyLQueue(const LQueue* Q) {
	if (!Q->front) {
		printf("\n�������롾1������������\n");
		return FALSE;
	}
	else if (Q->front == Q->rear) {
		printf("\n����һ���ն��У�\n");
		return TRUE;
	}
	else {
		printf("\n�ⲻ��һ���ն��У�\n");
		return FALSE;
	}
}

Status GetHeadLQueue(LQueue* Q) {
	if (!Q->front) {
		printf("\n�������롾1������������\n");
		return FALSE;
	}
	else if (Q->front == Q->rear) {
		printf("\n����һ���ն��У�\n");
		return FALSE;
	}
	else {
		if (Q->front->next->size == 8)
			printf("��ͷԪ���ǣ���%lf��\n", *(double*)Q->front->next->data);
		if (Q->front->next->size == 1)
			printf("��ͷԪ���ǣ���%c��\n", *(char*)Q->front->next->data);
		if (Q->front->next->size == 4)
			printf("��ͷԪ���ǣ���%d��\n", *(int*)Q->front->next->data);
		if (Q->front->next->size == 20)
			printf("��ͷԪ���ǣ���%s��\n", (char*)Q->front->next->data);
		return TRUE;
	}
}
void LengthLQueue(LQueue* Q) {
	printf("\n���г���Ϊ��%d\n",Q->length);
	return;
}

Status EnLQueue(LQueue* Q, void* data,int s) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = data;
	p->next = NULL;
	Q->rear->next = p;
	p->size = s;
	Q->rear = p;
	printf("\n������ӳɹ�\n");
	TraverseLQueue(Q);
	return TRUE;
}

Status DeLQueue(LQueue* Q) {
	if (!Q->front) {
		printf("\n�������롾1������������\n");
		return FALSE;
	}
	else if (Q->front == Q->rear) {
		printf("\n����һ���ն��У�\n");
		return FALSE;
	}
	else {
		Node* p = (Node*)malloc(sizeof(Node));
		p = Q->front->next;
		Q->front->next = p->next;
		if (!Q->front->next)
			Q->rear = Q->front;
		free(p);
		printf("\n���ݳ��ӳɹ�\n");
		TraverseLQueue(Q);
		return TRUE;
	}
}

void ClearLQueue(LQueue* Q) {
	if (!Q->front) {
		printf("\n�������롾1������������\n");
		return;
	}
	else if (Q->front == Q->rear) {
		printf("\n����һ���ն��У�\n");
		return;
	}
	else {
		Node* p, * q;
		Q->rear = Q->front;
		p = Q->front->next;
		while (p) {
			q = p;
			p = p->next;
			free(q);
		}
		free(p);
		printf("\n��������ճɹ���\n");
		return;
	}
}
 
Status TraverseLQueue(const LQueue* Q) {
	if (!Q->front) {
		printf("\n�������롾1������������\n");
		return FALSE;
	}
	else if (Q->front == Q->rear) {
		printf("\n����һ���ն��У�\n");
		return TRUE;
	}
	else {
		Node* p = (void*)malloc(Q->length);
		p = Q->front->next;
		printf("\n����Ϊ��\n");
		printf("��head�� -> ");
		while (p) {
			if (p->size == 8)
				printf("��%lf��", *(double*)p->data);
			if (p->size == 1)
				printf("��%c��", *(char*)p->data);
			if (p->size == 4)
				printf("��%d��", *(int*)p->data);
			if (p->size == 20) 
				printf("��%s��", (char*)p->data);
			printf(" -> ");
			p = p->next;
		}
		printf("��rear��\n");
		return TRUE;
	}
}

void checkinput(int* r) {
	int error, i = 0;
	char c[50] = { 0 };
	do {
		gets(c);
		error = 0;
		for (i = 0; c[i] != '\0'; i++) {
			if (i == 0 && c[i] == '-')
			{
				continue;
			}
			if (c[i] < '0' || c[i]>'9')
				error = 1;
		}
		if (error) {
			printf("����������������룡\n");
		}
	} while (error);
	*r = atoi(c);
}

void CheckType(LQueue* Q) {
	printf("\t\t\t|--------------------------------|\n");

	printf("\t\t\t|           ��������ѡ��         |\n");
	printf("\t\t\t|--------------------------------|\n");
	printf("\t\t\t|          1---����              |\n");
	printf("\t\t\t|          2---�ַ���            |\n");
	printf("\t\t\t|          3---������            |\n");
	printf("\t\t\t|          4---�ַ���            |\n");
	printf("\t\t\t|--------------------------------|\n");
	int t=1, s;
	printf("\n��������������ͣ�:\n");
	checkinput(&t);
	if (t > 0 && t < 5) {
		switch (t)
		{
		case 1: {
			int *a=(int*)malloc(sizeof(int));
			s = 4;
			printf("\n����ӵġ��������ݡ���\n");
			checkinput(a);
			EnLQueue(Q, a,s);
			break;
		}
		case 2: {
			char *a=(char*)malloc(sizeof(char));
			s = 1;
			printf("\n����ӵġ��ַ������ݡ���\n");
			scanf_s("%c", a);
			getchar();
			EnLQueue(Q, a,s);
			break;
		}
		case 3: {
			double *a= (double*)malloc(sizeof(double));
			s = 8;
			printf("\n����ӵġ����������ݡ���\n");
			scanf_s("%lf", a);
			getchar();
			EnLQueue(Q, a,s);
			break;
		}
		case 4: {
			char* a = (char*)malloc(20 * sizeof(char));
			s = 20;
			printf("\n����ӵġ��ַ��������ݡ�����󳤶�Ϊ20Ŷ������\n");
			gets(a);
			EnLQueue(Q, a, s);
			break;
		}
		}
	}
	else
	{
		printf("\nӦ������[1,4]֮���������\n");
		CheckType(Q);
	}
	return;
}