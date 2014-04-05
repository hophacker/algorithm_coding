#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int a, b, d, trueA;
	while(cin >> a >> b)
	{
		if (a < b)
			swap(a, b);
		d = a - b;
		if (b == int(floor(d * (1 + sqrt(5.0)) / 2))) cout << 0 << endl;
		else
			cout << 1 << endl;
	}
}