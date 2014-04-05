#include<iostream>
#include<fstream>
using namespace std;

struct node1
{
	int s, q;
}one[61];
int bit[11];
char map[101][12];
int n, m, oT = 0, tT = 0;
int dp[101][61][61];
inline void stoi(int t, int bit[])
{
	for (int i = 1; i <= m; i++)
		bit[i] = t % 2, t /= 2;
}
bool canPlace(int bit[])
{
	int i = 1, j = 1;
	while (bit[i] == 0 && i <= m) i++;
	while (i <= m)
	{
		j = i+1; 
		while (bit[j] == 0 && j <= m) j++;
		if (j > m) break;
		if (j - i <= 2) return false;
		i = j; 
	}
	return true;
}
inline int calc(int bit[])
{
	int t = 0;
	for (int i = 1; i <= m; i++) if(bit[i]) t++;
	return t;
}
bool okMap(int i, int t)
{
	stoi(t, bit);
	for (int j = 1; j <= m; j++)
		if (map[i][j] == 'H' && bit[j] == 1) return false;
	return true;
}
int main()
{
	//freopen("E:\\My Programs\\in.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) cin >> map[i][j];
	for (int i = 0; i < (1<<m); i++)	
	{
		stoi(i, bit);
		if (canPlace(bit))
		{
			oT++;
			one[oT].s = i;
			one[oT].q = calc(bit);
		}
	}
	memset(dp, -1, sizeof(dp));
	int maxq = 0;
	if (n == 1)
	{
		for (int i = 1; i <= oT; i++)
			if (okMap(1, one[i].s) && one[i].q > maxq) maxq =  one[i].q;
	} 
	else
	{
		for (int i = 1; i <= oT; i++)
			for (int j = 1; j <= oT; j++)
				if (okMap(1, one[i].s) && okMap(2, one[j].s) && ((one[i].s & one[j].s) == 0))
					dp[2][i][j] = one[i].q + one[j].q;
		for (int dep = 3; dep <= n; dep++)
			for (int i = 1; i <= oT; i++)
				for (int j = 1; j <= oT; j++)
					if (dp[dep-1][i][j] != -1)
						for (int k = 1; k <= oT; k++)
							if (okMap(dep, one[k].s) && ((one[i].s & one[k].s) == 0) && ((one[j].s & one[k].s) == 0))
								if (dp[dep-1][i][j] + one[k].q > dp[dep][j][k])
									dp[dep][j][k] = dp[dep-1][i][j] + one[k].q;
		for (int i = 1; i <= oT; i++)
			for (int j = 1; j <= oT; j++)
				if (dp[n][i][j] > maxq) maxq = dp[n][i][j];
	}
	cout << maxq << endl;
}

/*

struct node
{
	int s1, s2, q;
}two[3601];
for (int i = 1; i <= oT; i++)
		for (int j = 1; j <= oT; j++)
			if (one[i].s & one[j].s == 0)
				tT++, two[tT].s1 = one[i].s, two[tT].s2 = one[j].s, two[tT].s = one[i].s+one[j].s;
*/
