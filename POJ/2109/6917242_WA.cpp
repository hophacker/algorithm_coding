#include<iostream>
#include<fstream>
#include<memory.h>
#include<string>
using namespace std;

int n, bp, bk, i;
int p[110], k[11];
string s;

bool ok(int dep)
{
	int k1[11], k2[11];
	memcpy(k1, k, sizeof(k1));
	for (int i = 1; i <= n-1; i++)
	{
		memset(k2, 0, sizeof(k2));
		for (int j = 1; j <= 9; j++)
			for (int l = 1; l <= 9; l++)
				if (j+l-1 <= 9)
					k2[j+l-1] += k[j] * k1[l];
		memcpy(k1, k2, sizeof(k1));
		int jin = 0, t;
		for (int j = 1; j <= 9; j++)
		{
			t = k1[j] + jin;
			k1[j] = t % 10;
			jin = t / 10;
		}
	}
	for (int i = 1; i <= dep; i++)
		if (k1[i] != p[i]) return false;
	return true;
}
bool check()
{
	int a[110], a1[110];
	memset(a, 0, sizeof(a));
	a[1] = 1;
	for (int time = 1; time <= n; time++)
	{	
		memset(a1, 0, sizeof(a1));
		for (int i = 1; i <= bp + 5; i++)
			for (int j = 1; j <= bk; j++)
				if (i + j <= bp+5)
					a1[i+j-1] += a[i] * k[j];
		memcpy(a, a1, sizeof(a));
		int jin = 0, t;
		for (int i = 1; i <= bp + 5; i++)
		{
			t = a[i] + jin;
			a[i] = t % 10;
			jin = t / 10;
		}
	}
	for (int i = 1; i <= bp; i++)
		if (a[i] != p[i]) return false;
	return true;
}
void print(int k[11])
{
	for (int i = bk; i >= 1; i--)
		cout << k[i];
	cout << endl;
}
bool search(int dep)
{
	if (dep == bk+1)
		if (check()) 
		{
			print(k);
			return true;
		}
		else return false;
	for (int i = 0; i <= 9; i++)
	{
		k[dep] = i;
		if (ok(dep)) if(search(dep+1)) return true;
	}
	return false;
}
int main()
{
	//freopen("in.txt", "r", stdin);
	while(cin >> n >> s)
	{
		bp = s.length();
		for (i = 0; i < s.length(); i++)
			p[i+1] = s[s.length()-1-i]-'0';
		if (n == 1) cout << s << endl;
		else
		{
			bk = (bp-1) / n + 1;
			memset(k, 0, sizeof(k));
			search(1);
		}
	}
}
