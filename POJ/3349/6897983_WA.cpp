#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
const int mod = 10000;
struct node
{
	int s[6];
};
node snow;
const int jie[6] = {0, 1, 2, 6, 24, 120};
void left(node &snow)
{
	snow.s[6] = snow.s[0];
	for (int i = 1; i <= 6; i++)
		snow.s[i-1] = snow.s[i];
}
void reverse(node& snow)
{
	int t;
	for (int i = 0; i <= 2; i++)
		t = snow.s[i], snow.s[i] = snow.s[5-i], snow.s[5-i] = t;
}
int hash(node& snow)
{
	int s = 0;
	for (int i = 0; i < 6; i++) s += snow.s[i];
	return s % mod;
}
bool same(node& snow1, node& snow2)
{
	return true;//
	for (int i = 1; i <= 6; i++)
	{
		bool ok = true;
		for (int j = 0; j < 6; j++)
			if (snow1.s[j] != snow2.s[j]) 
			{
				ok = false;
				break;
			}
		if (ok) return true;
		left(snow2);
	}
	reverse(snow2);
	for (int i = 1; i <= 6; i++)
	{
		bool ok = true;
		for (int j = 0; j < 6; j++)
			if (snow1.s[j] != snow2.s[j])
			{
				ok = false;
				break;
			}
		if (ok) return true;
		left(snow2);
	}
	return false;
}
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	vector<node>vs[mod+3];
	int n;
	int num, maxNum;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 6; j++) cin >> snow.s[j];
		int hashNum = hash(snow);
		for (int j = 0; j < vs[hashNum].size(); j++)
		{
			if (same(vs[hashNum][j], snow)) 
			{
				cout << "Twin snowflakes found.\n";
				return 0;
			}
		}
		vs[hashNum].push_back(snow);
	}
	cout << "No two snowflakes are alike.\n";
}
