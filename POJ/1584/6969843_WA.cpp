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
	double t = sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
	if (t == 0) t = 0.0000000001;
	return t;
}
double dot(point& a, point& b, point& c)
{
	return (b.x-a.x)*(c.x-a.x) + (b.y-a.y)*(c.y-a.y);
}
bool inside(point p[], int n, point &g)
{
	double total = 0, angle;
	for (int i = 0; i < n; i++)
	{
		double t = cross(g, p[i], p[i+1]);
		double k = (dot(g, p[i], p[i+1]) / len(g, p[i]) / len(g, p[i+1]));
		if (k > 1) k = 1;if (k < -1) k = -1;
		angle = acos(k);
		if (t > 0) total += angle; else total -= angle;
	}
	if (abs(total) < 0.0001) return false;
	else return true;
}
int main()
{
	//freopen("E:\\My Programs\\in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	while (cin >> n, n >= 3)
	{
		scanf("%lf%lf%lf", &gr, &g.x, &g.y);
		for (int i = 0; i < n; i++)
			scanf("%lf%lf", &p[i].x, &p[i].y);
		p[n] = p[0];
		p[n+1] = p[1]; //!!!!!!!!!!!!!!
		bool fu = false, zh = false;   /////////////////
		double t1;
		for (int i = 0; i <= n-1; i++)  // n-2 ------> n-1
		{ 
			t1 = cross(p[i], p[i+1], p[i+2]);
			if (t1 > 0) zh = true;
			if (t1 < 0) fu = true;
		}
		if (!(fu && zh))
		{
			if (inside(p, n, g))
			{
				bool ok = true;
				for (int i = 0; i < n; i++)
					if (abs(cross(g, p[i], p[i+1])) / len(p[i], p[i+1]) <= gr)
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
