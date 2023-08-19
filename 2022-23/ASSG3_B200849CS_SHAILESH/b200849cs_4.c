#include <stdio.h>
#include <stdlib.h>

void read_array(int ar[] , int n){
	for(int i = 0 ; i<n ; i++){
		scanf("%d",&ar[i]);
	}
}

void Solution(int ar[] , int n, int k){

	for(int i = 1 ; i<n ; i++){
		int temp = ar[i];
		int j = i-1;
		while(j>=0 && ar[j] < temp){
			ar[j+1] = ar[j];
			j--;
		}
		ar[j+1] = temp;
	}

	int i = 0;
	while(i < k){
		printf("%d ",ar[i]);
		i++;
	}
}


int main(){

	int n, k;
	scanf("%d %d",&n , &k);

	int * arr = (int*)malloc(n*sizeof(int));

	read_array(arr , n);

	Solution(arr , n, k);

	return 0;
}