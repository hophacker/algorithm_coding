#define ll long long
#include<iostream>
using namespace std;

bool exist = true;
void gcdIt(ll a,ll& x, ll b, ll& y, ll c)
{
	if (b == 0)
	{
		x = c / a;
		y = 0;
		return;
	}
	ll x1, y1;
	gcdIt(b, x1, a%b, y1, c);
	x = y1;
	y = x1 - a / b * x;
}
ll gcd(ll a, ll b)
{
	if (a < b)
		swap(a, b);
	ll c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}
ll doit(ll a, ll b, ll c)
{
	int cao = 11111111;
	ll x, y, f1 = 1, f2 = 1;
	if (a < 0)	
	{
		f1 = -1;
		a *= -1;
	}
	if (b < 0)
	{
		f2 = -1;
		b *= -1;
	}
	ll gab= gcd(a,b);
	ll t = b / gab;
	if (c % gab != 0) return cao;
	if (a < b) gcdIt(b, y, a, x, c);
	else gcdIt(a, x, b, y, c);
	a *= f1; x *= f1;
	b *= f2; y *= f2;
	x %= t;
	if (x <= 0) x += t;
	//prllf("%d*%d + %d*%d = %d\n", a, x, b, y, c);
	return x;
}
int main()
{
	ll x, y, m, n, k;
	cin >> x >> y >> m >> n >> k;
	int re;
	re = doit(m-n, k, y-x);
	if (re == 11111111) cout << "Impossible\n";
	else cout << re << endl;
}
