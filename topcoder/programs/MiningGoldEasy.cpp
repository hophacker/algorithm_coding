// PROBLEM STATEMENT
// You are a goblin miner.
Your job is to mine gold.

Picture yourself located in a mine.
The mine can be seen as a rectangular grid of (N+1) times (M+1) cells.
Rows are numbered 0 through N, columns 0 through M.

You will work in the mine for several days.
You can choose the cell where you will work today (on day 0).
On each of the next days, you can either stay in the cell where you were on the previous day, or you can move to any other cell in the same row or in the same column.

Whenever somebody discovers gold in the mine, each goblin profits!
Your profit is N + M, minus your Manhattan distance from the cell where the gold was discovered.
Formally, if the gold is discovered at (a, b) and you are located at (c, d), your profit is N + M - |a-c| - |b-d|, where || denotes absolute value.

You are given the ints N and M.
You are also given two vector <int>s: event_i and event_j.
Both will contain the same number of elements.
Assume that for each valid k, there will be exactly one gold discovery on day k: in the cell (event_i[k], event_j[k]).

Compute and return the maximum total profit you can get by correctly choosing the cells where you work on each day.

DEFINITION
Class:MiningGoldEasy
Method:GetMaximumGold
Parameters:int, int, vector <int>, vector <int>
Returns:int
Method signature:int GetMaximumGold(int N, int M, vector <int> event_i, vector <int> event_j)


CONSTRAINTS
-N and M will be between 1 and 1,000,000, inclusive.
-event_i will contain between 1 and 50 elements, inclusive.
-event_j will contain the same number of elements as event_i.
-The elements of event_i will range between 0 and N, inclusive.
-The elements of event_j will range between 0 and M, inclusive.


EXAMPLES

0)
2
2
{0}
{0}

Returns: 4

Gold will be discovered today in the cell (0, 0). Your optimal strategy is to work there today.

1)
2
2
{0, 2}
{0, 1}

Returns: 7

Gold will be discovered in the cell (0, 0) today and in the cell (2, 1) tomorrow.
Note that you cannot move directly from (0, 0) to (2, 1), because these cells are neither in the same row nor in the same column.
One optimal strategy is to work in the cell (0, 0) today and in the cell (2, 0) tomorrow.
Your profit today will be 4, tomorrow it will be 3, thus the total profit is 4+3 = 7.

2)
3
3
{0, 3, 3}
{0, 3, 0}

Returns: 15



3)
3
4
{0, 3}
{4, 1}

Returns: 11



4)
5
6
{0, 4, 2, 5, 0}
{3, 4, 5, 6, 0}

Returns: 48



5)
557
919
{81, 509, 428, 6, 448, 149, 77, 142, 40, 405, 109, 247}
{653, 887, 770, 477, 53, 637, 201, 863, 576, 393, 512, 243}

Returns: 16255



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
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
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
class MiningGoldEasy
{
    public:
        int GetMaximumGold(int N, int M, vector <int> event_i, vector <int> event_j)
        {


            return int() ;
        }

        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arr2[] = {0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 4; verify_case(0, Arg4, GetMaximumGold(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; int Arr2[] = {0, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0, 1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 7; verify_case(1, Arg4, GetMaximumGold(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 3; int Arr2[] = {0, 3, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0, 3, 0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 15; verify_case(2, Arg4, GetMaximumGold(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 3; int Arg1 = 4; int Arr2[] = {0, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {4, 1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 11; verify_case(3, Arg4, GetMaximumGold(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 5; int Arg1 = 6; int Arr2[] = {0, 4, 2, 5, 0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {3, 4, 5, 6, 0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 48; verify_case(4, Arg4, GetMaximumGold(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 557; int Arg1 = 919; int Arr2[] = {81, 509, 428, 6, 448, 149, 77, 142, 40, 405, 109, 247}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {653, 887, 770, 477, 53, 637, 201, 863, 576, 393, 512, 243}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 16255; verify_case(5, Arg4, GetMaximumGold(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main(){
    MiningGoldEasy ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
