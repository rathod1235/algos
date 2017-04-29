#include<stdio.h>
#include<stdbool.h>
#define N 4
void printSol(int sol[N][N]){
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%d\t",sol[i][j]);
		}
		printf("\n");
	}
}
bool isSafe(int x,int y,int maze[N][N]){
	 if(x>=0 && x<N && y>=0 && y<N && maze[x][y]==1)
		return true;
	return false;
}
bool solveMazeUtil(int x,int y,int maze[N][N],int sol[N][N]){
	
	if(x==N-1 && y==N-1){
		sol[x][y]=1;
		return true;
	}
	if(isSafe(x,y,maze)==true){
		sol[x][y]=1;	
		if(solveMazeUtil(x+1,y,maze,sol)==true){
			return true;
		}
		if(solveMazeUtil(x,y+1,maze,sol)==true){
			return true;
		}
		sol[x][y]=0;
		return false;
	}
	return false;
}

bool solveMaze(int maze[N][N]){
	int sol[N][N]= { { 0,0,0,0},
			 { 0,0,0,0},
			 { 0,0,0,0},
			 { 0,0,0,0}
			};
	solveMazeUtil(0,0,maze,sol);
	if(solveMazeUtil(0,0,maze,sol)==false){	
			
		printf("solution doesn't exist\n");
		return false;
	}
	printSol(sol);
	return true;
}
int main(){
	int maze[N][N] ={ { 1,0,0,0},
			  { 1,1,0,1},
			  { 0,1,0,0},
			  { 1,1,1,1}
			};
//	printSol(maze);	
	bool x;
	x=solveMaze(maze);
	return 0;
}
