// 本题要求实现一个删除连续重复的字符的函数，例如bookkeeper -> bokeper。
// 函数接口定义：

// void removeDuplicateLetters(char *word)；
// 题目保证输入的字符串长度小与等于1024。

// 裁判测试程序样例：

#include <stdio.h>
#include <string.h>
#define MAX_LETTERS_LENGTH 1024

void removeDuplicateLetters(char* word);

int main()
{
    char word[MAX_LETTERS_LENGTH+1];
    gets(word);
    removeDuplicateLetters(word);
    puts(word);
    return 0;
}

/* 请在这里填写答案 */

void removeDuplicateLetters(char* word)
{
    char dest[1025];
    char* pword, *pdest = dest;
    
    dest[0] = word[0];
    pdest++;
    for(pword = word + 1; pword < word + strlen(word); pword++){
        if(*(pdest - 1) != *pword){
            *pdest++ = *pword;
        }
    }
    strcpy(word, dest);
}

