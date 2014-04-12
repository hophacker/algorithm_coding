#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
using namespace std;

bool sub(char s1[], char s2[])
{
	int len1 = strlen(s1), len2 = strlen(s2);
	int i2 = 0;
	for (int i = 0; i < len1; i++)
	{
		while (s2[i2] != s1[i] && i2 < len2) i2++;
	}
	if (i2 == len2) return false;
	else return true;
}
int main()
{
//	freopen("in.txt", "r", stdin);
	char s[100001], s1[100001];
	while (cin >> s >> s1)
	{
		if (sub(s, s1)) cout << "Yes\n";
		else cout << "No\n";
	}
}
