#include<iostream>
#include<fstream>
#include<memory.h>
using std::cin;
using std::cout;
const int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int n, m, k, res;
bool map[34][34];
int x, y;
int adj[34][34];
bool visit[34][34];
bool find(int x, int y)
{
	int x1, y1, d;
	for (int i = 0; i < 4; i++)
	{
		x1 = x + dir[i][0], y1 = y + dir[i][1];
		if (x1 > 0 && y1 > 0 && x1 <= n && y1 <= m && map[x1][y1] && !visit[x1][y1])
		{
			visit[x1][y1] = true;
			d = adj[x1][y1];
			if (d == -1 || find(x1+dir[d][0], y1+dir[d][1]))
			{
				adj[x1][y1] = (i + 2) % 4;
				return true;
			}
		}
	}
	return false;
}
int main()
{
// 	freopen("in.txt", "r", stdin);
	memset(map, 1, sizeof(map));
	cin >> n >> m >> k;
	res = n * m - k;
	if (res % 2 == 1)
		cout << "NO\n";
	else
	{
		res /= 2;
		while (k--)
		{
			cin >> x >> y; 
			map[x][y] = false;
		}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				adj[i][j] = -1;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if ((i+j) % 2 == 1 && map[i][j])
				{	
					memset(visit, 0, sizeof(visit));
					if (find(i, j))
						res--;
				}
		if (res == 0) cout << "YES\n";
		else cout << "NO\n";
	}
}

