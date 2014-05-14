// PROBLEM STATEMENT
// 
Shiny has a company.
There are N employees in her company.
The employees are numbered 0 through N-1 in order in which they joined the company.

Employee 0 is the only employee with no boss.
Every other employee has precisely one direct boss in the company.
You are given a vector <int> superior with N elements.
Element 0 of superior will be -1 to denote that employee 0 has no boss.
For each i between 1 and N-1, inclusive, element i of superior will be the number of the boss of employee i.

For each employee, their boss joined the company before them.
Formally, for each i between 1 and N-1, inclusive, superior[i] will be between 0 and i-1, inclusive.

At the moment, the employees of Shiny's company cannot do anything useful.
Shiny would like to change this.
She decided that she will pay for the employees' training.
More precisely, each employee will be trained to do two different types of work.
(The two types of work may be different for different employees.)

There are K types of work for which training is available.
You are given a vector <int> training with K elements.
For each i, training[i] is the cost of training any single employee to do work of type i.
If multiple employees are trained to do the same work type, Shiny must pay for each of them separately.

Each employee of the company has their own department.
The department of employee x is formed by employee x and all the employees such that x is their boss.
Formally, for any y different from x, employee y belongs into the department of employee x if and only if superior[y]=x.
Note that if superior[z]=y and superior[y]=x, employee z does not belong into the department of employee x.

Shiny likes diverse departments.
A department is diverse if:

Each employee in the department is doing something, and
no two employees in the department are doing the same type of work.


When Shiny comes to inspect a department, the employees in the department try to choose their work so that the department will be diverse.
If they can do that, Shiny says that the department is good.

Shiny considers her company good if all N departments are good.
(Note that the departments are not required to be diverse at the same time. A company is good as soon as each of its departments can be diverse at some point in time.)

Shiny now wants to choose, for each employee, the two work types they will be trained to do.
Shiny wants to have a good company, and also to spend as little money as possible.

If it is possible for Shiny to have a good company, return the smallest possible total amount of money spent on training the employees.
If it is impossible, return -1 instead.



DEFINITION
Class:GoodCompanyDivOne
Method:minimumCost
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int minimumCost(vector <int> superior, vector <int> training)


NOTES
-Each employee must learn to perform exactly two different work types (even though they might never need to do one of those two types of work).


CONSTRAINTS
-superior will contain between 1 and 30 elements, inclusive.
-superior[0] will be -1.
-For each valid i>0, superior[i] will be between 0 and i-1, inclusive.
-training will contain between 2 and 30 elements, inclusive.
-Each element of training will be between 1 and 100, inclusive.


EXAMPLES

0)
{-1}
{1, 2}

Returns: 3

There is only one employee (employee 0) and two work types. Employee 0 has to be trained to do both work types. This costs 1+2 = 3. After the training, the company is clearly good.

1)
{-1, 0, 0}
{1, 2, 3}

Returns: 10

One optimal solution:

Employee 0 learns work types 0 and 1 which costs 1+2 = 3.
Employee 1 learns work types 0 and 1 which costs 1+2 = 3.
Employee 2 learns work types 0 and 2 which costs 1+3 = 4.

The total cost is 3+3+4 = 10.
The company is now good because:

The department of employee 0 is formed by employees 0, 1, and 2. This department is good because they can choose work types 0, 1, and 2, respectively.
The department of employee 1 is formed only by employee 1 and it is clearly good.
The department of employee 2 is formed only by employee 2 and it is clearly good.



2)
{-1, 0, 0, 0}
{1, 2, 3}

Returns: -1

There are only three work types, but there are four employees in employee 0's department.
Therefore, this department can never be good.

3)
{-1, 0, 0, 2, 2, 2, 1, 1, 6, 0, 5, 4, 11, 10, 3, 6, 11, 7, 0, 2, 13, 14, 2, 10, 9, 11, 22, 10, 3}
{4, 2, 6, 6, 8, 3, 3, 1, 1, 5, 8, 6, 8, 2, 4}

Returns: 71




// BEGIN CUT HERE
#define debuging
#ifdef debuging
#define FIN  {freopen("new.in" , "r" , stdin) ;}
#define FOUT {freopen("new.out" , "w" , stdout) ;}
#define OUT(x)  {cout<< #x << "  : " << x <<endl ;}
#define ERR(x)  {cout<<"#error: "<< x ; while(1) ;}
#endif
#ifndef debuging
#define FIN  ;
#define FOUT ;
#define OUT(x)  ;
#define ERR(x)  ;
#endif
// END CUT HERE
#include <sstream>
#include <cmath>
#include <set>
#include <list>
#include <unordered_set>
#include <hash_map>
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
#define bit(x,i) (x&(1<<i))
#define lowbit(x) ((x)&((x)^((x)-1)))
//#define max(a,b) (a<b?b:a)
//#define abs(x) (x<0?-x:x)
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
#define clr(a,x) memset(a,x,sizeof(a))
#define getI(a) scanf("%d", &a)
#define getII(a,b) scanf("%d%d", &a, &b)
#define getIII(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define getS(x) scanf("%s", x);
#define SZ(x) ((int)((x).size()))
#define REMAX(a,b) (a)=max((a),(b));
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define REMIN(a,b) (a)=min((a),(b));
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define ALL(t) t.begin(),t.end()
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define us unsigned short
#define IOS ios_base::sync_with_stdio(0);
#define pb push_back
#define INF 1001001001
#define PI 3.1415926535897932384626
#define mp make_pair
#define ll long long
#define fi first
#define se second
#define wez(n) int (n); scanf("%d",&(n));
#define wez2(n,m) int (n),(m); scanf("%d %d",&(n),&(m));
#define wez3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k));
inline void pisz(int n) { printf("%d\n",n); }
#define TESTS wez(testow)while(testow--)
#define whileZ int T; getI(T); while(T--)
#define printA(a,L,R) FE(i,L,R) cout << a[i] << (i==R?'\n':' ')
#define printM(a,n,m) F(i,0,n){ F(j,0,m) cout << a[i][j] << ' '; cout << endl;}
#define printV(a) printA(a,0,a.size()-1);
#define printVV(a) F(i,0,a.size()) {F(j,0,a[i].size())cout << a[i][j] << ' '; cout << endl;}
#define MAXN 10000
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
typedef int elem_t;
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){F(i,0,SZ(t))s<<t[i]<<" ";return s; }
int gcd(int a,int b){return a?gcd(b%a,a):b;}
ll gcd(ll a,ll b){return a?gcd(b%a,a):b;}
ll powmod(ll a,ll p,ll m){ll r=1;while(p){if(p&1)r=r*a%m;p>>=1;a=a*a%m;}return r;}
const int fx[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
const int maxint = -1u>>2 ;
const double eps = 1e-6 ; 
class GoodCompanyDivOne
{
    public:
        int minimumCost(vector <int> superior, vector <int> training)
        {


            return int() ;
        }

        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {-1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(0, Arg2, minimumCost(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {-1, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; verify_case(1, Arg2, minimumCost(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {-1, 0, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(2, Arg2, minimumCost(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {-1, 0, 0, 2, 2, 2, 1, 1, 6, 0, 5, 4, 11, 10, 3, 6, 11, 7, 0, 2, 13, 14, 2, 10, 9, 11, 22, 10, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4, 2, 6, 6, 8, 3, 3, 1, 1, 5, 8, 6, 8, 2, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 71; verify_case(3, Arg2, minimumCost(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main(){
    GoodCompanyDivOne ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
