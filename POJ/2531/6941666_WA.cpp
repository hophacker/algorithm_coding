#include<iostream>
#include<fstream>
using namespace std;

int n, sum;
int c[21][21];
bool sel[21];
int main()
{
	//freopen("in.txt", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> c[i][j];
	memset(sel, false, sizeof(sel));
	int t, i;
	sum = 0;
	while(true)
	{
		for (i = 1; i <= n; i++)
		{
			t = 0;
			for (int j = 1; j <= n; j++)
				if (sel[i] == sel[j]) t += c[i][j];
				else t -= c[i][j];
			if (t > 0) 
			{
				sel[i] = !sel[i];
				sum += t;
				break;
			}
		}
		if (i == n+1) break;
	}
	cout << sum << endl;
}
