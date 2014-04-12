#include<iostream>
#include<fstream>
#include<memory.h>
#include<time.h>
using namespace std;
struct node
{
	bool a[4][4];
	int step;
	int father;
	int x, y;
};
int stoi(bool a[4][4])
{
	int t = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			t = t * 2 + a[i][j];
	return t;
}
int main()
{
//freopen("in", "r", stdin);
	bool a[4][4];
	char c;
	node q[65536];
	bool pan[65536];
	clock_t start = clock();
	memset(pan, 0, sizeof(pan));
	int h = 0, t = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) cin >> c, q[0].a[i][j] = (c == '+'? 1 : 0);
	q[0].step = 0;
	q[0].father = -1;
	pan[stoi(q[0].a)] = 1;
	while (h <= t)
	{
		node temp;
		temp.father = h;
		temp.step = q[h].step + 1;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
			{
				for (int i1 = 0; i1 < 4; i1++)
					for (int j1 = 0; j1 < 4; j1++)
						if (i1 == i || j1 == j)
							temp.a[i1][j1] = !(q[h].a[i1][j1]);
						else
							temp.a[i1][j1] = q[h].a[i1][j1];
				temp.x = i;
				temp.y = j;
				int ii = stoi(temp.a);
				if (!pan[ii])
				{
					pan[ii] = 1;
					q[++t] = temp;
					if (stoi(q[t].a) == 0)
						goto end;
				}
			}
		h++;
	}
	end:
	cout << q[t].step << endl;
	int list[65535];
	h = 0;
	while (q[t].father != -1)
	{
		list[++h] = t;
		t = q[t].father;
	}
	for (int i = h; i >= 1; i--)
		cout << q[list[i]].x+1 << ' ' << q[list[i]].y+1 << endl;
}