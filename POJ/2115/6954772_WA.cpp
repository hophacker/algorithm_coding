#define ll long long
#include<iostream>
#include<fstream>
using namespace std;

int gcdn;
void solve(ll a, ll& x, ll b, ll& y, ll c)
{
	if (b == 0)
	{
		x = c / a;
		y = 0;
		return;
	}
	ll t = a / b, x1, y1;
	solve(b, y1, a%b, x1, c);
	x = x1;
	y = y1 - x1 * t;
}
void doIt(ll a, ll & x, ll b, ll & y, ll c)
{
	if (c < 0)
		a = -a, b = -b, c = -c;
	if (abs(a) < abs(b))
		solve(abs(a), x, abs(b), y, c);
	else
		solve(abs(b), y, abs(a), x, c);
	if (a < 0) x = -x;
	if (b < 0) y = -y;
	int t = abs(b) / gcdn;
	//cout << a << ' ' << x << ' ' << b << ' ' << y << ' ' << c << endl;
	x = ((x % t) + t) % t;
}
ll gcd(ll a, ll b)
{
	if (a > b) swap(a, b);
	ll t;
	while (b != 0)
	{
		t = a % b;
		a = b;
		b = t;
	}
	return a;
}
int main()
{
	//freopen("in.txt", "r", stdin);
	ll a, b, c, k, x, y;
	while ((cin >> a >> b >> c >> k) && (a || b || c || k))
		if ((a-b) % (gcdn = gcd(1<<k, c)) == 0)
		{
			doIt(-c, x, 1<<k, y, a-b);
			cout << x << endl;
		}
		else
			cout << "FOREVER\n";
}
