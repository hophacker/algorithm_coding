#include<iostream>
#include<fstream>
#include<memory.h>
using namespace std;

struct node
{
	int z, x, y, d;
}q[27001];
struct node1
{
	int z, x, y;
}dir[6] = {{1,0,0}, {-1,0,0}, {0,1,0}, {0,-1,0}, {0,0,1}, {0,0,-1}};
int l, r, c, i, j, k, sk, si, sj, h, t, ti, tj, tk;
char map[32][32][32];
bool visit[32][32][32];
int main()
{
	//freopen("in.txt", "r", stdin);
	while (cin >> l >> r >> c && (l||r||c))
	{
		for (k = 1; k <= l; k++)
			for (i = 1; i <= r; i++)
				for (j = 1; j <= c; j++)
				{
					cin >> map[k][i][j];			
					if (map[k][i][j] == 'S')
						sk = k, si = i, sj = j;
				}
		h = t = 0;
		q[0].z = sk, q[0].x = si, q[0].y = sj, q[0].d = 0;
		memset(visit, 1, sizeof(visit));
		for (k = 1; k <= l; k++)
			for (i = 1; i <= r; i++)
				for (j = 1; j <= c; j++)
					visit[k][i][j] = false;
		while (h <= t)
		{
			sk = q[h].z, si = q[h].x, sj = q[h].y;	
			for (i = 0; i < 6; i++)
			{
				tk = sk + dir[i].z, ti = si + dir[i].x, tj = sj + dir[i].y;
				if (!visit[tk][ti][tj] && map[tk][ti][tj] != '#')
				{
					t++;
					q[t].z = tk, q[t].x = ti, q[t].y = tj, q[t].d = q[h].d + 1;
					visit[tk][ti][tj] = true;
					if (map[tk][ti][tj] == 'E')
						h = t;
				}
			}
			h++;
		}
		if (map[q[t].z][q[t].x][q[t].y] == 'E')
			printf("Escaped in %d minute(s).\n", q[t].d);
		else
			printf("Trapped!\n");
	}
}
