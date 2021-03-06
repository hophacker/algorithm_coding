#include <cmath>
#include <set>
#include <list>
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
#define maxN 100005
struct node{
    int index, fin, cost;
};
bool cmpFin(const node& a, const node& b){
    return a.fin > b.fin;
}
int n, m;
int cost[maxN];
node ver[maxN];
bool vis[maxN];
int block[maxN], blockN = 0;
vector<int> rel[maxN], rel1[maxN];
int T = 0;
void dfs(int u){
    vis[u] = true;
    T++;
    for (vector<int>::iterator v = rel[u].begin(); v != rel[u].end(); v++){
        if (!vis[*v]) dfs(*v);
    }
    T++;
    ver[u].fin = T;
}
void dfs1(int u){
    vis[u] = true;
    block[u] = blockN;
    for (vector<int>::iterator v = rel1[u].begin(); v != rel1[u].end(); v++){
        if (!vis[*v]) dfs1(*v);
    }
}
int main ( int argc, char *argv[] ) {
    /*{
    FILE* file = fopen(argv[1], "r");
    int a, b;
    while(fscanf(file, "%d,%d", &a, &b) != EOF){
    }*/
    /*
    getI(T);
    int T;
    FE(cases,1,T){
        printf("Cases #%d: ", cases);
    }
    }*/
    /*
    Solution s = Solution();
     */
    getI(n);
    F(i,0,n) getI(cost[i]);
    getI(m);
    F(i,0,m){
        wez2(x,y);
        x--;
        y--;
        rel[x].push_back(y);
        rel1[y].push_back(x);
    }
    clr(vis, 0);
    F(i,0,n) ver[i].index = i;
    F(i,0,n)if (!vis[i]) dfs(i);



    sort(ver, ver+n, cmpFin);

    clr(vis, 0);
    F(i,0,n){
        if (!vis[ver[i].index]){
            dfs1(ver[i].index);
            blockN++;
        }
    }

    vector<int> minCost(blockN, INT_MAX), conJuns(blockN, 0);
    F(i,0,n){
        int b = block[i];
        if (cost[i] < minCost[b]){
            minCost[b] = cost[i];
            conJuns[b] = 1;
        }else if (cost[i] == minCost[b]){
            conJuns[b] ++;
        }
    }
    ll costTotal = 0, wayTotal = 1;
    F(i,0,blockN){
        costTotal += minCost[i];
        wayTotal = wayTotal * conJuns[i] % 1000000007;
    }
    cout << costTotal << ' ' << wayTotal << endl;
    return EXIT_SUCCESS;
}
