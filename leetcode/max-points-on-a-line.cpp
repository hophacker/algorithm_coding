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
struct Point {
     int x;
     int y;
     Point() : x(0), y(0) {}
     Point(int a, int b) : x(a), y(b) {}
 };

bool cmp(const Point& a, const Point& b){
    if (a.x == b.x) return a.y < b.y;
    else return a.x < b.x;
}
class Solution {
public:
    bool mul(Point &a, Point &b){
        return (a.y * b.x == a.x * b.y);
    }
    bool inTheSameLine(Point &a, Point &b, Point &c){
        Point x(b.x-a.x, b.y-a.y);
        Point y(c.x-a.x, c.y-a.y);
        return mul(x, y);
    }
    bool equal(Point& a, Point &b){
        return a.x == b.x && a.y == b.y;
    }
    int maxPoints(vector<Point> &points) {
        sort(points.begin(), points.end(), cmp);
        if (points.size() <= 1) return points.size();
        int maxRet = 2;
        for (vector<Point>::iterator i = points.begin(); i != points.end();){
            vector<Point>::iterator j = i+1;
            while (j != points.end() && equal(*i, *j)) j++;
            int a = j -i;
            maxRet = max(maxRet, a);
            i = j;
        }
        for (vector<Point>::iterator i = points.begin(); i != points.end();) {
            int ret = 1;
            while(i+1 != points.end() && equal(*(i+1), *i)) i++, ret++;
            for (vector<Point>::iterator j = (i+1); j != points.end(); j++){
                int count = 1;
                for (vector<Point>::iterator t = (j+1); t != points.end(); t++) 
                    if (inTheSameLine(*i, *j, *t)) 
                        count ++;
                maxRet = max(maxRet, ret+count);
            }
            maxRet = max(maxRet, ret);
            i++;
        }
        return maxRet;
    }
};
int main ( int argc, char *argv[] ) {
    /*FILE* file = fopen(argv[1], "r");
    int a, b;
    while(fscanf(file, "%d,%d", &a, &b) != EOF){
    }*/
    /*
    getI(T);
    int T;
    FE(cases,1,T){
        printf("Cases #%d: ", cases);
    }
     */
    Point points[] = {Point(0,0),Point(1,1),Point(1,-1)};
    Solution sl = Solution();
    vector<Point> p(points, points+3);
    cout << sl.maxPoints(p) << endl;
    return EXIT_SUCCESS;
}



