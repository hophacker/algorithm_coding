#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

struct node
{
	double x, y;
}p[4];
int n;
double a[33], b[33], c[33], d[33];

void input(double a[])
{
	for (int i = 1; i <= n; i++) cin >> a[i];
}
void calcPoint(double a, double b, double c, double d, node& p)
{
	p.x = (a+(b-a)*c) / (1-(b-a)*(d-c));
	p.y = c + (d-c) * p.x;
}
double cross(double x1, double y1, double x2, double y2)
{
	return x1 * y2 - y1 * x2;
}
double calcArea(node p[])
{
	double s = 0;
	for (int i = 1; i <= 2; i++)
		s += cross(p[i].x-p[0].x, p[i].y-p[0].y, p[i+1].x-p[0].x, p[i+1].y-p[0].y);
	return abs(s / 2);
}
int main()
{
	//freopen("in.txt", "r", stdin);
	while (cin >> n, n)
	{
		a[0] = 0; input(a); a[n+1] = 1;
		b[0] = 0; input(b); b[n+1] = 1;
		c[0] = 0; input(c); c[n+1] = 1;
		d[0] = 0; input(d); d[n+1] = 1;
		double maxArea = 0;
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= n; j++)
			{
				calcPoint(a[i], b[i], c[j], d[j], p[0]);
				calcPoint(a[i+1], b[i+1], c[j], d[j], p[1]);
				calcPoint(a[i+1], b[i+1], c[j+1], d[j+1], p[2]);
				calcPoint(a[i], b[i], c[j+1], d[j+1], p[3]);
				maxArea = max(calcArea(p), maxArea);
			}
		printf("%0.6lf\n", maxArea);
	}
}
