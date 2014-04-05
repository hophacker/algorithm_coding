#include<iostream>
#include<memory.h>
#include<cmath>
using namespace std;
int mem[10001][150];
int n, m;
void a_b(int m, int n, int total[150])
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= total[0]; j++)
			total[j] *= m;
		int jin = 0, temp;
		for (int j = 1; j <= 149; j++)
		{
			temp = total[j] + jin;
			total[j] = temp % 10;
			jin = temp / 10;
		}
		temp = 149;
		while (total[temp] == 0) temp--;
		total[0] = temp;
	}
}
void sub(int total[150], int b[150])
{
	for (int i = 1; i <= 149; i++)
	{
		if (total[i] < b[i])
		{
			total[i+1] -= 1;
			total[i] += 10;
		}
		total[i] -= b[i];
	}
	int temp = 149;
	while (total[temp] == 0)
		temp--;
	total[0] = temp;
}
int* f(int m)
{
	if (m <= 10000 && mem[m][0] != 0) return mem[m];
	int *total = new int[150];
	memset(total, 0, sizeof(int)*150);
	total[1] = total[0] = 1;
	a_b(m, n, total);
	for (int i = 2; i <= sqrt(double(m)); i++)
		if (m % i == 0)
		{
			sub(total ,f(i));
			if (i * i != m)
				sub(total ,f(m / i));
		}
	int b[150];
	memset(b, 0, sizeof(b));
	b[1] = b[0] = 1;
	sub(total, b);
	if (m <= 10000)
		memcpy(mem[m], total, sizeof(total));
	return total;
}
void print(int total[150])
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
