#include<iostream>
#include<fstream>
#include<string.h>
#include<algorithm>
using namespace std;

struct node
{
	int p, len;
}hash[601];
char word[601][30];
char txt[310];
int dp[310];
int w, l, t, maxLen = 0;

int match(int x, int y)
{
	for (int i = 1; i <= w; i++)		
	{
		if (hash[i].len > (y-x+1)) continue;
		int t = hash[i].p;
		int p = x-1;
		for (int j = 0; j < hash[i].len; j++)
		{	
			p++;
			while (txt[p] != word[t][j] && p <= y) p++;
			if (p > y) break;
		}
		if (p <= y) return hash[i].len; 
	}
	return 0;
}
bool cmp(const node& a, const node& b)
{
	return a.len > b.len;
}
int main()
{
	//freopen("in.txt", "r", stdin);
	cin >> w >> l;
	getchar();
	cin.getline(txt, 100, '\n');
	for (int i = 1; i <= w; i++)
	{
		cin.getline(word[i], 100, '\n');
		hash[i].p = i;
		hash[i].len = strlen(word[i]);
		if (hash[i].len > maxLen) maxLen = hash[i].len;
	}
	sort(hash+1, hash+w+1, cmp);
	int t;
	for (int i = 1; i <= l; i++)
	{
		for (int j = 0; j < i; j++)
		{
			t = dp[j] + match(j, i-1);
			if (t > dp[i])  dp[i] = t;
		}
	}
	cout << l - dp[l] << endl;
}
