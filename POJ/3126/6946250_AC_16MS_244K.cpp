#include<iostream>
#include<memory.h>
#include<fstream>
using namespace std;

struct node
{
	int x, d;
}q[10001];
int a, b, h, t, bit[5];
bool prime[10000];
bool used[10000];
void getPrime(bool prime[])
{
	prime[1] = false;
	int i = 2, j;
	while (i <= 9999)
	{
		while (!prime[i] && i <= 9999) i++;
		j = i+i;
		while (j <= 9999)
			prime[j] = false, j += i;
		i++;
	}
}
int calc(int bit[5])
{
	int t = 0;
	for (int i = 1; i <= 4; i++)
		t = t * 10 + bit[i];
	if (t < 1000) return 1;
	else return t;
}
int main()
{
	//freopen("in.txt", "r", stdin);
	memset(prime, true, sizeof(prime));
	getPrime(prime);
	int tests; cin >> tests;
	while (tests--)
	{
		memset(used, false, sizeof(used));
		cin >> a >> b;
		used[a] = true;
		h = t = 0;
		q[0].x = a, q[0].d = 0;
		int x, temp, num;
		while (h <= t)
		{
			if (q[h].x == b) break;
			x = q[h].x;
			for (int i = 4; i >= 1; i--)
				bit[i] = x % 10, x /= 10;
			for (int i = 1; i <= 4; i++)
				for (int j = 0; j <= 9; j++)
				{
					temp = bit[i];
					bit[i] = j;
					num = calc(bit);
					if (prime[num] && !used[num])
					{
						used[num] = true;
						t++;
						q[t].x = num, q[t].d = q[h].d+1;
					}
					bit[i] = temp;
				}
			h++;
		}
		if (q[h].x == b) cout << q[h].d << endl;
		else cout << "Impossible\n";
	}
}
