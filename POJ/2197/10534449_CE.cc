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
#define FE(i,l,r) for (int i=l;i<=r;i++)
#define FF(i,r,l) for (int i=r;i>l;i--)
#define FFE(i,r,l) for (int i=r;i>=l;i--)
#define D(i,l,r) ((l<=i)&&(i<=r))
#define bit(x,i) ((x&(1<<i))!=0)
#define abs(x) (x<0?-x:x)
#define ll long long
#define max(a,b) (a<b?b:a)
#define min(a,b) (a<b?a:b)
#define maxDis 999999999
struct node{
	int v;
	int d;
	node* ne;
};
struct nodeR{
	int d;
	string path;
	friend bool operator<(nodeR a, nodeR b){
		if (a.d == b.d)
			return a.path < b.path;
		else 
			return a.d < b.d;
	}
};
node* u[21];
vector<nodeR> res;
int T, m, n;
int g_sV, g_dV, maxD;
bool visited[21];
char* toStr(int a);
void add(int a, int b, int d);
int dijkstra(int sV, int dV);
void search(int x, int dis, string path);
node* delIt(node* now){
	while(now != NULL){
		node* t = now;
		now = now->ne;
		delete t;
	}
	return NULL;
}
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	//	ifstream cin("in");
	/freopen("in", "r", stdin);
	int a, b, d;
	int cases = 0;
	while(getI(n), n!=-1){
		res.clear();
		F(i,0,21) u[i] = delIt(u[i]);
		getI(m);
		F(i,0,m){
			scanf("%d %d %d", &a, &b, &d);
			add(a,b,d);
			add(b,a,d);
		}
		scanf("%d %d %d", &g_sV, &g_dV, &maxD);
		int minSD = dijkstra(g_sV,g_dV);
		printf("Case %d:\n", ++cases);
		if (minSD > maxD){
			printf(" NO ACCEPTABLE TOURS\n");
		}else{
			clr(visited, false);
			visited[g_sV] = true;
			string s=" ";
			search(g_sV, 0, s + toStr(g_sV));
			sort(res.begin(), res.end());
			F(i, 0, res.size()){
				cout << ' ' << res[i].d << ':';
				cout << res[i].path << endl;
			}
		}
		cout << endl;
	}
}
void search(int x, int dis, string path){
	if (x == g_dV){
	 	nodeR temp = {
			d: dis, 
			path:path
		};
		res.push_back(temp);
	}
	node* now = u[x];
	while(now != NULL){
		if (!visited[now->v] && dis+now->d <= maxD){
			visited[now->v] = true;
			search(now->v, dis+now->d, path+" "+toStr(now->v));
			visited[now->v] = false;
		}
		now = now->ne;
	}
}
char* toStr(int a){
	char* ret = new char[3];
	if (a > 10){
		ret[0] = a/10+'0';
		ret[1] = a%10+'0';
		ret[2] = 0;
	}else{
		ret[0] = a+'0';
		ret[1] = 0;
	}
	return ret;
}
void add(int a, int b, int d){
	node* t = new node;
	t->v = b;
	t->d = d;
	t->ne = NULL;
	if (u[a] == NULL)
		u[a] = t;
	else{
		t->ne = u[a]->ne;
		u[a]->ne = t;
	}
}
int dijkstra(int sV, int dV){
	int dis[n+1];
	bool visit[n+1];
	int v;
	clr(visit, false);
	FE(i,1,n) dis[i] = maxDis;
	node* now = u[sV];
	while(now != NULL){
		v = now->v;
		dis[v] = now->d;
		now = now->ne;
	}
	visit[sV] = true;
	int _minD, _minI;
	F(t,0,n-2){
		_minD = maxDis;
		FE(i,1,n)
			if (!visit[i] && dis[i] < _minD){
				_minI = i;
				_minD = dis[i];
			}
		if (_minD == maxDis) break;

		node* now = u[_minI];
		visit[_minI] = true;

		while(now != NULL){
			v = now->v;
			if (dis[_minI]+now->d < dis[v])
				dis[v] = dis[_minI]+now->d;
			now = now->ne;
		}
	}
	return dis[dV];

}