#include<iostream>
#include<fstream>
#include<string.h>
#include<algorithm>
using namespace std;
char txt[310];
char word[601][30];
int w, L, t, maxLen = 0;

int main()
{
	freopen("in.txt", "r", stdin);
	/*cin >> w >> L;
	getchar();
	cin.getline(txt, 100, '\n');
	for (int i = 1; i <= w; i++)
		cin.getline(word[i], 100, '\n'); */
	scanf("%d %d\n",&w,&L);
    gets(txt);
    for (int i = 1; i <= w; ++i)gets(word[i]);
	int del[301];
	del[L] = 0;
	for (int i = L-1; i >= 0; i--)
	{
		del[i] = del[i+1] + 1;
		for (int j = 1; j <= w; j++)
		{
			int k = 0, p = i;
			for (; word[j][k] && p < L; p++)
				if (word[j][k] == txt[p]) k++;
			if (!word[j][k]) del[i] = min(del[i], p-i-k + del[p]);
		}
	}
	cout << del[0] << endl;
}
