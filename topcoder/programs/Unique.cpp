#include <set>
#include <sstream>
#include <vector>
#include <iostream>  
using namespace std;
#define F(i,L,R) for (int i = L; i < R; i++)
class Unique
{
    public:
        string removeDuplicates(string S)
        {
            string res = "";
            set<char> unique;
            F(i,0,S.size()){
                if (unique.find(S[i]) == unique.end()){
                    res.push_back(S[i]);
                    unique.insert(S[i]);
                }
            }
            return res;
        }

        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "banana"; string Arg1 = "ban"; verify_case(0, Arg1, removeDuplicates(Arg0)); }
	void test_case_1() { string Arg0 = "aardvark"; string Arg1 = "ardvk"; verify_case(1, Arg1, removeDuplicates(Arg0)); }
	void test_case_2() { string Arg0 = "xxxxx"; string Arg1 = "x"; verify_case(2, Arg1, removeDuplicates(Arg0)); }
	void test_case_3() { string Arg0 = "topcoder"; string Arg1 = "topcder"; verify_case(3, Arg1, removeDuplicates(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main(){
    Unique ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
