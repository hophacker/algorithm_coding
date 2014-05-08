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
#define ull unsigned ll
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
#define printV(a) printA(a,0,(int)a.size()-1);
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
const int fx[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

struct node{
    double avg;
    ull types;
    node(){};
    node(double a, ull t):avg(a),types(t){};
};

ull C[41][41];
void prepare(){
    C[1][0] = C[1][1] = 1;
    FE(n,2,40){
        C[n][0] = 1;
        FE(k,1,n)
            C[n][k] = C[n-1][k-1] + C[n-1][k];
    }
}
node f[2][41][41];

void printNode(int pre, int bTotalNum, int cNum){
    cout << bTotalNum << ' ' << cNum << ':' << f[pre][bTotalNum][cNum].types << ' ' << f[pre][bTotalNum][cNum].avg << endl;
}

int main ( int argc, char *argv[] ) {
    prepare();
    whileZ{
        wez2(n,m);
        vector<int> price(40,0);
        vector<double> avgP(40, 0);
        F(i,0,n){
            wez2(c, p);
            c--;
            price[c]++;
            avgP[c] += p;
        }
        int pN = 0;
        F(i,0,40)if (price[i]){
            price[pN] = price[i];
            avgP[pN] = avgP[i];
            pN++;
        }
        F(i,0,pN) avgP[i] /= price[i];

        FE(i,0,n)
            FE(j,0,pN) f[1][i][j] = node(0,0);

        f[1][0][0].types = 1;
        f[1][0][0].avg = 0;

        F(i,0,pN){
            memcpy(f[0], f[1], sizeof(f[1]));

            FE(bNum, 1, price[i]){
                FE(bTotalNum,0,n)
                    FE(cNum,0,pN) if (f[0][bTotalNum][cNum].types){
                        double avg = f[0][bTotalNum][cNum].avg + bNum * avgP[i];
                        ull types = f[0][bTotalNum][cNum].types * C[price[i]][bNum];
                        node fPre = f[1][bTotalNum+bNum][cNum+1];
                        f[1][bTotalNum+bNum][cNum+1] = node((avg*types + fPre.avg * fPre.types)/(types+fPre.types), types+fPre.types);
                    }
            }

/*             cout << i << "---------------------" << endl;
 *             FE(bTotalNum,0,n)
 *                 FE(cNum,0,pN) 
 *                     printNode(1, bTotalNum, cNum);
 */


        }
        ull types = 0;
        double totalScore = 0;
        FE(i,m,pN){
            FE(j,i,n){
                types += f[1][j][i].types;
                totalScore += f[1][j][i].types * f[1][j][i].avg;
            }
        }
        if (types == 0) printf("0\n");
        else printf("%.10lf\n", totalScore/types);
    }
    return EXIT_SUCCESS;
}


