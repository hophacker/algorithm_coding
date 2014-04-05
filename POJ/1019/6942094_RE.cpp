#include<iostream>
#include<fstream>
using namespace std;

const int maxi = 31267;
int a[100001], aa[31270];
void add(int x, int d)
{
	for (int i = x; i <= x*10-1; i++)
		a[i] = a[i-1] + d;
}
int main()
{
//	freopen("in.txt", "r", stdin);
	int tests, n, l, r, m;
	cin >> tests;
	a[0] = 0;
	add(1,1);add(10,2);add(100,3);add(1000,4);add(10000,5);
	aa[0] = 0;
	for (int i = 1; i <= maxi; i++)	aa[i] = a[i] + aa[i-1];
	while (tests--)
	{
		cin >> n;
		l = 1, r = maxi;
		while (l < r)
		{
			m = (l+r) /2;
			if (aa[m] > n) r = m-1;else 
			if (aa[m] < n) l = m+1;else break;
		}
		if (aa[m] == n) cout << (m%10) << endl;
		else
		{
			r--;
			while (aa[r+1] < n) r++;
			n -= aa[r];
			l = 1; r = maxi;
			while(l < r)
			{
				m = (l+r) / 2;
				if (a[m] > n) r = m-1;else
				if (a[m] < n) l = m+1;else break;
			}
			if (a[m] == n) cout << (m%10) << endl;
			else
			{
				r--;
				while (a[r+1] < n) r++;
				n -= a[r];
				int digit[10], num = r+1, t = 0;
				while (num > 0)
				{
					digit[++t] = num % 10;
					num /= 10;
				}
				cout << digit[t+1-n] << endl;
			}
		}
	}
}
