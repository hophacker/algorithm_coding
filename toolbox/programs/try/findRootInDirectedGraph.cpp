#include "graph.cpp"



class findRootInDirectedGraph: public graph{
private:
    vector<int> fa;
public:
    findRootInDirectedGraph():graph(true){
    }
    void read_graph(){
        graph::read_graph();
        fa = vector<int>(nvertices+1);
        for (int i = 1; i <= nvertices; i++) fa[i] = i;
    }
    int father(int x){
        if (fa[x] == x) return x;
        else return fa[x] = father(fa[x]);
    }
    void process_vertex_early(int v) {
        graph::process_vertex_early(v);
    }
    void process_vertex_late(int v) {
        graph::process_vertex_late(v);
    }
    void process_edge(int x, int y) {
        if (father(y) == y) fa[y] = x;
    }
    int edge_classification(int x, int y) {
        graph::edge_classification(x, y);
    }
    int getRoot(){
        int f = father(1);
        for (int i = 2; i <= nvertices; i++){
            if (father(i) != f) return -1;
        }
        return f;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    findRootInDirectedGraph g;
    g.read_graph();
    g.print_graph();
    g.initialize_search();
    g.dfs_graph();
    cout << g.getRoot() << endl;
}

