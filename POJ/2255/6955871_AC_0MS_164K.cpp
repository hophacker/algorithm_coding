#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void post(string pre, string in)
{
	if (pre.length() == 0) return;
	else if (pre.length() == 1) {cout << pre[0]; return;}
	int pos = in.find(pre[0]);
	post(pre.substr(1, pos), in.substr(0, pos));
	post(pre.substr(pos+1, pre.length()-pos-1), in.substr(pos+1, in.length()-pos-1));
	cout << pre[0];
}
int main()
{
	//freopen("in.txt", "r", stdin);
	string pre, in;
	while (cin >> pre >> in)
	{
		post(pre, in);	
		cout << endl;
	}
}
