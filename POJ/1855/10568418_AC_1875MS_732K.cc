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
int m, n;
int c, T;
int xD, xU;

int gcd(int a, int b){
	if (a < b) swap(a,b);
	int c;
	while(b != 0)
		c = a % b, a = b, b = c;
	return a;
}
int go(int a, int b, int c, int d){ 
	int ab = a*b/gcd(a,b);
	int cd = c*d/gcd(c,d);
	int md = ab*cd/gcd(ab,cd);
	return md;
}
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	//	ifstream cin("in");
	//freopen("in", "r", stdin);
	int co[51], coin[51];
	bool use[51];
	int num;
	int md;
	while(getII(n,m), n!=0){
		F(i,0,n) getI(coin[i]);
		F(i,0,m) {
			getI(T);
			xU = xD = INT_MAX;
			F(i,0,n-3){
				md = go(coin[i], coin[i+1], coin[i+2], coin[i+3]);
				xU = min(xU, T-T/md*md);
				xD = min(xD, ((T/md+1)*md-T)%md);
			}
			clr(use, 1);
			F(i,0,n)
				if (T-T/coin[i]*coin[i] >= xU) use[i] = false;
			num = 0;
			F(i,0,n) if(use[i]) co[num++] = coin[i];
			F(i1,0, num-3)
				F(i2,i1+1, num-2)
					F(i3,i2+1, num-1)
						F(i4,i3+1, num){
							md = go(co[i1], co[i2], co[i3], co[i4]);
							xU = min(xU, T-T/md*md);
							xD = min(xD, ((T/md+1)*md-T)%md);
						}


			clr(use, 1);
			F(i,0,n)
				if (((T/coin[i]+1)*coin[i]-T)%coin[i] >= xD) use[i] = false;
			num = 0;
			F(i,0,n) if(use[i]) co[num++] = coin[i];
			F(i1,0, num-3)
				F(i2,i1+1, num-2)
					F(i3,i2+1, num-1)
						F(i4,i3+1, num){
							md = go(co[i1], co[i2], co[i3], co[i4]);
							xD = min(xD, ((T/md+1)*md-T)%md);
						}
			cout << T-xU << ' ' << T+xD << endl;
		}
	}
}






