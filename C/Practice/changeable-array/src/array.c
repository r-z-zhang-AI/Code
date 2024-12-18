#include"array.h"
#include<string.h>
#include<stdio.h>
#include<stdlib.h>



// typedef struct {
//     int* array;
//     int size;
// } Array;

Array array_creat(int init_size)
{
    Array a;
    a.size = init_size;
    a.array = (int*)malloc(a.size * sizeof(int));
    return a;
}

void arrar_free(Array *a)
{
    free(a -> array);
    a -> size = 0;
    a -> array = 0;
}

// 代码的封装
int array_size(const Array *a)
{
    return a -> size;
}

int* array_at(Array *a, int index)
{
    if(index >= a -> size){
        array_inflate(a, (index / BLOCK_SIZE + 1) * BLOCK_SIZE - a -> size);
    }
    //return (a -> array) + index;
    return &(a -> array[index]);
}

void array_inflate(Array *a, int more_size)
{
    int* p = (int*)malloc(sizeof(int) * (a -> size + more_size));
    for(int i = 0; i < a -> size; i++){
        p[i] = *array_at(a, i);
    }  // 可以用标准库的memcpy函数
    int init_size = a -> size;
    free(a -> array);
    a -> size += more_size;
    a -> array = p;
}

int main(int argc, char const *argv[])
{
    int num;
    int cnt = 0;
    Array a = array_creat(100);
    while(num != -1){
        scanf("%d", &num);
        if(num != -1)
            *array_at(&a, cnt++) = num;
        // // cnt++;
        // scanf("%d", array_at(&a, cnt++));
    }
}