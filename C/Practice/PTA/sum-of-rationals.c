#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int gcd(int* arr, int n)
{
    int i, j;
    int flag = 0;
    int min = abs(arr[0]);
    for(i = 0; i < n; i++){
        if(abs(arr[i]) < min){
            min = abs(arr[i]);
        }
    }
    for(i = min; i >= 2; i--){
        for(j = 0; j < n; j++){
            if(arr[j] % i != 0){
                flag = 1;
                break;
            }
        }
        if(!flag){
            return i;
        }
        if(i != min){
            flag = 0;
        }
    }
    if(flag){
        return 1;
    }
}

int multi(int *arr, int n)
{
    int i;
    int mul = 1;
    for(i = 0; i < n; i++){
        mul *= arr[i];
    }
    return mul ;
}

int main()
{
    // int arr[3] = {3,6,10};
    // printf("%d\n", gcd(arr, 3));printf("%d", multi(arr, 3));
    int n, a0 = 0, b0 = 1, c0;
    int i;
    int a[100], b[100], ans[2];
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d/%d", &a[i], &b[i]);
    }
    b0 = multi(b, n);
    if(b0 == 0){
        printf("0");
        return 0;
    }
    for(i = 0; i < n; i++){
        a0 += a[i] * b0 / b[i];
    }
    ans[0] = a0;
    ans[1] = b0;
    a0 = a0 / gcd(ans, 2);
    b0 = b0 / gcd(ans, 2);
    if(a0 == 0){
        printf("0");
    }
    else if(abs(a0) >= abs(b0)){
        c0 = a0 / b0;
        a0 -= b0 * c0;
        if(a0 != 0){
            printf("%d %d/%d", c0, abs(a0), abs(b0));
        }
        else{
            printf("%d", c0);
        }
    } 
    else{
        printf("%d/%d", a0, b0);
    }
    return 0;
}



#include <stdio.h>
long gcd(long n,long m) {
	if(n<0) n=-n;
    if(m<0) m=-m;
	long g=m;
	while(n>0) {
		g=n;
		n=m%n;
		m=g;
	}
	return g;
}
main() {
	long n,i,g;
	long a,b,aa,bb;
	scanf("%ld",&n);
	scanf("%ld/%ld",&aa,&bb);
	for(i=1; i<n; i++) {
		scanf("%ld/%ld",&a,&b);
		aa=aa*b+bb*a;
		bb=bb*b;
		g=gcd(aa,bb);
		aa=aa/g;
		bb=bb/g;
	}
	if(aa%bb==0)
		printf("%ld",aa/bb);
	else if(aa/bb==0)
		printf("%ld/%ld",aa%bb,bb);
	else
		printf("%ld %ld/%ld",aa/bb,aa%bb,bb);
	return 0;
}

/*
辗转相除法求两个数的gcd：

int gcd(int m; int n)
{   
    m = abs(m);
    n = abs(n);
    int g = n;
    while(n > 0){
        g = n;
        n = m % n;
        m = g;
    }
}
*/