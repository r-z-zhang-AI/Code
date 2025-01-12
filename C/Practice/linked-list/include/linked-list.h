#ifndef _NODE_H_
#define _NODE_H_

typedef struct _node{
    int value;
    struct _node* next;
}Node;

typedef struct list {
    Node* head;
    //Node* tail;
}List;  // LIst结构代表这个链表，里面有head

void add(List* pList, int num);
void print(List* pList);
void search(List list, int number);
void delete(List* list, int number);

#endif