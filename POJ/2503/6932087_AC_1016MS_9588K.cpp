#include<iostream>
#include<fstream>
#include<string>
#include<map>
using namespace std;

map<string,string> stos;

int main()
{
	int p;
	string s;
//	ifstream cin("in.txt");
	while(true)
	{
		getline(cin, s);
		if (s == "") break;
		int p = s.find(" ");
		stos[s.substr(p+1, s.length()-1-p)] = s.substr(0, p);
	}
	map<string,string>::iterator ii;
	while (cin >> s)
	{
		ii = stos.find(s);
		if (ii == stos.end()) cout << "eh\n";
		else cout << ii->second << endl;
	}
}
