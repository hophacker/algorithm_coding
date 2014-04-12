#define ll unsigned int 
#include<iostream>
#include<fstream>
using namespace std;
ll n, m;
ll calc(ll n, ll k)
{
 	double  t = 1; 
	for (ll i = (n-k+1); i <= n; i++) t *= i;
	for (ll i = 1; i <= k; i++) t /= i;
	return static_cast<ll>(t + 0.5);
}
ll minIt(ll n, ll m) { return (n > m)? m: n; }
int main()
{
	while (scanf("%d %d", &n, &m), n || m)
		printf("%d\n", calc(n+m, minIt(n, m)));
}
