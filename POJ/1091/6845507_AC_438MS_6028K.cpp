#include<iostream>
#include<memory.h>
#include<cmath>
using namespace std;
const int nn = 35;
int mem[10001][nn];
int n, m;
void a_b(int m, int n, int total[nn])
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= total[0]; j++)
			total[j] *= m;
		int jin = 0, temp;
		for (int j = 1; j <= nn-1; j++)
		{
			temp = total[j] + jin;
			total[j] = temp % 10;
			jin = temp / 10;
		}
		temp = nn-1;
		while (total[temp] == 0) temp--;
		total[0] = temp;
	}
}
void sub(int total[nn], int b[nn])
{
	for (int i = 1; i <= nn-1; i++)
	{
		if (total[i] < b[i])
		{
			total[i+1] -= 1;
			total[i] += 10;
		}
		total[i] -= b[i];
	}
	int temp = nn-1;
	while (total[temp] == 0)
		temp--;
	total[0] = temp;
}
int* f(int m)
{
	if (m <= 10000 && mem[m][0] != 0) return mem[m];
	int total[nn];
	memset(total, 0, sizeof(int)*nn);
	total[1] = total[0] = 1;
	a_b(m, n, total);
	for (int i = 2; i <= sqrt(double(m)); i++)
		if (m % i == 0)
		{
			sub(total ,f(i));
			if (i * i != m)
				sub(total ,f(m / i));
		}
	int b[nn];
	memset(b, 0, sizeof(b));
	b[1] = b[0] = 1;
	sub(total, b);
	if (m <= 10000)
	{
		memcpy(mem[m], total, sizeof(total));
		return(mem[m]);
	}
	else
	{
		int *t = new int[nn];
		memcpy(t, total, sizeof(total));
		return t;
	}
}
void print(int total[nn])
{
	for (int i = total[0]; i >= 1; i--)
		cout << total[i];
	cout << endl;
}
int main()
{
	memset(mem, 0, sizeof(mem));
	mem[1][0] = mem[1][1] = 1;
    cin >> n >> m;
	print(f(m));
}