#include <cmath>
#include <list>
#include <climits>
#include <queue>
#include <vector>
#include <map>
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
#define printV(a) printA(a,0,a.size()-1)
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
const int fx[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
class Solution {
public:

#define NOT_INT 0
#define EMPTY_INT 1
#define INT 2
    int isInt(string s){
        if (s.length() == 0) return EMPTY_INT;
        if (s[0] == '-' || s[0] == '+'){
            return isUnsigned(s.substr(1));
        }
        else return isUnsigned(s.substr(0));
    }
#define NOT_UNSIGNED 0
#define EMPTY_UNSIGNED 1
#define UNSIGNED 2
    int isUnsigned(string s){
        if (s.length() == 0) return EMPTY_UNSIGNED;
        for (int i = 0; i < s.length(); i++){
            if (!isdigit(s[i])) return NOT_UNSIGNED;
        }
        return UNSIGNED;
    }
    bool isFloat(string s){
        int idot = s.find_first_of('.');
        if (idot == string::npos){
            return isInt(s) == INT;
        }else{ 
            int i = isInt(s.substr(0,idot)),
                f = isUnsigned(s.substr(idot+1));
            return (i == EMPTY_INT && f == UNSIGNED 
                    || i == INT && f == EMPTY_UNSIGNED 
                    || i == INT && f == UNSIGNED);
        }
    }
    bool isNumber(const char *s) {
        string S = string(s);
        int ie = S.find_first_of('e');
        if (ie != string::npos){
            int iL = ie-1, iR = ie+1;

            while(iL >= 0 && !isblank(S[iL])) iL--;
            while(iR < S.length() && !isblank(S[iR])) iR++;

            for (int i = 0; i < iL; i++) 
                if (!isblank(S[i])) return false;
            for (int i = iR; i < S.length(); i++) 
                if (!isblank(S[i])) return false;

            iL++, iR--;
            if (iL == ie || iR == ie) return false;
            
            if (ie != string::npos){
                string fs = S.substr(iL, ie-iL),
                       is = S.substr(ie+1, iR-ie);
                if (isFloat(fs) && isInt(is) == INT){
                    //if (atoi(fs.c_str()) == 0 && atoi(is.c_str()) < 0) return false;
                    return true;
                } else return false;
            }else return isFloat(S.substr(iL, iR-iL+1));
        }
        else{
            int iL = 0, iR = S.length()-1;
            while(iL < S.length() && isblank(s[iL]))  iL++;
            while(iR >= 0 && isblank(s[iR])) iR--;
            if (iL > iR) return false;
            else return isFloat(S.substr(iL, iR-iL+1));
        }
    }
};
int main ( int argc, char *argv[] ) {
    cout << (Solution().isNumber(" .789866e-3 ") ==1) << endl;
    cout << (Solution().isNumber(" .-4 ") ==0) << endl;
    cout << (Solution().isNumber(" +.8 ") == 1) << endl;
    cout << (Solution().isNumber("0..")  == 0) << endl;
    cout << (Solution().isNumber("abc") == 0) << endl;
    cout << (Solution().isNumber("1 a") == 0) << endl;
    cout << (Solution().isNumber("2e10")  == 1) << endl;
    cout << (Solution().isNumber("0") == 1) << endl;
    cout << (Solution().isNumber(" . ") == 0) << endl;
    cout << (Solution().isNumber(" e ") == 0) << endl;
    cout << (Solution().isNumber(" 3. ") == 1) << endl;
    cout << (Solution().isNumber(" .1 ") == 1) << endl;
    cout << (Solution().isNumber(" 0.1 ") == 1) << endl;
    return EXIT_SUCCESS;
}
