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
	double t = (b.x-a.x) * (c.y-a.y) - (c.x-a.x)*(b.y-a.y);
	return t;
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
	bool fu = false, zh = false;
	double t;
	for (int i = 0; i < n; i++)
	{
		t = cross(g, p[i], p[i+1]);
		if (t > 0) zh = true;
		if (t < 0) fu = true;
	}
	if (!(zh&&fu)) return true; else return false;
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
		double pp, qq;
		if (!(fu && zh))
		{
			if (inside(p, n, g))
			{
				bool ok = true;
				for (int i = 0; i < n; i++)
					if (p[i].x != p[i+1].x || p[i].y != p[i+1].y)
					{
						pp = abs(cross(g, p[i], p[i+1]));
						qq = len(p[i], p[i+1]);
						pp = abs(pp);
						if ((pp / qq) < gr)
						{
							ok = false;
							break;
						}
					}
				if (ok) printf("PEG WILL FIT\n");
				else printf("PEG WILL NOT FIT\n");
			}
			else printf("PEG WILL NOT FIT\n");
		}else
			printf("HOLE IS ILL-FORMED\n");
	}
}
