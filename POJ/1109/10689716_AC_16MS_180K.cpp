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
#define nbit(x,i) ((x&(1<<i))==0)
#define abs(x) (x<0?-x:x)
#define ll long long
#define max(a,b) (a<b?b:a)
#define min(a,b) (a<b?a:b)
#define maxLen 400000
#define NOP 1
#define skip(c) while(doc[p]==c) p++;
#define come(c) while(doc[p]!=c) p++;
#define up(c) (c>='a'?c-32:c)
#define isC(c) (c!='$'&&c!='%'&&c!='&'&&c!=NOP&&c!='}')
int T, m, n;
int len;
struct node{
	int p1;
	int p2;
	int page;
}ind[1210];
int pv[1210], pvT;
int L;
char doc[maxLen], s[82];
int strcmp1(char* s1, char* s2){
	int i = 0;
	while(isC(s1[i]) && isC(s2[i]) && up(s1[i])==up(s2[i])) i++;
	if (isC(s1[i])){
		if (isC(s2[i])) return up(s1[i])-up(s2[i]);
		else return 1;
	}else{
		if (isC(s2[i])) return -1;
		else return 0;
	}
}
bool big(node i1, node i2){
	int c1 = strcmp1(doc+i1.p1, doc+i2.p1);
	if (c1 == 0)  {
		if (i1.p2!=-1 && i2.p2!=-1) 
			return strcmp1(doc+i1.p2, doc+i2.p2)>0;
		else return i1.p2 > i2.p2;
	}
	else return c1 > 0;
}
void print(int p){
	while(isC(doc[p])) {
		printf("%c", doc[p]);
		p++;
	}
}
void printPV(){
	sort(pv,pv+pvT);
	int i = 0, j;
	while(i < pvT){
		printf(", %d", pv[i]);
		j = i+1;
		while(j < pvT && pv[j]==pv[j-1]) j++;
		i = j;
	}
	printf("\n");
}
int main(){
	//if you do not want to use file input stream, put "//" before ifstream
	//	ifstream cin("in");
	//freopen("in", "r", stdin);
	doc[0] = 0;
	int page, docId = 1;
	while(gets(s), !(s[0]=='*'&&s[1]=='*')){
		len = 0;
		while(true){
			for(int i = 0; s[i]!=0; i++)
				doc[len++] = s[i];
			gets(s);
			if (strcmp(s,"*")==0) break;
			else doc[len++] = ' ';
		}
		doc[len]=0;
		F(i,0,len){
			if (doc[i]=='{' || doc[i]=='%' || doc[i]=='$'){
				int j = i+1;
				while(j<len && doc[j]==' ') doc[j]=NOP, j++;
			}
			if (doc[i]=='}' || doc[i]=='%' || doc[i]=='$'){
				int j = i-1;
				while(j>=0 && doc[j]==' ') doc[j]=NOP, j--;
			}
		}
		page = 1;
		int p = 0;
		L = 0;
		while(p < len){
			if (doc[p]=='&') page++;
			else if(doc[p]=='{'){
				p++;
				skip(NOP);
				ind[L].page = page;
				ind[L].p1 = p;
				while(doc[p]!='%' && doc[p]!='$' && doc[p]!='}') p++;
				if (doc[p] == '}') ind[L].p2=-1;
				else if(doc[p] == '$'){
					p++; skip(NOP);
					ind[L].p2 = p;
					come('}');
				}else if(doc[p] == '%'){
					p++;
					skip(NOP);
					ind[L].p1 = p;
					while(doc[p]!='$' && doc[p]!='}') p++;
					if (doc[p] == '}') ind[L].p2 = -1;
					else{
						p++; skip(NOP);
						ind[L].p2 = p;
						come('}');
					}
				}
				L++;
			};
			p++;
		}
		F(i,0,L)
			F(j,i,L) if (big(ind[i],ind[j]))
				swap(ind[i], ind[j]);
		printf("DOCUMENT %d\n", docId++);
		bool first = true;
		int i = 0, i1, i2;
		while(i<L){
			print(ind[i].p1);
			i1 = i+1;
			while(i1 < L && strcmp1(doc+ind[i1].p1, doc+ind[i].p1)==0) i1++;
			pvT = 0;
			F(k,i,i1) if (ind[k].p2==-1)
				pv[pvT++] = ind[k].page;
			printPV();
			i2 = i;
			while(i2 < i1){
				if (ind[i2].p2 != -1){
					printf("+ ");
					print(ind[i2].p2);
					pvT = 1;
					pv[0] = ind[i2].page;
					i2++;
					while(i2 < L && ind[i2].p2 != -1 && strcmp1(doc+ind[i2].p2, doc+ind[i2-1].p2)==0){
						pv[pvT++] = ind[i2].page;
						i2++;
					}
					printPV();
				}else i2++;
			}
			i = i1;
		}
	}
}





