#include <cmath>
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
int gcd(int a,int b){return a?gcd(b%a,a):b;}
ll gcd(ll a,ll b){return a?gcd(b%a,a):b;}
ll powmod(ll a,ll p,ll m){ll r=1;while(p){if(p&1)r=r*a%m;p>>=1;a=a*a%m;}return r;}
const int fx[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
    vector<int> res;
    vector<int> inorder;
    vector<int> postorder;
public:
    int findInorder(int x, int p, int len){
        for (int i = 0; i < len; i++) if (inorder[i+p] == x) return i;
    }
    TreeNode *buildIt(int ii, int pi, int len) {
        if (len == 0) return NULL;
        int head = postorder[pi+len-1];
        TreeNode* node = new TreeNode(head);
        int i = findInorder(head, ii, len);
        node->left = buildIt(ii, pi, i);
        node->right = buildIt(ii+i+1, pi+i, len-1-i);
        return node;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        this->inorder = inorder;
        this->postorder = postorder;
        return buildIt(0, 0, inorder.size());
    }
};
void printTree(TreeNode* cur){
    if (cur == NULL) return;
    cout << cur->val << ' ';

    if (cur->left == NULL) cout << "NULL" << ' ';
    else {
        cout << cur->left->val << ' ';
    }

    if (cur->right == NULL) cout << "NULL" << endl;
    else {
        cout << cur->right->val << endl;
    }
    printTree(cur->left);
    printTree(cur->right);
}
int main ( int argc, char *argv[] ) {
    /*{
    FILE* file = fopen(argv[1], "r");
    int a, b;
    while(fscanf(file, "%d,%d", &a, &b) != EOF){
    }*/
    /*
    getI(T);
    int T;
    FE(cases,1,T){
        printf("Cases #%d: ", cases);
    }
    }*/
    /*
    Solution s = Solution();
     */
    int inorder[] = {4,2,5, 1, 6, 3};
    int postorder[] = {4,5,2, 6 ,3, 1};
    int n = sizeof(inorder) >> 2;
    vector<int> i = vector<int>(inorder, inorder+n);
    vector<int> p = vector<int>(postorder, postorder+n);
    Solution s = Solution();
    printTree(s.buildTree(i, p));
    return EXIT_SUCCESS;
}
