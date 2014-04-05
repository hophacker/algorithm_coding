#include <cmath>
#include <vector>
#include <map>
#include <queue>
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
#define ui unsigned int
typedef int elem_t;
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
int T, Q, N;
struct POINT{
    int index;
    double x, y;
};
struct LOCATION{    
    double x, y;
};
struct DIS{
    int index;
    double dis;
    bool operator<(const DIS &b)const{
        if (abs(dis-b.dis) < 0.001) return index > b.index;
        else return dis < b.dis;
    }
    DIS(const int INDEX, const double DIS){
        index = INDEX, dis = DIS;
    }
};
struct RELTOPICS{
    int index;
    vi topics;
    RELTOPICS(int i, vi t){
        index = i;
        topics = t;
    }
};
vector<POINT> topics;
POINT topicsA[100001];
vector<RELTOPICS > questions;
ui num;
double x, y;
inline double Distance(double _x, double _y){
    double dx = x - _x, dy = y - _y;
    return sqrt(dx*dx + dy*dy);

}
inline double Distance(int id){
    double dx = x - topicsA[id].x, dy = y - topicsA[id].y;
    return sqrt(dx*dx + dy*dy);
}
void generateRes(priority_queue<DIS>& q){
    vector<int> res;
    while(!q.empty()){
        res.push_back(q.top().index);
        q.pop();
    }
    for (int i = res.size()-1; i >= 0; i--)
        printf("%d%c", res[i], i==0?'\n':' ');
}
void add(priority_queue<DIS> &q, DIS &a){
    if (q.size() < num) q.push(a);
    else if (a < q.top()) {
        q.push(a);
        q.pop();
    }
}
double distanceFromQue(int i){
    double dis = Distance(questions[i].topics[0]);
    for (ui j = 1; j < questions[i].topics.size(); j++)
        dis = min(dis, Distance(questions[i].topics[j]));
    return dis;
}
void findTopics(){
    priority_queue<DIS> q;
    for (ui i = 0; i < topics.size(); i++){
        double dis = Distance(topics[i].x, topics[i].y);
        DIS a(topics[i].index, dis);
        add(q, a);
    }
    generateRes(q);
}
void findQuestions(){
    priority_queue<DIS> q;
    for (ui i = 0; i < questions.size(); i++){
        double dis = distanceFromQue(i);
        DIS a(questions[i].index, dis);
        add(q, a);
    }
    generateRes(q);
}
int main ( int argc, char *argv[] ) {
    cin >> T >> Q >> N;
    for (int i = 0; i < T; i++){
        POINT p;
        cin >> p.index >> p.x >> p.y;
        topicsA[p.index].x = p.x;
        topicsA[p.index].y = p.y;
        topics.push_back(p);
    }
    for (int i = 0; i < Q; i++){
        int qn, id, index;
        vector<int> ts;
        cin >> index >> qn;
        if (qn == 0) continue;
        while(qn--){
            cin >> id;
            ts.push_back(id);
        }
        questions.push_back(RELTOPICS(index, ts));
    }
    for (int i = 0; i < N; i++){
        char cho;
        cin >> cho >> num >> x >> y;
        if (num == 0){
            cout << endl;
            continue;
        }
        if (cho == 't') findTopics();
        else findQuestions();
    }
    return EXIT_SUCCESS;
}
