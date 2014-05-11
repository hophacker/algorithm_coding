// PROBLEM STATEMENT
// Fox Ciel wants to hire a new maid.
There are n candidates for the position.
There are m different skills a maid should have, such as cooking, cleaning, or discreetness.
Ciel numbered the candidates 0 through n-1 and the skills 0 through m-1.



Ciel evaluated the level each candidate has in each of the skills.
You are given this information encoded in a vector <string> score with n elements, each consisting of m characters.
For each i and j, the character score[i][j] represents the level candidate i has in skill j.
Said character will always be between 'A' and 'Z', inclusive, where 'A' means the best possible and 'Z' the worst possible candidate.



Immediately after the reviews, the order of the candidates was {0, 1, ..., n-1}.
Then, Ciel spent several days thinking about whom to hire.
On each day, she chose one skill and reordered the candidates according to their level in that skill, from the best to the worst one.
Whenever two candidates had the same level in the currently considered skill, she kept them in the order in which they were after the previous day.
(Formally, the sorting algorithm she used was stable.)



You are given a vector <int> result containing a permutation of 0 through n-1.
Return "Possible" (quotes for clarity) if it is possible that after zero or more days the order of candidates was precisely the one given in result.
Otherwise, return "Impossible".

DEFINITION
Class:CandidatesSelection
Method:possible
Parameters:vector <string>, vector <int>
Returns:string
Method signature:string possible(vector <string> score, vector <int> result)


CONSTRAINTS
-n will be between 1 and 50, inclusive.
-m will be between 1 and 50, inclusive.
-score will contain exactly n elements.
-Each element of score will contain exactly m characters.
-Each character in each element of score will be an uppercase English letter ('A'-'Z').
-result will be a permutation of 0 through n-1.


EXAMPLES

0)
{"CC", "AA", "BB"}
{1,2,0}

Returns: "Possible"

You can sort them by any skill to get the result.

1)
{"BAB", "ABB", "AAB", "ABA"}
{2,0,1,3}

Returns: "Possible"

We can first sort them by skill 0 to get {1, 2, 3, 0}, then sort them by skill 1 to get {2, 0, 1, 3}.

2)
{"BAB", "ABB", "AAB", "ABA"}
{0, 1, 3, 2}

Returns: "Impossible"



3)
{"AAA", "ZZZ"}
{1, 0}

Returns: "Impossible"



4)
{"ZZZ", "AAA"}
{0, 1}

Returns: "Possible"

Ciel can do no operation at all.

5)
{"ZYYYYX","YXZYXY","ZZZZXX","XZXYYX","ZZZYYZ","ZZXXYZ","ZYZZXZ","XZYYZX"}
{3,7,1,0,2,5,6,4}

Returns: "Possible"



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
class CandidatesSelection
{
    public:
        string possible(vector <string> score, vector <int> result)
        {


            return string() ;
        }

        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"CC", "AA", "BB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Possible"; verify_case(0, Arg2, possible(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"BAB", "ABB", "AAB", "ABA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,0,1,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Possible"; verify_case(1, Arg2, possible(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"BAB", "ABB", "AAB", "ABA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 3, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Impossible"; verify_case(2, Arg2, possible(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"AAA", "ZZZ"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Impossible"; verify_case(3, Arg2, possible(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"ZZZ", "AAA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Possible"; verify_case(4, Arg2, possible(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"ZYYYYX","YXZYXY","ZZZZXX","XZXYYX","ZZZYYZ","ZZXXYZ","ZYZZXZ","XZYYZX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,7,1,0,2,5,6,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Possible"; verify_case(5, Arg2, possible(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main(){
    CandidatesSelection ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
