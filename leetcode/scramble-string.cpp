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
#define printM(a,n,m) F(i,0,n){ F(j,0,m) cout << a[i][j] << ' '; cout << endl;}
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
private: 
    string s1, s2;
    vector<vector<vector<char> > > ok;
public:
    bool isScrambleRecursive(string s1, string s2){
        if (s1.length() == 1) return s1[0] == s2[0];
        int n = s1.length();
        vector<int> numChar(26,0);
        for (int i = 0; i < n; i++) 
            numChar[s1[i]-'a']++, numChar[s2[i]-'a']--;
        for (int i = 0; i < 26; i++) if (numChar[i] != 0) return false;
        for (int i = 1; i < n; i++)
            if (isScrambleRecursive(s1.substr(0,i), s2.substr(0,i)) && isScrambleRecursive(s1.substr(i), s2.substr(i)) ||
                isScrambleRecursive(s1.substr(0,i), s2.substr(n-i)) && isScrambleRecursive(s1.substr(i), s2.substr(0,n-i)) ) 
                return true;
        return false;
    }
    bool isScrambleRecursive(int L1, int L2, int len){
        if (len == 1) return s1[L1] == s2[L2];
        if (ok[len][L1][L2] != -1) return ok[len][L1][L2];
        vector<int> numChar(26,0);
        for (int i = 0; i < len; i++) numChar[s1[L1+i]-'a']++, numChar[s2[L2+i]-'a']--;
        for (int i = 0; i < 26; i++) if (numChar[i] != 0) return false;
        for (int i = 1; i < len; i++)
            if (isScrambleRecursive(L1, L2, i) && isScrambleRecursive(L1+i, L2+i, len-i) ||
                isScrambleRecursive(L1, L2+len-i, i) && isScrambleRecursive(L1+i, L2, len-i)) {
                return ok[len][L1][L2] = 1;
            }
        return ok[len][L1][L2] = 0;
    }
    bool isScramble(string s1, string s2) {
        if (s1.length() != s2.length()) return false;
        int n = s1.length();
        if (n == 0) return true;
        this->s1 = s1;
        this->s2 = s2;
        ok = vector<vector<vector<char> > > (n+1, vector<vector<char> >(n, vector<char>(n, -1)));
        return isScrambleRecursive(0, 0, s1.length());
    }
};
int main ( int argc, char *argv[] ) {
    Solution s = Solution();
    cout << s.isScramble("rgeat", "great") << endl;
    return EXIT_SUCCESS;
}
