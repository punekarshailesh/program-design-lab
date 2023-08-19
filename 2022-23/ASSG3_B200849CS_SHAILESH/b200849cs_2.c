#include <stdio.h>
#include <stdlib.h>


void read_array(int ar[], int size){
	for(int i = 0 ; i<size ; i++){
		scanf("%d",&ar[i]);
	}
}

void print_array(int ar[] , int n){
	for(int i = 0 ; i<n ; i++){
		printf("%d ",ar[i]);
	}
	printf("\n");
}

void Solve(int ar[] , int n){
	for(int i = 1 ; i<n ; i++){
		int temp = ar[i];
		int j = i-1;
		while(j>=0 && ar[j] > temp){
			ar[j+1] = ar[j];
			j--;
		}
		ar[j+1] = temp;
	}
}

int main(){

	int n;
	scanf("%d",&n);

	int * arr = (int*)malloc(n * sizeof(int));

	read_array(arr , n);

	Solve(arr , n);

	print_array(arr , n);

	return 0;
}