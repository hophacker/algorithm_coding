#define ll long long 
#include<iostream>
#include<fstream>
using namespace std;
int n, m;
ll calc(ll n, ll k)
{
 	double  t = 1; 
	for (int i = (n-k+1); i <= n; i++) t *= i;
	for (int i = 1; i <= k; i++) t /= i;
	return static_cast<ll>(t + 0.5);
}
ll min(ll n, ll m) { return (n > m)? m: n; }
int main()
{
	while (cin >> n>> m, n || m)
		cout << calc(n+m, min(n, m));
}
