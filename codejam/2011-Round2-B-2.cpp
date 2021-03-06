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

char m[510][510];
int bX[510][510], bY[510][510], sumK[510][510][510], sum[510][510];
int R, C, D;

bool ok(int k){

    int p = (k%2? k/2*(-2): k/2*(-2)+1);

    FE(x,1,R-k+1)
        FE(y,1,C-k+1){
            int unbX = bX[x+k-1][y+k-1] + bX[x-1][y-1] - bX[x+k-1][y-1] - bX[x-1][y+k-1];
            int unbY = bY[x+k-1][y+k-1] + bY[x-1][y-1] - bY[x+k-1][y-1] - bY[x-1][y+k-1];
            int dx = unbX - sumK[x][y][k] * (2*y-p) - (m[x-1][y-1]+m[x+k-2][y-1]) * p + (m[x-1][y+k-2]+m[x+k-2][y+k-2]) * p;
            int dy = unbY - sumK[x][y][k] * (2*x-p) - (m[x-1][y-1]+m[x-1][y+k-2]) * p + (m[x+k-2][y-1]+m[x+k-2][y+k-2]) * p;
            if (dx == 0 && dy == 0)
                return true;
        }
    return false;
}
int main ( int argc, char *argv[] ) {
    wez(T);
    FE(cases,1,T){
        getIII(R, C, D);
        F(i,0,R) {
            getS(m[i]);
            F(j,0,C) m[i][j] = m[i][j] - '0';
        }
        int ans = -1;

        clr(bX, 0);
        FE(x,1,R){
            FE(y,1,C){
                bX[x][y] = bX[x][y-1] + (y + y) * m[x-1][y-1];
            }
            FE(y,1,C){
                bX[x][y] += bX[x-1][y];
            }
        }


        clr(bY, 0);
        FE(y,1,C){
            FE(x,1,R){
                bY[x][y] = bY[x-1][y] + (x + x) * m[x-1][y-1];
            }
            FE(x,1,R){
                bY[x][y] += bY[x][y-1];
            }
        }


        clr(sum, 0);
        FE(x,1,R){
            FE(y,1,C){
                sum[x][y] = sum[x][y-1] + m[x-1][y-1];
            }
            FE(y,1,C){
                sum[x][y] += sum[x-1][y];
            }
        }



        clr(sumK, 0);
        FE(x,1,R)
            FE(y,1,C){
                FE(k,1,min(R-x+1,C-y+1)){
                    sumK[x][y][k] = sum[x+k-1][y+k-1] + sum[x-1][y-1] - sum[x+k-1][y-1] - sum[x-1][y+k-1];
                }
            }


        FFE(i,min(R,C),3){
            if (ok(i)){
                ans = i;
                break;
            }
        }


        printf("Case #%d: ", cases);
        if (ans == -1) cout << "IMPOSSIBLE\n";
        else cout << ans << endl;
    }
    return EXIT_SUCCESS;
}
