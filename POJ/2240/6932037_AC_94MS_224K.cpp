#include<iostream>
#include<map>
#include<memory.h>
#include<string>
using namespace std;

int n, m, i, j;
double rate[31][31];
string name[31];
int main()
{
//	freopen("in.txt", "r", stdin);
	for (int cases = 1;; cases++)
	{
		map<string, int> stoi;
		cin >> n;
		if (n == 0) break;
		for (i = 1; i <= n; i++) 
		{
			cin >> name[i];
			stoi[name[i]] = i;
		}
		cin >> m;
		string s1, s2;
		double r;
		int i1, i2;
		memset(rate, 0, sizeof(rate));
		for (i = 1; i <= m; i++)
		{
			cin >> s1 >> r >> s2;
			i1 = stoi.find(s1)->second;
			i2 = stoi.find(s2)->second;
			rate[i1][i2] = r;
		}
		double maxR[31];
		for (i = 1; i <= n; i++)
			maxR[i] = rate[1][i];
		for (int time = 1; time <= n; time++)
		{
			for (i = 1; i <= n; i++)
				for (j = 1; j <= n; j++)
					if (maxR[j]*rate[j][i] > maxR[i])
						maxR[i] = maxR[j]*rate[j][i];
			if (maxR[1] > 1) break;
		}
		printf("Case %d: ", cases);
		if (maxR[1] > 1) cout << "Yes\n";
		else cout << "No\n";
	}
}
