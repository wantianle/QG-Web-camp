#ifndef DULINKEDLIST_H_INCLUDED
#define DULINKEDLIST_H_INCLUDED

#define OVERFLOW -1

typedef int ElemType;

typedef struct DuLNode {
    ElemType data;
    struct DuLNode* prior, * next;
} DuLNode, * DuLinkedList;

typedef enum Status {
    ERROR,
    SUCCESS,
} Status;

Status InitList_DuL(DuLinkedList* L, int sizes);

void DestroyList_DuL(DuLinkedList* L);

Status InsertBeforeList_DuL(DuLinkedList* L, int sizes);

Status InsertAfterList_DuL(DuLinkedList* L, int sizes);

Status DeleteList_DuL(DuLinkedList* L, int sizes);

void TraverseList_DuL(DuLinkedList* L, int sizes);

void checkinput(int* r);

#endif
