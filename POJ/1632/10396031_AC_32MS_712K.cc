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
#include <map>
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
#define F(i,l,r) for (int i=l;i<=r;i++)
#define FD(i,r,l) for (int i=r-1;i>=l;i--)
#define D(i,l,r) ((l<=i)&&(i<=r))
#define abs(x) (x<0?-x:x)
#define ll long long
#define max(a,b) (a<b?b:a)
#define min(a,b) (a<b?a:b)
int sN, dN;
int T, m, n, sx, dx;
bool SD[38][38];
map<int,int> sToI;
map<int,int> dToI;
int maxK;
int getMapI(int x, map<int,int> &M, int &N){
	map<int,int>::iterator it = M.find(x);
	if (M.find(x) != M.end()) return it->second;
	else{
		N++;
		M.insert(pair<int, int>(x,N));
		return N;
	}
}
void search(int sI, bool *mat, int left, int inUse){
	if (sI == sN+1){
		maxK = max(maxK,min(left,inUse));
		return;
	}
	int q[38];
	int qN = 0;
	F(dI,1,dN)
		if (!SD[sI][dI] && mat[dI]){
			q[qN++] = dI;
			mat[dI] = false;
		}
	if (left > maxK)
		search(sI+1, mat, left-qN, inUse+1);
	F(i,0,qN-1)
		mat[q[i]] = true;
	search(sI+1, mat, left, inUse);
}
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	//freopen("in", "r", stdin);
	getI(T);
	bool mat[38];
	while(T--){
		clr(SD, 0);
		clr(mat, true);
		maxK = 0;
		getI(n);
		sToI.clear();
		dToI.clear();
		sN = dN = 0;
		F(i,1,n){
			scanf("%d %d", &sx, &dx);
			int sI = getMapI(sx, sToI, sN)	;
			int dI = getMapI(dx, dToI, dN)	;
			SD[sI][dI] = true;
		}
		search(1, mat, dN, 0);
		printf("%d\n", maxK);
	}
}