#include<iostream>
#include<fstream>
using namespace std;

bool map[501][50];
int match[501];
int n, k, cnt;
bool visit[501];

bool search(int p)
{
	for (int i = 1; i <= n; i++)
		if (!visit[i] && map[p][i])
		{
			visit[i] = true;
			if (match[i] == -1 || search(match[i]))
			{
				match[i] = p;
				return true;
			}
		}
	return false;
}
int main()
{
	//freopen("in.txt", "r", stdin);
	int x, y;
	cin >> n >> k;
	for (int i = 1; i <= k; i++) cin >> x >> y, map[x][y] = true;
	fill(&match[1], &match[n+1], -1);
	cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		fill(&visit[1], &visit[n+1], 0);
		if (search(i)) cnt++;
	}
	cout << cnt << endl;
}
