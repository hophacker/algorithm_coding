#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

const double PI = 3.14159265358979;
struct point
{
	double x, y;
}p[10000], g;
int n;
double gr;
double cross(point& a, point& b, point& c)
{
	return (b.x-a.x) * (c.y-a.y) - (c.x-a.x)*(b.y-a.y);
}
double len(point& a, point& b)
{
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
double dot(point& a, point& b, point& c)
{
	double t = (b.x-a.x)*(c.x-a.x) + (b.y-a.y)*(c.y-a.y);
	if (cross(a, b, c) < 0) return -t; else return t;
}
bool inside(point p[], int n, point &g)
{
	double total = 0, angle;
	for (int i = 0; i < n; i++)
	{
		angle = acos(dot(g, p[i], p[i+1]) / len(g, p[i]) / len(g, p[i+1]));
		if (abs(abs(angle)-PI) < 0.0001) return false;
		else total += angle;
	}
	if (abs(total) < 0.0001) return false;
	else return true;
}
int main()
{
	//freopen("in.txt", "r", stdin);
	while (cin >> n, n >= 3)
	{
		scanf("%lf%lf%lf", &gr, &g.x, &g.y);
		for (int i = 0; i < n; i++)
			scanf("%lf%lf", &p[i].x, &p[i].y);
		p[n] = p[0];
		bool ok = true;
		double t1 = cross(p[0], p[1], p[2]), t2;
		for (int i = 1; i <= n-2; i++)
		{
			t2 = cross(p[i], p[i+1], p[i+2]);
			if (t2 * t1 > 0)
				t1 = t2;
			else
			{
				ok = false;
				break;
			}
		}
		if (ok)
		{
			if (inside(p, n, g))
			{
				ok = true;
				for (int i = 0; i < n; i++)
					if (abs(cross(g, p[i], p[i+1])) / len(p[i], p[i+1]) < gr)
					{
						ok = false;
						break;
					}
				if (ok) printf("PEG WILL FIT\n");
				else printf("PEG WILL NOT FIT\n");
			}
			else printf("PEG WILL NOT FIT\n");
		}else
			printf("HOLE IS ILL-FORMED\n");
	}
}
