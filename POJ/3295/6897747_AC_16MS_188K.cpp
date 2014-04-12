#include<iostream>
#include<memory.h>
#include<string>
#include<fstream>
using namespace std;
bool used[6];    //对应于字母是否使用 
int num = 0;
int a[6], list[6]; //a对应于使用的字母 
string s;

bool ok(char c)
{
	return c-'p' <= 4 && c-'p' >= 0;
}
int trans(char c)
{
	if (c == 'K') return -1;else 
	if (c == 'A') return -2;else
	if (c == 'N') return -3;else
	if (c == 'C') return -4;else
	if (c == 'E') return -5;else
	return list[a[c-'p']];
}
bool compare()
{
	int stack[101], stack1[101], top, top1;
	for (int i = 1; i <= s.length(); i++)
		stack[i] = trans(s[i-1]);
	top = s.length();
	top1 = 0;
	while (top >= 2)
	{
		if (stack[top-1] == -3)
		{
			stack[top-1] = !stack[top];
			top--;
		}else
		if (stack[top-1] < 0)
		{
			
			if (stack[top-1] == -1) stack[top-1] = stack1[top1] && stack[top];else
			if (stack[top-1] == -2) stack[top-1] = stack1[top1] || stack[top];else
			if (stack[top-1] == -4) stack[top-1] = (stack1[top1] <= stack[top]);else
			if (stack[top-1] == -5) stack[top-1] = (stack1[top1] == stack[top]);
			top1 --, top--;
		}else
		if (stack[top-2] < 0 && stack[top-2] != -3)
		{
			if (stack[top-2] == -1) stack[top-2] = stack[top-1] && stack[top];else
			if (stack[top-2] == -2) stack[top-2] = stack[top-1] || stack[top];else
			if (stack[top-2] == -4) stack[top-2] = (stack[top-1] <= stack[top]);else
			if (stack[top-2] == -5) stack[top-2] = (stack[top-1] == stack[top]);
			top -= 2;
		}else
			stack1[++top1] = stack[top--];
	}
	return stack[1];
}
int main()
{
//	freopen("in.txt", "r", stdin);
	while (cin >> s, s != "0")
	{
		memset(list, 0, sizeof(list));
		memset(a, 0, sizeof(a));
		num = 0;
		for (int i = 0; i < s.length(); i++)
			if (ok(s[i]) && !used[s[i] - 'p'])
				used[s[i] - 'p'] = true;
		for (int i = 0; i < 5; i++)
			if (used[i]) a[i] = ++num;
		while (list[0] == 0)
		{
			if (!compare())
			{
				cout << "not\n";	
				break;
			}
			int p = num;
			while (list[p] == 1 && p >= 1) p--;
			list[p] = 1;
			for (int i = p+1; i <= num; i++) list[i] = 0; 
		}
		if (list[0] == 1)
			cout << "tautology\n";
	}
}
