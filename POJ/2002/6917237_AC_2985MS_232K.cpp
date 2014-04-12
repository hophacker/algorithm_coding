#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

struct node
{
	int x, y, hash;
}map[1001];
int n, i, j, x3, y3, x4, y4;
bool cmp(const node& a, const node& b)
{
	return a.hash < b.hash;
}
bool search(int x)
{
	int l = 1, r = n, mid;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (map[mid].hash == x) return true;
		if (map[mid].hash < x) l = mid+1;
		if (map[mid].hash > x) r = mid-1;
	}
	return false;
}
int main()
{
	//freopen("in.txt", "r", stdin);
	while(cin >> n && n != 0)
	{
		for (i = 1; i <= n; i++)
		{
			cin >> map[i].x >> map[i].y;
			map[i].hash = map[i].x * 20000 + map[i].y;
		}
		sort(map+1, map+1+n, cmp);
		int total =0;
		for (i = 1; i <= n-1; i++)
			for (j = i+1; j <= n; j++)
			{
				y3 = map[i].y + (map[j].x - map[i].x);
				x3 = map[i].x + (map[i].y - map[j].y);
				if (search(20000*x3+y3))
				{
					y4 = map[j].y + y3 - map[i].y;
					x4 = map[j].x + x3 - map[i].x;
					if (search(20000*x4+y4))
						total++;
				}
				y3 = 2 * map[i].y - y3;
				x3 = 2 * map[i].x - x3;
				if (search(20000*x3+y3))
				{
					y4 = map[j].y + y3 - map[i].y;
					x4 = map[j].x + x3 - map[i].x;
					if (search(20000*x4+y4))
						total++;
				}
			}
		cout << total/4 << endl;
	}
}
