#include<iostream>
#include<memory.h>
#include<string>
#include<fstream>
using namespace std;

int n, bp, i;
int p[120], q[120], r[120];
string s;

void calc(int q[120], int k, int n)
{
	memset(r, 0, sizeof(r));
	for (int i = 1; i <= n; i++)
	{
		int j;
		for (j = 1; j <= q[0]; j++)
			q[j] *= k;
		int jin = 0, t;
		for (j = 1; j <= q[0]+9; j++)
		{
			t = jin + q[j];
			q[j] = t % 10;
			jin = t / 10;
		}
		q[0] = q[0] + 9;
		while (q[q[0]] == 0) q[0]--;
		if (q[0] > 100) return;
	}
}
int compareIt(int p[120], int q[120])
{
	if (p[0] > q[0]) return 1;
	if (p[0] < q[0]) return -1;
	int t = q[0];
	while (p[t] == q[t] && t >= 1) t--;
	if (t == 0) return 0;
	if (p[t] > q[t]) return 1; else return -1;
}
int main()
{
//	freopen("in.txt", "r", stdin);
	while(cin >> n >> s)
	{
		p[0] = s.length();
		for (i = 0; i < s.length(); i++)
			p[i+1] = s[s.length()-1-i]-'0';
	
		if (n == 1) cout << s << endl;
		else
		{
			int lk = 1, rk = 1000000000, mk;
			while (lk <= rk)
			{
				mk = (lk + rk) / 2;
				memset(q, 0, sizeof(q));
				q[0] = q[1] = 1;
				calc(q, mk, n);
				int com = compareIt(p, q);
				if (com == 0) break;
				else if (com == -1) rk = mk-1;
					 else lk = mk+1;
			}
			cout << mk << endl;
		}
	}
}
