// BEGIN CUT HERE
#define debuging
#ifdef debuging
#define FIN  {freopen("new.in" , "r" , stdin) ;}
#define FOUT {freopen("new.out" , "w" , stdout) ;}
#define OUT(x)  {cout<< #x << "  : " << x <<endl ;}
#define ERR(x)  {cout<<"#error: "<< x ; while(1) ;}
#endif
#ifndef debuging
#define FIN  ;
#define FOUT ;
#define OUT(x)  ;
#define ERR(x)  ;
#endif
// END CUT HERE
#include <sstream>
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
#define printVV(a) F(i,0,a.size()) {F(j,0,(int)a[i].size())cout << a[i][j] << ' '; cout << endl;}
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
const int maxint = -1u>>2 ;
const double eps = 1e-6 ; 
class NarrowPassage
{
struct node{
    int a, b;
    node(int aa, int bb):a(aa), b(bb){
    }
    bool operator < (const node& other)const{
        return b < other.b;
    }
};
    private:
        int n;
        vector<int> fat;
    public:

        int father(int x){
            if (fat[x] != x)
                fat[x] = father(x);
            else return fat[x];
        }
        void combine(int a, int b){
            int fa = father(a);
            int fb = father(b);
            fat[fb] = fa;
        }
        int minDist(int L, vector <int> a, vector <int> b)
        {
            n = a.size();
            vector<node> T;
            F(i,0,n) T.push_back(node(a[i], b[i]));
            sort(T.begin(), T.end());

            fat = vector<int>(n);
            F(i,0,n) fat[i] = i;

            F(i,0,n)
                F(j,i+1,n) if (T[i].a > T[j].a){
                    combine(i,j);
                }

            int i = 0;
            while(i < n && T[i].a > T[i+1].a && T[i].b < T[i+1].b) i++;

        }

        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arr1[] = {1, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3, 4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4; verify_case(0, Arg3, minDist(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 10; int Arr1[] = {3, 9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {8, 6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 14; verify_case(1, Arg3, minDist(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 265467; int Arr1[] = {133548, 103861, 29821, 199848, 92684, 219824, 215859, 62821, 172409, 109235,
38563, 148854, 24742, 174068, 205005, 75922, 87316, 5542, 57484, 40792,
25229, 152216, 21547, 22203, 84712, 231522, 235703, 184895, 100787, 174440,
156904, 84898, 185568, 108732, 260098, 89488, 221604, 104555, 165775, 90444,
81952, 149671, 209674, 22185, 45420, 41928, 16098, 65324, 90870, 35243}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {150289, 135139, 69841, 227226, 177427, 230314, 199175, 81572, 220468, 151049,
40009, 145963, 115246, 252932, 263651, 38434, 120096, 69576, 29789, 115046,
33310, 260771, 5723, 80733, 107864, 142447, 235490, 242149, 124564, 134602,
245962, 7078, 215816, 219864, 190499, 210237, 212894, 142760, 126472, 201935,
119308, 120211, 235235, 19446, 87314, 17286, 61990, 102050, 261812, 257}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 7148670; verify_case(2, Arg3, minDist(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 1000000; int Arr1[] = {706292, 756214, 490048, 228791, 567805, 353900, 640393, 562496, 217533, 934149,
938644, 127480, 777134, 999144, 41485, 544051, 417987, 767415, 971662, 959022,
670563, 34065, 518183, 750574, 546576, 207758, 159932, 429345, 670513, 271901,
476062, 392721, 774733, 502586, 915436, 120280, 951729, 699859, 581770, 268966,
79392, 888601, 378829, 350198, 939459, 644983, 605862, 721305, 269232, 137587}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {322468, 673534, 83223, 551733, 341310, 485064, 885415, 927526, 159402, 28144,
441619, 305530, 883149, 413745, 932694, 214862, 677401, 104356, 836580, 300580,
409942, 748444, 744205, 119051, 999286, 462508, 984346, 887773, 856655, 245559,
418763, 840266, 999775, 962927, 779570, 488394, 760591, 326325, 206948, 13999,
285467, 401562, 786209, 169847, 171326, 2901, 296531, 572035, 364920, 939046}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 45670501; verify_case(3, Arg3, minDist(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main(){
    NarrowPassage ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
