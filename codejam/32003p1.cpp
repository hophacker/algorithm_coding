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
const int fx[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

vector<vector<int> > graph;
int W, H;

// dir{0:->}
inline void left(int& dir){
    if (dir == 0) dir = 3;
    else dir--;
}
inline void right(int& dir){
    if (dir == 3) dir = 0;
    else dir++;
}
inline void around(int& dir){
    dir += 2;
    if (dir >= 4) dir -= 4;
}
void move(int& x, int& y, int& dir, char m){
    if (m == 'R'){
        right(dir);
    }else if (m == 'L'){
        left(dir);
    }else{
        x += fx[dir][0];
        y += fx[dir][1];
    }
}
void addWall(int x, int y, int dir){
    if (0 <= x && x < H && 0 <= y && y < W){
        if (dir >= 4) dir %= 4;
        if (dir == 0) graph[x][y] |= 8;
        else if (dir == 1) graph[x][y] |= 2;
        else if (dir == 2) graph[x][y] |= 4;
        else graph[x][y] |= 1;
    }
}
void build(int x, int y, int dir, char m){
    if (m == 'L'){
        left(dir);
    }else if (m == 'R'){
        right(dir);
    }else if (m == 'U'){
        around(dir);
    }
    addWall(x, y, dir);
    addWall(x + fx[dir][0], y + fx[dir][1], dir+2);
}
void goThrough(int& x, int& y, int &dir, string& path){
    int i = 0;
    while(i < path.length()){
        //debug
//        cout << x << ' ' << y << ' ' << dir << endl;
        if (path[i] == 'R' && i < path.length()-1 && path[i+1] == 'R'){
            build(x, y, dir, 'U');
            move(x,y,dir,'R');
            move(x,y,dir,'R');
            i += 2;
        }else{
            build(x, y, dir, path[i]);
            move(x, y, dir, path[i]);
            i++;
        }
    }
}
int test = 0;
void printGraph(){
    printf("Case #%d:\n", ++test);
    for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++)
            printf("%c", (graph[i][j] > 9? graph[i][j]-10+'a':graph[i][j]+'0'));
        cout << endl;
    }
}
void solve(string &forward, string &back){
    int maxX = 0, minY = 0, maxY = 0;
    int x = 0, y = 0, dir = 1;
    for (int i = 0; i < forward.length(); i++) {
        REMAX(maxX, x);
        REMAX(maxY, y);
        REMIN(minY, y);
        move(x, y, dir, forward[i]);
    }
    around(dir);
    for (int i = 0; i < back.length(); i++) {
        move(x, y, dir, back[i]);
        REMAX(maxX, x);
        REMAX(maxY, y);
        REMIN(minY, y);
    }
    graph = vector<vector<int> >(maxX, vector<int>(maxY-minY+1, 0));
    W = maxY - minY + 1;
    H = maxX;
    x = -1, y = 0 - minY;
    dir = 1;
    goThrough(x, y, dir, forward);

    //debug
//    printGraph();
//    cout << endl;
//
    around(dir);
    goThrough(x, y, dir, back);

    printGraph();
}
int main ( int argc, char *argv[] ) {
    whileZ{
        string s1, s2;
        cin >> s1 >> s2;
        solve(s1, s2);
    }
    return EXIT_SUCCESS;
}
