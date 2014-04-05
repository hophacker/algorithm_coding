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
struct node{
	int a, b, s;
};
struct nodeP{
	int p;
	int col;
	nodeP* next;
};
int M, N, A, B, T;
nodeP* map[100];
void add(int a, int b, int col){
	nodeP* p = new nodeP();
	p->p = b;
	p->col = col;
	p->next = NULL;
	p->next = map[a];
	map[a] = p;
}
int col[100];
node q[10001];
bool pan[100][100];
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	//	ifstream cin("in");
	//freopen("in", "r", stdin);
	scanf("%d %d %d %d", &N, &A, &B, &T);
	F(i,0,N)
		getI(col[i]);
	getI(M);
	int a, b, c;
	F(i,0,M){
		scanf("%d %d %d", &a, &b, &c);
		a--, b--;
		add(a, b, c);
	}
	int h, t;
	h = t = 0;
	q[0].a = A;
	q[0].b = B;
	q[0].s = 0;
	clr(pan, 0);
	nodeP* te;
	pan[A][B] = pan[B][A] = true;
	while(h <= t){
		a = q[h].a;
		b = q[h].b;

		c = col[b];
		if (a == T || b == T) break;
		te = map[a];
		while(te != NULL){
			if (te->col==c && te->p != b && !pan[te->p][b]){
				pan[te->p][b] = pan[b][te->p] = true;
				t++;
				q[t].a = te->p;
				q[t].b = b;
				q[t].s = q[h].s + 1;
			}
			te = te->next;
		}

		swap(a, b);
		c = col[b];
		te = map[a];
		while(te != NULL){
			if (te->col==c && te->p != b && !pan[te->p][b]){
				pan[te->p][b] = pan[b][te->p] = true;
				t++;
				q[t].a = te->p;
				q[t].b = b;
				q[t].s = q[h].s + 1;
			}
			te = te->next;
		}
		h++;
	}

	if (h <= t) printf("YES\n%d\n", q[h].s);
	else printf("NO\n");

}
















