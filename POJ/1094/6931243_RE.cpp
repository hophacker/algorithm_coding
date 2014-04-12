#include<iostream>
#include<string>
#include<memory.h>
using namespace std;

int n, m;
bool map1[26][26], map[26][26], used1[26], used[26];
int id1[26], id[26];
int way[26];
int solve()
{
	memcpy(map, map1, sizeof(map));
	memcpy(id, id1, sizeof(id));
	memcpy(used, used1, sizeof(used));
	int stack[26], top = -1, wayT = 0;
	for (int i = 0; i < 26; i++)
		if (used[i] && id[i] == 0)
		{
			stack[++top] = i;
			way[++wayT] = i;
		}
	bool notCer = false;
	while (top >= 0)
	{
		if (top >= 1) notCer = true;
		int t = stack[top];
		top--;
		for (int i = 0; i < n; i++)
			if (map[t][i])
			{
				id[i]--;
				if (id[i] == 0)
				{
					stack[++top] = i;
					way[++wayT] = i;
				}
			}
	}
	for (int i = 0; i < n; i++)
		if (id[i] > 0) return 0;
	if (notCer) return 2;
	if (wayT == n)return 1;
	else return 3;
}
int main()
{
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	string s;
	cin >> n >> m;
	while (n || m)
	{
		memset(map1, false, sizeof(map1));
		memset(id1, 0, sizeof(id1));
		memset(used1, 0, sizeof(used1));
		bool printed = false;
		getline(cin, s);
		int first = 0;
		for (int i = 1; i <= m; i++)
		{
			getline(cin, s);
			if (!map1[s[0]-'A'][s[2]-'A']) 
				id1[s[2]-'A']++;
			map1[s[0]-'A'][s[2]-'A'] = true;
			used1[s[0]-'A'] = used1[s[2]-'A'] = true;
			int w;
			if (!printed) w = solve();
			if (w == 0 && !printed)
			{
				printf("Inconsistency found after %d relations.\n", i);
				printed = true;
			}
			if (w == 1)
			{
				if (first == 0) first = i;
				if (i == m && !printed)
				{
					printf("Sorted sequence determined after %d relations: ", first);
					printed = true;
					for (int i = 1; i <= n; i++)
						cout << static_cast<char>(way[i]+'A');
					cout << ".\n";
				}
			}
			if (i == m && !printed)
				printf("Sorted sequence cannot be determined.\n");
		}
		cin >> n >> m;
	}
}
