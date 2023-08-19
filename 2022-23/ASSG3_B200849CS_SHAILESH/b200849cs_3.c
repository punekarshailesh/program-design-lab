#include <stdio.h>
#include <stdlib.h>


void read_array(int arr[] , int n){
	for(int i = 0 ; i<n ; i++){
		scanf("%d",&arr[i]);
	}
}

void print_array(int arr[] , int n){
	for(int i = 0 ; i<n ; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void swap(int *a , int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void solve(int arr[] , int n){

	// swapping is done in the selection sort

	for(int i = 0 ; i<n ; i++){
		int maxIndex = i;
		for(int j = i+1 ; j<n ; j++){
			if(arr[j] > arr[maxIndex]){
				maxIndex =j;
			}
		}
		swap(&arr[i], &arr[maxIndex]);
	}
}


int main(){

	int n;
	scanf("%d",&n);

	int * arr = (int*)malloc(n * sizeof(int));

	read_array(arr , n);
	solve(arr , n);

	print_array(arr , n);
	return 0;
}