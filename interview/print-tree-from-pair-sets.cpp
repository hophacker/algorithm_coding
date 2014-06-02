#include<string>
#include<iostream>
#include<queue>
#include<vector>
#include<map>
#include<set>
using namespace std;



class solution{
private:
    int totalIndex = 0;
    int n;
    map<string, int> label2Index;
    vector<string> index2Label;
    vector<int> indegree;
    vector<set<int> > edges;
    vector<bool> visited;
    inline int setIndex(string s){
        if(label2Index.find(s) == label2Index.end())
            label2Index[s] = totalIndex++;
    }
    void dumpIndex(set<pair<string,string> > P){
        for (auto i = P.begin(); i != P.end(); i++){
            setIndex(i->first);
            setIndex(i->second);
        }

        n = label2Index.size();
        index2Label = vector<string>(n);
        indegree = vector<int>(n, 0);
        edges = vector<set<int> >(n);

        for (auto i = label2Index.begin(); i != label2Index.end(); i++){
            index2Label[i->second] = i->first;
        }
    }
public:
    solution(){
    }
    bool validTree(int x){
        visited = vector<bool>(n, false);
        queue<int> Q;
        Q.push(x);
        int visitedNum = 0;
        while(!Q.empty()){
            int u = Q.front();
            Q.pop();
            visited[u] = true;
            visitedNum++;
            for (auto i = edges[u].begin(); i != edges[u].end(); i++){
                if (!visited[*i]){
                    Q.push(*i);
                }else return false;
            }
        }
        return visitedNum == n;
    }
    void printTree(int u, int level){
        cout << string(level, ' ') << index2Label[u] << endl;
        for (auto i = edges[u].begin(); i != edges[u].end(); i++){
            printTree(*i, level+1);
        }
    }
    void printTreeFromPairSet(set<pair<string,string> > P){
        dumpIndex(P);
        for (auto i = P.begin(); i != P.end(); i++){
            int i1 = label2Index[i->first];
            int i2 = label2Index[i->second];
            edges[i1].insert(i2);
            indegree[i2]++;
        }

        int head = -1;
        int countHeads = 0;
        for (int i = 0; i < indegree.size(); i++){
            if (indegree[i] == 0){ 
                head = i;
                countHeads++;
            }
        }
        if (countHeads != 1 || !validTree(head)){
            cout << "These pairs can't consist a Tree!!!" << endl;
        }else{
            printTree(head, 0);
        }
    }
};

int main(){
    set<pair<string, string> > P;
    P.insert(make_pair("a", "b"));
    P.insert(make_pair("b", "c"));
    P.insert(make_pair("a", "d"));
    P.insert(make_pair("d", "e"));
    P.insert(make_pair("d", "f"));
    P.insert(make_pair("d", "g"));
    solution s;
    s.printTreeFromPairSet(P);
}
