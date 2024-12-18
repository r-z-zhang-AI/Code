#include<stdio.h>
void bubblesort(int* arr, int n)
{
	int t, i, j;
	for(i = 0; i < n; i++){
		for(j = 0; j < n - i - 1; j++){ //这里循环终止条件要保证第一次i = 0时，j + 1不造成越界访问，即j < n - i - 1
			if(arr[j] > arr[j + 1]){
				t = arr[j];
				arr[j] = arr[j+1];
				arr[j + 1] = t;
			}
		}
	}
}
int main()
{
	int arr[100];
	int n, i;
	scanf("%d", &n);
	for(i= 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	bubblesort(arr, n);
	for(i= 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	return 0;
}