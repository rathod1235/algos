#include<stdio.h>
#include<stdlib.h>
void maxHeap(int *array,int n,int k){
	int i,parent,max=0;
	for(i=(n-1)/k;i<=0;i--){
		if(



int main(){
	int n, *array,k;
	scanf("%d%d",&n,&k);
	array=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		scanf("%d",&array[i]);
	maxHeap(array,n,k);


return 0;
}
