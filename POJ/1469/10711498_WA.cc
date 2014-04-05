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
int T, m, n, k, c;
vector<int> lin[101];
int xu[101], yu[301];
bool vis[301];
bool search(int u){
	int v;
	F(i,0,lin[u].size()){
		v = lin[u][i];
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
	getI(T);
	while(T--){
		getII(m,n);
		FE(i,1,m) lin[i].clear();
		FE(i,1,m){
			getI(k);
			while(k--){
				getI(c);
				lin[i].push_back(c);
			}
		}
		clr(xu,-1);
		clr(yu,-1);
		int ans = 0;
		FE(i,1,m) if(xu[i] == -1 && search(i)) {
			clr(vis, 0);
			ans++;
		}
		if (ans == m)
			cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}