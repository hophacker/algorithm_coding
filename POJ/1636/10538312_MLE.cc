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
struct node{
	int v;
	node* ne;
};
int T, m, n;
void add(node* u[], int a, int b){
	node * t = new node();
	t->ne = NULL;
	t->v = b;
	if (u[a] == NULL)
		u[a] = t;
	else {
		t->ne = u[a];
		u[a] = t;
	}
}
node* uA[200];
node* uB[200];
bool vA[200], vB[200];
int pA[200], pB[200];
int pN, aN, bN;
void searchB(int x);
void searchA(int x);
int main(){
	//if you do not want to use file input stream, put ";//" before ifstream
	//	ifstream cin("in");
	//freopen("in", "r", stdin);
	getI(T);
	int a, b;
	bool dp[200][200][200];
	while(T--){
		clr(uA, 0);
		clr(uB, 0);
		clr(vA, 0);
		clr(vB, 0);
		getII(n,m);
		F(i,0,m){
			getII(a,b);
			add(uA,a,b);
			add(uB,b,a);
		}
		pN = 0;
		FE(i,1,n) if(!vA[i] && uA[i] != NULL){
			aN = 0;
			bN = 0;
			searchA(i);
			pN++;
			pA[pN] = aN;
			pB[pN] = bN;
		}
		if (pN == 0)
			printf("%d\n", n/2);
		else{
			clr(dp, 0);
			dp[1][pA[1]][pB[1]] = dp[1][0][0] = true;
			FE(k,2,pN){
				dp[k][0][0] = true;

				FE(i,1,n/2)
					FE(j,1,n/2){
						if (i >= pA[k] && j >= pB[k])
							dp[k][i][j] = dp[k-1][i][j] || dp[k-1][i-pA[k]][j-pB[k]];
						else 
							dp[k][i][j] = dp[k-1][i][j];
					}
			}
			FFE(i,n/2,0)
				if (dp[pN][i][i]){
					printf("%d\n", i);
					break;
				}
		}
	}
}
void searchA(int x){
	aN++;
	vA[x] = true;
	node* now = uA[x];
	while(now != NULL){
		if (!vB[now->v]) searchB(now->v);
		now = now->ne;
	}
}
void searchB(int x){
	bN++;
	vB[x] = true;
	node* now = uB[x];
	while(now != NULL){
		if (!vA[now->v]) searchA(now->v);
		now = now->ne;
	}
}