#include<iostream>
#include<memory.h>
#include<fstream>
using namespace std;

const int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
struct node
{
	int x, y;
}adj[42][12];
int h, w;
char map[42][12];
bool ok[42][12];
bool used[42][12];
bool search(int x, int y)
{
	int x1, y1;
	for (int fx = 0; fx <= 3; fx++)
	{
		x1 = x + dir[fx][0];
		y1 = y + dir[fx][1];
		if (ok[x1][y1] && map[x1][y1] == '*' && !used[x1][y1])
		{
			used[x1][y1] = true;
			if (adj[x1][y1].x == -1 || search(adj[x1][y1].x, adj[x1][y1].y))
			{
			 	adj[x1][y1].x = x;
				adj[x1][y1].y = y;
				return true;
			}
		}
	}
	return false;
}
int main()
{
//	freopen("in.txt", "r", stdin);
	int tests;
	cin >> tests;
	while (tests--)
	{
		memset(ok, 0, sizeof(ok));
		int total = 0;
		cin >> h >> w;
		for (int i = 1; i <= h; i++)
			for (int j = 1; j <= w; j++)
			{
				cin >> map[i][j];
				if (map[i][j] == '*') total++;
				adj[i][j].x = -1;
				ok[i][j] = true;
			}
		int place = 0;
		for (int i = 1; i <= h; i++)
			for (int j = 1; j <= w; j++)
				if ((i+j)%2 == 0 && map[i][j] == '*')
				{
					memset(used, 0, sizeof(used));
					used[i][j] = true;
					if (search(i, j))
						place += 2;	
				}
		cout << place / 2 + total - place << endl;
	}
}
