#include<iostream>
#include<fstream>
using namespace std;

int r[201][201];
int n, i;
int way[102], wayT, mul[102];

void setMul(int n)
{
	mul[0] = 1;
	for (int i = 1; i <= 101; i++) 
		mul[i] = (mul[i-1] * 10) % n;
}
int main()
{
	//freopen("in.txt", "r", stdin);
	for (int t = 1;; t++)
	{
		cin >> n;
		if (n == 0) break;
		if (n == 1) 
		{
			cout << 1 << endl;
			continue;
		}
		setMul(n);
		
		r[0][1] = r[0][0] = t;
		for (i = 1;; i++)
		{
			r[i][mul[i]] = t;
			for (int j = 1; j < n; j++)
				if (r[i-1][j] == t)
					r[i][j] = r[i][(j+mul[i]) % n] = t;
			if (r[i][0] == t) break;
		}
		memset(way, 0, sizeof(way));
		wayT = i;
		int left = 0;
		while (i >= 1)
		{
			way[i] = 1;
			left = (left + n - mul[i]) % n;
			i--;
			while (i >= 1 && r[i][left] != t) i--;
			while (i >= 1 && r[i][left] == r[i-1][left]) i--;
		}
		if (left == 0) way[0] = 0; else way[0] = 1;
		for (i = wayT; i >= 0; i--) cout << way[i];
		cout << endl;
	}
}
