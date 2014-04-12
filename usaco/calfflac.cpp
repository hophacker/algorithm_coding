/*
ID: fengjie3
PROG: calfflac
LANG: C++
*/

#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
int rep[20001];
bool pal(int i, int j)
{
	for (int t = i; t <= i + (j-i)/2; t++)
		if (rep[t] != rep[j+i-t]) return false;
	return true;
}
int main()
{
	freopen("calfflac.in", "r", stdin);
	freopen("calfflac.out", "w", stdout);
	char s[20001];
	int pos[20001];
	char c;
	int total = 0, n = 0;
	while ((c = getchar()) != EOF)
	{
		s[++n] = c;
	}
	for (int i = 1; i <= n; i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			pos[++total] = i;
			rep[total] = s[i] - 'a';
		}
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			pos[++total] = i;
			rep[total] = s[i] - 'A';
		}	
	}
	int p = 1, max = 1;
	for (int t = 2; t <= total-1; t++)
	{
		for (int i = 1; t-i >= 1 && t+i <= total; i++)
			if (rep[t-i] == rep[t+i])
			{	if (2*i+1 > max || 2*i+1 == max && t - i < p)
				{
					max = 2*i+1;
					p = t-i;
				}
			}
			else
				break;
	}
	for (int t = 1; t <= total-1; t++)
	{
		for (int i = 0; t-i >= 1 && t+i+1 <= total; i++)
			if (rep[t-i] == rep[t+i+1])
			{
				if (2*i+2 > max || 2*i+2 == max && t - i < p)
				{
					max = 2*i+2;
					p = t - i;
				}
			}
			else break;
	}
	cout << max << endl;
	for (int i = pos[p]; i <= pos[p+max-1]; i++)
		printf("%c", s[i]);
	cout << endl;
}
