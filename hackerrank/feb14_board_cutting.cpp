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
template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){F(i,0,SZ(t))s<<t[i]<<" ";return s; }
bool cmp(const ll x, const ll y){
    return x > y;
}
const ll MOD = 1000000007;
int main ( int argc, char *argv[] ) {
    whileZ{
        int n, m;
        getII(m,n);
        ll x[n], y[m];
        ll sumX = 0, sumY = 0;
        F(i,0,m-1) {
            cin >> y[i];
            sumY += y[i];
        }
        F(i,0,n-1) {
            cin >> x[i];
            sumX += x[i];
        }
        sort(x, x+n-1, cmp);
        sort(y, y+m-1, cmp);
        x[n-1] = y[m-1] = 0;
        //printA(x, 0, n-2);
        //printA(y, 0, m-2);
        int i = 0, j = 0;
        ll res = 0;
        while(i < n-1 && j < m-1){
            if (x[i] > y[j]){
                res = (res + x[i] * (j+1)) % MOD;
                i++;
           //     sumX -= x[i++];
            }else{
                res = (res + y[j] * (i+1)) % MOD;
                j++;
            //    sumY -= y[j++];
            }
        }
        F(k,i,n-1) res = (res + x[k] * m) % MOD;
        F(k,j,m-1) res = (res + y[k] * n) % MOD;
        cout << res << endl;
    }
    return EXIT_SUCCESS;
}
