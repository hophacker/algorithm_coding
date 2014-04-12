#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

struct node
{
	int u, v;
	double  d;
}way[101];
double disIt(double a, double b, double c)
{
	return pow(a*a+b*b+c*c, 0.5);
}
double calc(double a[4], double b[4])
{
	double dis = disIt(a[1]-b[1], a[2]-b[2], a[3]-b[3]); 
	if (dis > a[0]+b[0]) return dis - a[0] - b[0];
	else return 0;
}
int main()
{
	//freopen("in.txt", "r", stdin);
	int n;
	while (cin >> n, n)
	{
		double p[101][4], dis[101][101];
		for (int i = 1; i <= n; i++)
			scanf("%lf %lf %lf %lf", &p[i][1], &p[i][2], &p[i][3], &p[i][0]);
		for (int i = 1; i <= n-1; i++)
			for (int j = i+1; j <= n; j++)
				dis[i][j] = dis[j][i] = calc(p[i], p[j]);
		for (int i = 1; i < n; i++)	
			way[i].u = 1, way[i].v = i+1, way[i].d = dis[1][i+1];
		double minDis = 0;
		for (int time = 1; time < n; time++)
		{
			int minp; double mind = 1e20;
			for (int i = time; i < n; i++)
				if (way[i].d < mind) mind = way[i].d, minp = i;
			swap(way[time], way[minp]);
			minDis += way[time].d;
			int from = way[time].v;
			for (int i = time+1; i < n; i++)
				if (dis[from][way[i].v] < way[i].d)
					way[i].u = from, way[i].d = dis[way[i].v][way[i].u];
		}
		printf("%0.3lf\n", minDis);
	}
}
