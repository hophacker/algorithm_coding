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

struct Node{  
	int types,tot;  
	int answer[5];  
}ans;
bool tie;
bool yes;
vector<int> stamp;
void dfs(int req, int types, int tot, int *answer, int now){
	if(req == 0){
		if (!yes || types > ans.types ||
			(types == ans.types && tot < ans.tot) ||
			(types == ans.types && tot == ans.tot && answer[tot-1]>ans.answer[ans.tot-1])){
				ans.types = types;
				ans.tot = tot;
				F(i,0,tot) ans.answer[i]=answer[i];
				tie = false;
				yes = true;
		}else if(types == ans.types && tot == ans.tot && answer[tot-1]==ans.answer[ans.tot-1]){
			tie = true;
		}
	}
	if (tot >= 4 || now >= stamp.size()) return;
	dfs(req, types, tot, answer, now+1);
	int TT = 0;
	F(i,tot,4){
		TT += stamp[now];
		answer[i] = stamp[now];
		if (TT <= req)
			dfs(req-TT, types+1, i+1, answer, now+1);
		else break;
	}
}
int main(){
	//freopen("in.txt", "r", stdin);
	int sta, req;
	int answer[5];
	while(~scanf("%d", &sta)){
		stamp.clear();
		stamp.push_back(sta);
		while(scanf("%d", &sta), sta)
			stamp.push_back(sta);
		sort(stamp.begin(), stamp.end());
		while(scanf("%d", &req), req){
			tie = false;
			yes = false;
			dfs(req, 0, 0, answer, 0);
			if (!yes){
				printf("%d ---- none\n", req);
			}else{
				if (tie)
					printf("%d (%d): tie\n", req, ans.types);
				else{
					printf("%d (%d):", req, ans.types);
					F(i,0,ans.tot)
						printf(" %d", ans.answer[i]);
					printf("\n");
				}
			}
		}
	}
}