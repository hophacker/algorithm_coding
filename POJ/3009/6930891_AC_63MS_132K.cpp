#include<iostream>
#include<fstream>
using namespace std;

const int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int map[22][22];
int h, w, sx, sy, ex, ey, ans;

void go(int dep, int x, int y)
{
	if (dep > 10) return;
	int x1, y1;
	for (int fx = 0; fx < 4; fx++)
	{
		x1 = x + dir[fx][0], y1 = y + dir[fx][1];
		if (map[x1][y1] != 1 && map[x1][y1] != 4)
		{
			while (map[x1][y1] != 1 && map[x1][y1] != 4 && map[x1][y1] != 3)
				x1 += dir[fx][0], y1 += dir[fx][1];
			if (map[x1][y1] == 1)
			{
				map[x1][y1] = 0;
				if (dep+1 < ans) go(dep+1, x1-dir[fx][0], y1-dir[fx][1]);
				map[x1][y1] = 1;
			}else
			if (map[x1][y1] == 4)
				continue;
			else
			{	
				if (dep < ans)
					ans = dep;	
				return;
			}
		}
	}
}
int main()
{
//	freopen("in.txt", "r", stdin);
	while (scanf("%d%d", &w, &h), w&&h)
	{
		ans = 100;
		for (int i = 0; i <= 21; i++)
			for (int j = 0; j <= 21; j++) map[i][j] = 4;
		for (int i = 1; i <= h; i++)
			for (int j = 1; j <= w; j++)
			{
				scanf("%d", &map[i][j]);
				if (map[i][j] == 2) sx = i, sy = j;
			}
		go(1, sx, sy);
		if (ans == 100) printf("-1\n");
		else printf("%d\n", ans);
	}
}
