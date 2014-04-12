#include<iostream>
#include<stdio.h>
using namespace std;
#include <math.h>
#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)
struct point{double x,y;};

point p[20], p1[20];
double area_polygon(int n,point* p){
	double s1=0,s2=0;
	int i;
	for (i=0;i<n;i++)
		s1+=p[(i+1)%n].y*p[i].x,s2+=p[(i+1)%n].y*p[(i+2)%n].x;
	return fabs(s1-s2)/2;
}
int main()
{
	//freopen("H:/ACM/POJ/in.txt", "r", stdin); 
	//freopen("H:/ACM/POJ/out.txt", "w", stdout); 
	int tests, n, m, maxS, k, t, maxK, s;
	scanf("%d", &tests);
	while(tests--){
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%lf%lf", &p[i].x, &p[i].y);
		scanf("%d", &m);
		maxK = -1;
		for (int i = 0; i < m; i++){
			scanf("%d", &k);
			for (int j = 0; j < k; j++){
				scanf("%d", &t);
				p1[j] = p[t-1];
			}
			s = fabs(area_polygon(k, p1));
			if (maxK == -1 || maxS < s){
				maxS = s;
				maxK = i;
			}
		}
		printf("%d\n", maxK+1);
	}
}
