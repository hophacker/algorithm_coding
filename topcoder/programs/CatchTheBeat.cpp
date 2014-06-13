#include <sstream>
#include <cmath>
#include <set>
#include <list>
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
#define FF(i,L,R) for (int i = L; i > R; i--)
#define FFE(i,L,R) for (int i = L; i >= R; i--)
#define ll long long
const int maxint = -1u>>2 ;
const double eps = 1e-6 ; 
class CatchTheBeat
{
struct node{
    ll x, y;
    node(){
    }
    node(ll xx, ll yy):x(xx), y(yy){
    }
    bool operator<(const node& other)const{
        if (y == other.y)
            return x < other.x;
        else return y < other.y;
    }
};
    public:
        int maxCatched(int n, int x0, int y0, int a, int b, int c, int d, int mod1, int mod2, int offset)
        {
            vector<node> p(n);
            ll x = x0, y = y0;
            p[0].x = x - offset; p[0].y = y;

            F(i,1,n){
                x = ((x * a) + b) % mod1;
                y = ((y * c) + d) % mod2;
                p[i].x = x - offset;
                p[i].y = y;
            }


            sort(p.begin(), p.end());
            vector<int> f(p.size(), -1);


//            F(i,0,n) cout << p[i].x << ' ' << p[i].y << endl;
            int maxRet = 0;
            bool go = false;
            for (int i = 0; i < n; i++){

                if (abs(p[i].x) <= p[i].y){ 
                    f[i] = 1;
                    go = true;
                }

                if (go){
                    for (int j = i-1; j >= 0; j--){
                        if (abs(p[j].x - p[i].x) <= (p[i].y - p[j].y) && f[j] != -1){
                            f[i] = max(f[i], f[j]+1);
                            if (f[i] > maxRet) break;
                        }
                    }
                }
                maxRet = max(maxRet, f[i]);
            }
            return maxRet;
        }

        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 0; int Arg2 = 0; int Arg3 = 1; int Arg4 = 1; int Arg5 = 1; int Arg6 = 1; int Arg7 = 100; int Arg8 = 100; int Arg9 = 1; int Arg10 = 2; verify_case(0, Arg10, maxCatched(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 0; int Arg2 = 1234; int Arg3 = 0; int Arg4 = 0; int Arg5 = 0; int Arg6 = 0; int Arg7 = 1000000000; int Arg8 = 1000000000; int Arg9 = 1000; int Arg10 = 1; verify_case(1, Arg10, maxCatched(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 0; int Arg2 = 999; int Arg3 = 0; int Arg4 = 0; int Arg5 = 0; int Arg6 = 0; int Arg7 = 1000000000; int Arg8 = 1000000000; int Arg9 = 1000; int Arg10 = 0; verify_case(2, Arg10, maxCatched(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9)); }
	void test_case_3() { int Arg0 = 100; int Arg1 = 0; int Arg2 = 0; int Arg3 = 1; int Arg4 = 1; int Arg5 = 1; int Arg6 = 1; int Arg7 = 3; int Arg8 = 58585858; int Arg9 = 1; int Arg10 = 66; verify_case(3, Arg10, maxCatched(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9)); }
	void test_case_4() { int Arg0 = 500000; int Arg1 = 123456; int Arg2 = 0; int Arg3 = 1; int Arg4 = 0; int Arg5 = 1; int Arg6 = 1; int Arg7 = 1000000000; int Arg8 = 1000000000; int Arg9 = 0; int Arg10 = 376544; verify_case(4, Arg10, maxCatched(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9)); }
	void test_case_5() { int Arg0 = 500000; int Arg1 = 0; int Arg2 = 0; int Arg3 = 0; int Arg4 = 0; int Arg5 = 0; int Arg6 = 0; int Arg7 = 1; int Arg8 = 1; int Arg9 = 0; int Arg10 = 500000; verify_case(5, Arg10, maxCatched(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9)); }
	void test_case_6() { int Arg0 = 10; int Arg1 = 999999957; int Arg2 = 79; int Arg3 = 993948167; int Arg4 = 24597383; int Arg5 = 212151897; int Arg6 = 999940854; int Arg7 = 999999986; int Arg8 = 999940855; int Arg9 = 3404; int Arg10 = 3; verify_case(6, Arg10, maxCatched(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main(){
    CatchTheBeat ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
