#include<iostream>
#include<fstream>
using namespace std;

int bit[33], len;

int calc(int n ,int k)
{
	if (n < k) return 0;
	double a = 1; 
	for (int i = 1; i <= n; i++) a *= i;
	for (int i = 1; i <= k; i++) a /= i;
	for (int i = 1; i <= (n-k); i++) a/= i;
	return static_cast<int>(a+0.5);
}
int calc0(int n, int k)
{
	int t = 0;
	for (int i = k; i <= n; i++) t += calc(n, i);
	return t;
}
int calc1(int bit[33], int len, int k)
{
	if (k > len) return 0;
	else if (k == 0) return 1;

	if (bit[len] == 1)
		return calc1(bit, len-1, k) + calc0(len-1, k-1);
	else
		return calc1(bit, len-1, k-1);
}
int doIt(int n)
{
	if (n == -1) return 0;
	len = 0;
	while(n > 0)
		bit[++len] = n % 2, n /= 2;
	int t = (len+1) / 2;
	int total = calc1(bit, len-1, t); 
	for (int i = 1; i <= len-1; i++)
		total += calc0(i-1, (i+1)/2);
	return total;
}
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int a, b;
	cin >> a >> b;
	cout << doIt(b) -  doIt(a-1) << endl;
}
