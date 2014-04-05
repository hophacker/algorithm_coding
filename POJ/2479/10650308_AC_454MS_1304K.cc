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
int T, m, n;
int num[50001];
int L[50001], R[50001];
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	//	ifstream cin("in");
	//freopen("in", "r", stdin);
	getI(T);
	while(T--){
		getI(n);
		FE(i,1,n) getI(num[i]);
		L[1] = num[1];
		FE(i,2,n)
			L[i] = max(L[i-1]+num[i], num[i]);
		R[n] = num[n];
		FFE(i,n-1,1)
			R[i] = max(R[i+1]+num[i], num[i]);
		FE(i,2,n)
			L[i] = max(L[i], L[i-1]);
		FFE(i,n-1,1)
			R[i] = max(R[i], R[i+1]);
		int maxI = INT_MIN;
		FE(i,1,n-1)
			maxI = max(maxI, L[i]+R[i+1]);
		cout << maxI << endl;	
	}
}