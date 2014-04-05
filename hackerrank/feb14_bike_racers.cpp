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
#define printA(a,L,R) FE(i,L,R) cout << a[i] << (i==R?'\n':' ')
#define printV(a) printA(a,0,a.size()-1)
template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){F(i,0,SZ(t))s<<t[i]<<" ";return s; }
struct node{
    int x, y;
}man[250], bike[250];
inline ll sqr(int x){
    return (ll)x * (ll)x;
}
inline ll distan(int i, int j){
    return sqr(man[i].x - bike[j].x) + sqr(man[i].y - bike[j].y);
}
vector<int> link[250];
bool visited[250];
int mMan[250], mBike[250];
int N,M,K;
int path(int u){
    F(i,0,link[u].size()){
        int v = link[u][i];
        if (!visited[v]){
            visited[v] = 1;
            if (mBike[v] == -1 || path(mBike[v])){
                mMan[u] = v;
                mBike[v] = u;
                return 1;
            }
        }
    }
    return 0;
}
int maxMatch(){
    clr(mMan, -1);
    clr(mBike, -1);
    int res = 0;
    F(i,0,N){
        if (mMan[i] == -1){
            clr(visited, 0);
            res += path(i);
        }
    }
    return res;
}
int main ( int argc, char *argv[] ) {
    getIII(N,M,K);
    F(i,0,N) getII(man[i].x, man[i].y);
    F(i,0,M) getII(bike[i].x, bike[i].y);
    vector<ll> dis;
    F(i,0,N) F(j,0,M)
        dis.push_back(distan(i,j));
    //printA(dis, 0, dis.size()-1);
    sort(dis.begin(), dis.end());
    //printA(dis, 0, dis.size()-1);
    F(t,0,dis.size()){
        F(i,0,N) link[i].clear();
        if (t == 0 || dis[t] != dis[t-1]){
            F(i,0,N) F(j,0,M) if (distan(i,j) <= dis[t]) {
                link[i].push_back(j);
            }
        }
        //F(i,0,N) cout << ' ' << (link[i].size());
        //cout << endl;
        if (maxMatch() >= K){
            cout << dis[t] << endl;
            break;
        }
    }
        
    return EXIT_SUCCESS;
}
