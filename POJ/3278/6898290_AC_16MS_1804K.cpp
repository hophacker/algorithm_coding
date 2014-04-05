#include<iostream>
using namespace std;
int visit[200001];

int main()
{
	int a, b, h = 0, t = 0;
	int q[200001];
	cin >> a >> b, visit[a] = 1;
	q[h] = a;
	while (!visit[b])
	{
		int now = q[h];
		if (now * 2 <= 200000 && visit[now*2] == 0)
			visit[now*2] = visit[now]+1, q[++t] = now*2;
		if (visit[now+1] == 0)
			visit[now+1] = visit[now]+1, q[++t] = now+1;
		if (visit[now-1] == 0)
			visit[now-1] = visit[now]+1, q[++t] = now-1;
		h++;
	}
	cout << visit[b] - 1 << endl;
}
