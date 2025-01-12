//答案在PTA

// 6-5 链表拼接
// 分数 20
// 作者 张泳
// 单位 浙江大学
// 本题要求实现一个合并两个有序链表的简单函数。链表结点定义如下：

// struct ListNode {
//     int data;
//     struct ListNode *next;
// };
// 函数接口定义：
// struct ListNode *mergelists(struct ListNode *list1, struct ListNode *list2);
// 其中list1和list2是用户传入的两个按data升序链接的链表的头指针；函数mergelists将两个链表合并成一个按data升序链接的链表，并返回结果链表的头指针。

// 裁判测试程序样例：
// #include <stdio.h>
// #include <stdlib.h>

// struct ListNode {
//     int data;
//     struct ListNode *next;
// };

// struct ListNode *createlist(); /*裁判实现，细节不表*/
// struct ListNode *mergelists(struct ListNode *list1, struct ListNode *list2);
// void printlist( struct ListNode *head )
// {
//      struct ListNode *p = head;
//      while (p) {
//            printf("%d ", p->data);
//            p = p->next;
//      }
//      printf("\n");
// }

// int main()
// {
//     struct ListNode  *list1, *list2;

//     list1 = createlist();
//     list2 = createlist();
//     list1 = mergelists(list1, list2);
//     printlist(list1);
    
//     return 0;
// }

// /* 你的代码将被嵌在这里 */
// 输入样例：
// 1 3 5 7 -1
// 2 4 6 -1
// 输出样例：
// 1 2 3 4 5 6 7 
// 代码长度限制
// 16 KB
// 时间限制
// 400 ms
// 内存限制
// 64 MB



// 6-6 奇数值结点链表
// 分数 20
// 作者 C课程组
// 单位 浙江大学
// 本题要求实现两个函数，分别将读入的数据存储为单链表、将链表中奇数值的结点重新组成一个新的链表。链表结点定义如下：

// struct ListNode {
//     int data;
//     ListNode *next;
// };
// 函数接口定义：
// struct ListNode *readlist();
// struct ListNode *getodd( struct ListNode **L );
// 函数readlist从标准输入读入一系列正整数，按照读入顺序建立单链表。当读到−1时表示输入结束，函数应返回指向单链表头结点的指针。

// 函数getodd将单链表L中奇数值的结点分离出来，重新组成一个新的链表。返回指向新链表头结点的指针，同时将L中存储的地址改为删除了奇数值结点后的链表的头结点地址（所以要传入L的指针）。

// 裁判测试程序样例：
// #include <stdio.h>
// #include <stdlib.h>

// struct ListNode {
//     int data;
//     struct ListNode *next;
// };

// struct ListNode *readlist();
// struct ListNode *getodd( struct ListNode **L );
// void printlist( struct ListNode *L )
// {
//      struct ListNode *p = L;
//      while (p) {
//            printf("%d ", p->data);
//            p = p->next;
//      }
//      printf("\n");
// }

// int main()
// {
//     struct ListNode *L, *Odd;
//     L = readlist();
//     Odd = getodd(&L);
//     printlist(Odd);
//     printlist(L);

//     return 0;
// }

// /* 你的代码将被嵌在这里 */
// 输入样例：
// 1 2 2 3 4 5 6 7 -1
// 输出样例：
// 1 3 5 7 
// 2 2 4 6 
// 代码长度限制
// 16 KB
// 时间限制
// 400 ms
// 内存限制
// 64 MB



// 6-7 删除单链表偶数节点
// 分数 20
// 作者 C课程组
// 单位 浙江大学
// 本题要求实现两个函数，分别将读入的数据存储为单链表、将链表中偶数值的结点删除。链表结点定义如下：

// struct ListNode {
//     int data;
//     struct ListNode *next;
// };
// 函数接口定义：
// struct ListNode *createlist();
// struct ListNode *deleteeven( struct ListNode *head );
// 函数createlist从标准输入读入一系列正整数，按照读入顺序建立单链表。当读到−1时表示输入结束，函数应返回指向单链表头结点的指针。

// 函数deleteeven将单链表head中偶数值的结点删除，返回结果链表的头指针。

// 裁判测试程序样例：
// #include <stdio.h>
// #include <stdlib.h>

// struct ListNode {
//     int data;
//     struct ListNode *next;
// };

// struct ListNode *createlist();
// struct ListNode *deleteeven( struct ListNode *head );
// void printlist( struct ListNode *head )
// {
//      struct ListNode *p = head;
//      while (p) {
//            printf("%d ", p->data);
//            p = p->next;
//      }
//      printf("\n");
// }

// int main()
// {
//     struct ListNode *head;

//     head = createlist();
//     head = deleteeven(head);
//     printlist(head);

//     return 0;
// }

// /* 你的代码将被嵌在这里 */
// 输入样例：
// 1 2 2 3 4 5 6 7 -1
// 输出样例：
// 1 3 5 7 
// 代码长度限制
// 16 KB
// 时间限制
// 400 ms
// 内存限制
// 64 MB