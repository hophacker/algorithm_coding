#include<iostream>
#include<fstream>
#include<string>
using namespace std;

bool prime[1000101];
int pNum[1000101];
int pT = 0;
int bit[101];
bool devide(int m, int bit[], int len)
{	
	int temp = 0;
	for (int i = 1; i <= len; i++)
		temp = (temp * 10 + bit[i]) % m;
	if (temp % m == 0) return true;
	else return false;
}
int main()
{
	//freopen("in.txt", "r", stdin);
	memset(prime, 1, sizeof(prime));
	int i = 2, j;
	while (i <= 1000100)
	{
		while (!prime[i]) i++;
		j = i+i;
		while (j <= 1000100)
			prime[j] = false, j += i;
		i++;
	}
	for (int i = 2; i <= 1000100; i++)
		if (prime[i]) pNum[++pT] = i;
	string s;
	int m, p;
	while (cin >> s >> m, m)
	{
		for (int i = 0; i < s.length(); i++)
			bit[i+1] = s[i] - '0';
		p = 1;
		while (pNum[p] < m)
		{
			if (devide(pNum[p], bit, s.length())) break;
			p++;
		}
		if (pNum[p] >= m)
			cout << "GOOD\n";
		else
			cout << "BAD " << pNum[p] << endl;
	}
}
