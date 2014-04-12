vector<int> link[250];
bool visited[250];
int mX[250], mY[250];
int N,M,K;
int path(int u){
    F(i,0,link[u].size()){
        int v = link[u][i];
        if (!visited[v]){
            visited[v] = 1;
            if (mY[v] == -1 || path(mY[v])){
                mX[u] = v;
                mY[v] = u;
                return 1;
            }
        }
    }
    return 0;
}
int maxMatch(){
    clr(mX, -1);
    clr(mY, -1);
    int res = 0;
    F(i,0,N){
        if (mX[i] == -1){
            clr(visited, 0);
            res += path(i);
        }
    }
    return res;
}
