#include<iostream>
#include<fstream>
#include<memory.h>
#include<time.h>
using namespace std;
struct node
{
	int state;
	int step;
	int father;
	int x, y;
};
int con[16]={
0xF888,0xF444,0xF222,0xF111,
0x8F88,0x4F44,0x2F22,0x1F11,
0x88F8,0x44F4,0x22F2,0x11F1,
0x888F,0x444F,0x222F,0x111F};
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
		for (int j = 0; j < 4; j++) cin >> c, a[i][j] = (c == '+'? 1 : 0);
	q[0].state = stoi(a);
	q[0].step = 0;
	q[0].father = -1;
	pan[q[0].state] = 1;
	while (h <= t)
	{
		node temp;
		temp.father = h;
		temp.step = q[h].step + 1;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
			{	
				temp.state = q[h].state xor con[i*4 + j];
				temp.x = i;
				temp.y = j;
				if (!pan[temp.state])
				{
					pan[temp.state] = 1;
					q[++t] = temp;
					if (q[t].state == 0)
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