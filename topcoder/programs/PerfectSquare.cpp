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
#define clr(a,x) memset(a,x,sizeof(x))
#define ll long long
#define ui unsigned int
#define us unsigned short
const int maxint = -1u>>2 ;
const double eps = 1e-6 ; 
class PerfectSquare
{
    public:
        int ways(vector <int> x)
        {


            return int() ;
        }

        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 1,
 1, 2}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, ways(Arg0)); }
	void test_case_1() { int Arr0[] = {620, 620,
 620, 620}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, ways(Arg0)); }
	void test_case_2() { int Arr0[] = {1, 2, 3,
 4, 5, 6,
 7, 8, 9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, ways(Arg0)); }
	void test_case_3() { int Arr0[] = {2, 2, 2, 2, 2,
 2, 2, 2, 2, 2,
 2, 2, 2, 2, 2,
 2, 2, 2, 2, 2,
 2, 2, 2, 2, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, ways(Arg0)); }
	void test_case_4() { int Arr0[] = {2, 3, 4, 5,
 6, 7, 8, 9,
 10,11,12,13,
 14,15,16,17}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(4, Arg1, ways(Arg0)); }
	void test_case_5() { int Arr0[] = {9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,
 9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,
 9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,
 9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,
 9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,
 9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,
 9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,
 9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,
 9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,
 9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 993282280; verify_case(5, Arg1, ways(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main(){
    PerfectSquare ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
