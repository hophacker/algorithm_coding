#include<iostream>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;

struct node{
    string word;
    int times;
    bool operator<(const node& b)const{
        if (times == b.times) return word > b.word;
        else return times < b.times;
    }
    node(string w, int t){
        word = w;
        times = t;
    }
};
int main(){
    map<string, int> fre;
    int n;
    cin >> n;
    string s;
    while(n--){
        cin >>  s;
        if (fre.find(s) == fre.end())
            fre[s] = 1;
        else fre[s]++;
    }
    priority_queue<node> q;
    for(map<string,int>::const_iterator it = fre.begin(); it != fre.end(); ++it) {
        q.push(node(it->first, it->second));
    }
    int k;
    cin >> k;
    while(k--){
        node t = q.top();
        q.pop();
        cout << t.word << endl;
    }
}






