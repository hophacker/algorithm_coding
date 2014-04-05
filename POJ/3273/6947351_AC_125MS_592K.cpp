#include<iostream>
#include<fstream>
using namespace std;

int n, m, sum, l, r, mid, t, ans;
int a[100002];

int calc(int x)
{
	int total = 0, sum, p;
	p = 1;
	while (p <= n)
	{	
		sum = 0;
		while (sum <= x && p <= n) sum += a[p], p++;
		if (sum > x) p--;
		total++;
	}
	return total;
}
int main()
{
	//freopen("in.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	sum = 0;
	l = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]), sum += a[i];
		if (a[i] > l) l = a[i];
	}
	r = sum; 
	ans = sum;
	while (l <= r)
	{
		mid = (l + r) / 2;
		t = calc(mid);
		if (t <= m) 
		{
			r = mid-1;
			ans = mid;
		}else
		if (t > m) l = mid+1;
	}
	cout << ans << endl;
}
