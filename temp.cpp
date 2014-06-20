#include<queue>
#include<string>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class compare{
    public:
        bool operator()(ListNode*& a, ListNode*& b){
            return a->val > b->val;
        }
};
 
 
class Solution {
private:
    ListNode *head = NULL, *tail = NULL;
    void add(ListNode*& head, ListNode*& tail, ListNode* cur){
        if (head) tail->next = cur, tail = cur;
        else head = tail = cur;
    }
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode *head = NULL, *tail = NULL;
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        for (int  i = 0;i < lists.size(); i++) if (lists[i])
            pq.push(lists[i]);
        while(!pq.empty()){
            ListNode* h = pq.top(); pq.pop();
            add(head, tail, h);
            if (h->next){
                pq.push(h->next);
            }
        }
        return head;
    }
};
