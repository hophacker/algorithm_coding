#include<iostream>
#include<fstream>
using namespace std;

int g, b, m, x, y;
bool map[201][201];
bool visit[201];
int link[201][201];
int match[201];

bool ok(int x)
{
	int v;
	for (int i = 1; i <= link[x][0]; i++)
		if (!visit[link[x][i]])
			if (match[link[x][i]] == 0 || ok(match[link[x][i]]))
			{
				match[link[x][i]] = x;
				return true;
			}
			else 
				visit[link[x][i]] = true;
	return false;
}
int main()
{
	//ifstream cin("in.txt");
	int cases = 0;
	while (cin >> g >> b >> m, g || b || m)
	{
		memset(map, true, sizeof(map));
		for (int i = 1; i <= m; i++)	
		{
			cin >> x >> y;
			map[x][y] =  false;
		}	
		for (int i = 1; i <= g; i++)
		{
			link[i][0] = 0;
			for (int j = 1; j <= b; j++)
				if (map[i][j]) link[i][++link[i][0]] = j;
		}
		memset(match, 0, sizeof(match));
		int cnt = 0;
		for (int i = 1; i <= g; i++)
		{
			memset(visit, false, sizeof(visit));
			visit[i] = true;
			if (ok(i)) cnt++;
		}
		printf("Case %d: %d\n", ++cases, g+b-cnt);
	}
	//system("pause");
}
