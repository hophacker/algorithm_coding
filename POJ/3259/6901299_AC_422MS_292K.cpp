#include<iostream>
#include<fstream>
#include<limits.h>
using namespace std;
struct node
{
	int s, e, d;
};
int n, m, w;
int a, b, d, num;
node way[5205];
int dis[501];
int main()
{
//	freopen("in.txt", "r", stdin);
	int tests;
	cin >> tests;
	while (tests--)
	{
		num = 0;
		cin >> n >> m >> w;
		for (int i = 1; i <= m; i++)
		{
			cin >> a >> b >> d;
			num++;
			way[num].s = a;
			way[num].e = b;
			way[num].d = d;
			num++;
			way[num].s = b;
			way[num].e = a;
			way[num].d = d;
		}
		for (int i = 1; i <= w; i++)
		{
			cin >> a >> b >> d;
			num++;
			way[num].s = a;
			way[num].e = b;
			way[num].d = -d;
		}
		fill(&dis[0], &dis[500], 10000);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= num; j++)
				dis[way[j].e] = min(dis[way[j].e], dis[way[j].s] + way[j].d);
		bool yes = false;
		for (int j = 1; j <= num; j++)
			if (dis[way[j].s] + way[j].d < dis[way[j].e])
			{
				yes = true;
				break;
			}
		if (yes) cout << "YES\n"; else cout << "NO\n"; 			
	}
}
