#include <cmath>
#include <vector>
#include <map>
#include <climits>
#include <cstdlib>
#include <fstream>
#include <iomanip>   
#include <iostream>  
#include <algorithm>
#include <cstring>
#include <cassert>
using namespace std;
#define bit(x,i) (x&(1<<i))
#define max(a,b) (a<b?b:a)
#define abs(x) (x<0?-x:x)
#define IN(i,l,r) (l<i&&i<r)
#define LINR(i,l,r) (l<=i&&i<=r)
#define LIN(i,l,r) (l<=i&&i<r)
#define INR(i,l,r) (l<i&&i<r)
#define F(i,L,R) for (int i = L; i < R; i++)
#define FE(i,L,R) for (int i = L; i <= R; i++)
#define FF(i,L,R) for (int i = L; i > R; i--)
#define FFE(i,L,R) for (int i = L; i >= R; i--)
#define char2Int(c) (c-'0')
#define lastEle(vec) vec[vec.size()-1]
#define hBit(msb,n) asm("bsrl %1,%0" : "=r"(msb) : "r"(n))
#define clr(a,x) memset(a,x,sizeof(a))
#define getI(a) scanf("%d", &a)
#define getII(a,b) scanf("%d%d", &a, &b)
#define getIII(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define getS(x) scanf("%s", x);
#define SZ(x) ((int)((x).size()))
#define REMAX(a,b) (a)=max((a),(b));
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define REMIN(a,b) (a)=min((a),(b));
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define ALL(t) t.begin(),t.end()
#define ll long long
#define ui unsigned int
#define us unsigned short
#define IOS ios_base::sync_with_stdio(0);
#define pb push_back
#define INF 1001001001
#define PI 3.1415926535897932384626
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define fi first
#define se second
#define wez(n) int (n); scanf("%d",&(n));
#define wez2(n,m) int (n),(m); scanf("%d %d",&(n),&(m));
#define wez3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k));
inline void pisz(int n) { printf("%d\n",n); }
#define TESTS wez(testow)while(testow--)
#define whileZ int n; getI(n); while(n--)
template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){F(i,0,SZ(t))s<<t[i]<<" ";return s; }
struct node{
    int p, e;
}c[200005];
bool cmp1(const node &a, const node& b){
    return a.p > b.p;
}
bool cmp2(const node &a, const node& b){
    if (a.e == b.e) return a.p > b.p;
    else return a.e < b.e;
}

int n,k;
void printA(){
    for (int i = 0; i < n; i++){
        printf("%d %d\n", c[i].p, c[i].e);
    }
}
int main ( int argc, char *argv[] ) {
    getII(n,k);
    F(i,0,n) getII(c[i].p, c[i].e);
    sort(c, c+n, cmp1);
    int P = c[k].p; //result, P, P+1, P+2
    if (P > n){
        cout << -1 << endl;
        return 0;
    }
    vector<node> numP, numP_1;
    int EP = 0, EP_1 = 0, attackP = 0;
    F(i,0,n) 
        if (c[i].p == P) {
            if (i >= k) attackP++;
            numP.push_back(c[i]);
        }
        else if (c[i].p == P-1){ numP_1.push_back(c[i]); }
        else break;
    sort(numP.begin(), numP.end(), cmp2);
    sort(c, c+n, cmp2);

    int E = 0;
    F(i,0,attackP) E += numP[i].e;
    F(i,0,numP_1.size()) E+= numP_1[i].e;
    F(i,0, P - attackP - numP_1.size()) E += c[i].e;

    if (P <= n-1){
        int E1 = 0;
        F(i,0,attackP) E1 += numP[i].e;
        F(i,0, P+1 - attackP) E1 += c[i].e;
        if (E1 < E) E = E1;
    }

    if (P <= n-2){
        int E2 = 0;
        F(i,0,P+2) E2 += c[i].e;
        if (E2 < E) E = E2;
    }
    cout << E << endl;
    return EXIT_SUCCESS;
}






