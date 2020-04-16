#include"AQueue.h"
#include<stdio.h>
#include<stdlib.h>
void InitAQueue(AQueue* Q)
{
    int i;
    Q->front = Q->rear = 0;
    for (i = 0; i < MAXQUEUE; i++) {
        Q->data[i] = (void*)malloc(21);
        if(i< MAXQUEUE-1)
        CheckType(Q);
    }
    printf("\n���д����ɹ���\n");
}

void DestoryAQueue(AQueue* Q)
{
    if (Q->data[0] == NULL)
    {
        printf("�������롾1����������\n");
        return;
    }
    else {
        for (int i = 0; i < MAXQUEUE; i++)
            free(Q->data[i]);
        Q->data[0]= NULL;
        printf("�������ٳɹ���\n");
    }
}

Status IsFullAQueue(const AQueue* Q)
{
    if (Q->data[0] == NULL)
    {
        printf("�������롾1����������\n");
        return FALSE;
    }
    if (Q->length == 0) {
        return FALSE;
    }
    if (Q->length == MAXQUEUE - 1)
    {
        printf("����һ�������У�\n");
        return TRUE;
    }
    else {
        printf("�ⲻ��һ�������У�\n");
        return FALSE;
    }
}

Status IsEmptyAQueue(const AQueue* Q)
{
    if (Q->data[0] == NULL)
    {
        printf("�������롾1����������\n");
        return FALSE;
    }
    else if(Q->length == 0) {
        printf("����һ���ն��У�\n");
        return TRUE;
    }
    else{
        printf("�ⲻ��һ���ն��У�\n");
        return FALSE;
    }
}

Status GetHeadAQueue(AQueue* Q)
{
    if (Q->data[0] == NULL)
    {
        printf("�������롾1����������\n");
        return FALSE;
    }
    else if (Q->length==0)
    {
        printf("����Ϊ�գ�û�ж�ͷ��\n");
        return FALSE;
    }
    else {
        if (Q->type[Q->front] == 8)
            printf("��ͷԪ���ǣ���%lf��\n", *(double*)Q->data[Q->front]);
        if (Q->type[Q->front] == 1)
            printf("��ͷԪ���ǣ���%c��\n", *(char*)Q->data[Q->front]);
        if (Q->type[Q->front] == 4)
            printf("��ͷԪ���ǣ���%d��\n", *(int*)Q->data[Q->front]);
        if (Q->type[Q->front] == 20)
            printf("��ͷԪ���ǣ���%s��\n", (char*)Q->data[Q->front]);
        return TRUE;
    }
}

void LengthAQueue(AQueue* Q)
{
    if (Q->data[0] == NULL)
    {
        printf("�������롾1����������\n");
        return FALSE;
    }
    else {
        printf("���г���Ϊ:%d\n", Q->length);
        return ;
    }
}

Status EnAQueue(AQueue* Q, void* data,int s)
{ 
    if(Q->length==0)
    {
        Q->data[Q->front]=data;
        Q->rear = (Q->rear + 1) %MAXQUEUE;
        Q->type[Q->front] = s;
        Q->length++;
        printf("\n��ӳɹ���\n");
        TraverseAQueue(Q);
        return TRUE;
    }
    else {
        Q->data[Q->rear]=data;
        Q->type[Q->rear] = s;
        Q->rear = (Q->rear + 1) %MAXQUEUE;
        Q->length++;
        printf("\n��ӳɹ���\n");
        TraverseAQueue(Q);
        return TRUE;
    }
}

Status DeAQueue(AQueue* Q)
{
    if (Q->data[0] == NULL)
    {
        printf("�������롾1����������\n");
        return FALSE;
    }
    else if (Q->length==0)
    {
        printf("�����ǿյģ������˶ӣ�\n");
        return FALSE;
    }
    else{
        Q->front = (Q->front + 1) %MAXQUEUE;
        Q->length--;
        printf("\n���ӳɹ���\n");
        TraverseAQueue(Q);
        return TRUE;
    }
}

void ClearAQueue(AQueue* Q)
{
    if (Q->data[0] == NULL)
    {
        printf("�������롾1����������\n");
        return FALSE;
    }
    else if (Q->length==0)
    {
        printf("�����Ѿ��ǿյ��ˣ�\n");
        return;
    }
    else {
        Q->front = Q->rear = 0;
        Q->length = 0;
        printf("������ճɹ���\n");
    }
}

Status TraverseAQueue(const AQueue* Q)
{
    if (Q->data[0] == NULL)
    {
        printf("�������롾1����������\n");
        return FALSE;
    }
    else if (Q->length==0)
    {
        printf("��������ʲô��û��!\n");
        return FALSE;
    }
    else {
        printf("\n����Ϊ��\n");
        printf("��head�� -> ");
        for (int i = Q->front; i < Q->front+Q->length;i++) {
            if (Q->type[i] == 8)
                printf("��%lf��", *(double*)Q->data[i]);
            if (Q->type[i] == 1)
                printf("��%c��", *(char*)Q->data[i]);
            if (Q->type[i] == 4)
                printf("��%d��", *(int*)Q->data[i]);
            if (Q->type[i] == 20)
                printf("��%s��", (char*)Q->data[i]);
            printf(" -> ");
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

void CheckType(AQueue* Q) {
    printf("\t\t\t|--------------------------------|\n");

    printf("\t\t\t|           ��������ѡ��         |\n");
    printf("\t\t\t|--------------------------------|\n");
    printf("\t\t\t|          1---����              |\n");
    printf("\t\t\t|          2---�ַ���            |\n");
    printf("\t\t\t|          3---������            |\n");
    printf("\t\t\t|          4---�ַ���            |\n");
    printf("\t\t\t|--------------------------------|\n");
    int t = 1, s;
    printf("\n��������������ͣ�:\n");
    checkinput(&t);
    if (t > 0 && t < 5) {
        switch (t)
        {
        case 1: {
            int* a = (int*)malloc(sizeof(int));
            s = 4;
            printf("\n����ӵġ��������ݡ���\n");
            checkinput(a);
            EnAQueue(Q, a, s);
            break;
        }
        case 2: {
            char* a = (char*)malloc(sizeof(char));
            s = 1;
            printf("\n����ӵġ��ַ������ݡ���\n");
            scanf_s("%c", a);
            getchar();
            EnAQueue(Q, a, s);
            break;
        }
        case 3: {
            double* a = (double*)malloc(sizeof(double));
            s = 8;
            printf("\n����ӵġ����������ݡ���\n");
            scanf_s("%lf", a);
            getchar();
            EnAQueue(Q, a, s);
            break;
        }
        case 4: {
            char* a = (char*)malloc(20 * sizeof(char));
            s = 20;
            printf("\n����ӵġ��ַ��������ݡ�����󳤶�Ϊ20Ŷ������\n");
            gets(a);
            EnAQueue(Q, a, s);
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



