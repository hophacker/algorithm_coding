#include<iostream>
#include<fstream>
using namespace std;

int dp[21][8000];
int main()
{
	//freopen("in.txt", "r", stdin);
	int pT, wT, maxL = 0, maxp = 0;
	cin >> pT >> wT;
	int p[21], w[21];
	for (int i = 1; i <= pT; i++) 
	{
		cin >> p[i];
		if (abs(p[i]) > maxp) maxp = abs(p[i]);
	}
	for (int i = 1; i <= wT; i++) cin >> w[i], maxL += maxp * w[i];
	int d = maxL;
	for (int i = 1; i <= pT; i++) dp[1][d + w[1]*p[i]]++;
	for (int i = 2; i <= wT; i++)
		for (int j = 1; j <= pT; j++)
			for (int k = 0; k <= maxL*2; k++)
				if (dp[i-1][k] != 0)
					dp[i][k + w[i]*p[j]] += dp[i-1][k];
	cout << dp[wT][maxL] << endl;
}
