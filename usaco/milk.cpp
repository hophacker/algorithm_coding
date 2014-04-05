/*
ID: fengjie3
PROG: milk
LANG: C++
*/
#include<iostream>
#include<algorithm>
using namespace std;
struct node
{
	int p, a;
};
bool cmp(const node& a, const node& b)
{
	if (a.p < b.p) return true;
	else
		return false;
}
int main()
{
	freopen("milk.in", "r", stdin);
	freopen("milk.out", "w", stdout);
	int n, m;
	node milk[5001];
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
		cin >> milk[i].p >> milk[i].a;
	sort(milk+1, milk+m+1, cmp);
	int money = 0, total = 0;
	int t;
	for (int i = 1; i <= m; i++)
	{
		if (total + milk[i].a > n)
		 	t = n - total;
		else
			t = milk[i].a;
		total += t;
		money += t * milk[i].p;
		if (total == n) break;
	}
	cout << money << endl;
}
