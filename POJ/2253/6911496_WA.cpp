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
	//freopen("in.txt", "r", stdin);
	int tests = 0, i, j;
	int q[202];
	bool visit[202];
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
		for (i = 2; i <= n; i++)
			minDis[i] = dis[1][i];
		int h = 0, t = 0;
		memset(visit, 0, sizeof(visit));
		q[h] = 1, visit[1] = true;
		while (!visit[2])
		{
			double minD = 1e30;
			int minP;
			for (i = 1; i <= n; i++)
				if (!visit[i] && minDis[i] < minD)
					minD = minDis[i], minP = i;
			visit[minP] = true;
			for (i = 1; i <= n; i++)
				if (!visit[i] && dis[minP][i] < minDis[i])
					minDis[i] = dis[minP][i];
		}
		printf("Scenario #%d\n", tests);
		printf("Frog Distance = %0.3f\n\n", minDis[2]);
	}
}