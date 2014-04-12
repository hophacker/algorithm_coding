// PROBLEM STATEMENT
// In soccer, all the major national leagues are conducted in the following way:

A league consists of several teams.  Over the course of a year, each team must play exactly two matches against each of the other teams - one at its own stadium and one at the opponent's stadium.  When a team plays at its own stadium, it is called the "home team" and its opponent is called the "away team".  Each match ends in one of three possible results: a home team victory, a draw, or an away team victory.  Each time a team wins, it is awarded 3 points.  When there's a draw, both teams are awarded 1 point.  No points are awarded for a loss.  The overall ranking of the teams is based on the total number of points received by each team.

You are given a vector <string> matches.  The j-th character of the i-th element of matches denotes the result of the match between team i and team j at team i's stadium.  'W' represents a home team victory, 'D' represents a draw, and 'L' represents an away team victory.  All characters on the main diagonal of matches will be '-' because a team never plays against itself.  Return a vector <int> where the i-th element is the total number of points received by the i-th team.


DEFINITION
Class:SoccerLeagues
Method:points
Parameters:vector <string>
Returns:vector <int>
Method signature:vector <int> points(vector <string> matches)


CONSTRAINTS
-matches will contain exactly n elements, where n is between 2 and 50, inclusive.
-Each element of matches will contain exactly n characters.
-matches will contain only '-','W','D' and 'L' characters.
-For all i, the i-th character of the i-th element of matches will be '-', and no other characters will be '-'.


EXAMPLES

0)
{"-WW",
 "W-W",
 "WW-"}

Returns: {6, 6, 6 }

There are 3 teams in the league, and in all matches the home team has won.


1)
{"-DD",
 "L-L",
 "WD-"}

Returns: {5, 2, 8 }

This time, the first team has 1 win and 2 draws, the second one has 2 draws and the third has 2 wins and 2 draws.


2)
{"-DWWD",
 "L-WLL",
 "DD-WD",
 "DDL-L",
 "DDLL-"}

Returns: {14, 7, 12, 8, 10 }



3)
{"-LWWLWDLDWWWWWWDDWDW",
 "D-WWLDDWDWDLWDDWLWDD",
 "LL-DLDWDLDLDWWWLWDDW",
 "LDD-LLLDLWLWWWWDWDWL",
 "LWWW-DWDLWDWDWWWDWDW",
 "DLLWD-WWLLDDDLWWDWWW",
 "WWLWDL-LLDWWWWWDWWLW",
 "LLLLLDW-LDLWDDLLLDWL",
 "DWWWWDDD-DWWWWDWWWDW",
 "WWWWLLLWL-LWWWWWLWWW",
 "DWWWWWWWLW-WDWWWWWWW",
 "DDDLLLDWWWL-DDWDWLDD",
 "LWLWLDLLLDLW-DDDWWDD",
 "LLWWLWDDLWLWL-WWWDLL",
 "WWWWLLDDDWLWDD-WWWLW",
 "DLDLLLWWLLLWWLW-DWLL",
 "DLWWWLDLWWDWWDWL-WWD",
 "LLDDLLWLLWLWLDLWW-WW",
 "LLWLLLWWLWLWWDWWLD-W",
 "LLWDLWDWDWLLWWDDWWL-"}

Returns: {72, 62, 41, 41, 83, 63, 53, 35, 86, 50, 90, 32, 34, 41, 45, 36, 51, 32, 51, 45 }

This is the actual table for the latest season's Barclaycard Premiership with the teams sorted alphabetically.


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
class SoccerLeagues
{
public:
vector <int> points(vector <string> matches)
{


return vector <int>() ;
}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"-WW",
 "W-W",
 "WW-"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6, 6, 6 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, points(Arg0)); }
	void test_case_1() { string Arr0[] = {"-DD",
 "L-L",
 "WD-"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5, 2, 8 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, points(Arg0)); }
	void test_case_2() { string Arr0[] = {"-DWWD",
 "L-WLL",
 "DD-WD",
 "DDL-L",
 "DDLL-"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {14, 7, 12, 8, 10 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, points(Arg0)); }
	void test_case_3() { string Arr0[] = {"-LWWLWDLDWWWWWWDDWDW",
 "D-WWLDDWDWDLWDDWLWDD",
 "LL-DLDWDLDLDWWWLWDDW",
 "LDD-LLLDLWLWWWWDWDWL",
 "LWWW-DWDLWDWDWWWDWDW",
 "DLLWD-WWLLDDDLWWDWWW",
 "WWLWDL-LLDWWWWWDWWLW",
 "LLLLLDW-LDLWDDLLLDWL",
 "DWWWWDDD-DWWWWDWWWDW",
 "WWWWLLLWL-LWWWWWLWWW",
 "DWWWWWWWLW-WDWWWWWWW",
 "DDDLLLDWWWL-DDWDWLDD",
 "LWLWLDLLLDLW-DDDWWDD",
 "LLWWLWDDLWLWL-WWWDLL",
 "WWWWLLDDDWLWDD-WWWLW",
 "DLDLLLWWLLLWWLW-DWLL",
 "DLWWWLDLWWDWWDWL-WWD",
 "LLDDLLWLLWLWLDLWW-WW",
 "LLWLLLWWLWLWWDWWLD-W",
 "LLWDLWDWDWLLWWDDWWL-"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {72, 62, 41, 41, 83, 63, 53, 35, 86, 50, 90, 32, 34, 41, 45, 36, 51, 32, 51, 45 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, points(Arg0)); }

// END CUT HERE

};// BEGIN CUT HERE
int main(){
SoccerLeagues ___test;
___test.run_test(-1);
getch() ;
return 0;
}
// END CUT HERE
