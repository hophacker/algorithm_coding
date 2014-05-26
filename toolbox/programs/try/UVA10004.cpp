#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;


#define timeREE		0		/* tree edge */
#define BACK		1		/* back edge */
#define CROSS		2		/* cross edge */
#define FORWARD		3		/* forward edge */

typedef struct edgenode {
    int y;				/* adjancency info */
    int weight;			/* edge weight, if any */
    struct edgenode *next;		/* next edge in list */
} edgenode;



class graph{
protected:
    vector<edgenode*> edges;
    vector<int> degree;
    vector<int> color;

    int nvertices; //1..nvertices
    int nedges;
    int directed;
    bool yes = true;

    vector<bool> processed;	/* which vertices have been processed */
    vector<bool> discovered;  /* which vertices have been found */
    vector<int> parent;	/* discovery relation */

    vector<int> entry_time;         /* time of vertex entry */
    vector<int> exit_time;          /* time of vertex exit */
    int time;                       /* current event time */
    bool finished = false;	/* if true, cut off search immediately */
public:
    graph():directed(false){
    }
    graph(bool dir):directed(dir){
    }
    graph(int n, bool dir):nvertices(n), directed(dir){
        edges = vector<edgenode*>(nvertices+1, NULL);
        degree = vector<int>(nvertices+1, 0);
        nvertices = 0;
        nedges = 0;
    }
    void initialize_search()
    {
        processed = vector<bool>(nvertices+1, false);
        discovered = vector<bool>(nvertices+1, false);
        parent = vector<int>(nvertices+1, -1);
        entry_time = vector<int>(nvertices+1);
        exit_time = vector<int>(nvertices+1);
        time = 0;
    }
    void setnvertices(int n){
        nvertices = n;
        edges = vector<edgenode*>(nvertices+1, NULL);
        degree = vector<int>(nvertices+1, 0);
        color = vector<int>(nvertices+1, -1);
    }
    void insert_edge(int x, int y){
        edgenode *p;			/* temporary pointer */
        p = new edgenode;       /* allocate storage for edgenode */
            p->weight = 0;
            p->y = y;
            p->next = edges[x];
        edges[x] = p;		
        degree[x] ++;
        nedges ++;
    }
    bool read_graph(){
        int n;
        int m;				/* number of edges */
        int x, y;			/* vertices in edge (x,y) */
        scanf("%d %d",&n,&m);
        if (n == 0) return false;
        setnvertices(n);

        for (int i=1; i<=m; i++) {
            scanf("%d %d",&x,&y);
            x++; y++;
            insert_edge(x,y);
            if (!directed){
                insert_edge(y,x);
            }
        }
        return true;
    }
    virtual void process_vertex_early(int v) {
        time = time + 1;
        entry_time[v] = time;
//        printf("entered vertex %d at time %d\n",v, entry_time[v]);
    }

    virtual void process_vertex_late(int v) {
        time = time + 1;
        exit_time[v] = time;
    }

    bool process_edge(int x, int y) {
        if (color[y] == -1){
            color[y] = 1 - color[x];
            return true;
        }else return color[x] != color[y];
    }

    bool bfs(int start)
    {
        queue<int> q;
        int v;				/* current vertex */
        int y;				/* successor vertex */
        edgenode *p;			/* temporary pointer */

        q.push(start);
        discovered[start] = true;

        while (!q.empty()) {
            v = q.front(); q.pop();

            process_vertex_early(v);
            processed[v] = true;
            p = edges[v];
            while (p != NULL) {
                y = p->y;
                if ((processed[y] == false) || directed)
                    if (!process_edge(v,y)){
                        return false;
                    }
                if (discovered[y] == false) {
                    q.push(y);
                    discovered[y] = true;
                    parent[y] = v;
                }
                p = p->next;
            }
            process_vertex_late(v);
        }
        return true;
    }

    bool bfs_graph(){
        for (int i = 1; i <= nvertices; i++) if (!discovered[i]){
            color[i] = 0;
            if (!bfs(i)) return false;
        }
        return true;
    }
};
int main(){
    while(true){
        graph g;
        if (g.read_graph()){
            g.initialize_search();
            if (g.bfs_graph()) cout << "BICOLORABLE." << endl;
            else cout << "NOT BICOLORABLE." << endl;
        }else break;
    }
}
