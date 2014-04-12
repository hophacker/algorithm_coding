#include<iostream>
#include<memory.h>
#include<fstream>
#define MAXN 40000
using namespace std;
int p[MAXN],t, u[MAXN], tp[MAXN];

int find_p(int x, int& total)
{
	total = 0;
	for(;p[x];total+=tp[x],x=p[x]); 
	return x;
}
void set_p(int x, int xp, int total)
{
	for(;p[t=x];tp[x]=total,total-=tp[x],x=p[x],p[t]=xp); 
}
int main()
{
	//freopen("poj.in", "r", stdin);
	//freopen("poj.out", "w", stdout);
	for (int i = 1; i <= 40000; i++) u[i] = 1;	
	int n, a, b, ap, bp, total;
	char act;
	cin >> n;
	while (n--)
	{
		cin >> act;
		if (act == 'M'){
			cin >> a >> b;
			ap = find_p(a, total);
			set_p(a, ap, total);
			bp = find_p(b, total);
			set_p(b, bp, total);
			p[bp] = ap;
			tp[bp] = u[ap];
			u[ap] += u[bp];
		}
		else{
			cin >> a;
			ap = find_p(a, total);
			cout << u[ap]-total-1 << endl;
		}
	}
}
