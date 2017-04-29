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

	while(1){
		int j,child[k];
		for(j=1;j<=k;j++){
			if((k*i)+j<n){
				child[j]=(k*i)+j;
			}else{
				child[j]=-1;
			}
		}
		int maxChild=-1,maxChildIndex;
		for(j=1;j<=k;j++){
			if(child[j]!=-1 && array[child[j]]>maxChild){
				maxChild=array[child[j]];
				maxChildIndex=child[j];
			}
		}
		if(maxChild== -1){
			break;
		}
		if(array[maxChildIndex]>array[i]){
			swap(array,maxChildIndex,i);
		}
		i=maxChildIndex;
	}	
}
void restoreUp(int *array,int n,int k){
	int parent = (n)/k;
	while(parent>=0){
		if(array[parent]<array[n]){
			swap(array,parent,n);
			n=parent;
			parent=(n)/k;
		}
		else{
			break;
		}
	}
}
void extractMax(int *array,int *n,int k){
	int max=array[0];
	array[0]=array[*n-1];
	*n=*n-1;
	restoreDown(array,*n,k,0);
}

void insert(int *array,int *n,int k,int e){
	array[*n]=e;
	*n=*n+1;
	restoreUp(array,*n-1,k);
}

void buildHeap(int *array,int n,int k){
	int i;
	for(i=(n-1)/k;i>=0;i--){
		restoreDown(array,n,k,i);
	}
}
int main(){
	int n, *array,k,i;
	scanf("%d%d",&n,&k);
	array=(int *)malloc(n*sizeof(int));

	for(i=0;i<n;i++){
		scanf("%d",&array[i]);
	}
	buildHeap(array,n,k);
	int element;
	scanf("%d",&element);
	 for(i=0;i<n;i++){
                printf("%d\t",array[i]);
        }

	insert(array,&n,k,element);
	 for(i=0;i<n;i++){
                printf("%d\t",array[i]);
        }
	printf("\n");
	extractMax(array,&n,k);
	for(i=0;i<n;i++){
		printf("%d\t",array[i]);
	}

	return 0;
}
