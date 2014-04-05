#include<iostream>
#include<stdio.h>
#include <math.h>
#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)
using namespace std;
struct point{double x,y;};
point p[20000];
point convex[20000];
//计算cross product (P1-P0)x(P2-P0)
double xmult(point p1,point p2,point p0){
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
//graham算法顺时针构造包含所有共线点的凸包,O(nlogn)
point p1,p2;
int graham_cp(const void* a,const void* b){
	double ret=xmult(*((point*)a),*((point*)b),p1);
	return zero(ret)?(xmult(*((point*)a),*((point*)b),p2)>0?1:-1):(ret>0?1:-1);
}
void _graham(int n,point* p,int& s,point* ch){
	int i,k=0;
	for (p1=p2=p[0],i=1;i<n;p2.x+=p[i].x,p2.y+=p[i].y,i++)
		if (p1.y-p[i].y>eps||(zero(p1.y-p[i].y)&&p1.x>p[i].x))
			p1=p[k=i];
	p2.x/=n,p2.y/=n;
	p[k]=p[0],p[0]=p1;
	qsort(p+1,n-1,sizeof(point),graham_cp);
	for (ch[0]=p[0],ch[1]=p[1],ch[2]=p[2],s=i=3;i<n;ch[s++]=p[i++])
		for (;s>2&&xmult(ch[s-2],p[i],ch[s-1])<-eps;s--);
}
int graham(int n,point* p,point* convex,int maxsize=1,int dir=1){
	point* temp=new point[n];
	int s,i;
	_graham(n,p,s,temp);
	for (convex[0]=temp[0],n=1,i=(dir?1:(s-1));dir?(i<s):i;i+=(dir?1:-1))
		if (maxsize||!zero(xmult(temp[i-1],temp[i],temp[(i+1)%s])))
			convex[n++]=temp[i]; 
	delete []temp;
	return n;
}
int dots_inline(point p1,point p2,point p3){
	return zero(xmult(p1,p2,p3));
}
int main()
{
	//freopen("H:/ACM/POJ/in.txt", "r", stdin); 
	//freopen("H:/ACM/POJ/out.txt", "w", stdout); 
	int tests, n, num;
	scanf("%d", &tests);
	while(tests--){
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%lf%lf", &p[i].x, &p[i].y);
		
		if(n<3){printf("NO\n");continue;}
		num = graham(n, p, convex, 1, 1);
		if (num < n) printf("NO\n");
		else{
			bool isCon = false;
			for (int i = 0; i < n; i++)
				if (!dots_inline(p[i%n],p[(i+1)%n],p[(i+2)%n])) isCon = true;
			if (!isCon)
				{printf("NO\n");continue;}
			bool ok = true;
			for (int i = 1; i < n+1; i++){
				if (!dots_inline(p[i%n],p[(i+1)%n],p[(i+2)%n]) && !dots_inline(p[i%n],p[(i+1)%n],p[(i-1)%n])){
					ok = false;
					break;
				}
			}
			if (ok) printf("YES\n");
			else printf("NO\n");
		}
	}
}