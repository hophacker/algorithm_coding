#include<iostream>
#include<fstream>
#define MAXN 10010
using namespace std;
int n;
void search(bool mat[][MAXN], int *id, int now, int &time, int *endt)
{
	id[now] = 1;
	for (int i=0; i<n; i++)
		if (!id[i] && mat[now][i]) 
			search(mat,id,i,time,endt);
	endt[now] = ++time;
}
void search1(bool mat[][MAXN], int *id, int now, int cnt)
{
	id[now] = cnt;
	for (int i=0; i<n; i++)
		if (!id[i] && mat[now][i]) search1(mat, id, i, cnt);
}
int find_components(int n, bool mat[][MAXN], int *id)
{
	int endt[MAXN], time=0;
	for (int i=0; i<n; id[i++]=0);
	for (int i=0; i<n; i++)
		if (!id[i]) search(mat,id,i,time,endt);
	for (int i=0; i<n; i++)
		for (int j=0; j<i; j++) swap(mat[i][j],mat[j][i]);
	for (int i=0; i<n; id[i++]=0);
	int maxi, maxt, cnt = 0;
	for (;;){
		maxi = -1; maxt = 0;
		for (int i=0; i<n; i++) if (!id[i] && endt[i] > maxt) maxi = i, maxt = endt[i];
		if (maxi == -1) break;
		search1(mat, id, maxi, ++cnt);
	}
	return cnt;
}
int main()
{
	//freopen("test.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	bool mat[MAXN][MAXN];
	int id[MAXN], m;
	memset(mat, 0, sizeof(mat));
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		mat[a][b] = 1;
	}
	cout << find_components(n, mat, id) << endl;
	for (int i = 0; i < n; i++)
	{
		cout << id[i] << endl;
	}
}
