#include<iostream>
#include<fstream>
using namespace std;
struct node
{
	int pri, gra, num;
	int p[110], mon[110];
}obj[110];
int m, n, i, j, r, l, h, t;
int dis[110];
int line[100005];
inline bool ok(int k)
{
	return k >= l && k <= r;
}
int doit()
{
	for (int i = 1; i <= n; i++) dis[i] = 1000000000;
	line[0] = 1;
	h = t = 0;
	dis[1] = 0;
	int u, v;
	while (h <= t)
	{
		u = line[h];
		for (int i = 1; i <= obj[u].num; i++)
		{
			v = obj[u].p[i];
			if (ok(v) && dis[u] + obj[u].mon[i] < dis[v])
			{
				dis[v] = dis[u] + obj[u].mon[i];
				line[++t] = v;
			}
		}
		h++;
	}
	int minM = 1000000000;
	for (int i = 1; i <= n; i++)
		if (dis[i] + obj[i].pri < minM)
			minM = dis[i] + obj[i].pri;
	return minM;
}
int main()
{
	//freopen("in.txt", "r", stdin);
	cin >> m >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> obj[i].pri >> obj[i].gra >> obj[i].num;
		for (j = 1; j <= obj[i].num; j++)
			cin >> obj[i].p[j] >> obj[i].mon[j];
	}
	int minP = obj[1].pri;
	for (i = -m; i <= 0; i++)
	{
		l = obj[1].gra + i;
		r = l + m;
		minP = min(doit(), minP);
	}
	cout << minP << endl;
}
