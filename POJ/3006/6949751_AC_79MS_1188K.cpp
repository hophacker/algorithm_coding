#include<iostream>
#include<memory.h>
#include<fstream>
using namespace std;

bool prime[1000001];
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out1.txt", "w", stdout);
	memset(prime, 1, sizeof(prime));
	int i = 2, j;
	prime[1] = false;
	while (i <= 1000000)
	{
		while (!prime[i]) i++;
		j = i+i;
		while (j <= 1000000)
			prime[j] = false, j += i;
		i++;
	}
	int a, d, n, t;
	while (cin >> a >> d >> n, a || d || n)
	{
		t = 0;
		for (i = a;; i+= d)
		{
			if (prime[i]) t++;
			if (t == n) break;
		}
		cout << i << endl;
	}
}
