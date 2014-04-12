#include<iostream>
#include<fstream>
using namespace std;
struct node
{
	int u, v, d;
}dis[501];
int n;
int map[501][501];
int main()
{
//	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int tests;
	int mind, minp, from;
	cin >> tests;
	while (tests--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) scanf("%d", &map[i][j]);
		for (int i = 1; i < n; i++)
			dis[i].u = 1, dis[i].v = i+1, dis[i].d = map[1][i+1];
		for (int time = 1; time < n; time++)
		{
			mind = 100000000;
			for (int i = time; i < n; i++)
				if (dis[i].d < mind)
					mind = dis[i].d, minp = i;
			swap(dis[time], dis[minp]);
			from = dis[time].v;
			for (int i = time+1; i < n; i++)
				if (map[from][dis[i].v] < dis[i].d)
				{
					dis[i].u = from;
					dis[i].d = map[dis[i].u][dis[i].v];
				}
		}
		int maxd = -1;
		for (int i = 1; i < n; i++)
			if (dis[i].d > maxd) maxd = dis[i].d;
		cout << maxd << endl;
	}
}
