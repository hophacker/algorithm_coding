// PROBLEM STATEMENT
// Aurum Nugget, Inc. has just purchased some new gold mines.  They have a number of miners available to work in the mines, and would like to allocate the miners in such a way as to maximize their profit.  Each mine can support a maximum of 6 miners, and contains a maximum of 6 major ore deposits.  After the miners have been allocated to mines, the company earns (or loses) money as follows: 
If a mine has fewer miners than ore deposits, the company will earn $60 per miner allocated to that mine.
If a mine has the same number of miners as ore deposits, the company will earn $50 per miner allocated to that mine.
If a mine has more miners than ore deposits, the company will earn $50 for each miner up to the number of ore deposits, and will lose $20 for each extra miner allocated to that mine.

Even if it will lose money, the company must employ every available worker at one of its mines.

Write a class GoldMine with a method getAllocation that takes in a vector <string> mines and a int miners.  Each element of mines will be in the form "<p0>, <p1>, <p2>, <p3>, <p4>, <p5>, <p6>" (quotes for clarity) where each <pn> is a three digit number (with leading 0s if necessary.) Each <pn> represents the probability (as a percentage) that n deposits are present in the mine, and all <pn>'s within a mine will always add up to 100. miners is the number of employees the company must allocate.  The method should return a vector <int> indicating the number of miners to place in each mine in order to maximize the expected profit (where element i in the returned vector <int> corresponds to element i of mines).  If there are multiple allocations which maximize expected profit, return the allocation which places more miners in earlier mines.  More specifically, when comparing two different allocations  X0, X1, X2, ..., Xn and Y0, Y1, Y2, ..., Yn that yield the same expected profit, let i be the smallest index such that Xi is not equal to Yi.  Then if Xi > Yi, allocation X0, X1, X2, ..., Xn is preferred to allocation Y0, Y1, Y2, ..., Yn.

For example, suppose the company has 4 miners available, and purchased the following two mines:

	"000, 030, 030, 040, 000, 000, 000"
        "020, 020, 020, 010, 010, 010, 010"


The first mine has a 30 percent chance of containing 1 ore deposit, a 30 percent chance of containing 2 ore deposits, and a 40 percent chance of containing 3 ore deposits.  The second mine has a 20 percent chance of containing 0 ore deposits, a 20 percent chance of containing 1 ore deposit, a 20 percent chance of containing 2 ore deposits, a 10 percent chance of containing 3 ore deposits, a 10 percent chance of containing 4 ore deposits, a 10 percent chance of containing 5 ore deposits, and a 10 percent chance of containing 6 ore deposits.

In this scenario, the company can make the most money by allocating two miners at each mine, yielding an expected profit of 153:

	First Mine
	   0.3*30 + 0.3*100 + 0.4*120 =
           9 + 30 + 48 = 87

	Second Mine
           0.2*(-40) + 0.2*30 + 0.2*100 + 0.1*120 + 0.1*120 + 0.1*120 + 0.1*120 = 
           -8 + 6 + 20 + 12 + 12 + 12 + 12 = 66

	Total Profit
	   87 + 66 = 153


The method would have returned { 2, 2 }.  Other allocations would have yielded:

	{ 0, 4 } :  75
	{ 1, 3 } : 132
	{ 3, 1 } : 129
	{ 4, 0 } :  67



DEFINITION
Class:GoldMine
Method:getAllocation
Parameters:vector <string>, int
Returns:vector <int>
Method signature:vector <int> getAllocation(vector <string> mines, int miners)


NOTES
-Each mine can support a maximum of 6 miners.


CONSTRAINTS
-mines will contain between 1 and 50 elements, inclusive
-each element of mines will contain exactly 33 characters
-each element of mines will contain only digits ('0'-'9'), commas (',') and spaces (' ')
-each element of mines will be in the form "<p0>, <p1>, <p2>, <p3>, <p4>, <p5>, <p6>" (quotes for clarity) where each <pn> is a three digit number (with leading 0s if necessary.) Each <pn> represents the probability (as a percentage) that n deposits are present in the mine, and all <pn>'s within a mine will always add up to 100
-miners will be between 1 and (6 * the number of elements in mines), inclusive


EXAMPLES

0)
{ "000, 030, 030, 040, 000, 000, 000",
  "020, 020, 020, 010, 010, 010, 010" }
4

Returns: { 2,  2 }

This is the example from the problem statement.

1)
{ "100, 000, 000, 000, 000, 000, 000",
  "100, 000, 000, 000, 000, 000, 000",
  "100, 000, 000, 000, 000, 000, 000",
  "100, 000, 000, 000, 000, 000, 000",
  "100, 000, 000, 000, 000, 000, 000" }
8

Returns: { 6,  2,  0,  0,  0 }

There are no deposits in any mines.  However, since the company must employ every available worker, it loses $160 ($20 per worker).  The proper allocation places 6 workers in the first mine and 2 workers in the second mine, since that is the allocation that places more workers in earlier mines and the maximum number of workers a mine can support is 6.

