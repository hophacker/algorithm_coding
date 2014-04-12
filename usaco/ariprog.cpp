/*
ID: fengjie3
PROG: ariprog
LANG: C++
*/

#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<memory.h>
using namespace std;
bool pan[200000];
struct node 
{
	int a, b;
};
bool cmp(const node &a, const node &b)
{
	if (a.b == b.b) return a.a < b.a;
	else
		return a.b < b.b;
}
int main()
{
	//freopen("ariprog.in", "r", stdin);
	//freopen("ariprog.out", "w", stdout);
	int total = 0;
	int n, m;
	node pair[10001];
	cin >> n >> m;
	int max = m*m*2;
	memset(pan, false, sizeof(pan));
	for (int i = 0; i <= m; i++)
		for (int j = 0; j <= m; j++)
			pan[i*i + j*j] = true;
	int s;
	int num = 0;
	int list[1000000];
	for (int i = 0; i <= max; i++)	
		if (pan[i])
			list[++num] = i;
		
	for (int i = 1; i <= num-n+1; i++)
		for (int j = 1;; j++)
		{
			bool ok = true;
			int t = list[i];
			int d = list[i+j] - list[i];
			if (t + (n-1)*d > max) break;
			for (int time = 1; time <= n-1; time++)
				if (pan[t+d] && t+d <= max)
					t += d;
				else
				{
					ok = false;
					break;
				}
			if (ok) 
			{
				total++;
				pair[total].a = list[i];
				pair[total].b = list[i+j] - list[i];
			}
		}
			
	sort(pair+1, pair+total+1, cmp);
	for (int i = 1; i <= total; i++)
		printf("%ld %ld\n", pair[i].a, pair[i].b);
	if (total == 0) cout << "NONE" << endl;
	// cout << total << endl;
}
	
