#include<iostream>
#include<fstream>
#include<memory.h>
using namespace std;

struct node
{
	int x, y;
}p[30];
const int dir[8][2] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
int map[15][15];
int w, h;

bool search(int x, int y, int dep)
{	
	if (dep == w * h + 1) return true;
	int x1, y1;
	for (int i = 0; i < 8; i++)
	{
		x1 = x + dir[i][0], y1 = y + dir[i][1];
		if (1 <= x1 && x1 <= h && 1 <= y1 && y1 <= w && map[x1][y1] == 0)
		{			
			map[x1][y1] = dep;
			if (search(x1, y1, dep+1)) return true;
			map[x1][y1] = 0;
		}
	}
	return false;
}
int main()
{
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	int tests; cin >> tests;
	for (int time = 1; time <= tests; time++)
	{
		printf("Scenario #%d:\n", time);
		cin >> w >> h;
		if (min(w, h) == 2) cout << "impossible\n";else
		{
			memset(map, 0, sizeof(map));
			map[1][1] = 1;
			if (search(1, 1, 2)) 
			{
				for (int i = 1; i <= h; i++)
					for (int j = 1; j <= w; j++)
					{
						int t = map[i][j];
						p[t].x = i;
						p[t].y = j;
					}
				for (int i = 1; i <= h * w; i++)
					printf("%c%d", p[i].x-1+'A', p[i].y);
				cout << endl;
			}
			else cout << "impossible\n";
		}
		cout << endl;
	}
}
