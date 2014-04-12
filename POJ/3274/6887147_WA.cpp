#include<iostream>
#include<fstream>
#include<memory.h>
#include<algorithm>
using namespace std;
struct node
{
	long long x;
	int pos;
};
bool cmp(const node& a, const node& b)
{
	if (a.x == b.x) return a.pos < b.pos;
	else return a.x < b.x;
}
int main()
{
	//freopen("in", "r", stdin);
	int n, k;
	long long mod, num;
	node a[100001];
	cin >> n >> k, mod = (1 << k)-1;
	a[0].x = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> num;
		a[i].x = (num + a[i-1].x) % mod, a[i].pos = i;
	}
	sort(a+1, a+n+1, cmp);
	int max = 0, p = 1, p1;
	while (p <= n)
	{
		p1 = p+1;
		while (p1 <= n && a[p1].x == a[p].x) p1++;
		if (a[p1-1].pos - a[p].pos > max)
			max = a[p1-1].pos - a[p].pos;
		p = p1;
	}	
	cout << max << endl;
}