#include<iostream>
#include<fstream>
using namespace std;

int num[9][9];
bool row[9][10], col[9][10], block[9][10];
inline void fillIt(int i, int j, int t, bool b)
{
	row[i][t] = b;
	col[j][t] = b;
	block[i/3*3 +  j/3][t] = b;
}
bool search(int dep)
{
	if (dep > 80) return true;
	int x = dep / 9, y = dep % 9;
	if (!num[x][y])
	{
		for (int t = 1; t <= 9; t++)
			if (!row[x][t] && !col[y][t] && !block[x/3*3+y/3][t])
			{
				fillIt(x, y, t, true);
				num[x][y] = t;
				if (search(dep + 1)) return true;
				num[x][y] = 0;
				fillIt(x, y, t, false);
			}
		return false;
	}
	else if (search(dep+1)) return true;
	return false;
}
void printIt()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			cout << num[i][j];
		cout << endl;
	}
}
int main()
{
	//freopen("in.txt", "r", stdin);
	int tests; cin >> tests;
	char c;
	while (tests--)
	{
		memset(row, 0, sizeof(row));
		memset(col, 0, sizeof(col));
		memset(block, 0, sizeof(block));
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
			{
				cin >> c, num[i][j] = c - '0';
				if (num[i][j] > 0)
					fillIt(i, j, num[i][j], true);
			}
		if (search(0)) printIt();
	}
}
