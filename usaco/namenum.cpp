/*
ID: fengjie3
PROG: namenum
LANG: C++
*/

#include<iostream>
#include<algorithm>
#include<string>
#include<stdio.h>
using namespace std;

int numIt(char c)
{
	if (c < 'Q')
		return (c-'A')/3 + 2;
	else
		return (c-'B')/3 + 2;
}

int main()
{
	freopen("namenum.in", "r", stdin);
	freopen("namenum.out", "w", stdout);
	long long n, n1;
	cin >> n;
	freopen("dict.txt", "r", stdin);
	string s;
	string s1[5001];
	int total = 0;
	while (cin >> s)
	{
		n1 = 0;
		for (int i = 0; i < s.length(); i++)
			n1 = n1 * 10 + numIt(s[i]);
		if (n1 == n)
		{
			s1[++total] = s;
		}
	}
	sort(s1+1, s1+1+total);
	if (total == 0) cout << "NONE" << endl;
	else
	for (int i = 1; i <= total; i++)
		cout << s1[i] << endl;
}
