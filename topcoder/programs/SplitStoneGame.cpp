// PROBLEM STATEMENT
// 
Shiny likes to play games.
Her favorite games are games with pebbles (small stones).
Today, she is playing such a game with her friend Lucy.

Initially, there are N piles of stones.
You are given a vector <int> number with N elements.
Each element of number is the number of stones in one of the piles.

The players take alternating turns.
Shiny plays first.
In each turn, the current player must:

Choose a pile X that has at least two stones.
Split the chosen pile X into two non-empty parts A and B. (The parts can have arbitrary sizes, as long as both are non-empty.)
Choose two piles Y and Z. (Y and Z must be different non-empty piles other than X.)
Add all stones from A to the pile Y, and all stones from B to the pile Z.


For example, if the current piles are {1, 2, 50}, the current player could:

Choose the pile with 50 stones as X.
Split it into two parts with 25 stones each.
Choose the other two piles (the ones with 1 and 2 stones) to be Y and Z.
Add all stones from A to the pile Y, and all stones from B to the pile Z. At the end of the turn, there are two piles of stones: one with 26 and one with 27 stones.


The player who cannot make a valid move loses the game.
Assume that both players play the game optimally.
Return the string "WIN" (quotes for clarity) if Shiny wins the game, and "LOSE" if she does not.


DEFINITION
Class:SplitStoneGame
Method:winOrLose
Parameters:vector <int>
Returns:string
Method signature:string winOrLose(vector <int> number)


CONSTRAINTS
-number will contain between 1 and 50 elements, inclusive.
-Each element of number will be between 1 and 50, inclusive.


EXAMPLES

0)
{1, 1, 1}

Returns: "LOSE"

Shiny can't choose a pile X that has at least two stones, so she loses.

1)
{2, 2}

Returns: "LOSE"

After Shiny chooses one of the piles as X and splits it into two piles with one stone each, she is
unable to choose Y and Z, because there is only one pile left to choose from at the moment. Thus,
she cannot make a valid move and therefore she loses the game.

2)
{1, 1, 2}

Returns: "WIN"

Shiny can choose the last pile as X, split it into 1+1 stone, and add those stones to the other two
piles. This is a valid move that produces two piles with two stones each, and it is now Lucy's turn. 
As we saw in Example 1, Lucy now has no valid move left, thus she loses the game and Shiny is the
winner.

3)
{1, 2, 3, 4, 3, 2, 2, 4, 3, 1, 4, 4, 1, 2, 4, 4, 1, 4, 3, 1, 4, 2, 1}

Returns: "WIN"



4)
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 3, 1, 9, 1, 3, 1, 1, 1, 1, 1}

Returns: "LOSE"




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
class SplitStoneGame
{
    public:
        string winOrLose(vector <int> number)
        {


            return string() ;
        }

        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "LOSE"; verify_case(0, Arg1, winOrLose(Arg0)); }
	void test_case_1() { int Arr0[] = {2, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "LOSE"; verify_case(1, Arg1, winOrLose(Arg0)); }
	void test_case_2() { int Arr0[] = {1, 1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "WIN"; verify_case(2, Arg1, winOrLose(Arg0)); }
	void test_case_3() { int Arr0[] = {1, 2, 3, 4, 3, 2, 2, 4, 3, 1, 4, 4, 1, 2, 4, 4, 1, 4, 3, 1, 4, 2, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "WIN"; verify_case(3, Arg1, winOrLose(Arg0)); }
	void test_case_4() { int Arr0[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 3, 1, 9, 1, 3, 1, 1, 1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "LOSE"; verify_case(4, Arg1, winOrLose(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main(){
    SplitStoneGame ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
