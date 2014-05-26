#include "graph.cpp"


class determineTriangle:public graph{
private:
    bool triangles = false;
public:
    determineTriangle():graph(){
    }
    void process_vertex_early(int v) {
        graph::process_vertex_early(v);
    }
    void process_vertex_late(int v) {
        graph::process_vertex_late(v);
    }
    void process_edge(int x, int y) {
/*         cout << x << ' ' << y << endl;
 *         return;
 *         cout << x << ' ' << y << ' ' << parent[y] << ' ' ;
 *         if (parent[y] != -1) cout << parent[parent[y]] << endl;else cout << endl;
 */
        if (parent[x] != -1 && parent[parent[x]] == y) triangles = true;
    }
    int edge_classification(int x, int y) {
        graph::edge_classification(x, y);
    }
    void output(){
        cout << "There are " << (triangles?"":"no ") << "triangles.\n";
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    determineTriangle g;
    g.read_graph();
    g.print_graph();
    g.initialize_search();
    g.dfs_graph();
    g.output();
}
