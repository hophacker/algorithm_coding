#include<iostream>
#include<fstream>
using namespace std;
long long sum;
int a[500001];
int b[500001];
void merge(int l, int m, int r, int a[])
{
	int t = l, i = l, j = m+1;
	while (i <= m && j <= r)
		if (a[i] <= a[j])
			b[t++] = a[i++];
		else
			b[t++] = a[j++], sum += (m+1-i);
	while (i <= m)
		b[t++] = a[i++];
	while (j <= r)
		b[t++] = a[j++];
	for (int i = l; i <= r; i++)
		a[i] = b[i];
}
void mergeSort(int l, int r, int a[])
{
	if (r <= l) return;
	int m = (l + r) / 2;
	mergeSort(l, m, a);
	mergeSort(m+1, r, a);
	merge(l, m, r, a);
}
int main()
{
	//freopen("in.txt", "r", stdin);
	int n;
	while (scanf("%d", &n), n)
	{
		sum = 0;
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		mergeSort(1, n, a);
		cout << sum << endl;
	}
}
