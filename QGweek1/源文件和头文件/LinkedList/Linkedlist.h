
#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#define OVERFLOW -1
typedef int ElemType;

typedef struct LNode {
    ElemType data;
    struct LNode* next;
} LNode, * LinkedList;

typedef enum Status {
    ERROR,
    SUCCESS
} Status;

Status InitList(LinkedList* L,int sizes);

void DestroyList(LinkedList* L);

Status InsertList(LinkedList* L,int sizes);

Status DeleteList(LinkedList* L, int sizes);

void TraverseList(LinkedList* L, int sizes);

Status SearchList(LinkedList* L, ElemType e, int sizes);

Status ReverseList(LinkedList* L, int sizes);

Status IsLoopList(LinkedList* L);

Status ReverseEvenList(LinkedList* L, int sizes);

Status FindMidNode(LinkedList* L, int sizes);

void checkinput(int*r);
#endif
