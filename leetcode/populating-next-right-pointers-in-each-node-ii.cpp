/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
private:
    TreeLinkNode *head = NULL, *tail = NULL;
    void add(TreeLinkNode* cur){
        if (head) tail->next = cur, tail = cur;
        else head = tail = cur;
    }
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        root->next = NULL;
        TreeLinkNode* cur = root;
        
        while(cur){
            while(cur){
                if (cur->left) add(cur->left);
                if (cur->right) add(cur->right);
                cur = cur->next;
            }
            cur = head;
            head = tail = NULL;
        }
    }
};
