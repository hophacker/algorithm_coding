// PROBLEM STATEMENT
// 
Two sequences A and B are called similar if they have the same length and have the following property: we can obtain two identical sequences by deleting at most two elements of A and at most two elements of B. (The elements deleted from A don't have to have the same indices as the elements deleted from B. The order of the remaining elements in each sequence has to be preserved.)


You are given ints N and bound.
Consider all the sequences with length N such that each element is an integer between 1 and bound, inclusive.
Compute the number of ordered pairs of such sequences that are similar.
Return this count modulo 1,000,000,009.



DEFINITION
Class:SimilarSequencesAnother
Method:getCount
Parameters:int, int
Returns:int
Method signature:int getCount(int N, int bound)


CONSTRAINTS
-N will be between 1 and 100, inclusive.
-bound will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
2
10

Returns: 10000

Any two 2-element sequences are similar. There are (10^2)^2 = 10,000 pairs of such sequences.

1)
3
3

Returns: 687

In this case, two sequences are similar if they have at least one element in common.
In other words, the two sequences are similar if there is a value that occurs in each of them.

Let's count the pairs of sequences that are not similar.
There are two possibilities:

Each sequence contains the same value three times. For example, one sequence could be {1,1,1} and the other {3,3,3}. There are 6 such pairs.
One sequence contains the same value three times, and the other contains the other two values,
each of them at least once.
For example, one sequence could be {2,3,2} and the other {1,1,1}.
There are 2 * 3 * (2^3 - 2) = 36 such pairs.


Thus, the total number of pairs of similar sequences is 3^6 - 6 - 36 = 687.

2)
8
1

Returns: 1



3)
100
123456789

Returns: 439681851



4)
1
1000000000

Returns: 81




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
const int maxint = -1u>>2 ;
const double eps = 1e-6 ; 
class SimilarSequencesAnother
{
    public:
        int getCount(int N, int bound)
        {


            return int() ;
        }

        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 10; int Arg2 = 10000; verify_case(0, Arg2, getCount(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 687; verify_case(1, Arg2, getCount(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 8; int Arg1 = 1; int Arg2 = 1; verify_case(2, Arg2, getCount(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 100; int Arg1 = 123456789; int Arg2 = 439681851; verify_case(3, Arg2, getCount(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 1000000000; int Arg2 = 81; verify_case(4, Arg2, getCount(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main(){
    SimilarSequencesAnother ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
