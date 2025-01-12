/*
给定n本书的名称和定价，本题要求编写程序，查找并输出其中定价最高和最低的书的名称和定价。

输入格式:
输入第一行给出正整数n（<10），随后给出n本书的信息。每本书在一行中给出书名，即长度不超过30的字符串，随后一行中给出正实数价格。题目保证没有同样价格的书。

输出格式:
在一行中按照“价格, 书名”的格式先后输出价格最高和最低的书。价格保留2位小数。

输入样例:
3
Programming in C
21.5
Programming in VB
18.5
Programming in Delphi
25.0
输出样例:
25.00, Programming in Delphi
18.50, Programming in VB
*/

// 注意细节
#include<stdio.h>

typedef struct {
    char name[31];
    double price;
} Book;

int main()
{
    int n, i, k, maxi = 0, mini = 0;
    Book a[10];
    scanf("%d", &n);
    getchar();  // 读掉换行
    for(i = 0; i < n; i++){
        k = 0;  //循环使用，循环体内部开始时置0
        while((a[i].name[k] = getchar()) != '\n'){
            k++;
        }
        a[i].name[k] = '\0';
        scanf("%lf", &a[i].price);
        getchar();  // 读掉换行
    }
    for(i = 0; i < n; i++){
        if(a[i].price > a[maxi].price){
            maxi = i;
        }
        if(a[i].price < a[maxi].price){
            mini = i;
        }
    }
    printf("%.2lf, %s\n", a[maxi].price, a[maxi].name);
    printf("%.2lf, %s\n", a[mini].price, a[mini].name);
    return 0;
}