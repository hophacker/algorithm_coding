#include<iostream>
#include<fstream>
#include<memory.h>
using namespace std;

int main()
{
	//freopen("in.txt", "r", stdin);
	bool cash[110001];
	int sum, k;
	int n, d, t, jj;
	while (cin >> sum >> k)
	{
		t = 0;
		memset(cash, 0, sizeof(cash));
		cash[0] = true;
		for (int i = 1; i <= k; i++)
		{
			scanf("%d %d", &n, &d);
			for (int j = t; j >= 0; j--)
				if (cash[j] && n > 0)
				{
					jj = j + d;
					for (int p = 1; p <= n-1; p++)
						if (jj > sum || cash[jj])
							break;
						else cash[jj] = true, jj += d;
					if (jj > sum)
					{
						if (jj - d > t) t = jj - d; 
					}
					else 
						if (jj > t) t = jj;
				}
		}
		cout << t << endl;
	}
}
