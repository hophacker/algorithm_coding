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
#define lowb(t) (t &(-t))
#define pow2(x) (1<<x)
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
#define tr(c,i) for(auto i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
template<class T> string tos(T n) { stringstream ss; ss << n; return ss.str(); }
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
int a[1009];
int maxI[1009][1009], minI[1009][1009];
int ni[1009][1009], shun[1009][1009];
int f1[1009][1009], f2[1009][1009];
struct node{
    int num, index;
};
int reverse(int L, int R){
    if (L >= R) return 0;
    if (ni[L][R] == -1){
        int cnt = 0;
        FE(i,L,R)
            FE(j,i,R){
                if (a[i] > a[j]) cnt++;
            }
        ni[L][R] = cnt;
    }
    return ni[L][R];
}
int dp1(int L, int R){
    if (L >= R) return 0;
    if (f1[L][R] == -1){

        int minM = reverse(L, R);

        FE(i,L+1,R-1){
            if (maxI[L][i] < minI[i+1][R]){
                minM = min(minM, dp1(L,i) + dp1(i+1,R));
            }
        }
        f1[L][R] = minM;
    }
    return f1[L][R];
}
int shunn(int L, int R){
    if (L >= R) return 0;
    if (shun[L][R] == -1){
        int cnt = 0;
        FE(i,L,R)
            FE(j,i,R){
                if (a[i] < a[j]) cnt++;
            }
        
        shun[L][R] = cnt;
    }
    return shun[L][R];
}
int dp2(int L, int R){
    if (L >= R) return 0;

    if (f2[L][R] == -1){

        int minM = shunn(L, R);


        FE(i,L+1,R-1){
            if (minI[L][i] > maxI[i+1][R]){
                minM = min(minM, dp2(L,i) + dp2(i+1,R));
            }
        }
        f2[L][R] = minM;
    }
    return f2[L][R];
}
int main ( int argc, char *argv[] ) {
    wez(T);
    FE(cases,1,T){
        wez(n);
        printf("Case #%d: ", cases);

        F(i,0,n) getI(a[i]);
        if (n <= 2){
            cout << 0 << endl;
            continue;
        }
        clr(ni, -1);
        clr(shun, -1);
        clr(f1, -1);
        clr(f2, -1);

        F(i,0,n){
            F(j,i,n){
                if (j == i) maxI[i][j] = minI[i][j] = a[j];
                else {
                    maxI[i][j] = max(maxI[i][j-1], a[j]);
                    minI[i][j] = min(minI[i][j-1], a[j]);
                }
            }
        }



        int minM = min(dp1(0,n-1), dp2(0,n-1));
        FE(i,1,n-2){
            if (maxI[0][i] > maxI[i+1][n-1])
                minM = min(minM, dp1(0,i) + dp2(i+1,n-1));
        }
        cout << minM << endl;
    }
    return EXIT_SUCCESS;
}
