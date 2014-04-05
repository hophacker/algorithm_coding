#include<iostream>
#include<string>
using namespace std;
int n;
string str[11];
const int m = 17;
const int mod = 1327; 

bool ok(string& sub, string s)
{
	int tt = 0; 
	int jie = 1;
	int len = sub.length();
	for (int i = 1; i< len; i++) jie = (jie * m) % mod;
	for (int i = 0; i < len; i++) tt = (tt * m + sub[i]) % mod;
	int t[65];
	t[0] = 0;
	for (int i = 0; i < len; i++)
		t[0] = (t[0] * m + s[i]) % mod;
	for (int i = len; i < s.length(); i++)
		t[i - len + 1] = (((t[i - len] - s[i-len] * jie) * m + s[i]) % mod + mod) % mod;
	int j;
	for (int i = 0; i <= s.length() - len; i++)
	{
		if (t[i] == tt)
		{
			for (j = i; j < i+len; j++)	
				if (sub[j-i] != s[j]) break;
			if (j == i+len)
				return true;
		}	
	}
	return false;
}
bool check(string sub)
{
	for (int i = 2; i <= n; i++)
		if (!ok(sub, str[i])) return false;
	return true;
}
int main()
{
	int tests;
	//cout << ok("fengjie", "chenfengjieyou");
	//freopen("in.txt", "r", stdin);
	cin >> tests;
	while (tests--)
	{
		string longest = ""; int len;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> str[i];
		for (len = str[1].length(); len >= 3; len--)
		{
			for (int i = 0; i <= str[1].length() - len; i++)
			{
				string sub = str[1].substr(i, len);
				
				if (check(sub))
					if (longest == "" || sub < longest)
						longest = sub;
			}
			if (longest != "") break;
		}
		if (len <= 2) cout << "no significant commonalities\n";
		else cout << longest << endl;
	}	
}
