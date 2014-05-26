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
int n, K;
int x[10001], h[10001];
vector<int> check[10001], near[10001];

template <class typev>
class FenwickTree{
private:
    int n;
    vector<typev> val;
public:
    FenwickTree(int _n):n(_n){
        val = vector<typev>(n+1, 0);
    }
    void add(int i, int v){
        if (i == 0){
            val[0] += v;
            return;
        }
        for (; i < n; val[i] += v, i += lowb(i));
    }
    typev query(int i){
        typev s = 0;
        for (; i > 0; s += val[i], i -= lowb(i));
        return s+val[0];
    }
};

int main ( int argc, char *argv[] ) {
    wez(T);
    FE(cases,1,T){
        getI(n);
        F(i,0,n){
            getII(x[i], h[i]);
            near[i].clear();
            check[i].clear();
        }
        int j = -1;
        F(i,0,n){
            if (h[i] == 0){
                if (j != -1) near[i].push_back(j);
            }else j = i;
        }
        j = -1;
        FFE(i,n-1,0){
            if (h[i] == 0){
                if (j != -1){
                    if (near[i].size() == 1){

                        int dif = abs(x[j]-x[i]) - abs(x[near[i][0]]-x[i]);
                        if (dif == 0) near[i].push_back(j);
                        else if (dif < 0) near[i][0] = j;

                    }else near[i].push_back(j);
                }
            }else j = i;
        }
/*         F(i,0,n){
 *             cout << i << ": ";
 *             F(j,0,near[i].size()) cout << near[i][j] << ' ';
 *             cout << endl;
 *         }
 *         continue;
 */
        FenwickTree<int> f(100009);
        F(i,0,n)
            if (h[i] == 0){
                int hot = 0;
                F(k,0,near[i].size()){
                    check[near[i][k]].push_back(i);
                    hot = max(hot, h[near[i][k]]);
                }
                f.add(hot, 1);
            }else{
                f.add(h[i], 1);
            }



        printf("Case #%d:\n", cases);

        getI(K);
        while(K--){
            char c;
            int i, v;
            cin >> c;
            if (c == 'Q'){
                cin >> v;
                cout << f.query(v) << endl;
            }else{
                cin >> i >> v;

                if (h[i] != v){
                    F(j,0,check[i].size()){
                        int k = check[i][j]; // k needs to update
                        if (near[k].size() == 1){

                            f.add(h[i], -1);
                            f.add(v, 1);

                        }else{
                            int preH = max(h[near[k][0]], h[near[k][1]]);
                            int temp = h[i];
                            h[i] = v;
                            int nowH = max(h[near[k][0]], h[near[k][1]]);
                            h[i] = temp;
                            if (preH != nowH){
                                f.add(preH, -1);
                                f.add(nowH, 1);
                            }
                        }
                    }

                    f.add(h[i], -1);
                    f.add(v, 1);
                    h[i] = v;
                }
            }
        }
    }
    return EXIT_SUCCESS;
}
