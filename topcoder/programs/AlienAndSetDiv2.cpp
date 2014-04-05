// PROBLEM STATEMENT
// 
Alien Fred wants to destroy the Earth.
But before he does that, he wants to solve the following problem.




He has the set {1, 2, 3, ..., 2N}.
He wants to split this set into two new sets A and B.
The following conditions must all be satisfied:

Each element of the original set must belong to exactly one of the sets A and B.
The two new sets must have the same size. (I.e., each of them must contain exactly N numbers.)
For each i from 1 to N, inclusive: 
    Let A[i] be the i-th smallest element of A, and let B[i] be the i-th smallest element of B.
    The difference |A[i] - B[i]| must be less than or equal to K.





You are given the two ints N and K.
Let X be the total number of ways in which Fred can choose the sets A and B.
Return the value (X modulo 1,000,000,007).


DEFINITION
Class:AlienAndSetDiv2
Method:getNumber
Parameters:int, int
Returns:int
Method signature:int getNumber(int N, int K)


CONSTRAINTS
-N will be between 1 and 50, inclusive.
-K will be between 1 and 10, inclusive.


EXAMPLES

0)
2
1

Returns: 4

The initial set is {1, 2, 3, 4}.
The following 6 pairs of subsets are possible in this case:


A={1, 2} and B={3, 4}


A={1, 3} and B={2, 4}


A={1, 4} and B={2, 3}


A={2, 3} and B={1, 4}


A={2, 4} and B={1, 3}


A={3, 4} and B={1, 2}


The first option and the last option are both invalid.
One of the reasons is that in both cases the difference between the smallest element in A and the smallest element in B is too large (3-1 = 2, which is more than 1).
The other 4 options are valid.


Note that order of the two sets matters: the option A={1,3} and B={2,4} differs from the option A={2,4} and B={1,3}.

1)
3
1

Returns: 8



2)
4
2

Returns: 44



3)
10
10

Returns: 184756



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
class AlienAndSetDiv2
{
    public:
        int getNumber(int N, int K)
        {


            return int() ;
        }

        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 1; int Arg2 = 4; verify_case(0, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 8; verify_case(1, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 2; int Arg2 = 44; verify_case(2, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 10; int Arg2 = 184756; verify_case(3, Arg2, getNumber(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main(){
    AlienAndSetDiv2 ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
