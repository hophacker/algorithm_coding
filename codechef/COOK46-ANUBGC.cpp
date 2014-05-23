#include <cmath>
#include <set>
#include <list>
#include <unordered_set>
#include <hash_map>
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
#define ll unsigned long long
#define ui unsigned int
#define us unsigned short
#define IOS ios_base::sync_with_stdio(0);
#define pb push_back
#define INF 1001001001
#define PI 3.1415926535897932384626
#define mp make_pair
#define fi first
#define se second
#define wez(n) int (n); scanf("%d",&(n));
#define wez2(n,m) int (n),(m); scanf("%d %d",&(n),&(m));
#define wez3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k));
inline void pisz(int n) { printf("%d\n",n); }
#define TESTS wez(testow)while(testow--)
#define whileZ int T; getI(T); while(T--)
#define printA(a,L,R) FE(i,L,R) cout << a[i] << (i==R?'\n':' ')
#define printM(a,n,m) F(i,0,n){ F(j,0,m) cout << a[i][j] << ' '; cout << endl;}
#define printV(a) printA(a,0,a.size()-1);
#define printVV(a) F(i,0,a.size()) {F(j,0,a[i].size())cout << a[i][j] << ' '; cout << endl;}
#define MAXN 10000
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
typedef int elem_t;
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){F(i,0,SZ(t))s<<t[i]<<" ";return s; }
int gcd(int a,int b){return a?gcd(b%a,a):b;}
ll gcd(ll a,ll b){return a?gcd(b%a,a):b;}
ll powmod(ll a,ll p,ll m){ll r=1;while(p){if(p&1)r=r*a%m;p>>=1;a=a*a%m;}return r;}


struct node{
    int d, targetD;
    ll powK;
    node(int dd, ll powKK, int targetDD){
        d = dd;
        targetD = targetDD;
        powK = powKK;
    }
    bool operator <(const node& other)const{
        if (powK == other.powK){
            if (d == other.d) {
                return targetD < other.targetD;
            }else return d < other.d;
        }else return powK < other.powK;
    }
};

// d[k 0s] -> d[k 9s]
// targetD
// powK = 10**k
map<node, ll> ha;
ll calc(int d, ll powK, int targetD){
    if (powK == 1) return targetD == d;
    if (powK == 10) {
        if (targetD  == d) return 10;
        else return 1;
    }

    node yes(d,powK,targetD);
    if (ha.find(yes) == ha.end()){ 

        ll sum = 0;
        if (d == targetD) sum += powK;
        else{
            F(dd,0,10)
                sum += calc(dd, powK/10, targetD);
        }
        ha[yes] = sum;

    }
    return ha[yes];
}
ll getNumDig(ll n, int targetD, ll pow){
    ll sum = 0;


    while(pow >= 1){
        int hD = n/pow;
//        cout << n << ' ' << pow << endl;
        F(i,0,hD){
            sum += calc(i, pow, targetD);
        }
        if (hD == targetD){
            sum += n % pow + 1;
            break;
        }else{
            n %= pow;
            pow /= 10;
        }
    }
    return sum;
}
ll calc0(ll n, ll p){
    ll sum = 0;

    ll pow = p;

    while(pow >= 10){
        sum += 9 * calc(1, pow/10, 0);
        pow /= 10;
    }
    cout << sum << endl;

    sum += calc(0, n%p, 0);
    return sum;
}
vector<vector<ll> > generateComb(int n){
    vector<vector<ll> > comb;
    comb.push_back(vector<ll>());
    FE(i,1,n){
        comb.push_back(vector<ll>());
        comb[i].push_back(1);
        FE(j,1,i-1){
            comb[i].push_back(comb[i-1][j-1] + comb[i-1][j]);
        }
        comb[i].push_back(1);
    }
    return comb;
}

int main ( int argc, char *argv[] ) {
    vector<vector<ll> > comb;
    comb = generateComb(18);
    

    vector<ll> mul9;
    mul9.push_back(1);
    FE(i,1,17){
        mul9.push_back(mul9[i-1] * 9);
    }

//    printV(mul9);

    vector<ll> select;
    select.push_back(0);

    FE(i,1,17){
        ll sum = 0;
        FE(j,1,i){
            sum += comb[i][j] * mul9[i-j];
        }
        select.push_back(sum);
    }

//    printV(select);

    wez(T);
    ll n;
    FE(cases,1,T){
        cin >> n;

        ll pow = 1;
        while(pow <= n) pow *= 10;
        pow /= 10;

        ll sum = calc0(n, pow);
        cout << 0  << ' ' << sum << endl;
        F(i,1,10){
            ll add = getNumDig(n, i, pow);
            sum += add;
            cout << i << ' ' << add << endl;
        }
        // 0000
//        cout << sum << endl;
        ll total = n * 10;
        ll g = gcd(sum, total);
        cout << sum/g << '/' << total/g << endl;
    }
    return EXIT_SUCCESS;
}
