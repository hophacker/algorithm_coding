#include<iostream>
#include<fstream>
#include<string>
using namespace std;

inline int cton(char c)
{
	if (c == ' ') return 0;
	else return c - 'A' + 1;
}
int main()
{
	//freopen("in.txt", "r", stdin);
	string s;
	while (getline(cin, s), s != "#")
	{
		int t = 0;
		for (int i = 0; i < s.length(); i++)
			t += (i+1)*cton(s[i]);
		cout << t << endl;
	}
}
