#include<iostream>
#include<fstream>
using namespace std;

int bit[33], len;

int calc(int n ,int k)
{
	if (n < k) return 0;
	if (n == k) return 1;
	double a = 1; 
	for (int i = 1; i <= n; i++) a *= i;
	for (int i = 1; i <= k; i++) a /= i;
	for (int i = 1; i <= (n-k); i++) a/= i;
	return static_cast<int>(a+0.5);
}
int calc1(int n, int k)
{
	int t = 0;
	for (int i = k; i <= n; i++)
		if (i >= 0) t += calc(n, i);
	return t;
}

int doIt(int n)
{
	if (n == -1 || n == 0) return 0;
	len = 0;
	while(n > 0)
		bit[++len] = n % 2, n /= 2;
	int total = 0, zero = 0;
	for (int i = 1; i <= len-1; i++)
		total += calc1(i-1, (i+1)/2);
	int t = (len+1) /2;
	
	for (int i = len-1; i >= 1; i--)
		if (bit[i] == 1)
			total += calc1(i-1, t-zero-1);
		else zero += 1;
	if (zero >= (len+1)/2) total++;
	return total;
}
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int a, b;
	//for (int i = 1; i <= 13;i++)
	{
	cin >> a >> b;
	cout << doIt(b) -  doIt(a-1) << endl;
	}
}
