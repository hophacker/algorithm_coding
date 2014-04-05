#include<iostream>
#include<fstream>
#include<string>
using namespace std;

string dic[10001];
string w[51];
int change[10001];
int dicn, wn, cn;
bool check(string& s)
{
	cn = 0;
	int t;
	for (int i = 0; i < dicn; i++)
	{
		if (dic[i].length() == s.length())
		{
			if (dic[i] == s) return true;
			t = 0;
			for (int j = 0; j < s.length(); j++)
			{
				if (dic[i][j] != s[j]) t++;
				if (t > 2) break;
			}
			if (t == 1)
				change[cn++] = i;
		}else 
		if (dic[i].length() == s.length() - 1)
		{
			t = 0; int j;
			for (j = 0; j < dic[i].length(); j++)
				if ((t = s.find(dic[i][j], t)) == string::npos) break;
				else t++;
			if (j == dic[i].length())
				change[cn++] = i;
		}else
		if (dic[i].length() == s.length() + 1)
		{
			t = 0; int j;
			for (j = 0; j < s.length(); j++)
				if ((t = dic[i].find(s[j], t)) == string::npos) break;
				else t++;
			if (j == s.length())
				change[cn++] = i;
		}
	}
	return false;
}
int main()
{
	//freopen("in.txt", "r", stdin);
	dicn = wn = 0;
	while (cin >> dic[dicn] && dic[dicn] != "#") dicn++;
	while (cin >> w[wn] && w[wn] != "#") 
		wn++;
	for (int i = 0; i < wn; i++)
	{
		cout << w[i];
		if (check(w[i])) cout << " is correct\n";
		else
		{
			if (cn == 0)
				cout << ":\n";
			else
			{
				cout << ":";
				for (int j = 0; j < cn; j++)
					cout << ' ' << dic[change[j]];
				cout << endl;
			}
		}
	}
}
