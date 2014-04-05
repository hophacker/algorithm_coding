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
#define getII(n,m) scanf("%d%d", &n,&m)
#define getIII(n,m,k) scanf("%d%d%d", &n,&m,&k)
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
#define ull unsigned long long
#define max(a,b) (a<b?b:a)
#define min(a,b) (a<b?a:b)
#define modN 1000007
#define stepN 911
int fx[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
struct node{
	ull fa;
	char c;
	int step;
};
int T, m, n;
char b[8][8];
node hashT[modN];
bool fb[8][8];
node q[modN];
int h, t;
void hash_init(){
	clr(hashT, -1);
}
bool hash_put(node t){
	int p = ((t.fa*t.c) % modN + modN) % modN;
	while(hashT[p].c != -1){
		if (hashT[p].fa == t.fa && hashT[p].c == t.c)
			return false;
		else p = (p + stepN) % modN;
	}
	hashT[p] = t;
	return true;
}
void floodIt(char b[][8], int x, int y){
	int x1, y1;
	F(d,0,4){
		x1 = x + fx[d][0];
		y1 = y + fx[d][1];
		if (D(x1,0,n-1) && D(y1,0,n-1) && !fb[x1][y1]&& b[x1][y1] == b[x][y]){
			fb[x1][y1] = true;
			floodIt(b, x1, y1);
		}
	}
}
ull getFA(bool fb[][8]){
	ull ans = 0;
	F(i,0,n) F(j,0,n) if (fb[i][j]) 
		ans += 1 <<(i*n+j);
	return ans;
}
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	// ifstream cin("in");
	//freopen("in", "r", stdin);
	node pre, now;
	ull des;
	char bt[8][8];
	while(getI(n), n != 0){
		des = 0;
		F(i,0,n) F(j,0,n) getI(b[i][j]), des += 1<<(i*n+j);
		clr(fb, 0);
		fb[0][0] = true;
		floodIt(b, 0, 0);
		pre.fa = getFA(fb);
		pre.c = b[0][0];
		pre.step = 0;
		hash_init();
		if (hash_put(pre))
			q[0] = pre;
		h = 0;
	 	t = 1;
		while(h < t){
			pre = q[h++];
			if (pre.fa == des)
				break;
			memcpy(bt, b, sizeof(b));
			F(col,0,6) if (col != pre.c){
				F(i,0,n)
					F(j,0,n) if ((pre.fa & (1<<(i*n+j))) != 0)
						bt[i][j] = col;
				clr(fb, 0); fb[0][0] = true; floodIt(bt, 0, 0);
				now.fa = getFA(fb);
				now.c = col;
				now.step = pre.step+1;
				if (hash_put(now))
					q[t++] = now;
			}
		}
		cout << pre.step << endl;
	}
}