#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <assert.h>

void InsertSort(int* array, int size)
{
    assert(array);

    // 遍历未排序的部分
    for (int sortedEndIndex = 0; sortedEndIndex < size - 1; ++sortedEndIndex) // 已排序部分的最后一个下标
    {
        int unsortedElement = array[sortedEndIndex + 1]; // 需要插入到已排序部分的元素
        int currentIndex = sortedEndIndex; // 当前比较的已排序元素下标

        // 单趟插入过程：从已排序部分的末尾向前遍历
        while (currentIndex >= 0 && array[currentIndex] > unsortedElement)
        {
            array[currentIndex + 1] = array[currentIndex]; // 将较大的已排序元素向后移动
            --currentIndex; // 向前比较
        }

        // 将未排序元素插入到正确位置
        array[currentIndex + 1] = unsortedElement;
    }
}


