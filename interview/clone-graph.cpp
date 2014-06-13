#include<vector>
#include<map>
using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
private:
    map<UndirectedGraphNode *, UndirectedGraphNode *> mNN;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) return NULL;
        
        vector<UndirectedGraphNode *>& neighbors = node->neighbors;
         
        UndirectedGraphNode* cur = new UndirectedGraphNode(node->label);
        mNN[node] = cur;
        
        for (int i = 0; i < neighbors.size(); i++){
            if (mNN.find(neighbors[i]) == mNN.end()){
                (cur->neighbors).push_back(cloneGraph(neighbors[i]));         
            }else (cur->neighbors).push_back(mNN[neighbors[i]]);
        }
        
        return cur;

    }
};
