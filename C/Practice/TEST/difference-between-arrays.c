/*
练习7-4 找出不是两个数组共有的元素
分数 20
作者 张彤彧
单位 浙江大学
给定两个整型数组，本题要求找出不是两者共有的元素。

输入格式:
输入分别在两行中给出两个整型数组，每行先给出正整数N（≤20），随后是N个整数，其间以空格分隔。 

输出格式:
在一行中按照数字给出的顺序输出不是两数组共有的元素，数字间以空格分隔，但行末不得有多余的空格。题目保证至少存在一个这样的数字。同一数字不重复输出。 

输入样例:
10 3 -5 2 8 0 3 5 -15 9 100
11 6 4 8 2 6 -5 9 0 100 8 1
输出样例:
3 5 -15 6 4 1
*/

//2024-12-04 9:00 ~ 11:10
//last time 32min

#include<stdio.h>
int main()
{
    int dest[40];
    int n1, n2;
    int arr1[20], arr2[20];
    int i, j, k = 0;
    int flag;
    scanf("%d", &n1);
    for(i = 0; i < n1; i++){
        scanf("%d", &arr1[i]);
    }
    scanf("%d", &n2);
    for(i = 0; i < n2; i++){
        scanf("%d", &arr2[i]);
    }
    for(i = 0; i < n1; i++){
        for(j = 0; j <n2 ; j++){
            if(arr1[i] == arr2[j]){
                flag = 1;
                break;
            }
        }
        if(!flag){
            dest[k] = arr1[i];
            k++;
        }
        flag = 0;
    }
    for(i = 0; i < n2; i++){
        for(j = 0; j <n1 ; j++){
            if(arr2[i] == arr1[j]){
                flag = 1;
                break;
            }
        }
        if(!flag){
            dest[k] = arr2[i];
            k++;
        }
        flag = 0;
    }
    printf("%d", dest[0]);
    for(i = 1; i < k; i++){
        for(j = 0; j < i; j++){
            if(dest[i] == dest[j]){
                flag = 1;
                break;
            }
        }
        if(!flag){
            printf(" %d", dest[i]);
        }
        flag = 0;
    }
    return 0;
}

/*
对于数组之类多次用flag的情况，每次用完之后要重新置0
*/

/* python 版本
# 读取输入
arr1 = input().split()
arr2 = input().split()

# 提取数组内容
n1, list1 = int(arr1[0]), list(map(int, arr1[1:]))
n2, list2 = int(arr2[0]), list(map(int, arr2[1:]))

# 转为集合
set1 = set(list1)
set2 = set(list2)

# 找出不是共有的元素
result = (set1 - set2) | (set2 - set1)

# 按输入顺序排序
output = [x for x in list1 + list2 if x in result]

# 打印结果
print(" ".join(map(str, output)))
*/


//二刷 2024.12.12
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>

int inarry(int* arr, int size, int a);

int main()
{
    int arr1[20], arr2[20], dest[40];
    int n1, n2;
    int i, j = 0, d;
    scanf("%d", &n1);
    for(i = 0; i < n1; i++){
        scanf("%d", &arr1[i]);
    }
    scanf("%d", &n2);
    for(i = 0; i < n2; i++){
        scanf("%d", &arr2[i]);
    }
    for(i = 0; i < n1; i++){
        if(!inarry(arr2, n2, arr1[i]) && !inarry(dest, j + 1, arr1[i])){
            dest[j++] = arr1[i];
        }
    }
    for(i = 0; i < n2; i++){
        if(!inarry(arr1, n1, arr2[i]) && !inarry(dest, j + 1, arr2[i])){
            dest[j++] = arr2[i];
        }
    }
    for(i = 0; i < j; i++){
        if(i == 0){
            printf("%d", dest[0]);
        }
        else{
            printf(" %d", dest[i]);
        }
    }
    return 0;
}

int inarry(int* arr, int size, int a)
{
    int i;
    int flag = 0;
    for(i = 0; i < size; i++){
        if(arr[i] == a){
            return 1;
        }
    }
    return 0;
}