#include<iostream>
#include<fstream>
using namespace std;

int dp1[1002], dp2[1002];
double  h[1002];
int main()
{
	//freopen("in.txt", "r", stdin);
	int n;	
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> h[i];
	dp1[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
			if (h[i] > h[j] && dp1[i] < dp1[j]) dp1[i] = dp1[j];
		dp1[i]++;
	}
	dp2[n] = 1;
	for (int i = n-1; i >= 1; i--)
	{
		for (int j = i+1; j <= n; j++)
			if (h[i] > h[j] && dp2[i] < dp2[j]) dp2[i] = dp2[j];
		dp2[i]++;
	}
	int maxi = -1;
	for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (maxi < dp1[i] + dp2[j])
            	maxi = dp1[i] + dp2[j];
	cout << n-maxi << endl;
}
