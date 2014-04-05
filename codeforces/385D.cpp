#include <cmath>
#include <cmath>
#include <vector>
#include <map>
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
#define printA(a,L,R) FE(i,L,R) cout << a[i] << (i==R?'\n':' ')
const double PI=3.1415926535897932384626;
//new
#define eps 1e-9
#define zero(x) (-eps<x && x<eps)
template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){F(i,0,SZ(t))s<<t[i]<<" ";return s; }
struct node{
    double x, y, a;
};
int main ( int argc, char *argv[] ) {
    int n;
    double L, R, per = PI / 180;
    scanf("%d%lf%lf", &n, &L, &R);
    vector<node> v(n);
    F(i,0,n){
        cin >> v[i].x >> v[i].y >> v[i].a;
    }
    vector<double> dp(1<<n, L);
    double ans = L;
    F(k,0,1<<n)
        F(i,0,n) if (!bit(k,i)) {
            double x = v[i].x;
            double y = v[i].y;
            double a1 = max(atan((x-dp[k]) / y) - v[i].a*per, -PI/2+eps);
            double l = x - tan(a1) * y;
            REMAX(dp[k|1<<i],  l);
        }
    //printA(dp, 0, (1<<n)-1);
    F(k,0,1<<n) REMAX(ans, dp[k]);
    REMIN(ans, R);
    printf("%.9f\n", ans-L);
    return EXIT_SUCCESS;
}

