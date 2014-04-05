#include <cmath>
#include <vector>
#include <map>
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
#define printV(a) printA(a,0,a.size()-1)
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
const int fx[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

#define ui unsigned int
#define mi map<int, vector<vector<int> > >::iterator
class Solution {
public:
    vector<vector<int> > sum4;
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        map<string, int> exs;
        if (num.size() < 4) return  sum4;
        sort(num.begin(), num.end());
        int size = num.size();
        int maxI = num[size-1];
        int maxII = num[size-1] + num[size-2];
        int maxIII = num[size-1] + num[size-2] + num[size-3];
        for (int i = 0; i < size-3; i++){
            if (num[i] + num[i+1] + num[i+2] + num[i+3] > target) break;
            if (num[i] + maxIII < target) continue;
            for (int j = i+1; j < size-2; j++){
                int s2 = num[i] + num[j];
                if (s2 + num[j+1] + num[j+2] > target) break;
                if (s2 + maxII < target) continue;
                for (int k = j+1; k < size-1; k++){
                    int s3 = s2 + num[k];
                    int left = target - s3;
                    if (s3 + num[k+1] > target) break;
                    if (s3 + maxI < target) continue;
                    if (binary_search(num.begin()+k+1, num.end(), left)){
                        vector<int> t;
                        stringstream ss;
                        ss << num[i] << num[j] << num[k] << left;
                        string s  = ss.str();;
                        if (exs.find(s) == exs.end()){
                            exs[s] = 1;
                            t.push_back(num[i]);
                            t.push_back(num[j]);
                            t.push_back(num[k]);
                            t.push_back(left);
                            sum4.push_back(t);
                        }
                    }
                }
            }
        }
        return sum4;
    }
};
void printVV(vector<vector<int> >res){
    for (ui i = 0; i < res.size(); i++){
        for (ui j = 0; j < res[i].size(); j++) cout << res[i][j] << ' ';
        cout << endl;
    }
}
int main ( int argc, char *argv[] ) {
    //int a[]= {-499,-483,-463,-461,-431,-417,-390,-381,-366,-365,-342,-339,-321,-290,-285,-272,-265,-258,-228,-211,-188,-182,-146,-144,-123,-120,-112,-97,-92,-60,-58,-53,-53,-41,-36,-28,-15,-12,-7,22,45,57,59,62,77,81,99,103,105,115,119,135,147,154,169,183,187,215,243,258,259,266,272,272,275,309,319,345,370,382,385,389,436,439,442,469,484};
    //int a[] = {-2, -1, 0, 0, 1, 2};
    Solution s = Solution();

    int a[] = {1, 0, -1, 0, 0,  -2, 2};
    vector<int> aV(a, a+7);
    vector<vector<int> > res = s.fourSum(aV, 0);
    
    //int a[] = {91277418,66271374,38763793,4092006,11415077,60468277,1122637,72398035,-62267800,22082642,60359529,-16540633,92671879,-64462734,-55855043,-40899846,88007957,-57387813,-49552230,-96789394,18318594,-3246760,-44346548,-21370279,42493875,25185969,83216261,-70078020,-53687927,-76072023,-65863359,-61708176,-29175835,85675811,-80575807,-92211746,44755622,-23368379,23619674,-749263,-40707953,-68966953,72694581,-52328726,-78618474,40958224,-2921736,-55902268,-74278762,63342010,29076029,58781716,56045007,-67966567,-79405127,-45778231,-47167435,1586413,-58822903,-51277270,87348634,-86955956,-47418266,74884315,-36952674,-29067969,-98812826,-44893101,-22516153,-34522513,34091871,-79583480,47562301,6154068,87601405,-48859327,-2183204,17736781,31189878,-23814871,-35880166,39204002,93248899,-42067196,-49473145,-75235452,-61923200,64824322,-88505198,20903451,-80926102,56089387,-58094433,37743524,-71480010,-14975982,19473982,47085913,-90793462,-33520678,70775566,-76347995,-16091435,94700640,17183454,85735982,90399615,-86251609,-68167910,-95327478,90586275,-99524469,16999817,27815883,-88279865,53092631,75125438,44270568,-23129316,-846252,-59608044,90938699,80923976,3534451,6218186,41256179,-9165388,-11897463,92423776,-38991231,-6082654,92275443,74040861,77457712,-80549965,-42515693,69918944,-95198414,15677446,-52451179,-50111167,-23732840,39520751,-90474508,-27860023,65164540,26582346,-20183515,99018741,-2826130,-28461563,-24759460,-83828963,-1739800,71207113,26434787,52931083,-33111208,38314304,-29429107,-5567826,-5149750,9582750,85289753,75490866,-93202942,-85974081,7365682,-42953023,21825824,68329208,-87994788,3460985,18744871,-49724457,-12982362,-47800372,39958829,-95981751,-71017359,-18397211,27941418,-34699076,74174334,96928957,44328607,49293516,-39034828,5945763,-47046163,10986423,63478877,30677010,-21202664,-86235407,3164123,8956697,-9003909,-18929014,-73824245};
    //vector<int> aV(a, a+200);
    //vector<vector<int> > res = s.fourSum(aV, -236727523);
    printVV(res);
    return EXIT_SUCCESS;
}
