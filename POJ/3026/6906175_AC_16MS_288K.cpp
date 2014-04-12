#include<iostream>
#include<stdio.h>
#include<fstream>
#include<limits.h>
using namespace std;
const int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
struct node
{
	int x,y;
}pos[102];
struct node1
{
	int s, e, d;
}way[102];
char map[52][52];
int step[52][52], dis[102][102];
int xx, yy, np, i, j;
node q[2500];
void search(int x, int y)
{
	int h, t; 
	node temp;
	h = t = 0;
	step[x][y] = 1;
	q[0].x = x, q[0].y = y;
	while (h <= t)
	{
		for (int i = 0; i < 4; i++)
		{
			temp.x = q[h].x + dir[i][0];
			temp.y = q[h].y + dir[i][1];
			if (map[temp.x][temp.y] != '#' && !step[temp.x][temp.y])
			{
				step[temp.x][temp.y] = step[q[h].x][q[h].y] + 1;
				q[++t] = temp;
			}
		}
		h++;
	}
}
int main()
{
	//ifstream cin("in.txt");
	char c;
	int tests; cin >> tests;
	while (tests--)
	{
		cin >> yy >> xx;
		//scanf("%c", &c);
		for (i = 0; i <= xx; i++)
			cin.getline(map[i], 1000, '\n');
		np = 0;
		for (i = 1; i <= xx; i++)
			for (j = 1; j <= yy; j++)
				if (map[i][j] == 'S' || map[i][j] == 'A')
					np++, pos[np].x = i, pos[np].y = j;
		for (i = 1; i <= np; i++)
		{
			memset(step, 0, sizeof(step));
			search(pos[i].x, pos[i].y);
			for (j = 1; j <= np; j++) 
				dis[i][j] = step[pos[j].x][pos[j].y] - 1;
		}
		int total = 0;
		for (i = 1; i < np; i++)
			way[i].s = 1, way[i].e = i+1, way[i].d = dis[1][i+1];	
		for (int time = 1; time < np; time++)
		{
			int minD = 9999999, minP;
			for (i = time; i < np; i++)
				if (way[i].d < minD)
				{
					minD = way[i].d;
					minP = i;
				}
			swap(way[time], way[minP]);
			total += way[time].d;
			int from = way[time].e;
			for (i = time+1; i < np; i++)
				if (dis[from][way[i].e] < way[i].d)
				{
					way[i].s = from;
					way[i].d = dis[from][way[i].e];
				}
		}
		cout << total << endl;
	}
}