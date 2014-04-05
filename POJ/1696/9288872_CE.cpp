#include <iostream>
using namespace std;
#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)
struct point{
	double x,y;
	int index;
};
point p[50], convex[50];
//计算cross product (P1-P0)x(P2-P0)
double xmult(point p1,point p2,point p0){
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
//graham算法顺时针构造包含所有共线点的凸包,O(nlogn)
point p1,p2;
int graham_cp(const void* a,const void* b){
	double ret=xmult(*((point*)a),*((point*)b),p1);
	if (zero(ret)){
		if (  fabs(((point*)a)->x - p1.x) >  fabs(((point*)b)->x - p1.x))
			return 1; 
		else 
			return -1;
	}else{
		return (ret>0?1:-1);
	}
}
void calc(int n,point* p){
	p1 = p[n];
	qsort(p,n,sizeof(point),graham_cp);
}
int main(){
	//freopen("H:/ACM/POJ/in.txt", "r", stdin); 
	int tests, n, m;
	scanf("%d", &tests);
	while(tests--){
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d%lf%lf", &p[i].index, &p[i].x, &p[i].y);
		for (int i = 0; i < n-1; i++)
			if (p[i].y < p[n-1].y) swap(p[i], p[n-1]);
		printf("%d", n);
		for (int i = n-1; i >= 1; i--){
			calc(i, p);
			printf(" %d", p[i].index);
		}
		printf(" %d\n", p[0].index);
	}
}