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
#define printV(a) printA(a,0,(int)a.size()-1);
#define printVV(a) F(i,0,a.size()) {F(j,0,a[i].size())cout << a[i][j] << ' '; cout << endl;}
#define MAXN 10000
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define tiny ((double) 1e-15)
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
vector<char> divd;
map<vector<char>, double> r_pro;
double calc3(int total, bool win){
    if (total == 0){
        if (win) return 0;
        else return 1;
    }
    auto i = r_pro.find(divd);
    if (i != r_pro.end()){
        if (win) return i->second;
        else return 1 - i->second;
    }
    char mac = divd[8];
    double pro = 0;
    F(i,0,8)if (divd[i] > 0){
        double portion = 1.0 * divd[i] / total;
        if (mac & i){
            divd[i]--;
            divd[8] = mac & i;
            pro += portion * calc3(total-1, !win);
            divd[8] = mac;
            divd[i]++;
        }else{
            if (!win) pro += portion;
        }
    }
    if (win) r_pro[divd] = pro;
    else r_pro[divd] = 1-pro;
    return pro;
}
int main ( int argc, char *argv[] ) {
    int primeA[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    int A[101];
    vector<int> primeV(primeA, primeA+sizeof(primeA)/4);
/*     printf("%.6lf\n", tiny);
 *     return 0;
 */

    whileZ{
        wez(n);
        F(i,0,n) getI(A[i]);
        double win = 0;
        bool sureWin = false;
        F(cho,0,n){
            if (A[cho] == 1) continue;
            vector<int> primeFac;
            vector<int> fac;
            F(i,0,primeV.size())if (A[cho] % primeV[i] == 0){
                primeFac.push_back(primeV[i]);
            }
            F(i, 0, 1 << (primeFac.size())){
                int f = 1;
                F(b,0,primeFac.size()) if (bit(i,b)){
                    f *= primeFac[b];
                }
                fac.push_back(f);
            }
            divd = vector<char>(9,0);
            F(t,0,n) if (t != cho){
                FFE(i,fac.size()-1,0)
                    if (A[t] % fac[i] == 0){ 
                        divd[i]++;
                        break;
                    }
            }
            divd[8] = fac.size()-1;
            double oppoLose = calc3(n-1, false);
            if (close(oppoLose, 1.0)) sureWin = true;
            win += oppoLose;
        }
        printf("%d %.4lf\n", sureWin, win/n);
    }
    return EXIT_SUCCESS;
}

/* double F1[101][101][2];
* double F2[101][101][101][2];
*     F1[0][0][0] = 1;
 *     F1[0][0][1] = 0;
 *     FE(i,0,100) FE(j,0,100) if (i+j != 0 && i+j <= 100){
 *         F1[i][j][0] = F1[i][j][1] = 0;
 *         double total = i + j;
 *         if (i == 0){
 *             F1[i][j][1] = 0;
 *             F1[i][j][0] = 1;
 *         }else{
 *             F1[i][j][1] = (i/total) * F1[i-1][j][0];
 *             F1[i][j][0] = (i/total) * F1[i-1][j][1];
 *             if (j > 0){
 *                 F1[i][j][0] += (j/total);
 *             }
 *         }
 *     }
 *     F2[0][0][0][0] = 1;
 *     F2[0][0][0][1] = 0;
 *     FE(ij,0,100) FE(i,0,100) FE(j,0,100) if (ij+i+j != 0 && ij+i+j <= 100){
 *         F2[ij][i][j][0] = F2[ij][i][j][1] = 0;
 *         double total = i+j+ij;
 *         if (ij > 0){
 *             F2[ij][i][j][1] += (ij/total) * F2[ij-1][i][j][0];
 *             F2[ij][i][j][0] += (ij/total) * F2[ij-1][i][j][1];
 *         }
 *         if (i > 0){
 *             F2[ij][i][j][1] += (i/total) * F1[i-1][j][0]; 
 *             F2[ij][i][j][0] += (i/total) * F1[i-1][j][1]; 
 *         }
 *         if (j > 0){
 *             F2[ij][i][j][1] += (j/total) * F1[j-1][i][0]; 
 *             F2[ij][i][j][0] += (j/total) * F1[j-1][i][1]; 
 *         }
 *     }
 */
