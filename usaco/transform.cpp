/*
ID: fengjie3
PROG: transform
LANG: C++
*/

#include<iostream>
#include<memory.h>
using namespace std;
int size;
void rotate(char map[11][11])
{
	char mapc[11][11];
	for (int i = 1; i <= size; i++)
		for (int j = 1; j <= size; j++)
			mapc[i][j] = map[i][j];
	for (int i = 1; i <= size; i++)
		for (int j = 1; j <= size; j++)
			map[i][j] = mapc[size+1-j][i];		
}
void ref(char map[11][11])
{
	char mapc[11][11];
	for (int i = 1; i <= size; i++)
		for (int j = 1; j <= size; j++)
			mapc[i][j] = map[i][j];
	for (int i = 1; i <= size; i++)
		for (int j = 1; j <= size; j++)
			map[i][j] = mapc[i][size+1-j];
}
bool same(char map1[11][11], char map2[11][11])
{
	for (int i = 1; i <= size; i++)
		for (int j = 1; j <= size; j++)
			if (map1[i][j] != map2[i][j]) return false;
	return true;
}
void print(char map[11][11])
{
	for (int i = 1; i <= size; i++)
	{
		for (int j = 1; j <= size; j++)
			cout << map[i][j];
		cout << endl;
	}
}
int main()
{
	freopen("transform.in", "r", stdin);
	freopen("transform.out", "w", stdout);
	char map1[11][11],map2[11][11];
	cin >> size;
	for (int i = 1; i <= size; i++)
		for (int j = 1; j <= size; j++)
			cin >> map1[i][j];
	for (int i = 1; i <= size; i++)
		for (int j = 1; j <= size; j++)
			cin >> map2[i][j];
	int result = 0;
	while (true)
	{
		rotate(map1);
		if (same(map1, map2))
		{
			result = 1;
			break;
		}
		rotate(map1);
		if (same(map1, map2))
		{
			result = 2;
			break;
		}
		rotate(map1);
		if (same(map1, map2))
		{
			result = 3;
			break;
		}
		rotate(map1);
		
		ref(map1);
		if (same(map1, map2))
		{
			result = 4;
			break;
		}
		for (int i = 1; i <= 3; i++)
		{
			rotate(map1);
			if (same(map1, map2))
			{
				result = 5;
				break;
			}
		}
		if (result == 5) break;
		
		rotate(map1);ref(map1);
		if (same(map1, map2))
		{
			result = 6;
		}
		else
		{
			result = 7;
		}
		break;
	}
	cout << result << endl;
}
