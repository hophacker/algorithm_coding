#include<iostream>
#include<memory.h>
#include<fstream>
using namespace std; 
const int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
struct node 
{
	int x, y, d;
};
int main()
{
    //freopen("in","r", stdin);
	int cases;
	int x, y, w, h, n, m, t;
	int num, time;
	node robot[101];
	int map[101][101];
	char c, act;
	bool ok;
	cin >> cases;
	while (cases--)
	{
		cin >> w >> h;
		cin >> n >> m;
		memset(map, 0, sizeof(map));
		for (int i = 1; i <= n; i++)
		{
			cin >> x >> y >> c;
			if (c == 'N') t = 0;
			if (c == 'E') t = 1;
			if (c == 'S') t = 2;
			if (c == 'W') t = 3;
			robot[i].x = x, robot[i].y = y, robot[i].d = t;
			map[x][y] = i;
		}
		ok = true;
		for (int i = 1; i <= m; i++)
		{
			cin >> num >> act >> time;
			if (ok)
			{
				if (act == 'F')
				{
					int d = robot[num].d, x = robot[num].x, y = robot[num].y;
					int x1 = time * dir[d][0] + x, y1 = time * dir[d][1] + y;
					if (x1 >= 1 && x1 <= w && y1 >= 1 && y1 <= h)
					{
						map[x][y] = 0;
						robot[num].x = x1;
						robot[num].y = y1;
						for (int j = 1; j <= time; j++)
						{
							x += dir[d][0];
							y += dir[d][1];
							if (map[x][y])
							{
								ok = false;
								printf("Robot %d crashes into robot %d\n", num, map[x][y]);
								break;
							}
						}
						map[x1][y1] = num;
					}else
					{
						printf("Robot %d crashes into the wall\n", num);
						ok = false;
					}
				}else
				if (act == 'L')
					robot[num].d = ((robot[num].d - time) % 4 + 4) % 4;
				else
				if (act == 'R')
					robot[num].d = (robot[num].d + time) % 4;

			}
		}
		if (ok) cout << "OK\n";
	}
}
