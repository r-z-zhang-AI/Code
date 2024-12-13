#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef enum { false, true } bool;

bool palindrome(char *s) {
    int left = 0;
    int right = strlen(s) - 1;

    while (left < right) {
        // 跳过非字母数字字符
        while (left < right && !isalnum(s[left])) {
            left++;
        }
        while (left < right && !isalnum(s[right])) {
            right--;
        }

        // 忽略大小写比较
        if (tolower(s[left]) != tolower(s[right])) {
            return false;
        }

        left++;
        right--;
    }

    return true;
}

int main() {
    char test1[] = "A man, a plan, a canal, Panama";
    char test2[] = "Not a palindrome";

    printf("Test 1: %s\n", palindrome(test1) ? "true" : "false");
    printf("Test 2: %s\n", palindrome(test2) ? "true" : "false");

    return 0;
}

/*
代码解析

1. **`typedef enum {false, true} bool;`**  
   定义了一个枚举类型 `bool`，其中 `false` 表示 0，`true` 表示 1。

2. **`palindrome` 函数**  
   - 接收一个字符串 `s`。
   - 使用两个指针 `left` 和 `right` 分别从字符串的开头和结尾向中间移动。
   - 跳过非字母数字字符，并忽略大小写比较。
   - 如果发现字符不匹配，返回 `false`；如果遍历完成未发现不匹配，返回 `true`。

3. **`isalnum` 和 `tolower`**  
   - `isalnum` 检查字符是否是字母或数字。
   - `tolower` 将字符转换为小写，便于忽略大小写的比较。

4. **测试用例**  
   - `test1` 是一个经典的回文短语，函数应返回 `true`。
   - `test2` 不是回文，函数应返回 `false`。

注意事项
1. 如果输入字符串可能包含 NULL 指针或为空字符串，应添加额外的边界检查。
2. 如果支持 C99 标准，可以直接使用 `<stdbool.h>` 提供的布尔类型。

*/