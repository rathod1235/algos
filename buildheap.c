#include<stdio.h>
#include<stdlib.h>
struct heap {
	int *arr;
	int count;
	int heap_size;
};
struct heap* create_heap(int heap_size) {
	struct heap* h=(struct heap*)malloc(sizeof(struct heap));
	if(h==NULL) {
		printf("memory error");
	}
	h->count=0;
	h->heap_size=heap_size;
	h->arr=(int *)malloc(sizeof(int)*h->heap_size);
	if(h->arr==NULL) {
		printf("memory error");
	}
	return h;
}
int left(struct heap* h,int i) {
	int l=((2*i));
	if(l>h->count) {
		return -1;
	}
	else {
		return l;
	}
}
int right(struct heap* h,int i) {
	int r=((2*i)+1);
	if(r>h->count) {
		return -1;
	}
	else {
		return r;
	}
}
void max_heapify(struct heap* h,int i) {
	int l,r,max;
	int temp;
	l=left(h,i);
	r=right(h,i);
	if(l<=h->heap_size&&h->arr[i]>h->arr[l]) {
		max=i;
	}
	else {
		max=l;
	}
	if(r<=h->heap_size&&h->arr[r]>h->arr[max]) {
		max=r;
	}
	if(max!=i) {
		temp=h->arr[i];
		h->arr[i]=h->arr[max];
		h->arr[max]=temp;
		max_heapify(h,max);
	}
}
void resize_heap(struct heap* h) {
	int *arr_old=h->arr;
	h->arr=(int *)malloc(sizeof(int)*h->heap_size*2);
	if(h->arr==NULL) {
		printf("memoryerror");
		return ;
	}
	for(int i=1;i<=h->heap_size;i++) {
		h->arr[i]=arr_old[i];
	}
	h->heap_size*=2;
	free(arr_old);
}
void build_heap(struct heap* h,int arr[],int n) {
	int i;
	if(h==NULL) {
		return ;
	}
	while(n>h->heap_size) {
		resize_heap(h);
	}
	for(i=1;i<=n;i++) {
		h->arr[i]=arr[i];
	}
	h->count=n;
	for(i=n/2;i>=1;i--) {
		max_heapify(h,i);
	}
}
	
int main() 
{
	struct heap* h=NULL;
	int arr[100],n,i,x;
	scanf("%d",&n);
	for(i=1;i<=n;i++) {
		scanf("%d",&arr[i]);
	}
	h=create_heap(n);
	for(i=1;i<=n;i++) {
		printf(" %d  ",arr[i]);
	}
	printf("\n");
	build_heap(h,arr,n);
	for(i=1;i<=n;i++) {
		printf(" %d  ",h->arr[i]);
	}
	printf("\n");
}
	
