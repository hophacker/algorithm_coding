#include<iostream>
using namespace std;



class TreeNode{
public:
    int key;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
    TreeNode(int key):key(key), left(NULL), right(NULL), parent(NULL){}
    TreeNode* leftMost(){
        TreeNode* cur = this;
        while(cur->left != NULL) cur = cur->left;
        return cur;
    }
};


class BST{
private:
    TreeNode* root = NULL;
public:
    class BSTIterator{
        TreeNode* current;
    public:
        BSTIterator(TreeNode* cur){
            current = cur;
        }
        BSTIterator& operator++(){
            TreeNode* cur;
            while(cur->right == NULL){
                if (cur->parent == NULL){
                    return ;
                }
                    cur->parent;
            }
        }
    };
    BST(){}
    void addNode(int key){
        if (root == NULL) root = new TreeNode(key);
        else{
            addNode(key, root, NULL);
        }
    }
    void addNode(int key, TreeNode*& cur, TreeNode* parent){
        if (cur == NULL) {
            cur = new TreeNode(key);
            cur->parent = parent;
        }
        else if (key == cur->key) return;
        else if (key < cur->key) addNode(key, cur->left, cur);
        else addNode(key, cur->right, cur);
    }
    BSTIterator begin(){
        if (root == NULL) return BSTIterator(NULL);
        else{
            return BSTIterator(root->leftMost());
        }
    }
};


int main(){
}

