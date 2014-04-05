/*
ID: fengjie3
PROG: friday
LANG: C++
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool leapYear(int year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) return true;
	else
	 	return false;
}
int mm[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main()
{
	freopen("friday.in", "r", stdin);
	freopen("friday.out", "w", stdout);
	int n;
	int we = 0; 
	vector<int> sum(7, 0);
	cin >> n;
	for (int year = 1900; year <= 1900+n-1; year++)
	{
		if (leapYear(year)) mm[2] = 29;
		else
			mm[2] = 28;
		for (int month = 1; month <= 12; month++)
		{
			sum[(we + 13) % 7]++;
			we = (we+mm[month]) % 7;
		}
	}
	cout << sum[6];
	for (int i = 0; i <= 5; i++)
		cout << " " << sum[i];
	cout << endl;
}
