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
#define F(i,l,r) for (int i=l;i<=r;i++)
#define FF(i,r,l) for (int i=r-1;i>=l;i--)
#define D(i,l,r) ((l<=i)&&(i<=r))
#define abs(x) (x<0?-x:x)
#define ll long long
#define max(a,b) (a<b?b:a)
#define min(a,b) (a<b?a:b)
#define zuo(c) (c=='('||c=='[')
#define you(c) (c==')'||c==']')
#define pei(c1,c2) (c1=='(' && c2 ==')' || c1=='[' && c2==']')
int T, m, n;
char bra[102];
int dp[101][101], bL;
char rev(char c){
	switch (c){
		case '(': return ')';
		case ')': return '(';
		case '[': return ']';
		case ']': return '[';
	}
}
void printIt(int L, int R){
	if (L > R) return;
	if (L < R && pei(bra[L],bra[R]) && dp[L][R]==dp[L+1][R-1]){
		printf("%c", bra[L]);
		printIt(L+1,R-1);
		printf("%c", bra[R]);
	}else if (zuo(bra[L]) && dp[L][R]==dp[L+1][R]+1){
		printf("%c", bra[L]);
		printIt(L+1,R);
		printf("%c", rev(bra[L]));
	}else if (you(bra[R]) && dp[L][R]==dp[L][R-1]+1){
		printf("%c", rev(bra[R]));
		printIt(L,R-1);
		printf("%c", bra[R]);
	}else
		F(i,L,R-1) if(dp[L][R]==dp[L][i]+dp[i+1][R]){
			printIt(L,i);
			printIt(i+1,R);
			return;
		}
}
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	//	ifstream cin("in");
	//freopen("in", "r", stdin);
	scanf("%s", bra);
	bL = strlen(bra);
	clr(dp, 0);
	F(i,0,bL-1)
		dp[i][i] = 1;
	int R;
	F(k,2,bL)
		F(L,0,bL-k){
			R = L+k-1;
			dp[L][R] = INT_MAX;
			if (zuo(bra[L])) dp[L][R] = min(dp[L][R], 1+dp[L+1][R]);
			if (you(bra[R])) dp[L][R] = min(dp[L][R], 1+dp[L][R-1]);
			if (pei(bra[L], bra[R])) dp[L][R] = min(dp[L][R], dp[L+1][R-1]);

			F(i,L,R-1)
				dp[L][R] = min(dp[L][R], dp[L][i]+dp[i+1][R]);
		}
	printIt(0,bL-1);
	printf("\n");
}