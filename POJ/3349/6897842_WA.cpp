#include<iostream>
#include<fstream>
using namespace std;
int snow[7];
bool pan[721];
const int jie[6] = {0, 1, 2, 6, 24, 120};
void left()
{
	snow[6] = snow[0];
	for (int i = 1; i <= 6; i++)
		snow[i-1] = snow[i];
}
void reverse()
{
	int t;
	for (int i = 0; i <= 2; i++)
		t = snow[i], snow[i] = snow[5-i], snow[5-i] = t;
}
int hash()
{
	int t, num = 0;
	for (int i = 0; i <= 4; i++)
	{
		t = 0;
		for (int j = i+1; j <= 5; j++) if (snow[i] > snow[j]) t++;
		num += jie[5-i] * t;
	}
	return num;
}
int main()
{
	//freopen("in.txt", "r", stdin);
	int n;
	int num, maxNum;
	cin >> n;
	if (n > 720) 
	{
		
		cout << "Twin snowflakes found.\n";
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 6; j++) cin >> snow[j];
		maxNum = -1;
		for (int j = 1; j <= 6; j++)
		{
			num = hash();
			if (num > maxNum) maxNum = num;
			left();
		}
		reverse();
		for (int j = 1; j <= 6; j++)
		{
			num = hash();
			if (num > maxNum) maxNum = num;
			left();
		}
		if (pan[maxNum])
		{
			cout << "Twin snowflakes found.\n";
			return 0;
		}
		else pan[maxNum] = true;
	}
	cout << "No two snowflakes are alike.\n";
}
