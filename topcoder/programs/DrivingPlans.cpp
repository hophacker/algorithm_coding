#include <climits>
#include <queue>
#include <vector>
#include <fstream>
#include <iomanip>   
#include <iostream>  
#include <algorithm>
using namespace std;
#define F(i,L,R) for (int i = L; i < R; i++)
#define FE(i,L,R) for (int i = L; i <= R; i++)
#define FF(i,L,R) for (int i = L; i > R; i--)
#define FFE(i,L,R) for (int i = L; i >= R; i--)
const int maxint = 400000000;
class DrivingPlans
{
struct node{
    int v, w;
    node(int v, int w):v(v), w(w){

    }
};
    public:
        int count(int N, vector <int> A, vector <int> B, vector <int> C) {

            int M = A.size();
            vector<vector<node> > edges(N+1, vector<node>());
            queue<int> oh;
            vector<bool> vis(N+1, false);
            F(i,0,M){
                edges[A[i]].push_back(node(B[i],C[i]));
                edges[B[i]].push_back(node(A[i],C[i]));
                if (C[i] == 0){
                    oh.push(A[i]);
                    oh.push(B[i]);
                    vis[A[i]] = true;
                    vis[B[i]] = true;
                }
            }


            vector<int> dis(N+1, maxint);
            vector<int> ways(N+1, 0);
            vector<bool> update(N+1, false);
            dis[1] = 0;
            ways[1] = 1;
            update[1] = true;
            F(times, 0, N-1){
                vector<bool> update1(N+1, false);
                F(i,0,M){
                    int u = A[i];
                    int v = B[i];
                    int w = C[i];
                    if (update[u]){
                        if(dis[u] + w < dis[v]){
                            dis[v] = dis[u] + w;
                            ways[v] = ways[u];
                            update1[v] = true;
                        }else if (dis[u] + w == dis[v]){
                            ways[v] += ways[u];
                        }
                    }

                    swap(u,v);
                    if (update[u]){
                        if(dis[u] + w < dis[v]){
                            dis[v] = dis[u] + w;
                            ways[v] = ways[u];
                            update1[v] = true;
                        }else if (dis[u] + w == dis[v]){
                            ways[v] += ways[u];
                        }
                    }
                }
                update = update1;
            }

            while(!oh.empty()){
                int u = oh.front(); oh.pop();
                if (u == N) return -1;
                F(i,0,edges[u].size()){
                    int v = edges[u][i].v;
                    int w = edges[u][i].w;
                    if (!vis[v] && dis[u] + w == dis[v]){
                        oh.push(v);
                        vis[v] = true;
                    }
                }
            }
            return ways[N];
        }

        

};
