#include<iostream>
#include<memory.h>
#include<fstream>
using namespace std;

bool prime[10001];
int pNum[10001];
int pT = 0;
int sum[10001];
int main()
{
	//freopen("in.txt", "r", stdin);
	memset(prime, 1, sizeof(prime));
	int i = 2, j;
	while (i <= 10000)
	{
		while (!prime[i]) i++;
		j = i+i;
		while (j <= 10000)
			prime[j] = false, j += i;
		i++;
	}
	for (int i = 2; i <= 10000; i++)
		if (prime[i]) pNum[++pT] = i;
	int t;
	for (int i = 1; i <= pT; i++)
	{
		t = 0;
		for (int j = i; j <= pT; j++)
		{
			t += pNum[j];
			if (t > 10000) break; 
			sum[t]++;
		}
	}
	int n;
	while (cin >> n, n != 0) cout << sum[n] << endl;
}
