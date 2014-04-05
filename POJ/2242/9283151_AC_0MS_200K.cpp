#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
#define PI 3.141592653589793
struct point{double x,y;};
point p1, p2, p3;
double a, b, c, cosA, sinA, d;

double distan(point p1,point p2){
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
int main()
{
	//freopen("H:/ACM/POJ/in.txt", "r", stdin); 
	//freopen("H:/ACM/POJ/out.txt", "w", stdout); 
	while(scanf("%lf%lf%lf%lf%lf%lf", &p1.x, &p1.y, &p2.x, &p2.y, &p3.x, &p3.y) != EOF){
		a = distan(p1, p2);
		b = distan(p2, p3);
		c = distan(p3, p1);
		cosA = (b*b+c*c-a*a)/(2*b*c);
		sinA = sqrt(1-cosA*cosA);
		d = a / sinA;
		printf("%0.2lf\n", d*PI);
	}
}