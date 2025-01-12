#include"../include/linked-list.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// typedef struct _node{
//     int value;
//     struct _node* next;
// }Node;

// typedef struct list {
//     Node* head;
//     //Node* tail;
// }List;  // List结构代表这个链表，里面有head

int main()
{
    List list;
    list.head = NULL;
    //list.tail = NULL;
    int num;
    do {
        scanf("%d", &num);
        if(num != -1){
            add(&list, num);
        }
    }while(num != -1);
    print(&list);
    int number;
    scanf("%d", &number);
    search(list, number);
    delete(&list, number);
    print(&list);
    return 0;
}

void add(List* plist, int num)
{
    //add to list
    Node* p = (Node*)malloc(sizeof(Node));
    p -> value = num;
    p -> next = NULL;
    //find the last
    Node* last = plist -> head;
    if( last ){
        while( last -> next){
            last = last -> next;
        }
        //attach
        last -> next = p;
    }
    else{
        plist -> head = p;
    }
}

void print(List* pList)  
// 事实上这里也可以用List 类型，不用指针，像底下几个函数一样，没区别
// 只有当在函数内部需要对参数进行修改的时候才需要传指针作为参数：类比swap交换两个数字的函数
// 参数建议全传指针~
{
    Node* p;  
    // 这里用指针，其实就跟用int指针遍历int数组一样。
    // 必须得用指针，不能用Node变量，
    // 原因1. Node中一个成员就是指针，这样一来移动可以用指针间的赋值轻松解决
    // 原因2. 如果用Node p，就得&p = pList -> head，而&p是指针表达式，不是可修改的左值。
    for(p = pList -> head; p; p = p -> next){  // 常见的遍历链表的语句
        printf("%d\t", p->value);
    }
    printf("\n");
}

void search(List list, int number)
{
    Node* p;
    int isFound = 0;
    for(p = list.head; p; p = p -> next){
        if(number == p -> value){
            printf("找到了\n");
            isFound = 1;
            break;
        }
    }
    if(!isFound){
        printf("没找到\n");
    }
}

void delete(List* list, int number)  // 这里要修改链表，故参数必须是指针
{
    Node* p, *q;
    for(q = NULL, p = list -> head; p; q = p, p = p -> next){
        if( q ){
            if(number == p -> value){
                q -> next = p -> next;
                free(p);
            }
        }
        else{
            list -> head = p -> next;
        }  // 找所有出现在->左边的指针，判断其是不是NULL！ or人工想清其边界
    }
}


/*列表的增添与删除二刷*/
/*
typedef struct _node{
    int num;
    char name[100];
    int score;
    struct _node* next;
} Node;

typedef struct _list {
    Node* head;
} List;

void delete(List* list, Node* p);
void append(List* list, int num, char* name, int score);
void print(List list);

int main()
{
    List list;
    list.head = NULL;
    int num, score, line;
    char name[100];
    while(1){
        scanf("%d", &num);
        if(num){
            scanf("%s %d", name, &score);
            append(&list, num, name, score);
        }
        else{
            break;
        }
    }
    scanf("%d", &line);
    Node* p;
    for(p = list.head; p; p = p->next){
        if(p->score < line){
            delete(&list, p);
        }
    }
    print(list);
}

void delete(List* list, Node* p)
{
    if(p != list->head){
        Node* former;
        for(former = list->head; ;){
            if(former->next == p){
                break;
            }
            former = former->next;
        }
        former->next = p->next;
    }
    else{
        list->head = p->next;
    }
    free(p);
}

void append(List* list, int num, char* name, int score)
{
    Node* p;
    p = (Node*)malloc(sizeof(Node));
    p->num = num;
    strcpy(p->name, name);
    p->score = score;
    p->next = NULL;

    if(list->head){
        Node* last;
        last = list->head;
        while(last->next){
            last = last->next;
        }
        last->next = p;
    }
    else{
        list->head = p;
    }
}

void print(List list)
{
    Node* p;
    for(p = list.head; p; p = p->next){
        printf("%d %s %d\n", p->num, p->name, p->score);
    }
}
*/

//另，在List 里面放上tail，更简单：添加时tail->next = p; tail = p
/*
typedef struct _node{
    int num;
    char name[100];
    int score;
    struct _node* next;
} Node;

typedef struct _list {
    Node* head;
    Node* tail;
} List;

void delete(List* list, Node* p);
void append(List* list, int num, char* name, int score);
void print(List list);

int main()
{
    List list;
    list.head = NULL;
    list.tail = NULL;
    int num, score, line;
    char name[100];
    while(1){
        scanf("%d", &num);
        if(num){
            scanf("%s %d", name, &score);
            append(&list, num, name, score);
        }
        else{
            break;
        }
    }
    scanf("%d", &line);
    Node* p;
    for(p = list.head; p; p = p->next){
        if(p->score < line){
            delete(&list, p);
        }
    }
    print(list);
}

void delete(List* list, Node* p)
{
    if(p != list->head){
        Node* former;
        for(former = list->head; ;){
            if(former->next == p){
                break;
            }
            former = former->next;
        }
        former->next = p->next;
    }
    else{
        list->head = p->next;
    }
    free(p);
}

void append(List* list, int num, char* name, int score)
{
    Node* p;
    p = (Node*)malloc(sizeof(Node));
    p->num = num;
    strcpy(p->name, name);
    p->score = score;
    p->next = NULL;

    if(list->head){
        (list->tail)->next = p;
        list->tail = p;
    }
    else{
        list->head = p;
        list->tail = p;
    }
}

void print(List list)
{
    Node* p;
    for(p = list.head; p; p = p->next){
        printf("%d %s %d\n", p->num, p->name, p->score);
    }
}
*/