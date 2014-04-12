#include<iostream>
#include<fstream>
using namespace std;

int n, maxSum, sum;
int c[21][21];
bool sel[21];

void search(int dep)
{
	if (dep > n)
	{
		if (sum > maxSum) maxSum = sum;
		return;	
	}
	for (int b = 1; b >= 0; b--)
	{
		sel[dep] = b;
		int d = 0;
		for (int i = 1; i < dep; i++)
			if (sel[i] != sel[dep]) d += c[i][dep];
		sum += d;
		search(dep+1);
		sum -= d;
	}	
}
int main()
{
	//freopen("in.txt", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> c[i][j];
	memset(sel, false, sizeof(sel));
	int t, i;
	maxSum = 0; sum = 0;
	search(1);
	cout << maxSum << endl;
}
