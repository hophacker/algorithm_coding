#include<iostream>
#include<fstream>
using namespace std;
struct node
{
	int s, e, d;
}way[101];
int n, i, j;
int dis[101][101];
int main()
{
	//freopen("in.txt", "r", stdin);
	while(cin >> n)
	{
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				cin >> dis[i][j];
		for (i = 1; i < n; i++)
			way[i].s = 1, way[i].e = i+1, way[i].d = dis[1][i+1];
		int cost = 0;
		for (int time = 1; time < n; time++)
		{
			int minD = 100000000, minP;
			for (i = time; i < n; i++)
				if (way[i].d < minD) minD = way[i].d, minP = i;
			swap(way[time], way[minP]);
			cost += way[time].d;
			int from = way[time].e;
			for (i = time+1; i < n; i++)
				if (dis[from][way[i].e] < way[i].d)
					way[i].d = dis[from][way[i].e], way[i].s = from;
		}
		cout << cost << endl;
	}
}