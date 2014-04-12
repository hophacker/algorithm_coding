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
#define sz(x) (uint)x.size()
#define see(x) cerr<<#x<<" "<<x<<endl
#define se(x) cerr<<" "<<x 
#define pb push_back
#define mp make_pair
#define getI(n) scanf("%d", &n)
#define getII(n,m) scanf("%d %d", &n,&m)
#define putI(n) pruintf("%d\n", n)
#define getS(s) scanf("%s", s)
#define F(i,l,r) for (uint i=l;i<r;i++)
#define FE(i,l,r) for (uint i=l;i<=r;i++)
#define FF(i,r,l) for (uint i=r;i>l;i--)
#define FFE(i,r,l) for (uint i=r;i>=l;i--)
#define D(i,l,r) ((l<=i)&&(i<=r))
#define bit(x,i) ((x&(1<<i))!=0)
#define abs(x) (x<0?-x:x)
#define ll long long
#define max(a,b) (a<b?b:a)
#define min(a,b) (a<b?a:b)
#define maxN 20000
#define uint unsigned int
struct node{
	uint x, y, v;
	void init(){
		scanf("%d%d%d", &x, &y, &v);
	}
	friend bool operator<(const node a, const node b){
		return a.x < b.x;
	}
}star[maxN+1];
uint n, W, H;
uint y[2*maxN+1];
uint sum[4*maxN+1];
uint maxSum[4*maxN+1];
void insert(uint ii, uint L, uint R, uint x, uint c){
	if (L<R){
		uint mid = (L+R)>>1;
		if (x<=mid) insert(ii*2,L,mid,x,c);
		else insert(ii*2+1,mid+1,R,x,c);
	}
	sum[ii]+=c; 
	if (L==R) maxSum[ii] = sum[ii];
	else{
		maxSum[ii] = maxSum[ii*2];
		maxSum[ii] = max(maxSum[ii], maxSum[2*ii+1]+sum[ii]-sum[2*ii+1]);
	}
}
bool cmp(const uint a, const uint b){
	return a < b;
}
int main(){
//if you do not want to use file input stream, put "//" before ifstream
// ifstream cin("in");
//	freopen("in", "r", stdin);
	uint totY;
	while(scanf("%d%d%d", &n, &W, &H) != -1){
		F(i,0,n){
			star[i].init();
			star[n+i].x = star[i].x;
			star[n+i].y = star[i].y + H;//need repair
			star[n+i].v = -star[i].v;
			y[i] = star[i].y, y[n+i] = star[n+i].y;
		}
		sort(y, y+n+n);
		totY = unique(y, y+n+n) - y;
		sort(star, star+n+n);
		clr(sum, 0);
		clr(maxSum, 0);
		uint ans = 0, L=0, R=0, x;
		n = n+n;
		while(R<n){
			x = star[R].x;
			while(L<n && x-star[L].x>=W){
				insert(1,0,totY-1,lower_bound(y,y+totY,star[L].y)-y,-star[L].v);
				L++;
			}
			while(R<n && x == star[R].x){
				insert(1,0,totY-1,lower_bound(y,y+totY,star[R].y)-y,star[R].v);
				R++;
			}
			ans = max(ans, maxSum[1]);
		}
		cout << ans << endl;
	}
}