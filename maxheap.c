#include<stdio.h>
#include<stdlib.h>
void swap(int *array, int i, int j)
{
	int temp;
	temp = array[i];
	array[i] =array[j];
	array[j] = temp;
}
void restoreDown(int *array,int n,int k,int i){
	int j,child[k];
while(1){
	for(j=0;i<k;i++){
		if((k*i)+j<n){
			child[j]=(k*i)+j;
		}else{
			child[j]=-1;
		}
	}
	int maxChild=-1,maxChildIndex;
	for(j=0;j<k;j++){
		if(child[j]!=-1 && array[child[j]]>maxChild){
			maxChild=array[child[j]];
			maxChildIndex=child[j];
		}
	}
	if(maxChild== -1)
		break;
	if(array[maxChildIndex]>array[i]){
		swap(array,maxChildIndex,i);
	}
	i=maxChildIndex;
}	
}
void buildHeap(int *array,int n,int k){
	int i;
	printf("hi");
	for(i=(n-1)/k;i>=0;i--){
		printf("in buildheap %d",i);
		restoreDown(array,n,k,i);
	}
}
int main(){
	int n, *array,k,i;
	scanf("%d%d",&n,&k);
	array=(int *)malloc(n*sizeof(int));
//	printf("hi");

	for(i=0;i<n;i++){
		scanf("%d",&array[i]);
	}
//	printf("hi");
//	 for(i=0;i<n;i++){
  //            printf("%d\t",array[i]);
 //     }

	buildHeap(array,n,k);
	for(i=0;i<n;i++){
		printf("%d\t",array[i]);
	}

	return 0;
}
