#include<iostream>
#include<fstream>
#include<memory.h>
using namespace std;

bool same;
int total, b[8], bt, ans[8], len, ans1[8];
void search(int dep, int k, int sum)
{
	if (k == 0)
	{
		if (sum == ans[0]) same = true; else
		if (sum > ans[0]) 
		{
			for (int i = 0; i < 8; i++) ans1[i] = ans[i];
			same = false;
			ans[0] = sum;
			len = dep-1;
		}
	}
	int t = 0;
	for (int i = k; i >= 1; i--)
	{
		t = t * 10 + b[i];
		ans[dep] = t;		
		if (t + sum <= total)
			search(dep+1, i-1, sum+t);
	}
}
int main()
{
	//freopen("E:\\My Programs\\in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int n, minv;
	
	while(cin >> total >> n, total || n)
	{
		bt = 0;
		minv = 0;
		while (n > 0)
			minv += (b[++bt] = n % 10),  n /= 10;
		if (minv <= total)
		{
			ans[0] = -1;
			same = true;
			search(1, bt, 0);
			if (same)
				cout << "rejected\n";
			else
			{
				cout << ans[0];
				for (int i = 1; i <= len; i++)
					cout << ' ' << ans1[i];
				cout << endl;
			}
		}else
			cout << "error\n";
	}
}
