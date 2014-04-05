#include<iostream>
#include<memory.h>
#include<fstream>
using namespace std;

bool prime[1000001];
int pNum[1000001];
int pT = 0;
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
	for (int i = 2; i <= 1000000; i++)
		if (prime[i]) pNum[++pT] = i;
	int n;
	while (cin >> n, n != 0)
	{
		for (int i = 1; i <= pT; i++)
			if (prime[pNum[i]] && prime[n - pNum[i]])
			{
				printf("%d = %d + %d\n", n, pNum[i], n-pNum[i]);
				break;
			}	
	}
}
