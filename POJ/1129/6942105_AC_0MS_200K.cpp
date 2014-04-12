#include<iostream>
#include<fstream>
using namespace std;

int n, i, j, t;
bool used[26][26];
bool cc[26];
char s[100];
int main()
{
	//freopen("in.txt", "r", stdin);
	while (cin >> n, n)
	{
		memset(used, 0, sizeof(used));
		memset(cc, 0, sizeof(cc));
		cin.getline(s, 100, '\n');
		for (i = 0; i < n; i++)
		{
			cin.getline(s, 100, '\n');
			for (j = 0; j < n; j++)
				if (!used[i][j]) { t = j; cc[j] = true; break;}
			for (j = 2; s[j]; j++)
			{
				used[s[j]-'A'][t] = true;
			}
		}
		t = 0; 
		for (i = 0; i < n; i++) t += cc[i];
		cc[2] = 0;
		if (t == 1)
			printf("%d channel needed.\n", t);
		else 
			printf("%d channels needed.\n", t);
	}
}
