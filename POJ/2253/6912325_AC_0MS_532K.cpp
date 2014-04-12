#include<iostream>
#include<cmath>
#include<memory.h>
#include<stdio.h>
using namespace std;
struct node
{
	double x, y;
}p[201];
int n;
double dis[201][201];
double minDis[201];
inline double disIt(double a, double b)
{
	return sqrt(a*a + b*b);
}
int main()
{
//	freopen("in.txt", "r", stdin);
	int tests = 0, i, j;
	double temp;
	while (cin >> n && n != 0)
	{
		tests++;
		for (i = 1; i <= n; i++)
			cin >> p[i].x >> p[i].y;
		for (i = 1; i <= n-1; i++)
			for (j = i+1; j <= n; j++)
			{
				temp = disIt(p[i].x-p[j].x, p[i].y-p[j].y);
				dis[i][j] = dis[j][i] = temp;
			}
		for (i = 1; i < n; i++)
			minDis[i] = dis[1][i+1];
		int h = 0, t = 0;
		bool con = true;
		while (con)
		{
			double t, mint;
			con = false;
			for (i = 1; i < n; i++)
			{
				mint = 1e20;
				for (j = 1; j < n; j++)
					if (i != j)
					{
						t = max(minDis[j], dis[j+1][i+1]);
						if (t < mint) mint = t;
					}
				if (mint < minDis[i])
				{
					con = true;
					minDis[i] = mint;
				}
			}
		}
		printf("Scenario #%d\n", tests);
		printf("Frog Distance = %0.3f\n\n", minDis[1]);
	}
}
