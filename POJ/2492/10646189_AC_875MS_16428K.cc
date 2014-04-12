#include <cstdlib>
#include <cctype>
#include <cstring>
#include <string.h>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <queue>
#include <stack>
#include <ctime>
#include <limits.h>
#include <math.h>
using namespace std;
typedef long long ll;
#define clr(x,a) memset(x,a,sizeof(x))
#define sz(x) (int)x.size()
#define see(x) cerr<<#x<<" "<<x<<endl
#define se(x) cerr<<" "<<x 
#define pb push_back
#define mp make_pair
#define getI(n) scanf("%d", &n)
#define getII(n,m) scanf("%d %d", &n,&m)
#define putI(n) printf("%d\n", n)
#define getS(s) scanf("%s", s)
#define F(i,l,r) for (int i=l;i<r;i++)
#define FE(i,l,r) for (int i=l;i<=r;i++)
#define FF(i,r,l) for (int i=r;i>l;i--)
#define FFE(i,r,l) for (int i=r;i>=l;i--)
#define D(i,l,r) ((l<=i)&&(i<=r))
#define bit(x,i) ((x&(1<<i))!=0)
#define nbit(x,i) ((x&(1<<i))==0)
#define abs(x) (x<0?-x:x)
#define ll long long
#define max(a,b) (a<b?b:a)
#define min(a,b) (a<b?a:b)
struct node{
	int x;
	int ne;
};
int T, m, n, a, b;
int col[2001];
node lin[2000001];
int linT;
int u[2001];
bool nop;
void add(int a, int b){
	lin[linT].x = b;
	if (u[a] == -1){
		u[a] = linT;
		lin[linT].ne = -1;
	}else{
		lin[linT].ne = u[a];
		u[a] = linT;
	}
	linT++;
}
bool search(int i, int c){
	col[i] = c;
	int now = u[i];
	while(now != -1){
		if (col[lin[now].x] == 0){
			if (!search(lin[now].x, 3-c)) return false;
		}
		else if (col[lin[now].x] == c)
			return false;
		now = lin[now].ne;
	}
	return true;
}
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	//	ifstream cin("in");
	//freopen("in", "r", stdin);
	getI(T);
	FE(t,1,T){
		getII(n,m);
		linT = 0;
		clr(col, 0);
		clr(u, -1);
		F(i,0,m){
			getII(a,b);
			add(a,b);
			add(b,a);
		}
		nop = false;
		FE(i,1,n) if (col[i] == 0)
			if (!search(i, 1)){
				nop = true;
				break;
			}
		if (nop)
			printf("Scenario #%d:\nSuspicious bugs found!\n\n", t);
		else
			printf("Scenario #%d:\nNo suspicious bugs found!\n\n", t);
	}
}