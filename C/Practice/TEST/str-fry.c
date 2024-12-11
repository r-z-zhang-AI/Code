/*
对字符串进行翻炒有3个步骤
1.将整个字符串倒转过来
2.若是字符串长度为奇数，最中间的字符删除，否则删除两端的字符
3.将两两字符翻转，如第1个和第2个调换，第3个和第4个调换

输入格式:
输入一行长度不大于10^4的字符串，本题保证输入全部为英文字母。
输出格式:
输出经过3步翻炒后的字符串
输入样例1: abcdefg  输出样例1: fgceab
输入样例2: abcdefgh  输出样例2: fgdebc
*/

#include<stdio.h>
#include<string.h>

void rev(char* str, char* dest1, int len)
{
    //char dest1[10001];
    int i;
    for(i = 0; i < len; i++){
        dest1[len - 1 - i] = str[i];
    }
    dest1[len] = '\0';
    //return dest1;

}

int main()
{
    char str[10001];
    char dest1[10001], dest2[10001], dest3[10001];
    char* p1 = dest1, *p2 = dest2, *p3 = dest3;
    int k = 0, i, j;
    char t;
    while((str[k] = getchar()) != '\n'){
        k++;
    }
    str[k] = '\0';
    rev(str, dest1, k);
    //printf("%s", dest1);

    if(k % 2){
        int mid = (k - 1) / 2;
        char midch[2];
        midch[0] = dest1[mid];
        midch[1] = '\0';
        //printf("%s", midch);
        char *front = strtok(dest1, midch);
        char *last = strtok(NULL, "");
        strcat(front, last);
        strcpy(dest2, front);
        //printf("%s", dest2);
    }
    else{
        char str2[10001];
        strncpy(str2, str, k - 1);
        rev(str2, dest2, k - 1);
        dest2[k - 2] = '\0';
        //printf("%s", dest2);
    }

    for(j = 0; j < strlen(dest2); j += 2){
        t = dest2[j];
        dest2[j] = dest2[j + 1];
        dest2[j + 1] = t;
    }

    printf("%s\n", dest2);

    return 0;
}

/*GPT版本*/

#include <stdio.h>
#include <string.h>

// 函数：将字符串倒转
void reverse_string(const char *str, char *dest, int len) {
    for (int i = 0; i < len; i++) {
        dest[len - 1 - i] = str[i];
    }
    dest[len] = '\0';
}

int main() {
    char str[10001];  // 增加 1 字节防止溢出
    char dest1[10001], dest2[10001];
    int len = 0;

    // 读取输入字符串
    while ((str[len] = getchar()) != '\n' && str[len] != EOF) {
        len++;
    }
    str[len] = '\0';

    // 1. 字符串倒转
    reverse_string(str, dest1, len);
    
    // 2. 删除中间或首尾字符
    if (len % 2 == 1) {
        // 长度为奇数：删除中间字符
        int mid = len / 2;
        strncpy(dest2, dest1, mid);                  // 拷贝前半部分
        strcpy(dest2 + mid, dest1 + mid + 1);        // 拷贝后半部分
        dest2[len - 1] = '\0';                       // 新长度
    } else {
        // 长度为偶数：删除两端字符
        strncpy(dest2, dest1 + 1, len - 2);
        dest2[len - 2] = '\0';
    }

    // 3. 两两字符翻转
    for (int i = 0; i < strlen(dest2) - 1; i += 2) {
        char temp = dest2[i];
        dest2[i] = dest2[i + 1];
        dest2[i + 1] = temp;
    }

    // 输出结果
    printf("%s\n", dest2);
    return 0;
}
