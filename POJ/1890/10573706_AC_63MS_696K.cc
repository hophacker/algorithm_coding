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
int dur[8], err[8], bestErr[8], tim[8], bestTime[8];
bool use[8];
struct node{
	int ord, p;
}al[8];
bool cmp1(const node a, const node b){
	return a.ord < b.ord;
}
bool cmp2(const node a, const node b){
	return a.p < b.p;
}
bool ok(){
	FE(i,1,5) 
		if (err[i] != bestErr[i]) return err[i]<bestErr[i];
	return true;
}
void search(int dep, int k){
	if (dep == n){
		F(i,k,m)
			err[al[i].ord] += al[i].p-tim[dep-1];
		if (ok()){
			memcpy(bestErr, err, sizeof(int)*6);
			memcpy(bestTime, tim, sizeof(int)*(n+1));
		}
		return;
	}
	int k1 = k;
	while(k1<m && D(al[k1].p,tim[dep-1],tim[dep])){
		err[al[k1].ord] += min(al[k1].p-tim[dep-1], tim[dep]-al[k1].p);
		k1++;
	}
	if (ok()){
		F(i,0,n) if (!use[i]){
			tim[dep+1] = tim[dep] + dur[i];
			use[i] = true;
				search(dep+1, k1);
			use[i] = false;
		}
	}
	F(i,k,k1)
		err[al[i].ord] -= min(al[i].p-tim[dep-1], tim[dep]-al[i].p);
}
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	////ifstream cin("in");
	//freopen("in", "r", stdin);
	int dataSet=0;
	while(getI(n), n!=0){
		dataSet++;
		printf("Data set %d\n", dataSet);
		F(i,0,n) getI(dur[i]);
		getI(m);
		if (m == 0){
			printf("Order:");
			F(i,0,n) printf(" %d", dur[i]);
			printf("\n");
			printf("Error: 0\n");
			continue;
		}
		F(i,0,m) 
			getII(al[i].ord, al[i].p);
		sort(al,al+m,cmp2);
		clr(use,0);
		F(i,0,6) bestErr[i] = INT_MAX;
		clr(err,0);
		tim[0] = 0;
		F(i,0,n){
			use[i] = true;
			tim[1] = dur[i];
			search(1, 0);
			use[i] = false;
		}
		printf("Order:");
		F(i,0,n) printf(" %d", bestTime[i+1]-bestTime[i]);
		printf("\n");
		int error = 0;
		F(i,0,5)  error += bestErr[i];
		printf("Error: %d\n", error);
		continue;
	}
}




