#include <stdio.h>
#include <stdlib.h>
#include<math.h>

struct point2d {
	int x,y;
};

struct point3d {
	int x,y,z;
};

void closestpair2d(struct point2d *,struct point2d *, int);
void closestpair3d(struct point3d *,struct point3d *,int);
void euclideanMST(struct point2d **,struct point2d *,int);

int main()
{
	struct point2d *points,close2d[2],**mst;
	struct point3d *plane,close3d[2];
	close2d[0].x = 99999;
	close3d[0].x = 99999;
	int i,n,m, j;
		scanf("%d",&n);
		points = (struct point2d *)malloc(n*sizeof(struct point2d));
		for(i=0;i<n;i++)
		scanf("%d%d",&(points[i].x),&(points[i].y));
	//	closestpair2d(close2d, points, n);
	//	for(i = 0; i < 2; i++){
	//	printf("%d, %d\n", close2d[i].x, close2d[i].y);
	//	}
	 
/*	scanf("%d",&m);
	plane = (struct point3d *)malloc(m*sizeof(struct point3d));
	for(i=0;i<m;i++)
		scanf("%d%d%d",&(plane[i].x),&(plane[i].y),&(plane[i].z));
	//	closestpair2d(close2d,points,n);
	closestpair3d(close3d,plane,m);

	for(i = 0; i < 2; i++){
		printf("%d, %d , %d\n", close3d[i].x, close3d[i].y , close3d[i].z);
	}

*/		mst = (struct point2d **)malloc((n-1)*sizeof(struct point2d *));
		for(i=0;i<n;i++)
		mst[i]=(struct point2d *)malloc(2*sizeof(struct point2d));
		euclideanMST(mst,points,n);
		for(i = 0; i < n-1; i++){
			for(j = 0; j < 2; j++){
				printf(" (%d , %d) ", mst[i][j].x, mst[i][j].y);
			}
			printf("\n");
		}
	
	return 0;
}
float dist(struct point2d a, struct point2d b){
	float distance = sqrt((a.x - b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
	return distance;
}
void sort(struct point2d * points, int n){
	int i, j;
	struct point2d temp;
	for(i = 0; i < n; i++){
		for(j = 0; j < n-1; j++){
			if(points[j].x > points[j+1].x){
				temp = points[j];
				points[j] = points[j+1];
				points[j+1] = temp;
			}
		}
	}
}
void sort_3d(struct point3d * plane, int n){
	int i, j;
	struct point3d temp;
	for(i = 0; i < n; i++){
		for(j = 0; j < n-1; j++){
			if(plane[j].x > plane[j+1].x){
				temp = plane[j];
				plane[j] = plane[j+1];
				plane[j+1] = temp;
			}
		}
	}
}

void min_dis(struct point2d *close2d, struct point2d *points, int n){
	int x, y, i, j;
	float  dis, d;
	struct point2d a, b;
	printf("in min_dist!!!");
	for(i = 0; i < n; i++){
		for(j= i+1; j < n; j++){
			dis = dist(points[i], points[j]);

			if(close2d[0].x != 99999){
				a = close2d[0];
				b = close2d[1];
				d = dist(a, b);
				if(dis < d){
					close2d[0] = points[i];
					close2d[1] = points[j];
				}
			}

			else{
				close2d[0] = points[i];
				close2d[1] = points[j];
			}

		}
	}

}
void closestpair2d(struct point2d *close2d, struct point2d *points, int n)
{
	if (n <= 3){
		return min_dis(close2d, points, n);
	}
	sort(points, n);
	int mid_pt = n/2;
	closestpair2d(close2d, points, mid_pt);
	closestpair2d(close2d, points+mid_pt, n-mid_pt);                                      

	float d_min = dist(close2d[0], close2d[1]);

	struct point2d *strip = (struct point2d *)malloc(n*sizeof(struct point2d));
	int j = 0, i;

	for(i = 0; i < n; i++){
		if(abs(points[i].x - points[mid_pt].x) < d_min){
			strip[j] = points[i];
			j++;
		}
	}

	min_dis(close2d, strip, j); 



}
float dist_3d(struct point3d a, struct point3d b){
	float distance = sqrt((a.x - b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) + (a.z -b.z)*(a.z - b.z));
	return distance;
}

void min_dist_3d(struct point3d *close3d, struct point3d *plane, int n){

	int x, y, i, j;
	float dis, d;
	struct point3d a, b;
	printf("in min_dist_3d!!!");
	for(i = 0; i < n; i++){
		for(j= i+1; j < n; j++){
			dis = dist_3d(plane[i], plane[j]);

			if(close3d[0].x != 99999){
				a = close3d[0];
				b = close3d[1];
				d = dist_3d(a, b);
				if(dis < d){
					close3d[0] = plane[i];
					close3d[1] = plane[j];
				}
			}

			else{
				close3d[0] = plane[i];
				close3d[1] = plane[j];
			}

		}
	}

}
void closestpair3d(struct point3d *close3d, struct point3d *plane,int m)
{

	if (m <= 3){
		min_dist_3d(close3d, plane, m);

	}

	else {
		sort_3d(plane, m);
		int mid = m/2;

		closestpair3d(close3d, plane, mid);
		closestpair3d(close3d, plane+mid, m-mid);

		float d_min = dist_3d(close3d[0], close3d[1]);

		struct point3d *strip = (struct point3d *)malloc(m*sizeof(struct point3d));
		int j = 0, i;

		for(i = 0; i < m; i++){
			if(abs(plane[i].x - plane[mid].x) < d_min && abs(plane[i].y - plane[mid].y) < d_min){
				strip[j] = plane[i];
				j++;
			}
		}

		min_dist_3d(close3d, strip, j);


	}
}

void make_set(int n , int * parent, struct point2d * points){
	int i;
	struct 
	for(i = 0; i < n; i++){
		parent[points[i].x = i;
	}
}

int find_parent(int * parent, int i){
	if(parent[i] == i){
		return i;
	else
		return parent[i] = find_parent(parent, parent[i]);
}
void unionn(int a, int  b, int  *parent){
	int pa, pb;
	pa = find_parent(parent, a);
	pb = find_parent(parent, b);

	if(pa != pb){
		parent[pa] = pb;
	}
}


void mstt(struct point2d **mst, struct point2d *points, int n){
	int i, j;
	sort(points, n);
	float d;
	float min;
	struct point2d point;
	for(i = 0; i < n-1; i++){
		min = 99999;
		for(j = 0; j < n; j++){
			d = dist(points[i],points[j] );
			if(d <= min && d != 0){
				min = d;
				point = points[j];
			}
		}

		mst[i][0] = points[i];
		mst[i][1] = point;
	}

}
void euclideanMST(struct point2d **mst,struct point2d *points,int n)
{

	if (n <= 3){
		mstt(mst, points,  n);

	}
}
/*	else {
		sort_3d(plane, m);
		int mid = m/2;

		closestpair3d(close3d, plane, mid);
		closestpair3d(close3d, plane+mid, m-mid);

		float d_min = dist_3d(close3d[0], close3d[1]);

		struct point3d *strip = (struct point3d *)malloc(m*sizeof(struct point3d));
		int j = 0, i;

		for(i = 0; i < m; i++){
			if(abs(plane[i].x - plane[mid].x) < d_min && abs(plane[i].y - plane[mid].y) < d_min){
				strip[j] = plane[i];
				j++;
			}
		}

		min_dist_3d(close3d, strip, j);


	}
*/


