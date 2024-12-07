/*

第一周 编程8
本题目要求编写程序统计一行字符中单词的个数。所谓“单词”是指连续不含空格的字符串，各单词之间用空格分隔，空格数可以是多个。

输入格式:
输入给出一行字符。 

输出格式:
在一行中输出单词个数。 

输入样例:
Let's go to room 209.

输出样例:
5
*/

#include<stdio.h>
#include<string.h>
int main()
{
    int k = 0, num = 0, i;
    char str[1000];
    while((str[k] = getchar()) != '\n'){
        k++;
    }
    str[k] = '\0';
    for(i = 0; i < k; i++){
        if(str[i] == ' ' && str[i + 1] != ' '){
            num++;
        }
    }
    if(str[0] == ' ' && str[k - 1] == ' '){
        printf("%d\n", num - 1);
    }
    else if((str[0] == ' ' && str[k - 1] != ' ') || (str[0] != ' ' && str[k - 1] == ' ')){
        printf("%d\n", num);
    }
    else{
        printf("%d\n", num + 1);
    }
    return 0;
}