#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	//freopen("in.txt", "r", stdin);
	int n;
	int a[351][351];
	int sum[351];
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			cin >> a[i][j];
	for (int i = 1; i <= n; i++)
		sum[i] = a[n][i];
	for (int i = n-1; i >= 1; i--)
		for (int j = 1; j <= i; j++)
			sum[j] = max(sum[j], sum[j+1]) + a[i][j];
	cout << sum[1] << endl;
}
