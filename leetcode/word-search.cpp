#include <cmath>
#include <climits>
#include <queue>
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
class Solution {
private:
    int n, m;
    vector<vector<bool> >vis;
    vector<vector<char> >b;
    string w;
public:
    bool search(int i, int j, int len){
        if (len == w.length() - 1) return true;
        for (int d = 0; d < 4; d++){
            int x = fx[d][0] + i;
            int y = fx[d][1] + j;
            if (0 <= x && x < n && 0 <= y && y < m && !vis[x][y] && b[x][y] == w[len+1]){
                vis[x][y] = true;
                if (search(x, y, len+1)) return true;
                vis[x][y] = false;
            }
        }
        return false;
    }
    bool exist(vector<vector<char> > &board, string word) {
        n = board.size();
        m = board[0].size();
//        for (int i = 0; i < n; i++){
//            for (int j = 0; j < m; j++)
//                cout << board[i][j];
//            cout << endl;
//        }
        
        vis = vector<vector<bool> >(n, vector<bool>(m, false));
        b = board;
        w = word;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++){
                if (b[i][j] == w[0]){
                    vis[i][j] = true;
                    if (search(i, j, 0)) return true;
                    vis[i][j] = false;
                }
            }
        return false;
    }
};
int main ( int argc, char *argv[] ) {
    vector<vector<char> > vvc;
    char * s = "ABCD";
    vector<char> vc(s, s+4);
    vvc.push_back(vc);

    s = "SFCS";
    vc = vector<char>(s, s+4);
    vvc.push_back(vc);

    s = "ADEE";
    vc = vector<char>(s, s+4);
    vvc.push_back(vc);

    Solution sl = Solution();
    cout << sl.exist(vvc, "ABCB");

}
