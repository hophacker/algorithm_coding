#include<iostream>
#include<memory.h>
#include<fstream>
using namespace std;
struct node
{
	int x, fa;
};
int n, np, nc, m;
int c[102][102], f[102][102];
bool used[102];
bool Ford_Fulkerson()
{
	node q[102];
	int h, t, u, v;
	memset(used, false, sizeof(used));
	used[0] = true;
	h = t = 0;
	q[h].x = 0; q[h].fa = -1;
	while (h <= t && !used[n+1])
	{
		u = q[h].x;
		for (int i = n+1; i >= 1; i--)
		{
			if (!used[i] && c[u][i] - f[u][i] > 0)
			{
				t++;
				q[t].x = i, q[t].fa = h;
				used[i] = true;
				if (i == n+1) break;
			}
		}
		h++;
	}
	if (used[n+1]) 
	{
		int minw = 10000000;
		int s = t;
		while (q[s].fa != -1)
		{
			u = q[q[s].fa].x;
			v = q[s].x;
			if (c[u][v] - f[u][v] < minw) minw = c[u][v] - f[u][v];
			s = q[s].fa;
		}
		s = t;
		while (q[s].fa != -1)
		{
			u = q[q[s].fa].x;
			v = q[s].x;
			f[u][v] += minw;
			s = q[s].fa;
		}
		return true;
	}
	else return false;
}
int main()
{	
//	freopen("in.txt", "r", stdin);
	while (cin >> n >> np >> nc >> m)
	{
		memset(c, 0, sizeof(c));
		memset(f, 0, sizeof(f));
		int a, b, d;
		char ch;
		for (int i = 1; i <= m; i++)
		{	
			cin >> ch;
			scanf("%d", &a);
			cin >> ch;
			scanf("%d", &b);
			cin >> ch;
			scanf("%d", &d);
			c[a+1][b+1] = d;
		}
		for (int i = 1; i <= np; i++)
		{
			cin >> ch >> a >> ch >> d;
			c[0][a+1] = d;
		}
		for (int i = 1; i <= nc; i++)
		{
			cin >> ch >> a >> ch >> d;
			c[a+1][n+1] = d;
		}
		while (Ford_Fulkerson()){};
		int con = 0;
		for (int i = 1; i <= n; i++)
			con += f[i][n+1];
		cout << con << endl;
	}
}
