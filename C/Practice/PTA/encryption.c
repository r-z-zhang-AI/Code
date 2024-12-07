/*
本题要求编写程序，将英文字母替换加密。为了防止信息被别人轻易窃取，需要把电码明文通过加密方式变换成为密文。变换规则是：将明文中的所有英文字母替换为字母表中的后一个字母，同时将小写字母转换为大写字母，大写字母转换为小写字母。例如，字母a->B、b->C、…、z->A、A->b、B->c、…、Z->a。输入一行字符，将其中的英文字母按照以上规则转换后输出，其他字符按原样输出。

输入格式:
输入一行字符，以回车符 '\n'作为 结束符。

输出格式:
将输入的一行字符中的所有英文字母替换为字母表中的后一个字母，同时将小写字母转换为大写字母，大写字母转换为小写字母后输出，其他字符按原样输出。

输入样例:
在这里给出一组输入。例如：
Reold  Z123?

输出样例:
在这里给出相应的输出。例如：
sFPME  a123?

*/


#include<stdio.h>
#include<string.h>
int main()
{
    char str[1000];
    //int k;
    char* ch = str;
    while((*ch = getchar()) != '\n'){
        ch++;
    }
    *ch = '\0';
    for(ch = str; ch < str + sizeof(str)/sizeof(char); ch++){
        if(isupper(*ch) && *ch != 'Z'){
            *ch = tolower(*ch) + 1;
        }
        else if(*ch == 'Z'){
            *ch = 'a';
        }
        else if(islower(*ch) && *ch != 'z'){
            *ch = toupper(*ch) + 1;
        }
        else if(*ch == 'z'){
            *ch = 'A';
        }
        else{
            *ch = *ch;
        }
    }
    printf("%s\n", str);
    //printf("%d %d", 'z', 'Z');
    return 0;
}