2)
{ "050, 000, 000, 000, 000, 050, 000",
  "050, 000, 000, 000, 000, 050, 000",
  "050, 000, 000, 000, 000, 050, 000",
  "050, 000, 000, 000, 000, 050, 000",
  "050, 000, 000, 000, 000, 050, 000",
  "050, 000, 000, 000, 000, 050, 000",
  "050, 000, 000, 000, 000, 050, 000",
  "050, 000, 000, 000, 000, 050, 000",
  "050, 000, 000, 000, 000, 050, 000",
  "050, 000, 000, 000, 000, 050, 000" }
30

Returns: { 4,  4,  4,  4,  4,  4,  4,  2,  0,  0 }

Each mine has a 50 percent chance of containing no deposits and a 50 percent chance of containing 5 deposits.  The expected value from a mine like this is maximized with 4 workers. Since we allocate workers to earlier mines first, the early mines are filled with 4 workers each, and the remaining 2 miners are placed in the next available mine.

3)
{ "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004" }
56

Returns: { 2,  2,  2,  2,  2,  2,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1 }

4)
{ "100, 000, 000, 000, 000, 000, 000",
  "090, 010, 000, 000, 000, 000, 000",
  "080, 020, 000, 000, 000, 000, 000",
  "075, 025, 000, 000, 000, 000, 000",
  "050, 050, 000, 000, 000, 000, 000",
  "025, 075, 000, 000, 000, 000, 000",
  "020, 080, 000, 000, 000, 000, 000",
  "010, 090, 000, 000, 000, 000, 000",
  "000, 100, 000, 000, 000, 000, 000",
  "000, 090, 010, 000, 000, 000, 000",
  "000, 080, 020, 000, 000, 000, 000",
  "000, 075, 025, 000, 000, 000, 000",
  "000, 050, 050, 000, 000, 000, 000",
  "000, 025, 075, 000, 000, 000, 000",
  "000, 020, 080, 000, 000, 000, 000",
  "000, 010, 090, 000, 000, 000, 000",
  "000, 000, 100, 000, 000, 000, 000",
  "000, 000, 090, 010, 000, 000, 000",
  "000, 000, 080, 020, 000, 000, 000",
  "000, 000, 075, 025, 000, 000, 000",
  "000, 000, 050, 050, 000, 000, 000",
  "000, 000, 025, 075, 000, 000, 000",
  "000, 000, 020, 080, 000, 000, 000",
  "000, 000, 010, 090, 000, 000, 000",
  "000, 000, 000, 100, 000, 000, 000",
  "000, 000, 000, 100, 000, 000, 000",
  "000, 000, 000, 090, 010, 000, 000",
  "000, 000, 000, 080, 020, 000, 000",
  "000, 000, 000, 075, 025, 000, 000",
  "000, 000, 000, 050, 050, 000, 000",
  "000, 000, 000, 025, 075, 000, 000",
  "000, 000, 000, 020, 080, 000, 000",
  "000, 000, 000, 010, 090, 000, 000",
  "000, 000, 000, 000, 100, 000, 000",
  "000, 000, 000, 000, 090, 010, 000",
  "000, 000, 000, 000, 080, 020, 000",
  "000, 000, 000, 000, 075, 025, 000",
  "000, 000, 000, 000, 050, 050, 000",
  "000, 000, 000, 000, 025, 075, 000",
  "000, 000, 000, 000, 020, 080, 000",
  "000, 000, 000, 000, 010, 090, 000",
  "000, 000, 000, 000, 000, 100, 000",
  "000, 000, 000, 000, 000, 090, 010",
  "000, 000, 000, 000, 000, 080, 020",
  "000, 000, 000, 000, 000, 075, 025",
  "000, 000, 000, 000, 000, 050, 050",
  "000, 000, 000, 000, 000, 025, 075",
  "000, 000, 000, 000, 000, 020, 080",
  "000, 000, 000, 000, 000, 010, 090",
  "000, 000, 000, 000, 000, 000, 100" }
150

Returns: { 0,  0,  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  2,  2,  2,  2,  2,  2,  2,  2,  3,  3,  3,  3,  3,  3,  3,  3,  3,  4,  4,  4,  4,  4,  4,  4,  4,  4,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  6,  6 }

#include <sstream>
/*
*/
#define debuging
#ifdef debuging
#define FIN  {freopen("new.in" , "r" , stdin) ;}
#define FOUT {freopen("new.out" , "w" , stdout) ;}
#define OUT(x)  {cout<< #x << "  : " << x <<endl ;}
#define ERR(x)  {cout<<"#error: "<< x ; while(1) ;}
#endif


