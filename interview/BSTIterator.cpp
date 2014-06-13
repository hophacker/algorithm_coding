#include<iostream>
using namespace std;

template <class T>
struct TreeNode {
    TreeNode<T> *left;
    TreeNode<T> *right;
    TreeNode<T> *parent;
    T data;
    TreeNode(int d):data(d), left(NULL), right(NULL){
    }
    TreeNode<T>* leftMost(){
        TreeNode<T>* cur = this;
        while(cur->left) cur = cur->left;
        return cur;
    }
};


template <class T>
class BST{
    TreeNode<T> *root = NULL;
public:

    void add(T x){
        TreeNode<T>* newNode = new TreeNode<T>(x);
        add(newNode, root, NULL);
    }

    void add(TreeNode<T>* newNode, TreeNode<T>*& cur, TreeNode<T>* parent){
        if (!cur) cur = newNode, cur->parent = parent;
        else if (newNode->data == cur->data){
            cout << "Duplicate Nodes" << endl;
        }
        else if (newNode->data < cur->data)
            add(newNode, cur->left, cur);
        else 
            add(newNode, cur->right, cur);
    }

    TreeNode<T>* find(T x){
        TreeNode<T> * cur = root;
        while(cur){
            if (cur->data == x) return cur;
            else if (cur->data < x) cur = cur->left;
            else cur = cur->right;
        }
        return NULL;
    }

    ~BST(){
        deleteTree(root);
    }
    void deleteTree(TreeNode<T>* cur){
        if (cur){
            deleteTree(cur->left);
            deleteTree(cur->right);
            free(cur);
        }
    }
    class iterator{
    private:
        TreeNode<T>* cur;
    public:
        iterator(TreeNode<T>* cur):cur(cur){
        }
        iterator& operator++(){

            if (cur->right) cur = cur->right->leftMost();
            else if (cur->parent && cur->parent->left == cur) cur = cur->parent;
            else cur = NULL;
            return  *this;
        }
        bool operator != (iterator itr){
            return cur != itr.cur;
        }
        T operator*(){
            return cur->data;
        }
    };
    iterator begin(){
        TreeNode<T>* cur = root;
        if (cur == NULL) return iterator(NULL);
        else{
            cur = cur->leftMost();
            while(cur->left) cur = cur->left;
            return iterator(cur);
        }
    }
    iterator end(){
        return iterator(NULL);
    }
};


int main(){
    BST<int> bst;
    bst.add(2);
    bst.add(1);
    bst.add(3);
    bst.add(13);
    bst.add(31);
    for (BST<int>::iterator i = bst.begin(); i != bst.end(); ++i){
        cout << *i << endl;
    }
}
