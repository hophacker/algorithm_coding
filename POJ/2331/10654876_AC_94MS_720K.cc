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
int xA, x2, yA, y2, n;
int L[4], C[4], M[4];
int maxLen[4];
int minS=INT_MAX;
void search(int dx, int dy, int dep, int sticks){
	int dx1, dy1;
	if (dx == 0 && dy == 0){
		if (sticks < minS) minS = sticks;
		return;
	}
	if (dep == n-1){
		if (dx % L[dep] == 0 && dy % L[dep] == 0){
			int t = (abs(dx)+abs(dy)) / L[dep];
			if (t <= C[dep] && sticks+t < minS) minS = sticks+t;
		}
		return;
	}
	if (M[dep] < abs(dx)+abs(dy) || (abs(dx)+abs(dy))/maxLen[dep]+sticks >= minS) return;
	FE(i,0,C[dep])
		FE(j,0,C[dep]-i){
			dx1 = L[dep] * i, dy1 = L[dep] * j;
			search(dx+dx1,dy+dy1,dep+1,sticks+i+j);
			search(dx+dx1,dy-dy1,dep+1,sticks+i+j);
			search(dx-dx1,dy+dy1,dep+1,sticks+i+j);
			search(dx-dx1,dy-dy1,dep+1,sticks+i+j);
		}

}
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	//	ifstream cin("in");
//	freopen("in", "r", stdin);
	scanf("%d %d %d %d %d", &xA, &yA, &x2, &y2, &n);
	F(i,0,n) getI(L[i]);
	F(i,0,n) getI(C[i]);
	M[n-1] = L[n-1]*C[n-1];
	FFE(i,n-2,0) M[i] = L[i]*C[i]+M[i+1];
	maxLen[n-1] = L[n-1];
	FFE(i,n-2,0) maxLen[i] = max(maxLen[i+1], L[i]);
	search(x2-xA,y2-yA,0,0);
	if (minS == INT_MAX) cout << -1 << endl;
	else cout << minS << endl;
}