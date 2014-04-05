#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int c[27][27];
void pre()
{
	c[1][0] = c[1][1] = 1;
	for (int i = 2; i <= 26; i++)
	{
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; j++)
			c[i][j] = c[i-1][j-1] + c[i-1][j];
	}
}
bool ok(string &s)
{
	for (int i = 0; i < s.length()-1; i++)
		if (s[i] >= s[i+1]) return false;
	return true;
}
int main()
{
	//freopen("in.txt", "r", stdin);
	string s;
	cin >> s;
	pre();
	if (ok(s))
	{
		int ans = 0, len = s.length(), f;
		for (int i = 1; i <= s.length()-1; i++)
			ans += c[26][i];
		for (int i = 0; i < s.length(); i++)
		{
			if (i == 0) f = 1; else f = s[i-1]-'a'+2;
			for (int j = f; j <= (s[i]-'a'); j++)
				ans += c[26-j][len-i-1];
		}
		cout << ans+1 << endl;
	}
	else cout << 0;
}
