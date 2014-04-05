#include<iostream>
#include<memory.h>
#include<fstream>
#include<string>
using namespace std;

char map[9][9];
void doIt(string& s, char cc)
{
	int x, y, p , q;
	p = s.find(' ');
	while(true)
	{
		if ('A' <= s[p+1] && s[p+1] <= 'Z')
		{
			x = s[p+3] - '0';
			y = s[p+2] - 'a' + 1;
			map[x][y] = s[p+1] - 'A' + cc;
		}
		else
		{
			x = s[p+2] - '0';
			y = s[p+1] - 'a' + 1;
			map[x][y] = ('p' - 'a') + cc;
		}
		if ((p = s.find(",", p+1)) == string::npos) break;
	}
}
void printLine()
{
	for (int i = 1; i <= 8; i++)
		cout << "+---";
	cout << "+\n";
}
void print(bool yes)
{
	if (yes) cout << '.';else cout << ':';
}
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	string s;
	memset(map, ' ', sizeof(map));
	getline(cin, s);
	doIt(s, 'A');
	getline(cin, s);
	doIt(s, 'a');
	for (int i = 8; i >= 1; i--)
	{
		printLine();
		for (int j = 1; j <= 8; j++)
		{
			cout << '|';
			bool yes = ((i+j)%2 ==	1);
			print(yes);
			if (map[i][j] == ' ') 
				print(yes);
			else cout << map[i][j];
			print(yes);
		}
		cout << '|' << endl;
	}
	printLine();
}
