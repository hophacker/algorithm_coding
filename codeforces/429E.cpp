#include <cmath>
#include <set>
#include <list>
//#include <unordered_set>
//#include <hash_map>
#include <climits>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <cstdlib>
#include <fstream>
#include <iomanip>   
#include <iostream>  
#include <sstream>  // istringstream buffer(myString);
#include <stack>
#include <algorithm>
#include <cstring>
#include <cassert>
using namespace std;
#define bit(x,i) (x&(1<<i))
#define lowbit(x) ((x)&((x)^((x)-1)))
//#define max(a,b) (a<b?b:a)
//#define abs(x) (x<0?-x:x)
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
#define ull unsigned long long
#define ui unsigned int
#define us unsigned short
#define IOS ios_base::sync_with_stdio(0);
#define pb push_back
#define INF 1001001001
#define PI 3.1415926535897932384626
#define mp make_pair
#define ll long long
#define fi first
#define se second
#define root(x) ((int)sqrt((double)x))
#define wez(n) int (n); scanf("%d",&(n));
#define wez2(n,m) int (n),(m); scanf("%d %d",&(n),&(m));
#define wez3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k));
inline void pisz(int n) { printf("%d\n",n); }
#define TESTS wez(testow)while(testow--)
#define whileZ int T; getI(T); while(T--)
#define printA(a,L,R) FE(i,L,R) cout << a[i] << (i==R?'\n':' ')
#define printM(a,n,m) F(i,0,n){ F(j,0,m) cout << a[i][j] << ' '; cout << endl;}
#define printV(a) printA(a,0,(int)a.size()-1);
#define printVV(a) F(i,0,a.size()) {F(j,0,a[i].size())cout << a[i][j] << ' '; cout << endl;}
#define MAXN 10000
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define tiny (double)1e-13
#define close(x,y) (abs(x-y)<tiny)
typedef int elem_t;
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){F(i,0,SZ(t))s<<t[i]<<" ";return s; }
int gcd(int a,int b){return a?gcd(b%a,a):b;}
ll gcd(ll a,ll b){return a?gcd(b%a,a):b;}
ll powmod(ll a,ll p,ll m){ll r=1;while(p){if(p&1)r=r*a%m;p>>=1;a=a*a%m;}return r;}
const int fx[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
#define maxn (int)1e5+10
struct SEG{
    double L, R;
    bool operator<(const SEG& other)const {
        if (L == other.L) return R < other.R;
        else return L < other.L;
    }
};
int n;
SEG seg[maxn]; 
int color[maxn];
vector<int> total;
int start[maxn];
vector<double> p;
bool ok(int t){
    if (t != 0){
        F(i,start[t-1], start[t]){
            if (abs(total[i]) > 1) return false;
        }
    }
    // - 1
    if (abs(total[t] - 1) <= 1){
        for (int i = start[t]; i < p.size() && p[i] <= seg[t].R; i++){
            if (color[i] == 1) break;
        }
        if (i < p.size() && color[i] == 1){
        }else{
            int i = start[t];
            while(i < p.size() && p[i] <= seg[t].R){
                color[t] = 0;
            }
        }
    }
    if (abs(total[t] + 1) <= 1){
        color[t] = 1;
    }
}
int main ( int argc, char *argv[] ) {
    getI(n);
    F(i,0,n) {
        cin >> seg[i].L >> seg[i].R;
        if (seg[i].L == seg[i].R){
            p.push_back(seg[i].L);
        }else{
            p.push_back(seg[i].L);
            p.push_back(seg[i].R);
        }
    }
    sort(seg, seg+n);
    sort(p.begin(), p.end());
    int L = 0;
    F(i,0,p.size()){
        if (i != 0 && p[i] == p[i-1]) continue;
        else p[L++] = p[i];
    }
    p.resize(L);
    for (int i = 0, k = p.size(); i < k-1; i++){
        p.push_back((p[i]+p[i+1])/2);
    }
    sort(p.begin(), p.end());
    F(i,0,n){
        start[i] = lower_bound(p.begin(), p.end(), seg[i].L) - p.begin();
    }
/*     F(i,0,n){
 *         cout << seg[i].L << ' ' << seg[i].R << endl;
 *     }
 *     printV(p);
 *     printA(start, 0, n-1);
 */
    clr(color, 0);
    total = vector<int>(p.size(), 0);
    if (ok(0)){
    }else{
        cout << -1 << endl;
    }
    return EXIT_SUCCESS;
}



