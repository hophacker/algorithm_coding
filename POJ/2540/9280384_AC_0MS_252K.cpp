#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string>
#include <math.h>
using namespace std;
#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)
#define fin cin
//ifstream fin("H:/ACM/POJ/in.txt");
//freopen("H:/ACM/POJ/out.txt", "w", stdout); 
struct point{double x,y;};

double xmult(point p1,point p2,point p0){
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}

int same_side(point p1,point p2,point l1,point l2){
	return xmult(l1,p1,l2)*xmult(l1,p2,l2)>eps;
}

point intersection(point u1,point u2,point v1,point v2){
	point ret=u1;
	double t=((u1.x-v1.x)*(v1.y-v2.y)-(u1.y-v1.y)*(v1.x-v2.x))
			/((u1.x-u2.x)*(v1.y-v2.y)-(u1.y-u2.y)*(v1.x-v2.x));
	ret.x+=(u2.x-u1.x)*t;
	ret.y+=(u2.y-u1.y)*t;
	return ret;
}

//将多边形沿l1,l2确定的直线切割在side侧切割,保证l1,l2,side不共线
void polygon_cut(int& n,point* p,point l1,point l2,point side){
	point pp[100];
	int m=0,i;
	for (i=0;i<n;i++){
		if (same_side(p[i],side,l1,l2))
			pp[m++]=p[i];
		if (!same_side(p[i],p[(i+1)%n],l1,l2)&&!(zero(xmult(p[i],l1,l2))&&zero(xmult(p[(i+1)%n],l1,l2))))
			pp[m++]=intersection(p[i],p[(i+1)%n],l1,l2);
	}
	for (n=i=0;i<m;i++)
		if (!i||!zero(pp[i].x-pp[i-1].x)||!zero(pp[i].y-pp[i-1].y))
			p[n++]=pp[i];
	if (zero(p[n-1].x-p[0].x)&&zero(p[n-1].y-p[0].y))
		n--;
	if (n<3)
		n=0;
}
double area_polygon(int n,point* p){
	double s1=0,s2=0;
	int i;
	for (i=0;i<n;i++)
		s1+=p[(i+1)%n].y*p[i].x,s2+=p[(i+1)%n].y*p[(i+2)%n].x;
	return fabs(s1-s2)/2;
}
int main(){ 
	point p[100], p1, p2, pMid, l1, l2;
	double area = 100;
	int n = 4;
	p[0].x = 0,p[0].y = 0;
	p[1].x = 0,p[1].y = 10;
	p[2].x = 10,p[2].y = 10;
	p[3].x = 10,p[3].y = 0;
	p1.x = 0,p1.y = 0;
	string state;
    while(fin >> p2.x >> p2.y){
		fin >> state;
		l1.x = (p1.x+p2.x)/2;
		l1.y = (p1.y+p2.y)/2;
		l2.x = l1.x-(p2.y-p1.y), l2.y = l1.y+(p2.x-p1.x);
		if (state=="Colder"){
			polygon_cut(n, p, l1, l2, p1);
		}
		else if(state =="Hotter"){
			polygon_cut(n, p, l1, l2, p2);
		}else if(state =="Same"){
			if (!zero(p1.x-p2.x) || !zero(p1.y-p2.y)){
				area = 0;
			}
		}
		if (area > eps)
			area = area_polygon(n, p);
		printf("%0.2lf\n", area);
		p1 = p2;
    }
}