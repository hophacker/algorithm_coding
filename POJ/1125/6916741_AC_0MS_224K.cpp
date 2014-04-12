#include<iostream>
#include<fstream>
#include<memory.h>
using namespace std;

const int maxi = 100000000;
int n; // n <= 100;
int k, b, d;
int map[101][101], dis[101];
bool used[101];
int main()
{
	//freopen("in.txt", "r", stdin);
	while (cin >> n && n != 0)
	{		
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				map[i][j] = maxi; 
		for (int i = 1; i <= n; i++)
		{
			cin >> k;
			for (int j = 1; j <= k; j++)
			{
				cin >> b >> d;
				map[i][b] = d;
			}
		}
		int minTime = maxi, time, tp = 0;
		for (int u = 1; u <= n; u++)
		{
			for (int i = 1; i <= n; i++)
				dis[i] = map[u][i];
			dis[u] = 0;
			memset(used, 0, sizeof(used));
			used[u] = true;
			for (int i = 1; i <= n-1; i++)
			{
				int mind = maxi, minp;
				for (int j = 1; j <= n; j++) if (!used[j] && dis[j] < mind)
					mind = dis[j], minp = j;
				if (mind == maxi) break;
				used[minp] = true;
				for (int j = 1; j <= n; j++)
					if (!used[j] && dis[minp] + map[minp][j] < dis[j])
						dis[j] = dis[minp] + map[minp][j];
			}
			time = -maxi;
			for (int i = 1; i <= n; i++)
				if (time < dis[i]) time = dis[i];
			if (time <=  minTime) minTime = time, tp = u;
		}
		if (tp == 0) cout << "disjoint\n";
		else cout << tp << ' ' << minTime << endl;
	}
}
