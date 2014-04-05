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
#define putI(n) printf("%d\n", n)
#define getS(s) scanf("%s", s)
#define F(i,l,r) for (int i=l;i<r;i++)
#define FD(i,r,l) for (int i=r;i>=l;i--)
#define D(i,l,r) ((l<=i)&&(i<=r))
#define bit(a,x) ((a&(1<<x))!=0)
#define abs(x) (x<0?-x:x)
#define ll long long
#define max(a,b) (a<b?b:a)
#define min(a,b) (a<b?a:b)
int T, m, n, minBus;
int t[60], next[60];
int check(int L, int R){
	int d = R - L;
	int m = INT_MAX;
	if (L >= d) return 0;
	while(R < 60 && t[R] != 0)
		m = min(t[R],m), R += d;
	if (R >= 60) return m;
	else return 0;
}
void setT(int L, int d, int x){
	while(L < 60)
		t[L] += x, L += d;
}
void search(int L, int num){
	int R = L;
	while(next[R] != -1){
		R = next[R];
		if (t[R] != 0 && check(L,R)>0){
			setT(L,R-L, -1);
			int tL = L;
			while(tL != -1 && t[tL] == 0) tL = next[tL];
			if (tL == -1){
				if (num < minBus) minBus = num;
			}else{
				if (num+1 < minBus && num+1 <= 17)
					search(tL, num+1);
			}
			setT(L,R-L, 1);
		}
	}
}
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	//	ifstream cin("in");
	//freopen("in", "r", stdin);
	getI(n);
	clr(t, 0);
	clr(next, -1);
	F(i,0,n)
		getI(T), t[T]++;
	int last = -1;
	FD(i,59,0) if (t[i] != 0){
		if (last == -1)
			last = i;
		else{
			next[i] = last;
			last = i;
		}
	}
	minBus = INT_MAX;
	search(last, 1);
	printf("%d\n", minBus);
}