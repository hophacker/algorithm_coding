#include<iostream>
#include<fstream>
#include<algorithm>
#include<cmath>
using namespace std;
const double precision = 1e-8; 
struct Point 
{
	double x, y;
}u[21], d[21];

int dblcmp(double d)
{
	if (fabs(d) < precision)
		return 0;
	return (d > 0)?1 : -1;
}
double det(double x1, double y1, double x2, double y2)
{
	return x1 * y2 - x2 * y1;
}
double cross(Point a, Point b, Point c)
{
	return det(b.x-a.x, b.y-a.y, c.x-a.x, c.y-a.y);
	//<0 ac在ab的右旋方向
	//>0 ac在ab的左旋方向 
	// == 0 三点共线 
}
bool segcross(Point a, Point b, Point c, Point d)
{
	double s1, s2;
	int d1, d2;
	d1 = dblcmp(s1 = cross(a, b, c)); 
	d2 = dblcmp(s2 = cross(a, b, d));
	if (d1 * d2 <= 0)
		return true;
	else return false;	
}
double calc(Point a, Point b, Point c, Point d)
{
	double s1, s2;
	int d1, d2;
	d1 = dblcmp(s1 = cross(a, b, c));
	d2 = dblcmp(s2 = cross(a, b, d));
	if (d1 == 0) return c.x;
	if (d2 == 0) return d.x;
	return (c.x*s2-d.x*s1)/(s2-s1);
}
int main()
{
	//ifstream cin("E:\\My Programs\\in.txt");
	int n;
	while (cin >> n, n)
	{
		bool through = false;
		for (int i = 1; i <= n; i++)
			cin >> u[i].x >> u[i].y, d[i].x = u[i].x, d[i].y = u[i].y - 1;
		double ma = u[1].x, x;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				int k;
				for (k = 1; k <= n; k++)
					if (!segcross(u[i], d[j], u[k], d[k])) break;
				if (k == n+1) {
					through = true;		
					break;
				}else if (k > 1)
				{
					if (segcross(u[i], d[j], u[k], u[k-1])){
						x = calc(u[i], d[j], u[k], u[k-1]);
						ma = max(x, ma);
					}
					if (segcross(u[i], d[j], d[k], d[k-1])){
						x = calc(u[i], d[j], d[k], d[k-1]);
						ma = max(x, ma);
					}
				}
							
			}
			if (through) break;
		}
		if (through) cout << "Through all the pipe." << endl;
		else printf("%.2lf\n", ma);

	}
	//system("pause");
}
