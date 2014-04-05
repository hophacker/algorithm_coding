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
#include <string.h>
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
#define low(c) (c>='a'?c:c-'A'+'a')
char s[15];
int n, len;
bool cmp(const char& a, const char& b){
	return low(a) < low(b) || (low(a)==low(b) && a < b);
}
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	//freopen("in.txt", "r", stdin);
	scanf("%d", &n);
	while(n--){
		scanf("%s", s);
		len = strlen(s);
		sort(s, s+len, cmp);
		printf("%s\n", s);
		while(next_permutation(s, s+len, cmp))
			printf("%s\n", s);
	}
}