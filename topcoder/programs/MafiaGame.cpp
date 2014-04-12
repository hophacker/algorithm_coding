// PROBLEM STATEMENT
// N friends (numbered from 0 to N-1) play a game called Mafia. The exact rules of the game are not important for this problem. What's important is that at some point in the game they will need to choose one player who will lose and leave the game.

It is known that some players have a definite opinion on who should lose. Their opinions are given in the vector <int> decisions, where each element corresponds to a single opinion and is the number of a player who should lose according to that opinion. All opinions in decisions belong to different players. If decisions contains less than N elements, then all other players do not have a definite opinion on who should lose.

In order to determine who will lose, one or more rounds of voting will be conducted. In each round, there's a set of players for whom the players are allowed to vote. The players in this set are called "vulnerable". It's impossible to vote for players not in this set. Before the first round of voting, all N players are included in this set.

All N players will vote in each round. The voting is held according to the following scheme:

First, each player who has a definite opinion on who should lose is allowed to vote if the player he thinks should lose is "vulnerable" in this round.  All of these players will vote according to their opinions.
Then all other players vote, in order. Each of them votes for the "vulnerable" player who currently has the smallest number of votes (only considering the votes in the current round). If there are several such players, he/she chooses one of them uniformly at random and votes for the chosen player.
Once all players have voted, if there is only one player who has the largest number of votes in the current round, this player loses and leaves the game. In this case there will be no more rounds of voting. Otherwise, the set of "vulnerable" players in the next round is set to all players who have the largest number of votes in the current round.

If it is possible that an infinite number of voting rounds will be held, then return 0. Otherwise, consider an array containing exactly N elements, where the i-th element (0-based) is equal to the probability that the i-th player will lose. Return the maximum value among all elements of this array.

DEFINITION
Class:MafiaGame
Method:probabilityToLose
Parameters:int, vector <int>
Returns:double
Method signature:double probabilityToLose(int N, vector <int> decisions)


NOTES
-The exact numbers of people to whom the opinions in decisions belong are not relevant in this problem.
-It is possible that a player will decide to vote against himself (see example 0). It is also possible that a player will have to vote against himself (if he is one of "vulnerable" players who have the smallest number of votes in the current round).
-The returned value must have an absolute or relative error less than 1e-9.


CONSTRAINTS
-N will be between 2 and 500, inclusive.
-decisions will contain between 1 and min(N, 50) elements, inclusive.
-Each element of decisions will be between 0 and N-1, inclusive.


EXAMPLES

0)
3
{1, 1, 1}

Returns: 1.0

After the first voting round, there will be 3 votes against player 1 and no votes against other players. Therefore player 1 will lose with probability 1.0.

1)
5
{1, 2, 3}

Returns: 0.0

The first round will proceed as follows. The first three votes will be against players 1, 2 and 3. The next vote will be against player 0 with probability 50% (in this case the last vote will be against player 4) or against player 4 with probability 50% (in this case the last vote will be against player 0). In both cases, after the end of the round there will be 1 vote against each player, so the set of "vulnerable" players will remain unchanged.

Each next round will proceed according to the same scenario, so there will be infinitely many rounds.

2)
20
{1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5, 6, 7, 18, 19, 0}

Returns: 0.0

There can be different voting scenarios, but in each of them the number of "vulnerable" players after the first three rounds is 7, 6 and 2, respectively. Then, starting from the fourth round, there will be exactly 10 votes against each "vulnerable" player, so the set of "vulnerable" players will remain unchanged and there will be infinitely many rounds.

3)
23
{17, 10, 3, 14, 22, 5, 11, 10, 22, 3, 14, 5, 11, 17}

Returns: 0.14285714285714285

There can also be many different voting scenarios, but each of them consists of exactly 3 rounds. Each of players 3, 5, 10, 11, 14, 17, 22 can lose with the same probability of 1/7.

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
class MafiaGame
{
public:
double probabilityToLose(int N, vector <int> decisions)
{


return double() ;
}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arr1[] = {1, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.0; verify_case(0, Arg2, probabilityToLose(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5; int Arr1[] = {1, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(1, Arg2, probabilityToLose(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 20; int Arr1[] = {1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5, 6, 7, 18, 19, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(2, Arg2, probabilityToLose(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 23; int Arr1[] = {17, 10, 3, 14, 22, 5, 11, 10, 22, 3, 14, 5, 11, 17}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.14285714285714285; verify_case(3, Arg2, probabilityToLose(Arg0, Arg1)); }

// END CUT HERE

};// BEGIN CUT HERE
int main(){
MafiaGame ___test;
___test.run_test(-1);
getch() ;
return 0;
}
// END CUT HERE
