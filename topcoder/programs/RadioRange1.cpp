


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
#define printV(a) printA(a,0,(int)a.size()-1);
#define printVV(a) F(i,0,a.size()) {F(j,0,(int)a[i].size())cout << a[i][j] << ' '; cout << endl;}
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



class RadioRange
{
    public:
    struct node{
        double b, e;
        bool operator<(const node& other)const{
            return b < other.b;
        }
        node(double bb, double ee):b(bb), e(ee){
        }
    };

        double RadiusProbability(vector <int> X, vector <int> Y, vector <int> R, int z)
        {
            double Z = z;
            vector<node> p;
            F(i,0,X.size()){
                double d = sqrt(1.0*X[i]*X[i] + 1.0*Y[i]*Y[i]);
                if (d-R[i] <= Z){
                    p.push_back(node(max(d-R[i],0.0), min(d+R[i],Z)));
                }
            }

            if (p.size() == 0){
                return 1.0;
            }

            sort(p.begin(), p.end());


            double ok_seg = min(p[0].b, 1.0*Z);

            int i = 0;
            double e_max;
            while(i < p.size()){
                e_max = p[i].e;
                int j = i+1;
                while(j < p.size() && p[j].b <= e_max){
                    e_max = max(e_max, p[j].e),j++;
                }
                if (j < p.size()){
                    ok_seg += p[j].b - e_max;
                }
                i = j;
            }
            ok_seg += Z - e_max;
            return ok_seg / Z;
        }

        


        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 10; double Arg4 = 0.5; verify_case(0, Arg4, RadiusProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 10; double Arg4 = 0.0; verify_case(1, Arg4, RadiusProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 10; double Arg4 = 0.4142135623730951; verify_case(2, Arg4, RadiusProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {11, -11, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 11, -11}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10, 10, 10, 10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 31; double Arg4 = 0.3548387096774194; verify_case(3, Arg4, RadiusProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 10; double Arg4 = 1.0; verify_case(4, Arg4, RadiusProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arr0[] = {1000000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1000000000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1000000000}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1000000000; double Arg4 = 0.41421356237309503; verify_case(5, Arg4, RadiusProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_6() { int Arr0[] = {20, -20, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 20, -20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {50, 50, 50, 50}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 100; double Arg4 = 0.3; verify_case(6, Arg4, RadiusProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_7() { int Arr0[] = {-187730043, 932334096, 59236807, -602044448, 441157147, 569003535, 563472630, 493784941, -928345136, -198534684, -507361726, -486699261, -705601684, -671249417, -79879427, 71698248, 146683444, 414416326, 53196305, -666818573, 178619454, -893182413, 224302710, 296990194, -885921154, -173521881, -493092068, 900325848, -353242967, -631482448, 112982750, 553248219, 264762102, -318102799, -836641673, -812311860, -73259832, 609869565, 650010687, 155243096, -107417345, 634247427, -841502473, -651719520, -958664893, 480384188, -691415372, 36346544, 706329659, 126652235, 44403422, -263265167, -349491074, 120258505, 485027199, -240466308, -456782932, 192953958, -261803363, -198063552, 980391799, 997148607, 417112854, -333017353, -945493557, 371446553, 251150037, -960076588, -360362805, -305175580, 208353048, -437834549, -420355623, -668454094, 180494692, 755143595, 249998094, 537726369, 343336414, 495586169, 35446018, 131243302, 501744441, 739753520, -876687692, 560013605, -443087342, 455209428, 333669368, 398118304, -695213876, 527566904, -463103162, -317355625, 641069703, -947785900, -532490870, -963111776, -727898154, 748858912}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
        int Arr1[] = {452827103, 247175647, 11753377, -611873763, -531081305, 859586805, -868286674, -876539858, 304963335, 990345765, -859353631, -475065113, -574709927, 131112520, -846074893, 464742988, -41360301, 899849149, -266820064, -251052777, 226747686, 876712903, -350309643, 131456902, -799664596, 453822371, -617483392, 755895436, -72097080, 199834107, -619495741, -922106677, 229012084, 419002428, 38711443, 293733516, 633211140, -65526196, -776215532, -491310115, -23818472, 792447417, 726536324, -686011537, -140383515, -569321731, -402939093, -125768005, -18416939, 127783325, -67341991, -322587512, -296995968, -536590267, 437613161, -206640690, -825549222, 102733497, -399947312, 55751657, 527107031, -152726436, -821534503, 267030010, -528297582, -897079824, -521362885, 1225411, 460297398, 596603062, -270748768, 211858545, -654848212, -353416243, 955853430, -447642704, 739273996, -118039293, 583896289, -253276293, 632398992, 560349797, 222539806, 677153439, -804423594, -285780470, 782032960, 23986706, -812231058, 344193048, 491603558, 956077657, -97237599, -644202406, -311702606, 645844112, 47834815, -802896183, 472801824, 658244534}; 
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
        int Arr2[] = {4, 7, 4, 4, 5, 1, 8, 4, 5, 7, 8, 3, 5, 5, 9, 5, 8, 5, 6, 7, 7, 8, 10, 6, 10, 6, 3, 4, 5, 1, 5, 8, 9, 8, 2, 3, 1, 9, 8, 5, 8, 6, 9, 2, 2, 9, 9, 2, 6, 4, 8, 2, 4, 9, 7, 5, 5, 2, 1, 9, 2, 5, 6, 10, 4, 9, 4, 4, 10, 1, 10, 9, 8, 10, 2, 2, 9, 10, 3, 4, 6, 10, 5, 1, 9, 3, 5, 5, 4, 5, 5, 5, 1, 10, 6, 7, 1, 1, 10, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
        int Arg3 = 1000000000; double Arg4 = 0.999999094; verify_case(7, Arg4, RadiusProbability(Arg0, Arg1, Arg2, Arg3)); }



// END CUT HERE

};
// BEGIN CUT HERE
int main(){
    RadioRange ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
