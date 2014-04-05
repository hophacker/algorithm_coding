#include<iostream>
#include<fstream>
#include<string>
using namespace std;
bool first = true;
char map[9][9];
int d, l, r;
void cao(char c)
{
	for (int i = 1; i <= 8; i++)
		for (int j = 1; j <= 8; j++)
			if (map[i][j] == c)
			{
				if (first) first = false;
				else cout << ',';
				if (c != 'p' && c != 'P') cout << c;
				cout << char(j+'a'-1) << i;
				
			}
}
void cao1(char c)
{
	for (int i = 8; i >= 1; i--)
		for (int j = 1; j <= 8; j++)
			if (map[i][j] == c)
			{
				if (first) first = false;
				else cout << ',';
				if (c != 'p' && c != 'P') cout << char(c+'A'-'a');
				cout << char(j+'a'-1) << i;
				
			}
}
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	string s;
	for (int i = 1; i <= 8; i++)
	{
		getline(cin, s);
		getline(cin, s);
		for (int j = 1; j <= 8; j++)
			map[9-i][j] = s[j*4-2];
	}
	first = true;
	cout << "White: ";
	cao('K');cao('Q');cao('R');cao('B');cao('N');cao('P');
	cout << endl;
	first = true;
	cout << "Black: ";
	cao1('k');cao1('q');cao1('r');cao1('b');cao1('n');cao1('p');
	cout << endl;
}
