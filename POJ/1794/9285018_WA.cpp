#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
struct node{
	int x, y;
};
node a[60000], b[30000];
bool cmp(node a, node b){
	if (a.y == b.y) return a.x > b.x;
	else return a.y < b.y;
}

int calcRecur(node* a, int L, int R){
	if (L >= R) return 0;
	int s = 0;
	int M = (L + R)/2;
	s += calcRecur(a, L, M);
	s += calcRecur(a, M+1, R);
	int L1 = L, L2 = M+1;
	while(L1 <= M){
		while(L2 <= R && a[L1].x>a[L2].x) L2++;
		s += (L2-M-1);
		L1++;
	}
	return s;
}
int calcReverse(node* a, int n){
	sort(a, a+n, cmp);
	return calcRecur(a, 0, n-1);
}
int main()
{
	//freopen("H:/ACM/POJ/in.txt", "r", stdin); 
	//freopen("H:/ACM/POJ/out.txt", "w", stdout); 
	int tests, n, m;
	int s1, s2, s3;
	scanf("%d", &tests);
	for (int cases = 1; cases <= tests; cases++){
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
			scanf("%d%d", &a[i].x, &a[i].y);
		for (int i = 0; i < m; i++)
			scanf("%d%d", &b[i].x, &b[i].y);
		s1 = calcReverse(a, n);
		s2 = calcReverse(b, m);
		memcpy(a+n, b, m*sizeof(node));
		s3 = calcReverse(a, n+m);
		printf("Scenario #%d:\n%d\n", cases, s3-s2-s1);
	}
}