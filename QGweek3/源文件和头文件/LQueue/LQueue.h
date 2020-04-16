#ifndef LQUEUE_H_INCLUDED
#define LQUEUE_H_INCLUDED

//链式队列结构
typedef struct Node
{
    void *data;
    struct Node* next;
    int size;
} Node;

typedef struct Lqueue
{
    Node *front;                   //队头
    Node *rear;                    //队尾
    int length;            //队列长度
} LQueue;

typedef enum
{
    FALSE=0, TRUE=1
} Status;
	

void InitLQueue(LQueue *Q);

void DestoryLQueue(LQueue *Q);

Status IsEmptyLQueue(const LQueue *Q);

Status GetHeadLQueue(LQueue *Q);

void LengthLQueue(LQueue *Q);

Status EnLQueue(LQueue *Q, void *data,int s);

Status DeLQueue(LQueue *Q);

void ClearLQueue(LQueue *Q);

Status TraverseLQueue(const LQueue *Q);

void checkinput(int* r);

void CheckType(LQueue* Q);

#endif

