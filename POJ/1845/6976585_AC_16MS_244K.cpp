#define ll long long
#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

const ll mod = 9901;
ll d[100], dT = 0, p, tim[100], s, t, bit[100], bT;

ll powIt(ll a, ll n)
{
	bT = 0;
	while (n > 0) bit[++bT] = n % 2, n /= 2;
	ll t = 1;
	for (ll i = bT; i >= 1; i--)
		if (bit[i]) t = (t*t*a) % mod;
		else t = (t*t) % mod;
	return t;
}
ll calc(ll a, ll n)
{
	if (n == 0) return 1;
	if (n == 1) return (1+a) % mod;
	if (n == 2) return (1+a+a*a) % mod;
	if (n & 1)
		return (1 + powIt(a, (n+1)/2)) * calc(a, n/2) % mod;
	else
		return (powIt(a, n) + calc(a, n-1)) % mod;
}
int main()
{
	//freopen("E:\\My Programs\\in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ll a, b;
	cin >> a >> b;
	if (b == 0 || a == 1) cout << 1 << endl;
	else
		if (a == 0) cout << 0 << endl;
	else
	{
		memset(tim, 0, sizeof(tim));
		dT = 0;
		int cao = int(pow(a, 0.5))+1;
		for (int p = 2; p <= cao; p++)
		{
			if (a % p == 0)
			{
				d[++dT] = p;
				while (a % p == 0) tim[dT]++, a /= p;
			}
		}
		if (a != 1) d[++dT] = a, tim[dT] = 1;
		for (ll i = 1; i <= dT; i++)
			tim[i] *= b;
		s = 1;
		for (ll i = 1; i <= dT; i++)
		{
			t = calc(d[i], tim[i]);
			s = (s * t) % mod;
		}
		cout << s << endl;
	}
}
