#include<iostream>
using namespace std;
struct node
{
	int x, y;
};
const int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
char map[42][42];
node s, e, a, aa;
int fx, tfx, ffx;
int w, h;
int side(int k)
{
	node t;
	int step = 2;
	a = aa;
	fx = ffx;
	while (!(a.x == e.x && a.y == e.y))
		{
 			step++;
			tfx = (fx+k+4)  % 4;
			t.x = a.x + dir[tfx][0], t.y = a.y +dir[tfx][1];
			if (map[t.x][t.y] == '.')
			{
				a.x = t.x, a.y = t.y;
				fx = tfx;		//1
			}else
				{
					t.x = a.x + dir[fx][0], t.y = a.y + dir[fx][1];
					if (map[t.x][t.y] == '.')
						a.x = t.x, a.y = t.y; 		//2
					else
						{
							tfx = (fx - k + 4) % 4;
							t.x = a.x + dir[tfx][0], t.y = a.y + dir[tfx][1];
							if (map[t.x][t.y] == '.')
								a.x = t.x, a.y = t.y, fx = tfx; 		// 3
							else
								step--, fx = (fx + 2) % 4; 		// 4
						}
				}
		}
	return step;
}
int dis()
{
	node q[1601];
	int h = 0, t = 0;
	int used[42][42];
	memset(used, 0, sizeof(used));
	used[aa.x][aa.y] = true;
	q[h] = aa;
	while (!used[e.x][e.y] && h <= t) 
	{
		node p1, p2;
		p1 = q[h];
		for (int i = 0; i < 4; i++)
		{
			p2 = p1, p2.x += dir[i][0], p2.y += dir[i][1];
			if (!used[p2.x][p2.y] && map[p2.x][p2.y] == '.')
			{
				used[p2.x][p2.y] = used[p1.x][p1.y]+1;
				q[++t] = p2;
			}
		}
		h++;
	}
	return used[e.x][e.y]+1;
}
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int tests;
	cin >> tests;
	while(tests--)
	{
		cin >> w >> h;
		for (int i = 1; i <= h; i++)
			for (int j = 1; j <= w; j++)
			{ 
				cin >>	map[i][j];
				if (map[i][j] == 'S')
					s.x = i, s.y = j;
				if (map[i][j] == 'E')
					e.x = i, e.y = j;
			}
		aa.x = s.x, aa.y = s.y;
		if (s.x == 1) aa.x++, ffx = 2; else
		if (s.x == h) aa.x--, ffx = 0; else
		if (s.y == 1) aa.y++, ffx = 1; else
					  aa.y--, ffx = 3;
		map[e.x][e.y] = '.';
		cout << side(-1) << ' ';
		cout  << side(1) << ' ';
		cout << dis() << endl;
	}	
}
