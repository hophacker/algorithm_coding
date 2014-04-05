/*  
View Code

Problem : 2768 ( Cat vs. Dog )     Judge Status : Accepted
RunId : 9481543    Language : G++    Author : jokerfeng2010
Code Render Status : Rendered By HDOJ G++ Code Render Version 0.01 Beta
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<fstream>
#include<string>
#include<string.h>
#define ll long long
#define maxN 505
using namespace std;

struct Tendency{
    string like, hate;
};

class Catvsdog{
    private:
        int C, D, V;
        vector<int> link[maxN];
        Tendency ten[maxN];
        int pre[maxN];
        int maxThreads;
        bool visit[maxN];
    public:
    Catvsdog();
    void input();
    void process();
    void output();
    void createMap();
    int expand(int);
};

Catvsdog::Catvsdog(){
    input();
}
void Catvsdog::input(){
    cin >> C >> D >> V;
    Tendency tempTen;
    for (int i = 0; i < V; i++)
        cin >> ten[i].like >> ten[i].hate;

}
void Catvsdog::createMap(){
    for (int i = 0; i < V; i++)
        link[i].clear();
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            if (ten[i].like == ten[j].hate || ten[i].hate == ten[j].like)
                link[i].push_back(j);
}
int Catvsdog::expand(int u){
    int v;
    for (int i = 0; i < link[u].size(); i++){
        v = link[u][i];
        if (!visit[v]){
            visit[v] = 1;
            if (pre[v] == -1 || expand(pre[v])){
                pre[v] = u;
                return 1;
            }
        }
    }
    return 0;
}
void Catvsdog::process(){
    createMap();
    memset(pre, -1, sizeof(pre));
    maxThreads = 0;
    for (int i = 0; i < V; i++){
        memset(visit, 0, sizeof(visit));
        maxThreads += expand(i);
    }
}
void Catvsdog::output(){
    cout << V-maxThreads/2 << endl;
}
int main(){
    int cases;
    cin >> cases;
    while(cases--){
        Catvsdog* catvsdog = new Catvsdog();
        catvsdog->process();
        catvsdog->output();
    }
}
