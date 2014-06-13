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
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
    TreeNode(int x, TreeNode* l, TreeNode* r): val(x), left(l), right(r){}
};
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

void printIntervals(vector<Interval> i){
    F(j,0,i.size()){
        cout << i[j].start << ' ' << i[j].end << endl;
    }
}
void printTreeNode(TreeNode* cur){
    cout << cur->val << ' ';

    if (cur->left == NULL) cout << "NULL" << ' ';
    else {
        cout << cur->left->val << ' ';
    }

    if (cur->right == NULL) cout << "NULL" << endl;
    else {
        cout << cur->right->val << endl;
    }
}


void printTree(TreeNode* cur){
    if (cur == NULL) return;
    printTreeNode(cur);
    printTree(cur->left);
    printTree(cur->right);
}
void addNode(ListNode* &head, int x){
    ListNode *a = new ListNode(x);
    if (head == NULL){
        head = a;
    }else{
        a->next = head;
        head = a;
    }
}
void printList(ListNode* head){
    while(head != NULL){
        cout << head->val << ' ';
        head = head->next;
    }
    cout << endl;
}
void printDoubleLinkedList(TreeNode* head){
    TreeNode* h = head;
    cout << h << endl;
    do{
        cout << head->left->val << ' ' << head->val << ' ' << head->right->val << endl;
        head = head->right;
        cout << head << endl;
    }while(head != h);
}


TreeNode* treeExample7(){
    TreeNode* a0 = new TreeNode(1);
    TreeNode* a1 = new TreeNode(2);
    TreeNode* a2 = new TreeNode(3);
    TreeNode* a3 = new TreeNode(4);
    TreeNode* a4 = new TreeNode(5);
    TreeNode* a5 = new TreeNode(6);
    TreeNode* a6 = new TreeNode(7);
    a4->left = a5;
    a4->right = a6;
    a2->left = a3;
    a2->right = a4;
    a0->left = a1;
    a0->right = a2;
    return a0;
}
TreeNode* treeExample2(){
    TreeNode* a0 = new TreeNode(1);
    TreeNode* a1 = new TreeNode(2);
    a0->left = a1;
    return a0;
}



void iterativeInorder(TreeNode* root){
    stack<TreeNode*> st;
    TreeNode* cur = root;
    while(!st.empty() || cur){
        if (cur){
            st.push(cur);
            cur = cur->left;
        }else{
            cur = st.top(); st.pop();
            printTreeNode(cur);
            cur = cur->right;
        }
    }
}


void flat(TreeNode* cur, TreeNode*& head, TreeNode*& tail){
    if (cur){
        TreeNode *head1, *head2, *tail1, *tail2;
        flat(cur->left, head1, tail1);
        flat(cur->right, head2, tail2);

        cur->left = NULL;
        head = tail = cur;


        if (head1)
            head->right = head1, tail = tail1;

        if (head2)
            tail->right = head2, tail = tail2;


    }else{
        head = NULL;
        tail = NULL;
    }
}
void flatten(TreeNode *root) {
    TreeNode *head, *tail;
    flat(root, head, tail);
}
void testFlatten(){
    TreeNode *root = treeExample2();
    flatten(root);
    cout << root << ' ' << root->right << endl;
}
void testIterativeInorder(){
    TreeNode* root = treeExample7();
//    printTree(root);
    iterativeInorder(root);
}

class buildTreeOfInorderAndPostorder {
private:
    TreeNode *convert(vector<int> &inorder, vector<int> &postorder, int iL, int pL, int len){
        if (len == 0) return NULL;
        TreeNode* cur = new TreeNode(postorder[pL+len-1]);
        
        if (len == 1) return cur;
        
        
        int i = find(inorder.begin()+iL, inorder.begin()+iL+len, postorder[pL+len-1]) - inorder.begin() - iL;
        
        cur->left = convert(inorder, postorder, iL, pL, i);
        cur->right = convert(inorder, postorder, iL+i+1, pL+i, len-1-i);
        return cur;
    }
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return convert(inorder, postorder, 0, 0, inorder.size());
    }
};
void testBuildTreeOfInorderAndPostorder(){
    buildTreeOfInorderAndPostorder s;
    int a1[] = {2,1};
    int a2[] = {2,1};
    vector<int> A1(a1, a1+sizeof(a1)/4);
    vector<int> A2(a2, a2+sizeof(a2)/4);

    TreeNode *root = s.buildTree(A1, A2);
    printTree(root);
}

int main(){
}
