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
struct node{
	int L, D, TT;
	friend bool operator<(node a, node b){
		if (a.TT != b.TT) return a.TT > b.TT;
		if (a.L != b.L) return a.L < b.L;
		return a.D < b.D;
	}
};
vector<node> inter;
int t[60];
int check(int L, int d){
	int lineNum = 0;
	if (L >= d) return 0;
	while(L < 60 && t[L] != 0)
		L += d, lineNum++;
	if (L >= 60) return lineNum;
	else return 0;
}
int setT(int L, int d, int x){
	int num = 0;
	while(L < 60)
		t[L] += x, L += d, num++;
	return num;
}
void search(int k, int num, int n){
	if (n == 0){
		if (num < minBus) minBus = num;
		return;
	}
	if (num >= minBus-1) return;
	F(i,k,inter.size()){
		if (num + t[inter[i].L] >= minBus) return;
		if (num+n/inter[i].TT >= minBus) return;
		if (check(inter[i].L, inter[i].D)){
			setT(inter[i].L, inter[i].D, -1);
			search(i, num+1, n-inter[i].TT);
			setT(inter[i].L, inter[i].D, 1);
		}
	}
}
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	//	ifstream cin("in");
	//freopen("in.txt", "r", stdin);
	getI(n);
	clr(t, 0);
	F(i,0,n)
		getI(T), t[T]++;
	int TT;
	F(i,0,59)
		F(j,i+1,59)
			if (TT = check(i,j-i)){
				node t;
				t.L = i;
				t.D = j-i;
				t.TT = TT;
				inter.push_back(t);
			}
	sort(inter.begin(), inter.end());
//	F(i,0,inter.size()){
	//	printf("%d %d\n", inter[i].L, inter[i].D);
//	}
	minBus = 17;
	search(0, 0, n);
	printf("%d\n", minBus);
}