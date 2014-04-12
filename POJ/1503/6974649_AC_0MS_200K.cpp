#include<iostream>
#include<string.h>
#include<fstream>
#include<memory.h>
using namespace std;

int main()
{
	//freopen("in.txt", "r", stdin);
	int a[110];
	memset(a, 0, sizeof(a));
	char s[110];
	while (scanf("%s", s) && strcmp(s, "0"))
	{
		int len = strlen(s);
		for (int i = 1; i <= len; i++)
			a[i] += (s[len-i] - '0');
	}
	int jin = 0, t;
	for (int i = 1; i <= 109; i++)
	{
		t = jin + a[i];
		a[i] = t % 10;
		jin = t /= 10;
	}
	t = 109;
	while (a[t] == 0 && t >= 1) t--;
	if (t == 0) cout << 0 << endl;
	else 
	{
		for (int i = t; i >= 1; i--) cout << a[i];
		cout << endl;
	}
}
