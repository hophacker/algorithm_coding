/*
ID: fengjie3
PROG: dualpal
LANG: C++
*/
#include<iostream>
#include<string>
using namespace std;
char charIt(int num)
{
	if (num < 10) return num+'0';
	else
		return num-10+'A';
}

string turn(int n, int base)
{
	string s("");
	while (n > 0)
	{
		s = charIt(n % base)+s;
		n /= base;
	}
	return s;
}
bool pal(string ss)
{
	if (ss.length() == 1) return true;
	for (int i = 0; i <= ss.length()/2 - 1; i++)
		if (ss[i] != ss[ss.length() - 1 - i]) return false;
	return true;
}
int main()
{
	freopen("dualpal.in", "r", stdin);
	freopen("dualpal.out", "w", stdout);
	int n, m;
	int total = 0;
	string s;
	cin >> n >> m;
	for (int i = m+1;; i++)
	{
		int t = 0;
		for (int base = 2; base <= 10; base++)
			if (pal(turn(i, base))) t++;
		if (t > 1) 
		{
			total++;
			cout << i << endl;
		}
		if (total == n) break;
	}
}
