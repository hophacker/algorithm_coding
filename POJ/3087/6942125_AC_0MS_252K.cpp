#include<iostream>
#include<fstream>
using namespace std;

int n, gtd;
int cir[201], total;

inline int gcd(int a, int b)
{
	int t;
	while (a != 0)
	{
		t = b % a;
		b = a;
		a = t;
	}
	return b;
}
int gtdIt(int a, int b)
{
	if (a > b) swap(a, b);
	return a * b / gcd(a, b);
}
void fill(int i)
{
	total = 0;
	while (cir[i] == 0)
	{
		cir[i] = 1;
		total++;
		if (i <= n) i *= 2;
		else i = (i-n)*2 - 1;
	}
	gtd = gtdIt(gtd, total);
}
bool same(char a[], char b[])
{
	for (int i = 1; i <= 2*n; i++)
		if (a[i] != b[i]) return false;
	return true;
}
int main()
{
	//freopen("in.txt", "r", stdin);
	int tests; cin >> tests;
	char a[201], b[201], c[201];
	for (int te = 1; te <= tests; te++)
	{
		cin >> n;
		for (int i = 1; i <= 2*n; i++) cin >> a[i];
		for (int i = 1; i <= 2*n; i++) cin >> b[i];
		memset(cir, 0, sizeof(cir));
		gtd = 1;
		for (int i = 1; i <= 2*n; i++)
			if (cir[i] == 0)
				fill(i);
		int i;
		for (i = 1; i <= gtd+1; i++)
		{
			if (same(a, b)) break;
			memcpy(c, a, sizeof(c));
			for (int i = 1; i <= 2*n; i++)	
				if (i <= n) a[i*2] = c[i];
				else a[(i-n)*2 - 1] = c[i];
		}
		cout << te << ' ';
		if (i != gtd+2) cout << i-1 << endl;
		else cout << -1 << endl;
	}
}
