#include<iostream>
#include<fstream>
#include<memory.h>
using namespace std;
int n, k, i, j, total, ans;
int s[10][10];
bool col[10];
char c;
void search(int dep, int k)
{
	if (k == 0) 
	{
		ans++;
		return;
	}
	if (dep-1 > total-k) return;
	search(dep+1, k);
	for (int i = 1; i <= s[dep][0]; i++)
		if (!col[s[dep][i]])
		{
			col[s[dep][i]] = true;
			search(dep+1, k-1);
			col[s[dep][i]] = false;
		}
}
int main()
{
	//freopen("in.txt", "r", stdin);
	while (cin >> n >> k && n != -1)
	{
		for (i = 1; i <= n; i++)
		{
			s[i][0] = 0;
			for (j = 1; j <= n; j++) 
				if (cin >> c && c == '#') 
					s[i][++s[i][0]] = j;
		}
		memset(col, false, sizeof(col));
		total = 0;
		int ii = 0; 
		for (i = 1; i <= n; i++)
			if (s[i][0] > 0) 
				memcpy(s[++ii], s[++total], sizeof(s[total]));
		if (total < k) 
		{
			cout << 0 << endl;
			continue;
		}
		ans = 0;		
		search(1, k);
		cout << ans << endl;
	}
}