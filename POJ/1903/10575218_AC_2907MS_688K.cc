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
int ans, bestAns, minDep;
int a[25];
int tar;
int num;
void search(int dep, int k, int ansT, int tar){
	if (dep >= minDep) return;
	if (tar == 0){
		bestAns = ansT;
		minDep = dep;
		return;
	}
	if (dep == n) return;
	F(i,k,n)
		search(dep+1, i+1, ansT^(1<<i), tar^a[i]);
}
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	//	ifstream cin("in");
	char s[28];
	//freopen("in", "r", stdin);
	getI(n);
	tar = 0;
	ans = 0;
	F(k,0,n){
		num = 0;
		getS(s);
		for(int i=0;s[i]!=0;i++)
			num += 1 << (s[i]-'A');
		tar ^= num;
		ans |= 1 << k;
		a[k] = num;
	}
	if (tar == 0)  bestAns = ans;
	else{
		minDep = INT_MAX;
		search(0,0,ans,tar);
	}
	printf("%d\n", n-minDep);
	bool first = true;
	F(i,0,n)
		if ((bestAns&(1<<i)) != 0) {
			if (first) first = false;
			else printf(" ");
			printf("%d", i+1);
		}
	printf("\n");
}