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
#define head(i) word[i][0]
int T, n,L;
char word[1000][21];
int len[1000];
int pos[256];
char s[200], res[200];
bool ans;
bool use[1000];
int t1;
bool ok(char* w, char* s, int l){
	int p = 0;
	while(w[p]!=0 && s[l+p]!=0 && w[p]==s[l+p]) p++;
	if (w[p]==0 || s[l+p]==0) return true;
	return false;
}
void search(int l1, int l2){
	if (clock()-t1 > 1200) return;
	if (l1 > L || l2 > L) return;
	if (l1 == l2){
		if (l1 == L && (!ans || strcmp(s, res) < 0)){
			ans = true;
			strcpy(res, s);
		}
	}else if (l1 < l2){
		int p = pos[s[l1]-'a'];
		F(i,p,n)if (!use[i]){
			if (len[i]+l1 != L && len[i] == l2-l1 || len[i]+l1>L) continue; //!!
			if (!ok(word[i], s, l1)) continue;
			if (len[i] > l2-l1) strcpy(s+l1, word[i]);

			if (ans && strcmp(s,res)>0){
				s[l2] = 0;
				break;
			}
			use[i] = true;
			search(l1+len[i], l2);
			s[l2] = 0;
			use[i] = false;
		}
	}else{
		int p = pos[s[l2]-'a'];
		F(i,p,n)if (!use[i]){
			if (len[i]+l2 != L && len[i] == l1-l2 || len[i]+l2>L) continue; //!!
			if (!ok(word[i], s, l2)) continue;
			if (len[i] > l1-l2) strcpy(s+l2, word[i]);

			if (ans && strcmp(s,res)>0){
				s[l1] = 0;
				break;
			}
			use[i] = true;
			search(l1, l2+len[i]);
			s[l1] = 0;
			use[i] = false;
		}
	}
}
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	//	ifstream cin("in");
	t1 = clock();
	//freopen("in", "r", stdin);
	clr(pos,0);
	getII(L,n);
	char last = ' ';
	ans = false;
	clr(use, 0);
	F(i,0,n){
		scanf("%s", word[i]);
		len[i] = strlen(word[i]);
		if (word[i][0]!=last){
			last = word[i][0];
			pos[word[i][0]-'a'] = i;
		}
	}
	int pre = 0;
	F(i,0,27){
		if (pos[i] == 0) pos[i] = pre;
		pre = pos[i];
	}
	F(i,0,n){
		if (ans && strcmp(word[i],res)>0) break;
		strcpy(s,word[i]);
		use[i] = true;
		search(len[i], 0);
		use[i] = false;
	}
	if (ans) printf("%s\n", res);
	else printf("NO SOLUTION\n");
}

