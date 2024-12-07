/*
pta 66
习题7-8 字符串转换成十进制整数

输入一个以#结束的字符串，本题要求滤去所有的非十六进制字符（不分大小写），组成一个新的表示十六进制数字的字符串，然后将其转换为十进制数后输出。如果在第一个十六进制字符之前存在字符“-”，则代表该数是负数。

输入格式：
输入在一行中给出一个以#结束的非空字符串。

输出格式：
在一行中输出转换后的十进制数。题目保证输出在长整型范围内。

输入样例：
+-P-xf4+-1!#
输出样例：
-3905
*/

#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    char str[1000];
    int ans = 0, digit, op = 1, flag = 0;
    int i, j, k, cnt = 0;
    while((str[k] = getchar()) != '#'){
        k++;
    }
    str[k] = '\0';
    for(i = k - 1; i >= 0; i--){
        if(isdigit(str[i])){
            ans += (str[i] - '0') * pow(16, cnt++);
        }
        if(!isdigit(str[i]) && isxdigit(str[i])){
            ans += (str[i] - 'a' + 10) * pow(16, cnt++);
        }
    }
    for(i = 0; i < k; i++){
        if(isxdigit(str[i])){
            flag = 1;
            break;
        }
    }
    if(flag){
        for(j = 0; j < i; j++){
            if(str[j] == '-'){
                op = -1;
                break;
            }
        }
    }
    printf("%d", op * ans);
}

#include<stdio.h>

int main()
{

    char a;
    int flag=1,mark=0,sum=0; 
	//flag来表示有没有读到第一个字符，mark来表示第一个字符是不是'-'
    scanf("%c",&a);
    while(a!='#')
    {
        if(a>='0'&&a<='9'){
            flag=0;
            sum=sum*16+a-'0';

        }else if(a>='a'&&a<='f'){
            flag=0;
            sum=sum*16+a-'a'+10;

        }else if(a>='A'&&a<='F'){
            flag=0;
            sum=sum*16+a-'A'+10;

        }else if(a=='-'&&flag==1)
            mark=1;
        scanf("%c",&a);
	}

    if(sum==0) 
		printf("0");
    else
	{
        if(mark==1) 
			printf("-");
        printf("%d\n",sum);
    }

    return 0;

}
//《在西伯利亚森林中》