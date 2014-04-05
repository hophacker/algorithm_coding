/*
ID: fengjie3
PROG: milk2
LANG: C++
*/
#include<iostream>
#include<algorithm>
using namespace std;
struct node
{
	int b, e;
};
bool cmp(const node& a, const node& b)
{
	if (a.b < b.b) return true;
	if (a.b == b.b && a.e < b.e) return true;
	return false;
}
int main()
{
	freopen("milk2.in", "r", stdin);
	
	freopen("milk2.out", "w", stdout);
	int n;
	int total, max1 = 0, max2 = 0;
	node time[5001];
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> time[i].b >> time[i].e;
	sort(time+1, time+n+1, cmp);
	int i, j;
	for (i = 1; i <= n;)
	{
		int max = time[i].e;
		for (j = i; j < n && time[j+1].b <= max; j++)
			if (time[j+1].e > max) max = time[j+1].e;


		if (max - time[i].b > max1) max1 = max - time[i].b;
		if (j <= n)	if (time[j+1].b - max > max2) max2 = time[j+1].b - max;
		i = j+1;
	}
	cout << max1 << " " << max2 << endl;
}
