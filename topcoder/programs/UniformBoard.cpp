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
#define F(i,L,R) for (int i = L; i < R; i++)
#define FE(i,L,R) for (int i = L; i <= R; i++)
#define clr(a,x) memset(a,x,sizeof(a))
class UniformBoard
{
    private: 
        int a[21][21];
        int p[21][21];
        int n;
    public:
        int getBoard(vector <string> board, int K)
        {
//            printVV(board);
            n = board.size();
            int as = 0, ps = 0;
            clr(a, 0);
            clr(p, 0);
            FE(i,1,n){ 
                FE(j,1,n){
                    if (board[i-1][j-1] == 'A') a[i][j] = 1, as++;
                    else if (board[i-1][j-1] == 'P') p[i][j] = 1, ps++;

                    if (i != 0){
                        a[i][j] += a[i][j-1];
                        p[i][j] += p[i][j-1];
                    }
                }
                if (i != 0){
                    FE(j,1,n) a[i][j] += a[i-1][j], p[i][j] += p[i-1][j];
                }
            }

            int maxT = 0;
            if (as + ps == n*n){
                FE(i,1,n) FE(j,1,n) FE(i1,i,n) FE(j1,j,n){
                    int totalA = a[i1][j1] - a[i-1][j1] - a[i1][j-1] + a[i-1][j-1];
                    if (totalA == (i1-i+1)*(j1-j+1)){
                        maxT = max(maxT, totalA);
                    }
                }
            }else{
                FE(i,1,n) FE(j,1,n) FE(i1,i,n) FE(j1,j,n){
                    int totalA = a[i1][j1] - a[i-1][j1] - a[i1][j-1] + a[i-1][j-1];
                    int totalP = p[i1][j1] - p[i-1][j1] - p[i1][j-1] + p[i-1][j-1];
                    int total = (i1-i+1)*(j1-j+1);
                    int move = totalP + total - totalA;
                        if (total <= as && move <= K){
                            maxT = max(maxT, total);
                        }
                    }
            }
            return maxT;
        }

        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"AP",
 ".A"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 1; verify_case(0, Arg2, getBoard(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"AP",
 ".A"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; verify_case(1, Arg2, getBoard(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"PPP",
 "APA",
 "A.P"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; verify_case(2, Arg2, getBoard(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"AAA",
 "PPP",
 "AAA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 3; verify_case(3, Arg2, getBoard(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000; int Arg2 = 0; verify_case(4, Arg2, getBoard(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"PPAAPA..AP",
 "PPA.APAP..",
 "..P.AA.PPP",
 "P.P..APAA.",
 "P.P..P.APA",
 "PPA..AP.AA",
 "APP..AAPAA",
 "P.P.AP...P",
 ".P.A.PAPPA",
 "..PAPAP..P"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 15; verify_case(5, Arg2, getBoard(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main(){
    UniformBoard ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
