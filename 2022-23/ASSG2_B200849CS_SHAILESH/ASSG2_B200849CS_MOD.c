#include <stdio.h>
#include <stdlib.h>

void read_array(int arr[] , int n){
	for(int i = 0 ; i<n ; i++){
		scanf("%d",&arr[i]);
	}
}

void print_array(int ar[] , int n){
	for(int i = 0 ; i<n ; i++){
		printf("%d ",ar[i]);
	}
	printf("\n");
}

void solve(int arr[] , int n){

	for(int i = 1 ; i<n ; i++){
		int j = i-1;
		int temp = arr[i];
		while(j>=0 && temp < arr[j]){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = temp;
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
