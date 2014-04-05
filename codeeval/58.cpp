#include <cmath>
#include <vector>
#include <map>
#include <queue>
#include <cstdlib>
#include <fstream>
#include <iomanip>   
#include <iostream>  
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
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define fi first
#define se second
#define wez(n) int (n); scanf("%d",&(n));
#define wez2(n,m) int (n),(m); scanf("%d %d",&(n),&(m));
#define wez3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k));
inline void pisz(int n) { printf("%d\n",n); }
#define TESTS wez(testow)while(testow--)
#define whileZ int T; getI(T); while(T--)
#define printA(a,L,R) FE(i,L,R) cout << a[i] << endl
#define printV(a) printA(a,0,a.size()-1)
#define MAXN 30000
typedef int elem_t;
template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){F(i,0,SZ(t))s<<t[i]<<" ";return s; }
vector<string> tests;
vector<string> friends;
vector<int> link[MAXN];
bool isFriends(string& a, string &b){
    if (a.size() - b.size() == 1){
        int i = 0;
        for(;i < b.size() && a[i] == b[i]; i++);
        if (i == b.size()) return true;
        else{
            for (;i < b.size() && a[i+1] == b[i]; i++);
            if (i == b.size()) return true;
            else return false;
        }
    }else if (a.size() == b.size()){
        int count = 0;
        F(i,0,a.size()) if (a[i] != b[i]) count++;
        return count <= 1;
    }else return false;
}
bool isF(string&a, string&b){
    if (a.size() < b.size()) return isFriends(b, a);
    else return isFriends(a, b);
}
bool vis[MAXN];
void doIt(string& test){
    queue<int> q;
    int n = friends.size();
    clr(vis, 0);
    int count = 0;
    F(i,0,friends.size()){
        if (isF(test, friends[i])){
            q.push(i);
            vis[i] = true;
            count ++;
        }
    }
    while(!q.empty()){
        int x = q.front(); q.pop();
        F(i,0,link[x].size()){
            int y = link[x][i];
            if (!vis[y]){
                q.push(y);
                vis[y] = true;
                count++;
            }
        }
    }
    cout << count << endl;
}
int main ( int argc, char *argv[] ) {
    ifstream cin(argv[1]);
    while(!cin.eof()){
        string s;
        getline(cin, s);
        if (s != "END OF INPUT")
            tests.push_back(s);
        else break;
    }
    while(!cin.eof()){
        string s;
        getline(cin, s);
        if (s.size() > 0)
            friends.push_back(s);
    }
//    printV(tests);
//    cout << endl;
//    cout << friends.size() << endl;
//    cout << friends[0].size() << endl;
//    printV(friends);
//    return 0;
    F(i,0,friends.size())
        F(j,i+1,friends.size()){
            if (isF(friends[i], friends[j])){
                link[i].push_back(j);
                link[j].push_back(i);
            }
        }
//    F(i,0,friends.size()) cout << link[i].size() << endl;
//    cout << endl;
    F(i,0,tests.size())
        doIt(tests[i]);
    return EXIT_SUCCESS;
}

