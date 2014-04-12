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
#define abs(x) (x<0?-x:x)
#define ll long long
#define max(a,b) (a<b?b:a)
#define min(a,b) (a<b?a:b)
int T, m, n,k, a, b;
vector<int>  li[100];
int xu[100], yu[100];
bool vis[100];
bool search(int u){
	int v;
	F(i,0,li[u].size()){
		v = li[u][i];
		if (!vis[v]){
			vis[v] = true;
			if (yu[v]==-1 || search(yu[v])){
				xu[u] = v;
				yu[v] = u;
				return true;
			}
		}
	}
	return false;
}
int main(){
//if you do not want to use file input stream, put "//" before ifstream 
// ifstream cin("in");
	//freopen("in", "r", stdin);
	int c;
	while(getI(n), n!=0){
		int ans = 0;
		getII(m,k);
		F(i,0,100) li[i].clear();
		F(i,0,k){
			scanf("%d %d %d", &c, &a, &b);
			li[a].push_back(b);
		}
		clr(xu, -1);
		clr(yu, -1);
		F(i,1,n) if(xu[i] == -1 && li[i].size()!=0){
			clr(vis, false);
			if (search(i)) ans ++;
		}
		cout << ans << endl;
	}
}