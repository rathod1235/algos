#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define N 4
bool isSafe(int next_x,int next_y,int i){
	return (next_x>=0 && next_x<N && next_y >=0 && next_y<N && i==-1);
}
void printSolution(int sol[N][N]){
	int x,y;
	for(x=0;x<N;x++){
		for(y=0;y<N;y++){
			printf("%d\t",sol[x][y]);
		}
		printf("\n");
	}
}
int solveKTUtil(int x,int y,int movei,int sol[N][N],int xMove[N],int yMove[N]){
	int k,next_x,next_y;
	if(movei==N*N)
		return true;
	for(k=0;k<N;k++)
	{
		next_x=x+xMove[k];
		next_y=y+yMove[k];
		if(isSafe(next_x,next_y,sol[next_x][next_y]))
		{
			sol[next_x][next_y]=movei;
			printf("x=%d y=%d step=%d\n",next_x,next_y,sol[next_x][next_y]);
			if(solveKTUtil(next_x,next_y,movei+1,sol,xMove,yMove)==true)
			{
				return true;
			}else
			{
				sol[next_x][next_y]=-1;  //backtracking
			}
		}
	}
	return false;
}
bool solveKT(){
	int sol[N][N],i,x,y;
	for(x=0;x<N;x++)
		for(y=0;y<N;y++)
			sol[x][y]=-1;
	int xMove[N]={ 1,-1,-1,1};
	int yMove[N]={ 1,-1,1,-1};
	sol[1][1] = 0;
	if(solveKTUtil(1,1,1,sol,xMove,yMove)== false){
		printf("solution does not exist\n");
		return false;
	}
	else{
		printSolution(sol);
	}
	return true;
}

int main(){
	solveKT();
	return 0;
}
