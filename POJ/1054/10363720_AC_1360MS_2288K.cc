#include <cstdlib>
#include <cctype>
#include <cstring>
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
using namespace std;
typedef long long ll;
#define clr(x,a) memset(x,a,sizeof(x))
#define sz(x) (int)x.size()
#define see(x) cerr<<#x<<" "<<x<<endl
#define se(x) cerr<<" "<<x 
#define pb push_back
#define mp make_pair
#define F(i,l,r) for (int i=l;i<r;i++)
#define D(i,l,r) ((l<=i)&&(i<=r))
#define hp 398689
#define step 98698
struct node{
	int x, y;
}p[5001];

int used[hp];
int r, c, n;
bool cmp(const node& a, const node& b){
	if (a.x != b.x)
		return a.x < b.x;
	else
		return a.y < b.y;
}
void hash(int i){
	int hashX = (p[i].x * c + p[i].y)%hp;
	while(used[hashX])
		hashX = (hashX+step)%hp;
	used[hashX] = i;
}
int find(int x, int y){
	if (!D(x,1,r) || !D(y,1,c)) return -1;
	int hashX = (x * c + y) % hp;
	int t;
	while(used[hashX]){
		t = used[hashX];
		if (p[t].x == x && p[t].y == y) return 1;
		hashX = (hashX+step)%hp;
	}
	return 0;
}
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	scanf("%d %d %d", &r, &c, &n);
	F(i,1,n+1){
		scanf("%d %d", &p[i].x, &p[i].y);
	}
	sort(p, p+n, cmp);
	memset(used, 0, sizeof(used));
	F(i,1,n+1)
		hash(i);		
	int ii, jj;
	int maxN = 2, dx, dy, tot, x, y;
	F(i,1,n)
		F(j,i+1,n+1){
			dx = p[j].x- p[i].x;
			dy = p[j].y- p[i].y;
			if (find(maxN*dx+p[i].x, maxN*dy+p[i].y) == -1) continue;
			if (find(p[i].x-dx, p[i].y-dy) != -1) continue;
			tot = 2;
			x = p[j].x + dx;
			y = p[j].y + dy;
			while(find(x,y) == 1){
				tot++;
				x += dx;
				y += dy;
			}
			if (tot > maxN && !(D(x,1,r)&&D(y,1,c))) {
				maxN = tot;
				ii = i;
				jj = j;
			}
		}
	if (maxN > 2) printf("%d\n", maxN);
	else printf("0\n");
}












