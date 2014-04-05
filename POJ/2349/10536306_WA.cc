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
#define getDis(a,b) sqrt((double)(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y))

struct node{
	int x, y;
}p[500];
struct node1{
	int p1, p2;
	double dis;
	friend bool operator<(node1 a, node1 b){
		return a.dis > b.dis;
	}
};
int fa[501];
int T, m, n;
int father(int x){
	if (fa[x] = x) return x;
	else
		return fa[x] = father(fa[x]);
}
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	//	ifstream cin("in");
	//freopen("in", "r", stdin);
	getI(T);
	priority_queue<node1> q;
	while(T--){
		q.empty();
		getII(m,n);
		F(i,0,n){
			getII(p[i].x, p[i].y);
			fa[i] = i;
		}
		F(i,0,n)
			F(j,i+1,n){
				node1 s = {
					p1:i,p2:j,dis:getDis(p[i],p[j])
				};
				q.push(s);
			}
		if (n<=m) {
			printf("0.00\n");
			continue;
		}		
		int t = 0;
		node1 s;
		F(i,0,n-m){
			while(true){
				s = q.top(); q.pop();
				if (fa[s.p1] != fa[s.p2]) break;
			}
			fa[s.p1] = s.p2;
		}
		printf("%.2f\n", s.dis);
		
	}
}






