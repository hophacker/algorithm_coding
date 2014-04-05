#include<iostream>
#include<fstream>
#define MAXN 10010
using namespace std;
int n;
struct node1{
	int x;
	node1* next;
};
node1* mat[MAXN];
node1* mat1[MAXN];
struct node{
	int p, num;
}herd[MAXN];
void search(node1* mat[], int *id, int now, int &time, int *endt)
{
	id[now] = 1;
	node1* te = mat[now];
	while (te != NULL)
	{
		if (!id[te->x])
			search(mat,id,te->x,time,endt);
		te = te->next;
	}
	endt[now] = ++time;
}
void search1(node1* mat[], int *id, int now, int cnt)
{
	id[now] = cnt;
	
	node1* te = mat[now];
	while (te != NULL)
	{
		if (!id[te->x])
			search1(mat, id, te->x, cnt);
		te = te->next;
	}
}
int find_components(int n, node1* mat[], int *id)
{
	int endt[MAXN], time=0;
	for (int i=0; i<n; id[i++]=0);
	for (int i=0; i<n; i++)
		if (!id[i]) search(mat,id,i,time,endt);
	int maxi, maxt, cnt = 0;
	maxi = -1; maxt = 0;

	for (int i=0; i<n; i++) if (endt[i] > maxt) maxi = i, maxt = endt[i];
	for (int i=0; i<n; id[i++]=0);
	search1(mat, id, maxi, 1);
	for (int i=0; i<n; i++) if (!id[i]) return 0;

	int superi = maxi;
	for (int i=0; i<n; id[i++]=0);
	for (;;){
		maxi = -1; maxt = 0;
		for (int i=0; i<n; i++) if (!id[i] && endt[i] > maxt) maxi = i, maxt = endt[i];
		if (maxi == -1) break;
		search1(mat1, id, maxi, ++cnt);
	}
	cnt = 0;
	for (int i = 0; i < n; i++)if (id[i] == id[superi]) cnt++;
	return cnt;
}
void insert(node1* mat[],int a, int b)
{
	node1* now = new(node1);
	now->next = mat[a];
	now->x = b;
	mat[a] = now;
}
int main()
{
//	freopen("test.in", "r", stdin);
//	freopen("test.out", "w", stdout);
	int id[MAXN], m;
	memset(mat, 0, sizeof(mat));
	cin >> n >> m;
	for (int i = 0; i < n; i++) mat[i] = NULL;
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		insert(mat, b-1, a-1);
		insert(mat1, a-1, b-1);
	}
	cout << find_components(n, mat, id) << endl;
}
