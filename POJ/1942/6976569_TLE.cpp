#define ll unsigned int 
#include<iostream>
#include<fstream>
using namespace std;
ll n, m;
double calc(ll n, ll k)
{
 	double  t = 1; 
	for (ll i = (n-k+1); i <= n; i++) t *= i;
	for (ll i = 1; i <= k; i++) t /= i;
	return t;
}
ll minIt(ll n, ll m) { return (n > m)? m: n; }
int main()
{
	while (scanf("%d %d", &n, &m), n || m)
		printf("%0.0f\n", calc(n+m, minIt(n, m)));
}
