#include<stdio.h>
int selectsort(int* arr, int n)
{
	int i, min, j, t;
	for(i = 0; i < n; i++){
		min = arr[i];
		for(j = i; j < n; j++){
			if(arr[j] < min){
				min = arr[j];
			}
		}
		for(j = i; j < n; j++){
			if(arr[j] == min){
				break;
			}
		}
		t = arr[i];
		arr[i] = arr[j];
		arr[j] = t;
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
	selectsort(arr, n);
	for(i= 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	return 0;
}
