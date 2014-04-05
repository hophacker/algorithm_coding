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
#define F(i,l,r) for (int i=l;i<=r;i++)
#define FD(i,r,l) for (int i=r;i>=l;i--)
#define D(i,l,r) ((l<=i)&&(i<=r))
#define abs(x) (x<0?-x:x)
#define ll long long
#define max(a,b) (a<b?b:a)
#define min(a,b) (a<b?a:b)
int T, m, n;
int maxN;
struct node{
	node* LTr;
	node* RTr;
	int L, R, num;
};
node* creNode(int L, int R){
	node* head = new node();
	head->L = L;
	head->R = R;
	head->num = 0;
	head->LTr = head->RTr = NULL;
	return head;
}
void lay(node* n, int a, int b){
	int L = n->L;
	int R = n->R;
	if (b < L || R < a) return;
	if (a <= L && R <= b) {
		n->num++;
		return;
	}
	//now n->L must < n->R	
	if (n->LTr != NULL && n->RTr != NULL){
		lay(n->LTr, a, b);
		lay(n->RTr, a, b);
	}else{
		n->LTr = creNode(L, (L+R)/2);
		n->RTr = creNode((L+R)/2+1, R);
		lay(n->LTr, a, b);
		lay(n->RTr, a, b);
	}
}
void cal(node* n, int num){
	if (n->LTr != NULL && n->RTr != NULL){
		cal(n->LTr, num+n->num);
		cal(n->RTr, num+n->num);
		n->num = 0;
	}
	else{
		n->num += num;
		maxN = max(maxN, n->num);
	}
}
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	//	ifstream cin("in");
	//freopen("in", "r", stdin);
	getI(T);
	int a, b;
	while(T--){
		getI(n);
		node* head = creNode(1,200);
		F(i,1,n){
			scanf("%d %d", &a, &b);
			if (a > b) swap(a,b);
			lay(head, (a+1)/2, (b+1)/2);
		}
		maxN = 0;
		cal(head, 0);
		printf("%d\n", maxN*10);
	}
}