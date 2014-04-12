#include<iostream>
#include<memory.h>
#include<fstream>
using namespace std;

int a[6];
int x1[101];
int* x = x1 + 50;
bool pan1[250001];
bool* pan = pan1 + 125000;
int main()
{
	memset(pan, false, sizeof(pan));
//	freopen("in.txt", "r",stdin);
	for (int i = 1; i <= 5; i++) 
		cin >> a[i];
	for (int i = -50; i <= 50; i++) 
	{
		x[i] = i * i * i;
		pan[x[i]] = true;
	}
	int total = 0, t, k;
	int x1, x2, x3, x4, x5;
	for (x1 = 1; x1 <= 50; x1++)
		for (x2 = -50; x2 <= 50; x2++) if (x2 != 0)
			for (x3 = -50; x3 <= 50; x3++) if (x3 != 0)
				for (x4 = -50; x4 <= 50; x4++) if (x4 != 0)
				{
					t = x[x1]*a[1] + x[x2]*a[2] + x[x3]*a[3] + x[x4]*a[4];
					if (t % a[5] == 0)
					{
						k = t / a[5];
						if (k == 0) continue;
						if (k < 0) k = -k;
						if (k <= 125000 && pan[k]) total++;
					}
				}
	cout << total*2 << endl;
}
