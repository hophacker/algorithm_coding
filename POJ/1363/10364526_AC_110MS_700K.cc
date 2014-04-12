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
#define D(i,l,r) ((l<=i)&&(i<r))
int main(){
	//freopen("in.txt", "r", stdin);
	int n;
	int a[1002];
	int pos[1002];
	int last;
	bool no;
	while(scanf("%d", &n), n){
		while(scanf("%d", &a[1]), a[1]){
			F(i,2,n+1) scanf("%d", &a[i]);
			F(i,1,n+1)
				pos[a[i]] = i;

			no = false;
			for (int i = n; i >= 1; i--){
				last = pos[i];
				for (int j = i-1; j >= 1; j--)if (pos[j] > pos[i]){
					if (pos[j] > last)
						last = pos[j];
					else {
						no = true;
						break;
					}	
				}
				if (no)
					break;
			}
			if (no)
				printf("No\n");
			else
				printf("Yes\n");
		}
		printf("\n");
	}
}