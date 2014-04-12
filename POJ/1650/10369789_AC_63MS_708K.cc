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
#define F(i,l,r) for (int i=l;i<r;i++)
#define D(i,l,r) ((l<=i)&&(i<=r))
#define abs(x) (x<0?-x:x)
#define ll long long

int L, N, D;
double temp, minR = 10.0, A;

void compare(int j, int i){
		if (j>L) return;
		temp = fabs(A - (double)i/j);
		if (temp < minR){
			minR = temp;
			N = i;
			D = j;
		}
}

int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	//	ifstream cin("in.txt");
	//freopen("in.txt", "r", stdin);
	scanf("%lf%d", &A, &L);
	int j;
	F(i,1,L+1){
		j = (int)i/A;
		compare(j, i);
		j++;
		compare(j, i);
	}
	printf("%d %d\n", N, D);
}