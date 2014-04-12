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
#define D(i,l,r) ((l<i)&&(i<r))
#define bit(x,i) ((x&(1<<i))!=0)
#define abs(x) (x<0?-x:x)
#define ll long long
#define max(a,b) (a<b?b:a)
#define min(a,b) (a<b?a:b)
struct node{
	int v;
	node* ne;
};
node* adj[15];
int T, m;
int ind[15];
bool use[15];
int minSteps;
struct nodeR{
	int x1, y1, x2, y2, c;
}rec[15];
void search(int c, int steps, int ind_back[], bool use_back[]){
	int ind[15];
	bool use[15];
	memcpy(ind, ind_back, sizeof(ind));
	memcpy(use, use_back, sizeof(use));
	int q[16];
	int h,t;
	h = 0;
	t = 0;
	F(i,0,m) if (!use[i] && ind[i] == 0 && rec[i].c == c)
		q[t++] = i;
	int v;
	while(h < t){
		use[q[h]] = true;
		node* now = adj[q[h++]];
		while(now != NULL){
			v = now->v;
			ind[v]--;
			if (ind[v]==0 && rec[v].c==c) q[t++] = v;
			now = now->ne;
		}
	}
	bool color[21];
	bool ans = true;
	clr(color,false);
	F(i,0,m) if (ind[i] == 0 && !use[i])
		color[rec[i].c] = true, ans = false;
	if (ans) 
		minSteps = min(steps, minSteps);
	else 
		if(steps >= minSteps-1) return;

	F(c,0,21) if(color[c])
			search(c, steps+1, ind, use);
	
}
void add(int i, int j){
	node* t = new node();
	t->v = j;
	t->ne = NULL;
	if (adj[i] == NULL)
		adj[i] = t;
	else{
		t->ne = adj[i];
		adj[i] = t;
	}
}
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	//freopen("in", "r", stdin);
	getI(T);
	while(T--){
		getI(m);
		clr(adj,0);
		clr(ind, 0);
		clr(use, false);
		F(i,0,m)
			scanf("%d %d %d %d %d", &rec[i].y1, &rec[i].x1, &rec[i].y2, &rec[i].x2, &rec[i].c);
		F(i,0,m)
			F(j,0,m)if(i != j){
				if (rec[j].y1 >= rec[i].y2 && (rec[j].x1<rec[i].x2) && (rec[j].x2>rec[i].x1)){
					add(i,j);
					ind[j]++;
				}
			}
		bool color[21];
		minSteps = INT_MAX;
		clr(color,false);
		F(i,0,m) if (ind[i] == 0 && !use[i])
			color[rec[i].c] = true;
		F(c,0,21) if(color[c])
			search(c, 1, ind, use);
		printf("%d\n", minSteps);
	}
}





