#include<iostream>
#include<fstream>
#include<cmath>
#include<algorithm>
using namespace std;

struct Point
{
	int x, y;
}p[1002], hull[1002];
int n, len, top;
bool cmp(const Point& a, const Point& b)
{
	if (a.y == b.y) return a.x < b.x;
	else return a.y < b.y;
}
int det(int x1, int y1, int x2, int y2)
{
	return x1 * y2 - x2 * y1;
}
int cross(Point &a, Point &b, Point &c)
{
	return det(b.x-a.x, b.y-a.y, c.x-a.x, c.y-a.y);
}
void graham()
{
	hull[1] = p[1];
	hull[2] = p[2];
	top = 2;
	for (int i = 3; i <= n; i++)
	{
		while (top >= 2 && cross(hull[top-1], hull[top], p[i]) <= 0) top--;
		hull[++top] = p[i];
	}
	int len = top;
	hull[++top] = p[n-1];
	for (int i = n-2; i >= 1; i--)
	{
		while (top >= len+1 && cross(hull[top-1], hull[top], p[i]) <= 0) top--;
		hull[++top] = p[i];
	}
}
double dis(Point &a, Point &b)
{
	return sqrt(((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y))*1.0);
}
int main()
{
	//ifstream cin("E:\\My Programs\\in.txt");
	cin >> n >> len;
	for (int i = 1; i <= n; i++) cin >> p[i].x >> p[i].y;
	sort(p+1, p+n+1, cmp);
	graham();
	double s = 0;
	for (int i = 1; i <= top-1; i++)
		s += dis(hull[i], hull[i+1]);
	s += len*3.14159265358979*2;
	printf("%.0lf\n", s);
	//system("pause");
}
