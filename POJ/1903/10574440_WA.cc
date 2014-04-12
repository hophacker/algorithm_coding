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

int T, n;
int res[28], maxRes[28];
int maxN;
int a[25];
void search(int dep, int fr, int x){
	if (x == 0){
		if (dep > maxN){
			maxN = dep;
			memcpy(maxRes, res, sizeof(int)*maxN);
		}
		return;
	}
	if (fr == n) return;
	F(i,fr,n){
		res[dep] = i;
		search(dep+1, i+1, x^a[i]);
	}
}
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	//	ifstream cin("in");
	char s[28];
	//freopen("in", "r", stdin);
	getI(n);
	int num;
	F(k,0,n){
		num = 0;
		getS(s);
		for(int i=0;s[i]!=0;i++)
			num += 1 << (s[i]-'A');
		a[k] = num;
	}
	maxN = 0;
	F(i,0,n)
		search(1,i+1,a[i]);
	printf("%d\n", maxN);
	sort(maxRes,maxRes+maxN);
	F(i,0,maxN-1) printf("%d ", maxRes[i]+1);
	if (maxN > 0)printf("%d\n", maxRes[maxN-1]+1);
}