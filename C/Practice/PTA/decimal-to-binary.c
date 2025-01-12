
#include <stdio.h>

void dectobin( int n );

int main()
{
    int n;
    
    //scanf("%d", &n);
    dectobin(0);
    printf("\n");
    printf("%d", -1 > 2);
    
    return 0;
}

/* 你的代码将被嵌在这里 */
#include <stdio.h>

void dectobin(int n) {
    unsigned int a = 1u << 31;
    int flag = 0;
    while (a) {
        if((a & n)) flag = 1;
        if(flag){
            if ((a & n) == 0)
                printf("0");
            else
                printf("1");
        }
        a = a >> 1;
    }
    if(!flag){
        printf("0");
    }
}
