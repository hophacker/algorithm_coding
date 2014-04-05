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
#define F(i,l,r) for (int i=l;i<r;i++)
#define FF(i,r,l) for (int i=r-1;i>=l;i--)
#define D(i,l,r) ((l<=i)&&(i<=r))
#define abs(x) (x<0?-x:x)
#define ll long long
int T, m, n;
int A[7][7];
int minV;

void search(int de){
	if (de == n){
		int maxL = INT_MIN, L;
		F(j,0,n){
			L = 0;
			F(i,0,n) L += A[i][j];
			maxL = max(maxL, L);
		}
		minV = min(minV, maxL);
		return;
	}
	int t;
	F(i,0,n){
		search(de+1);
		t = A[de][n-1];
		FF(j,n-1,0)
			A[de][j+1] = A[de][j];
		A[de][0] = t;
	}
}
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	//	ifstream cin("in.txt");
	//freopen("in.txt", "r", stdin);
	while(scanf("%d", &n), n!=-1){
		F(i,0,n)
			F(j,0,n)
				scanf("%d", &A[i][j]);
		minV = INT_MAX;
		search(0);
		printf("%d\n", minV);
	}
}