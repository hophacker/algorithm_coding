#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	int a[10001];
	for (int i = 1; i <= 10000; i++)
		cin >> a[i];
	sort(a+1, a+n+1);
	cout << a[(n+1) / 2] << endl;
}
