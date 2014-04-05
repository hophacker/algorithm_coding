#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

int l, m, n;
int a[50002];
int lef, rig, mid;
int main()
{
	//freopen("in.txt", "r", stdin);
	cin >> l >> n >> m;
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	sort(a+1, a+n+1);
	a[0] = 0, a[n+1] = l;
	lef = rig = l;
	for (int i = 1; i <= n+1; i++)
		if (a[i] - a[i-1] < lef) lef = a[i] - a[i-1];
	int p, d, total, ans = 0;
	if (n == 0) 
	{
		cout << l << endl;
		return 0;
	}
	while (lef <= rig)
	{
		mid = (lef + rig) / 2;
		p = 1, d = a[1], total = 0;
		while (p < n+1)
		{
			while (d < mid && p < n+1) 
			{
				p++;
				d += (a[p] - a[p-1]);
				total++;
			}
			if (p < n+1)
			{
				p++;
				d = a[p] - a[p-1];
			}
		}
		if (total <= m)
		{
			ans = mid;
			lef = mid + 1;
		}
		else if (total > m)
			rig = mid - 1;
	}
	cout << ans << endl;
}
