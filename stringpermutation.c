#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void swap(char *s,int l,int r){
	char temp;
	temp= s[l];
	s[l]=s[r];
	s[r]=temp;
}
void permute(char *s,int l,int r){
	if(l==r){
	printf("%s\n",s);
	}
	int i;
	for(i=l;i<=r;i++){
		swap(s,l,i);
		permute(s,l+1,r);
		swap(s,l,i);  //backtracking
	}
}
int main(){
	char *s;
	s= (char *)malloc(sizeof(char));
	scanf("%s",s);
	int n=strlen(s);
	permute(s,0,n-1);
	return 0;
}
