#include <stdio.h>
# include <stdlib.h>

void dijkstra(int *,int *,int *,int,int);

int main()
{
  int **adj, *parent1,*parent2,*parent3;
  int n,k,i,j;
  scanf("%d",&n);
  adj = (int **)calloc(n,sizeof(int *));
  for(i=0;i<n;i++)
    {
      adj[i] = (int *)calloc(n,sizeof(int));
    }
  parent1 = (int *)calloc(n,sizeof(int));
  parent2 = (int *)calloc(n,sizeof(int));
  parent3 = (int *)calloc(n,sizeof(int));
  
  scanf("%d%d%d",&i,&j,&k);
  while(i!=-1)
    {
      adj[i][j]=w
      scanf("%d%d%d",&i,&j,&k);
    }
  scanf("%d%d",&s,&t);
  disjkstra(parent1,parent2,parent3,s,t);
  temp=t;
  printf("\n path1: %d",t);
  while(temp!=s)
    {
      printf("->%d",parent1[temp]);
      temp=parent1[temp];
    }
  temp=t;
  printf("\n path2: %d",t);
  while(temp!=s)
    {
      printf("->%d",parent2[temp]);
      temp=parent2[temp];
    }
  temp=t;
  printf("\n path3: %d",t);
  while(temp!=s)
    {
      printf("->%d",parent3[temp]);
      temp=parent3[temp];
    }
  return 0;
}

void dijkstra(int *p1,int *p2,int *p3,int s,int t)
{

  return;
}

