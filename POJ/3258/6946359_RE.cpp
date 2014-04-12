#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

const int maxi = 1000000001;
int a[50001];
int l, n, m;
int dp[5001][5001];
int main()
{
	//freopen("in.txt", "r", stdin);
 	scanf("%d%d%d", &l, &n, &m);
	a[0] = 0;
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	sort(a+1, a+n+1);
	a[n+1] = l;
	//initialize
	for (int i = 1; i <= n+1; i++)
		for (int j = 0; j <= m; j++)
			dp[i][j] = maxi;
	dp[1][0] = a[1];
	int t;
	for (int i = 2; i <= n+1; i++)
	{
		dp[i][0] = min(dp[i-1][0], a[i]-a[i-1]);
		dp[i][i-1] = a[i];

		for (int j = 1; j <= min(i-2, m); j++)
		{
			dp[i][j] = -maxi;
			
			for (int k = 0; k <= j-1; k++)
			{		
				t = min(dp[i-k-1][j-k], a[i]-a[i-k-1]);
				if (t > dp[i][j]) dp[i][j] = t;
			}
		}
	}
	cout << dp[n+1][m] << endl;
}
