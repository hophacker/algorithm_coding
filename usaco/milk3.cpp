/*
ID: fengjie3
PROG: milk3
LANG: C++
*/

#include<iostream>
#include<memory.h>
#include<queue>
using namespace std;

int a, b, c;
bool used[61];
bool pan[21][21][21];
struct node
{	
	int a, b, c;
};
queue<node> q;
void dao(int a, int b, int c)
{
	node t;
	t.a = a;
	t.b = b;
	t.c = c;
	
	if (pan[t.a][t.b][t.c])
	{
		if (t.a == 0)
			used[t.c] = true;
		pan[t.a][t.b][t.c] = false;
		q.push(t);
	}
}
int main()
{
	freopen("milk3.in", "r", stdin);
	freopen("milk3.out", "w", stdout);
	cin >> a >> b >> c;
	memset(used, false, sizeof(used));
	memset(pan, true, sizeof(pan));
	node t;
	t.a = 0;
	t.b = 0;
	t.c = c;
	pan[0][0][c] = false;
	used[c] = true;
	q.push(t);
	
	while (!q.empty())
	{
		t = q.front();
		q.pop();
		if (t.a + t.b > b)
			dao(t.a + t.b - b, b, t.c);
		else
			dao(0, t.a + t.b, t.c);
		
		if (t.b + t.a > a)
			dao(a, t.b + t.a - a, t.c);
		else
			dao(t.b + t.a, 0, t.c);
		
		if (t.a + t.c > c)
			dao(t.a + t.c - c, t.b, c);
		else
			dao(0, t.b, t.a + t.c);
		
		if (t.a + t.c > a)
			dao(a, b, t.a + t.c - a);
		else
			dao(t.a + t.c, t.b, 0);
		
		if (t.b + t.c > c)
			dao(t.a, t.b + t.c - c, c);
		else
			dao(t.a, 0, t.b + t.c);
		
		if (t.b + t.c > b)
			dao(t.a, b, t.b + t.c - b);
		else
			dao(t.a, t.b + t.c, 0);
	}
	int result[61];
	int total = 0;
	for (int i = 0; i <= 60; i++)
		if (used[i])
			result[++total] = i;
	for (int i = 1; i <= total; i++)
	{
		cout << result[i];
		if (total == i) cout << endl;
		else cout << " ";
	}
}
