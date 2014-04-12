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
#define N 1005

struct set
{
	int parent;  //记录父节点
	int rank;    //记录集合的节点数
}elem[N];

int MAX;

void init()
{
	int i;
	for(i=0;i<=N;i++)
	{
		elem[i].parent=i;
		elem[i].rank=1;
	}
}

int Find(int x)
{
	int root,temp;
	temp=x;
	while(x!=elem[x].parent)    //寻找根节点
		x=elem[x].parent;
	root=x;
	x=temp;
	while (x!=elem[x].parent)   //压缩路径，全部赋值为根节点的值
	{
		temp=elem[x].parent;
		elem[x].parent=root;
		x=temp;
	}
	return root;
}

void Union(int x,int y)   //合并两个集合
{
	if(elem[x].rank>=elem[y].rank)
	{
		elem[y].parent=elem[x].parent;
		elem[x].rank+=elem[y].rank;
		if(MAX<elem[x].rank)
			MAX=elem[x].rank;
	}
	else
	{
		elem[x].parent=elem[y].parent;
		elem[y].rank+=elem[x].rank;
		if(MAX<elem[y].rank)
			MAX=elem[y].rank;
	}
}
int m, n, x, y, fx, fy;
int main(){
	//freopen("in", "r", stdin);
	int cas = 0;
	while(getII(x,y), x != -1){
		init();
		bool tree = true;
		while(x!=0){
			if (tree){
				fx = Find(x);
				fy = Find(y);
				if (fx == fy || fy != y) tree = false;
				else Union(fx, fy);
			}
			getII(x,y);
		}
		if (tree)
			printf("Case %d is a tree.\n", ++cas);
		else 
			printf("Case %d is not a tree.\n", ++cas);

	}
}




