#include<iostream>
#include<fstream>
using namespace std;

int t, c;
int sum[101];
int a[101], p[101], dp[101];
int main()
{
	freopen("E:\\My Programs\\in.txt", "r", stdin);
	//scanf("%ld", &t);
	while (t--)
	{
		scanf("%ld", &c);
		sum[0] = 0;
		for (int i = 1; i <= c; i++)
		{
			scanf("%ld %ld", &a[i], &p[i]); 
			sum[i] = sum[i-1] + a[i];
		}
		for (int i = 1; i <= c; i++)
		{
			dp[i] = (sum[i] + 10) * p[i];
			for (int j = 1; j < i; j++)
				dp[i] = min(dp[i], dp[j] + (sum[i] - sum[j] + 10) * p[i]);
		}
		printf("%ld\n", dp[c]);
	}
}
