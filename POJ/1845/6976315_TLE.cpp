#include<iostream>
#include<fstream>
using namespace std;

const int mod = 9901;
int d[100], dT = 0, p, tim[100], s, t, jie;
int main()
{
	int a, b;
	cin >> a >> b;
	if (b == 0 || a == 1) cout << 1 << endl;
	else
		if (a == 0) cout << 0 << endl;
	else
	{
		while (a > 1)
		{
			for (p = 2;;p++)
				if (a % p == 0) break;
			d[++dT] = p;
			while (a % p == 0) tim[dT]++, a /= p;
		}
		for (int i = 1; i <= dT; i++)
			tim[i] *= b;
		s = 1;
		for (int i = 1; i <= dT; i++)
		{
			t = 1; jie = 1;
			while (tim[i]--)
			{
				jie = (jie*d[i]) % mod;
				t = (t + jie) % mod;
			}
			s = (s * t) % mod;
		}
		cout << s << endl;
	}
}
