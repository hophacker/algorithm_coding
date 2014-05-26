#include <cmath>
#include <set>
#include <list>
//#include <unordered_set>
//#include <hash_map>
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
#define lowb(t) (t &(-t))
#define pow2(x) (1<<x)
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
#define root(x) ((int)sqrt((double)x))
#define wez(n) int (n); scanf("%d",&(n));
#define wez2(n,m) int (n),(m); scanf("%d %d",&(n),&(m));
#define wez3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k));
inline void pisz(int n) { printf("%d\n",n); }
#define TESTS wez(testow)while(testow--)
#define whileZ int T; getI(T); while(T--)
#define printA(a,L,R) FE(i,L,R) cout << a[i] << (i==R?'\n':' ')
#define printM(a,n,m) F(i,0,n){ F(j,0,m) cout << a[i][j] << ' '; cout << endl;}
#define printV(a) printA(a,0,(int)a.size()-1);
#define printVV(a) F(i,0,a.size()) {F(j,0,a[i].size())cout << a[i][j] << ' '; cout << endl;}
#define MAXN 10000
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(auto i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
template<class T> string tos(T n) { stringstream ss; ss << n; return ss.str(); }
#define tiny (double)1e-13
#define close(x,y) (abs(x-y)<tiny)
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
const int fxx[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};

// (tree edge,back edge, cross edge, forward edge)
enum{timeREE, BACK, CROSS, FORWARD};
struct edgenode {
    int y;				/* adjancency info */
    int weight;			/* edge weight, if any */
    struct edgenode *next;		/* next edge in list */
};

class graph{
protected:
    vector<edgenode*> edges;
    vector<int> degree;

    int nvertices; //1..nvertices
    int nedges;
    int directed;

    vector<bool> processed;	/* which vertices have been processed */
    vector<bool> discovered;  /* which vertices have been found */
    vector<int> parent;	/* discovery relation */

    vector<int> entry_time;         /* time of vertex entry */
    vector<int> exit_time;          /* time of vertex exit */
    int time;                       /* current event time */
    bool finished = false;	/* if true, cut off search immediately */
public:
    graph():directed(false){
    }
    graph(bool dir):directed(dir){
    }
    graph(int n, bool dir):nvertices(n), directed(dir){
        edges = vector<edgenode*>(nvertices+1, NULL);
        degree = vector<int>(nvertices+1, 0);
        nvertices = 0;
        nedges = 0;
    }
    void initialize_search()
    {
        processed = vector<bool>(nvertices+1, false);
        discovered = vector<bool>(nvertices+1, false);
        parent = vector<int>(nvertices+1, -1);
        entry_time = vector<int>(nvertices+1);
        exit_time = vector<int>(nvertices+1);
        time = 0;
    }
    void setnvertices(int n){
        nvertices = n;
        edges = vector<edgenode*>(nvertices+1, NULL);
        degree = vector<int>(nvertices+1, 0);
    }
    void insert_edge(int x, int y){
        edgenode *p;			/* temporary pointer */
        p = new edgenode;       /* allocate storage for edgenode */
            p->weight = 0;
            p->y = y;
            p->next = edges[x];
        edges[x] = p;		
        degree[x] ++;
        nedges ++;
    }
    bool read_graph(){
        wez2(n,m);
        setnvertices(n);
        for (int i=1; i<=m; i++) {
            wez2(x,y);
            insert_edge(x,y);
            if (!directed){
                insert_edge(y,x);
            }
        }
        return true;
    }
    void print_graph() {
        edgenode *p;			/* temporary pointer */
        cout << "Graph Printing...." << endl;
        for (int i=1; i<= nvertices; i++) {
            printf("%d: ",i);
            p = edges[i];
            while (p != NULL) {
                printf(" %d",p->y);
                p = p->next;
            }
            printf("\n");
        }
    }
    void dfs(int v) {
        edgenode *p;			/* temporary pointer */
        int y;				/* successor vertex */

        if (finished) return;		/* allow for search termination */

        discovered[v] = true;
        time = time + 1;
        entry_time[v] = time;

        process_vertex_early(v);

        p = edges[v];
        while (p != NULL) {
            y = p->y;
            if (discovered[y] == false) {
                parent[y] = v;
                process_edge(v,y);
                dfs(y);
            } 
            else if ((!processed[y]) || (directed))
                process_edge(v,y);

            if (finished) return;

            p = p->next;
        }
        process_vertex_late(v);

        time = time + 1;
        exit_time[v] = time;
        processed[v] = true;
    }
    virtual void dfs_graph(){
        for (int i = 1; i <= nvertices; i++) if (!discovered[i])
            dfs(i);
    }

    virtual void process_vertex_early(int v) {
        time = time + 1;
        entry_time[v] = time;
    }

    virtual void process_vertex_late(int v) {
        time = time + 1;
        exit_time[v] = time;
    }

    virtual void process_edge(int x, int y) {
//        int cla = edge_classification(x,y);
    }
    virtual int edge_classification(int x, int y) {
        if (parent[y] == x) return(timeREE);
        if (discovered[y] && !processed[y]) return(BACK);
        if (processed[y] && (entry_time[y]>entry_time[x])) return(FORWARD);
        if (processed[y] && (entry_time[y]<entry_time[x])) return(CROSS);
    }
    void bfs(int start)
    {
        queue<int> q;
        int v;				/* current vertex */
        int y;				/* successor vertex */
        edgenode *p;			/* temporary pointer */

        q.push(start);
        discovered[start] = true;

        while (!q.empty()) {
            v = q.front(); q.pop();

            process_vertex_early(v);
            processed[v] = true;
            p = edges[v];
            while (p != NULL) {
                y = p->y;
                if ((processed[y] == false) || directed)
                    process_edge(v,y);
                if (discovered[y] == false) {
                    q.push(y);
                    discovered[y] = true;
                    parent[y] = v;
                }
                p = p->next;
            }
            process_vertex_late(v);
        }
    }
    void bfs_graph(){
        for (int i = 1; i <= nvertices; i++) if (!discovered[i]){
            bfs(i);
        }
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    graph g;
    g.read_graph();
    g.print_graph();
    g.initialize_search();
    g.dfs_graph();
}
