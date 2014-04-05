#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string s1, s2;
int n1[26], n2[26];
int main()
{
	//freopen("in.txt", "r", stdin);
	getline(cin, s1);	
	getline(cin, s2);
	for (int i = 0; i < s1.length(); i++) 
		n1[s1[i]-'A']++, n2[s2[i]-'A']++;
	sort(n1, n1+26);
	sort(n2, n2+26);
	for (int i = 0; i < 26; i++)
		if (n1[i] != n2[i]) 
		{
			cout << "NO" << endl;
			return 0;
		}
	cout << "YES" << endl;
}
