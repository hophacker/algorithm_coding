#include <cmath>
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
struct node{
    string type;
    float score;
    vector<string> tokens;
    int time;
};
int N;
ui num;

struct ansNode{
    string id;
    float score;
    int time;
    ansNode(const string& _id, const float& _score, const int& _time){
        id = _id;
        score = _score;
        time = _time;
    }
    bool operator<(const ansNode &b)const{
        if (score == b.score) return time > b.time;
        else return score > b.score;
    }
};
map<string, node> expr;
inline bool pre(string& sub, string& s){
    if (s.length() < sub.length()) return false;
    for (ui i = 0; i < sub.length(); i++)
        if (s[i] != sub[i]) return false;
    return true;
}
inline bool prefix(string& word, vector<string>& tokens){
    int L = 0, R = tokens.size() - 1, M;
    while(L <= R){
        M = (L+R) >> 1;
        if (pre(word, tokens[M])) return true;
        else{
            if (word > tokens[M]) L = M+1;
            else R = M-1;
        }
    }
    return false;
}
bool check(vector<string>& words, vector<string>& tokens){
    for (ui i = 0; i < words.size(); i++){
        if (!prefix(words[i], tokens)) return false;
    }
    return true;
}
void add(priority_queue<ansNode> &q, ansNode &a){
    if (q.size() < num) q.push(a);
    else if (a < q.top()) {
        q.push(a);
        q.pop();
    }
}
void printAnsNodes(priority_queue<ansNode> &q){
    if (q.size() == 0){
        cout << endl;
        return;
    }
    vector<string> res;
    res.reserve(q.size());
    while(!q.empty()){
        res.push_back(q.top().id);
        q.pop();
    }
    for (int i = res.size()-1; i >= 0; i--)
        cout << res[i] << (i==0?'\n':' ');
}
map<string, int> typeIdScore;
void extractScore(string& b){
    for (ui i = 0; i < b.length(); i++)
        if (b[i] == ':') b[i] = ' ';
    istringstream is(b);
    float score;
    string typeId;
    is >> typeId >> score;
    typeIdScore[typeId] = score;
}

inline float getScore(const string& typeId){
    if (typeIdScore.find(typeId) == typeIdScore.end()) return 1;
    else return typeIdScore[typeId];
}
inline void lowerIt(string &s){
    for (ui i = 0; i < s.length(); i++)
        if ('A' <= s[i] && s[i] <= 'Z')
            s[i] = s[i] - 'A' + 'a';
}
void processWords(int classes){
    string line;
    vector<string> words;
    string word;
    getline(cin, line);
    istringstream is(line);
    while(is >> word) {
        lowerIt(word); 
        words.push_back(word); 
    }

    priority_queue<ansNode> q;

    for (map<string,node>::iterator x = expr.begin(); x != expr.end(); x++){
        vector<string>& tokens = x->second.tokens;
        float score;
        if (classes == 0) 
            score = x->second.score;
        else{
            score = getScore(x->second.type) * 
                getScore(x->first) * x->second.score; //type + id
        }
        if (check(words, tokens)){
            ansNode an(ansNode(x->first, score, x->second.time));
            add(q, an);
        }
    }
    printAnsNodes(q);
}
int main ( int argc, char *argv[] ) {
    cin >> N;
    string line, com, type, id, token;
    int time = 0;
    while(N--){
        cin >> com;
        if (com == "ADD"){
            node t;
            t.time = time++;
            cin >> t.type >> id >> t.score;
            getline(cin, line);
            istringstream is(line);
            while(is >> token){
                lowerIt(token);
                t.tokens.push_back(token);
            }
            sort(t.tokens.begin(), t.tokens.end());
            //for (ui i = 0; i < t.tokens.size(); i++){
            //    cout << t.tokens[i] << (i == t.tokens.size()-1? '\n':' ');
            //}
            expr[id] = t;
        }else if (com == "DEL"){
            cin >> id;
            expr.erase(id);
        }else if (com == "QUERY"){
            cin >> num;
            if (num == 0){
                getline(cin, line);
                cout << endl;
                continue;
            }
            processWords(0);
        }else{ //"WQUERY"
            typeIdScore.clear();
            int numOfB;
            cin >> num >> numOfB;
            if (num == 0){
                getline(cin, line);
                cout << endl;
                continue;
            }
            for (int i = 0; i < numOfB; i++){
                string b;
                cin >> b;
                extractScore(b);
            }
            processWords(1);
        }
    }
    return EXIT_SUCCESS;
}
