#define debug
#undef outputNo

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



// debug and outputNo=>impossible
// debug => right answers
int  R, C, M;
bool printNo(){
#ifdef debug
#ifdef outputNo
    cout << R << ' ' << C << ' ' << M << endl;
    return true; 
#endif
    return true; 
#endif
    printf("Impossible\n");
    return true;
}
char board[50][50];
bool printAns(int R, int C, int M, int c){
    F(i,0,R){
        F(j,0,C)
            if (i == 0 && j == 0){
                board[i][j] = 'c';
                M--;
            }
            else if (M > 0 && j < c){ 
                board[i][j] = '.';
                M--;
            }else  board[i][j] = '*';
        }
    return true;
}
bool printIt(int R, int C, int M, int c, bool rev){
#ifdef debug
#ifdef outputNo
    return true;
#endif
    if (!rev) cout << R << ' ' << C << ' ' << M << endl;
    else cout << C << ' ' << R << ' ' << M << endl;
#endif 
    printAns(R,C,M,c);
    if (rev){
        for (int i = 0; i < C; i++){
            for (int j = 0; j < R; j++) printf("%c", board[j][i]);
            printf("\n");
        }
    }else{
        for (int i = 0; i < R; i++){
            for (int j = 0; j < C; j++) printf("%c", board[i][j]);
            printf("\n");
        }
    }
    return true;
}
void printSquare(int R){
#ifdef debug

#ifdef outputNo
    return;
#endif
    cout << R << ' ' << C << ' ' << M << endl;
#endif
    for (int i = 0; i < R; i++){
        for (int j = 0; j < R; j++){
            if (i == 0 && j == 0) printf("c");
            else if ((i != 0 && i != R-1) || (i == 0 && j <= R/2) || (i == R-1 && j >= R/2)) 
                printf(".");
            else printf("*");

        }
        printf("\n");
    }
}
void print1(int R, int C){
#ifdef debug

#ifdef outputNo
    return;
#endif
    cout << R << ' ' << C << ' ' << M << endl;
#endif
    F(i,0,R){
        F(j,0,C)
            if (i == 0 && j == 0) printf("c");
            else printf("*");
        printf("\n");
    }
}
void print4(){
#ifdef debug
#ifdef outputNo
    return;
#endif
    cout << R << ' ' << C << ' ' << M << endl;
#endif
    F(i,0,4){
        F(j,0,4)
            if (i == 0 && j == 0) printf("c");
            else if (i == 3 && j == 3 ||
                    i == 3 && j == 2 ||
                    i == 2 && j == 3) 
                printf("*");
            else printf(".");
        printf("\n");
    }
}
bool edgecases(int R, int C, int M){
    bool rev = false;
    if(M == 1){
        print1(R, C);
        return true;
    }
    if (C>R) {
        swap(R,C);
        rev = true;
    }
    if (C == 1){
        if (R == 1){
            // M == 1
            return printAns(C, R, M, 1);
        }else{
            if (M == 1) return printNo();
            else return printIt(R,C,M,1,rev);
        }
    }else if (C == 2){
        if (M % 2 == 0 && M >= 4){
            return printIt(R,C,M,2,rev);
        }else return printNo();
    }else{
        if (R == C && R >= 4 && M + C-1 == C*C){
            if (R == 4)
                print4();
            else printSquare(R);
            return true;
        }
    }
    return false;
}
void doIt(int R,int C,int M, bool rev, bool &ok){
    for (int c = C; c >= 2; c--){
        int r = (M-1)/c+1;
        if (r > R) break; // outrange of row
        if (r == 1) continue;
        else if (r == 2){
            if (c*r != M) continue;
            else{
                ok = true;
                printIt(R,C,M,c,rev);
                break;
            }
        }else{
            if (((M-1) % c + 1) >= 2){
                ok = true;
                printIt(R,C,M,c,rev);
                break;
            } 
        }
    }
}
int main ( int argc, char *argv[] ) {
    int cases = 0;
    whileZ{
#ifndef debug
        printf("Case #%d:\n", ++cases);
#endif
        getIII(R,C,M);
        M = R*C - M;
        if (edgecases(R,C,M)) continue;
        //min(C,R) >= 3
        bool ok = false;
        doIt(R,C,M,false,ok);
        if (!ok) doIt(C,R,M,true,ok);
        if (!ok) printNo();
    }
    return EXIT_SUCCESS;
}