// END CUT HERE
#ifndef debuging
#define FIN  ;
#define FOUT ;
#define OUT(x)  ;
#define ERR(x)  ;
#endif
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
const int fx[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

using namespace std ;
#define bit(x,i) (x&(1<<i))
#define max(a,b) (a<b?b:a)
#define abs(x) (x<0?-x:x)
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
#define clr(a,x) memset(a,x,sizeof(x))
#define ll long long
#define ui unsigned int
#define us unsigned short
const int maxint = -1u>>2 ;
const double eps = 1e-6 ; 
class GoldMine
{
    public:
        vector <int> getAllocation(vector <string> mines, int miners)
        {


            return vector <int>() ;
        }

        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = { "000, 030, 030, 040, 000, 000, 000",
  "020, 020, 020, 010, 010, 010, 010" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arr2[] = { 2,  2 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, getAllocation(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = { "100, 000, 000, 000, 000, 000, 000",
  "100, 000, 000, 000, 000, 000, 000",
  "100, 000, 000, 000, 000, 000, 000",
  "100, 000, 000, 000, 000, 000, 000",
  "100, 000, 000, 000, 000, 000, 000" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; int Arr2[] = { 6,  2,  0,  0,  0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, getAllocation(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = { "050, 000, 000, 000, 000, 050, 000",
  "050, 000, 000, 000, 000, 050, 000",
  "050, 000, 000, 000, 000, 050, 000",
  "050, 000, 000, 000, 000, 050, 000",
  "050, 000, 000, 000, 000, 050, 000",
  "050, 000, 000, 000, 000, 050, 000",
  "050, 000, 000, 000, 000, 050, 000",
  "050, 000, 000, 000, 000, 050, 000",
  "050, 000, 000, 000, 000, 050, 000",
  "050, 000, 000, 000, 000, 050, 000" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 30; int Arr2[] = { 4,  4,  4,  4,  4,  4,  4,  2,  0,  0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, getAllocation(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = { "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 56; int Arr2[] = { 2,  2,  2,  2,  2,  2,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, getAllocation(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = { "100, 000, 000, 000, 000, 000, 000",
  "090, 010, 000, 000, 000, 000, 000",
  "080, 020, 000, 000, 000, 000, 000",
  "075, 025, 000, 000, 000, 000, 000",
  "050, 050, 000, 000, 000, 000, 000",
  "025, 075, 000, 000, 000, 000, 000",
  "020, 080, 000, 000, 000, 000, 000",
  "010, 090, 000, 000, 000, 000, 000",
  "000, 100, 000, 000, 000, 000, 000",
  "000, 090, 010, 000, 000, 000, 000",
  "000, 080, 020, 000, 000, 000, 000",
  "000, 075, 025, 000, 000, 000, 000",
  "000, 050, 050, 000, 000, 000, 000",
  "000, 025, 075, 000, 000, 000, 000",
  "000, 020, 080, 000, 000, 000, 000",
  "000, 010, 090, 000, 000, 000, 000",
  "000, 000, 100, 000, 000, 000, 000",
  "000, 000, 090, 010, 000, 000, 000",
  "000, 000, 080, 020, 000, 000, 000",
  "000, 000, 075, 025, 000, 000, 000",
  "000, 000, 050, 050, 000, 000, 000",
  "000, 000, 025, 075, 000, 000, 000",
  "000, 000, 020, 080, 000, 000, 000",
  "000, 000, 010, 090, 000, 000, 000",
  "000, 000, 000, 100, 000, 000, 000",
  "000, 000, 000, 100, 000, 000, 000",
  "000, 000, 000, 090, 010, 000, 000",
  "000, 000, 000, 080, 020, 000, 000",
  "000, 000, 000, 075, 025, 000, 000",
  "000, 000, 000, 050, 050, 000, 000",
  "000, 000, 000, 025, 075, 000, 000",
  "000, 000, 000, 020, 080, 000, 000",
  "000, 000, 000, 010, 090, 000, 000",
  "000, 000, 000, 000, 100, 000, 000",
  "000, 000, 000, 000, 090, 010, 000",
  "000, 000, 000, 000, 080, 020, 000",
  "000, 000, 000, 000, 075, 025, 000",
  "000, 000, 000, 000, 050, 050, 000",
  "000, 000, 000, 000, 025, 075, 000",
  "000, 000, 000, 000, 020, 080, 000",
  "000, 000, 000, 000, 010, 090, 000",
  "000, 000, 000, 000, 000, 100, 000",
  "000, 000, 000, 000, 000, 090, 010",
  "000, 000, 000, 000, 000, 080, 020",
  "000, 000, 000, 000, 000, 075, 025",
  "000, 000, 000, 000, 000, 050, 050",
  "000, 000, 000, 000, 000, 025, 075",
  "000, 000, 000, 000, 000, 020, 080",
  "000, 000, 000, 000, 000, 010, 090",
  "000, 000, 000, 000, 000, 000, 100" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 150; int Arr2[] = { 0,  0,  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  2,  2,  2,  2,  2,  2,  2,  2,  3,  3,  3,  3,  3,  3,  3,  3,  3,  4,  4,  4,  4,  4,  4,  4,  4,  4,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  6,  6 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, getAllocation(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main(){
    GoldMine ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
