/*
ID: fengjie3
PROG: palsquare
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
	freopen("palsquare.in", "r", stdin);
	freopen("palsquare.out", "w", stdout);
	int base;
	cin >> base;
	int sq;
	string s;
	string ssq;
	for (int n = 1; n <= 300; n++)
	{
		sq = n * n;
		s = turn(n, base);
		ssq = turn(sq, base);
		if (pal(ssq)) cout << s << " " << ssq << endl;
	}
}
