#include<iostream>
#include<fstream>
#include<memory.h>
using namespace std;
int pow2[16];

struct node
{
	bool map[4][4];
	int step;
};
int vton(bool map[4][4])
{
	int t = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) t = t * 2 + map[i][j];
	return t;
}
int main()
{
//	freopen("in", "r", stdin);
	node queue[65536];
	bool pan[65536];
	int h = 0, t = 0;
	char c;
	for (int i = 0; i <= 15; i++)
		pow2[i] = 1 << i;
	int tar1 = 0, tar2 = 1 << 16 - 1;
	queue[0].step = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			cin >> c, queue[0].map[i][j] = (c == 'w'? 0:1);
	memset(pan, false, sizeof(pan));
	pan[vton(queue[0].map)] = 1;
	int n1, n2;
	while (h <= t)
	{
		n1 = vton(queue[h].map);
		if (n1 == tar1 || n1 == tar2) 
		{
			cout << queue[h].step << endl;
			return 0;
		}
		node temp;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
			{
				temp = queue[h];
				temp.step++;
				if (i > 0) temp.map[i-1][j] = !temp.map[i-1][j];
				if (i < 3) temp.map[i+1][j] = !temp.map[i+1][j];
				if (j > 0) temp.map[i][j-1] = !temp.map[i][j-1];
				if (j < 3) temp.map[i][j+1] = !temp.map[i][j+1];
				temp.map[i][j] = !temp.map[i][j];
				n1 = vton(temp.map);
				if (!pan[n1])
				{
					t++;
					queue[t] = temp;
					pan[n1] = 1;
				}
			}
		h++;
	}
}