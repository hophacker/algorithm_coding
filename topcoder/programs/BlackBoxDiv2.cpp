// PROBLEM STATEMENT
// Cat Upper has a rectangular black box.
On the bottom of the box there is a grid that divides the box into identical square cells.
There are no walls between the cells.
The sides of the box are transparent, the top and bottom are opaque (i.e., Upper cannot see through them).
Some of the cells are filled: each of them contains an opaque black block that fills the entire cell.
The remaining cells are empty.

Cat Upper looked into the black box from the front and recorded what he saw:
Whenever a column of the grid was completely empty, he could see through the box and wrote down '.' (a period).
And whenever a column of the grid contained at least one block, Upper could not see through the box and he wrote down 'B'.

Then, he looked into the black box from the left side and again he recorded what he saw:
for each row of the grid he wrote '.' if the row was completely empty and 'B' otherwise.

You are given the recorded information in two strings: front and side.

Return the number of possible arrangements of the opaque blocks within the black box, modulo 1,000,000,007.
Note that you don't know the exact number of blocks in the black box.


DEFINITION
Class:BlackBoxDiv2
Method:count
Parameters:string, string
Returns:int
Method signature:int count(string front, string side)


CONSTRAINTS
-front and side will each contain between 1 and 50 characters, inclusive.
-Each character in front and side will be 'B' or '.'.


EXAMPLES

0)
"BB"
"BB"

Returns: 7

There are seven possible arrangements, as shown in the figure below.




1)
"..."
"....."

Returns: 1

There is no block, thus there is exactly 1 valid arrangement: the one where all cells are empty.

2)
"..."
"BBB"

Returns: 0

There is no possible arrangement. Upper must have made a mistake.

3)
"...BB.B...."
"B.B.B.B.B"

Returns: 16081



4)
"BBBBB.BBBBBBBBB.BBBBBBB.BBBB.B.BB..BB.B.BBBBBBBBBB"
".B.BBB..BBBBBB.BBBB.B...BBBB.BB.BBBBBBBBBB.....BBB"

Returns: 771030153



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
#endif#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std ;
#define For(i , n) for(int i = 0 ; i < (n) ; ++i)
#define SZ(x)  (int)((x).size())
typedef long long lint ;
const int maxint = -1u>>2 ;
const double eps = 1e-6 ; 
class BlackBoxDiv2
{
public:
int count(string front, string side)
{


return int() ;
}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "BB"; string Arg1 = "BB"; int Arg2 = 7; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "..."; string Arg1 = "....."; int Arg2 = 1; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "..."; string Arg1 = "BBB"; int Arg2 = 0; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "...BB.B...."; string Arg1 = "B.B.B.B.B"; int Arg2 = 16081; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "BBBBB.BBBBBBBBB.BBBBBBB.BBBB.B.BB..BB.B.BBBBBBBBBB"; string Arg1 = ".B.BBB..BBBBBB.BBBB.B...BBBB.BB.BBBBBBBBBB.....BBB"; int Arg2 = 771030153; verify_case(4, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};// BEGIN CUT HERE
int main(){
BlackBoxDiv2 ___test;
___test.run_test(-1);
getch() ;
return 0;
}
// END CUT HERE
