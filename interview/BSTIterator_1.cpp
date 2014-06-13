#include<iostream>
using namespace std;



struct TreeNode{
    TreeNode *left, *right, *father;
    int data;
    TreeNode(int d, TreeNode* fa):data(d), father(fa), left(NULL), right(NULL){

    }
    TreeNode* leftMost(){
        TreeNode* cur = this;
        while(cur->left) cur = cur->left;
        return cur;
    }
};
class BST{
private:
    TreeNode* root = NULL;
    void insert(TreeNode*& cur, int d, TreeNode* fa){
        if (!cur) cur = new TreeNode(d, fa);
        else if (cur->data == d) return;
        else if (d < cur->data) insert(cur->left, d, cur);
        else insert(cur->right, d, cur);
    }
public:
    void insert(int d){
        insert(root, d, NULL);
    }
    bool find(int d){
        TreeNode* cur = root;
        while(cur){
            if (d == cur->data) return true;
            else if (d < cur->data) cur = cur->left;
            else cur = cur->right;
        }
        return false;
    }
    class iterator{
    private: 
            TreeNode* current;
    public:
        iterator(TreeNode* cur){
            current = cur;
        }
        iterator& operator++(){
            if (current->right) current = current->right->leftMost();
            if (current->father && current->father->left == current)
                current = current->father;
            else current = NULL;
            return *this;
        }
        bool operator != (iterator itr){
            return current != itr.current;
        }
        int operator *(){
            return current->data;
        }
    };

    iterator begin(){
        if (root) return iterator(root->leftMost());
        else return iterator(NULL);
    }
    iterator end(){
        return iterator(NULL);
    }

};

int main(){
    BST bst;
    bst.insert(1);
    bst.insert(3);
    bst.insert(2);
    for (BST::iterator i = bst.begin(); i != bst.end(); ++i){
        cout << *i << endl;
    }
}

