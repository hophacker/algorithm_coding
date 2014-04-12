// PROBLEM STATEMENT
// One day, Fox Ciel looked at the words "tokyo" and "kyoto" and noticed an unusual property:
We can split "tokyo" into "to"+"kyo", and then swap those two parts to obtain "kyo"+"to" = "kyoto".


Formally, let S and T be two different strings.
We call the pair (S,T) interesting if there are two non-empty strings A and B such that S = A+B and T = B+A.
For example, according to this definition, if S="tokyo" and T="kyoto", then the pair (S,T) is interesting, because we can find A="to" and B="kyo".


You are given a vector <string> words.
Return the number of interesting pairs we can find among the elements of words.
Only count each pair once.
E.g., ("tokyo","kyoto") and ("kyoto","tokyo") is the same interesting pair.

DEFINITION
Class:FoxAndWord
Method:howManyPairs
Parameters:vector <string>
Returns:int
Method signature:int howManyPairs(vector <string> words)


CONSTRAINTS
-words will contain between 2 and 50 elements, inclusive.
-Each element of words will contain between 1 and 50 characters, inclusive.
-Each character in each element of words will be a lowercase letter ('a'-'z').
-All the elements in words will be pairwise distinct.


EXAMPLES

0)
{"tokyo", "kyoto"}

Returns: 1

As mentioned in the problem statement, ("tokyo", "kyoto") is an interesting pair.

1)
{"aaaaa", "bbbbb"}

Returns: 0

("aaaaa", "bbbbb") is not an interesting pair.

2)
{"ababab","bababa","aaabbb"}

Returns: 1

There is one interesting pair: ("ababab","bababa").
Note that for this interesting pair there is more than one way to choose the strings A and B.

3)
{"eel", "ele", "lee"}

Returns: 3



4)
{"aaa", "aab", "aba", "abb", "baa", "bab", "bba", "bbb"}

Returns: 6



5)
{"top","coder"}

Returns: 0

Different elements of words may have different lengths.


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
class FoxAndWord
{
    public:
        int howManyPairs(vector <string> words)
        {


            return int() ;
        }

        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"tokyo", "kyoto"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, howManyPairs(Arg0)); }
	void test_case_1() { string Arr0[] = {"aaaaa", "bbbbb"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, howManyPairs(Arg0)); }
	void test_case_2() { string Arr0[] = {"ababab","bababa","aaabbb"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, howManyPairs(Arg0)); }
	void test_case_3() { string Arr0[] = {"eel", "ele", "lee"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, howManyPairs(Arg0)); }
	void test_case_4() { string Arr0[] = {"aaa", "aab", "aba", "abb", "baa", "bab", "bba", "bbb"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(4, Arg1, howManyPairs(Arg0)); }
	void test_case_5() { string Arr0[] = {"top","coder"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(5, Arg1, howManyPairs(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main(){
    FoxAndWord ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
