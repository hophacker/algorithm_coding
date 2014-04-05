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
#define copy(des,sou) memcpy(des,sou,sizeof(sou))
#define se(x) cerr<<" "<<x 
#define pb push_back
#define mp make_pair
#define getI(n) scanf("%d", &n)
#define getII(n,m) scanf("%d%d", &n,&m)
#define getIII(n,m,k) scanf("%d%d%d", &n,&m,&k)
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
#define ull unsigned long long
#define max(a,b) (a<b?b:a)
#define min(a,b) (a<b?a:b)
#define modN 10007
#define update(x) (ans = (ans+x)%modN)
int fx[8][2] = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
int T, m, n;
int invM[modN+1];
char b[1010], g[1010];
int c[1010][4];
int ff[1010][1010];
int k;
void calc(int a, int &x, int b, int &y){
	int x1, y1;
	if (a==1){
		x = 1;
		y = 0;
		return;
	}
	calc(b,x1,a%b,y1);
	x = y1;
	y = x1-a/b*x;
}
int f(int m, int k){
	if (m*3 < k) return 0;
	if (k < 0) return 0;
	if (m==0){
		if (k == 0) return 1;
		else return 0;
	}
	if (m==1){
		if (k==3) return c[n][3];
		else return 0;
	}
	if (ff[m][k] == -1){
		int ans = 0;
		update(f(m-1,k+3)*c[k+3][3]%modN);
		update(f(m-1,k+1)*c[k+1][2]*c[n-k-1][1]%modN);
		update(f(m-1,k-1)*c[k-1][1]*c[n-k+1][2]%modN);
		update(f(m-1,k-3)*c[n-k+3][3]%modN);
		update(-f(m-2,k)*(c[n][3]-m+2)%modN);
		ff[m][k] = (ans*invM[m]%modN + modN) % modN;
	}
	return ff[m][k];
}

int main(){
	//freopen("in", "r", stdin);
	F(i,0,1010)
		F(j,0,4){
			if (i<j) c[i][j] = 0;
			else if (i==j || j == 0) c[i][j] = 1;
			else c[i][j] = (c[i-1][j]+c[i-1][j-1]) % modN;
		}
	int y;
	F(i,1,10007){
		calc(10007,y,i,invM[i]);
		invM[i] = (invM[i]%modN+modN) % modN;
	}
	while(getII(n,m), n||m){
		clr(ff,-1);
		ff[0][0] = 1;
		getS(b);
		getS(g);
		if (n <= 2){
			cout << 0 << endl; 
			continue;
		}
		k = 0;
		F(i,0,n) k += (b[i] != g[i]);
		int ans = f(m,k);
		F(i,0,k) ans = ans * (i+1) % modN * invM[n-i] % modN;
		cout << ans << endl;
	}
}
