#include<iostream>
#include<stack>
using namespace std;


struct TreeNode{
    TreeNode *left, *right, *father;
    int data;
    int height;
    TreeNode(int d):data(d), height(1), left(NULL), right(NULL), father(NULL){
    }
    TreeNode(int d, TreeNode* fa):data(d), height(1), 
        left(NULL), right(NULL), father(fa){
    }
};


class BST{
    TreeNode* root;
    BST(){
        root = NULL;
    }
    inline int H(TreeNode* cur){
        if (cur == NULL) return 0;
        else return cur->height;
    }
    void rightRotation(TreeNode* cur, TreeNode* fa, TreeNode* grandFa){

    }
    void insert(int d){
        if (root == NULL) root = new TreeNode(d);
        else{
            TreeNode* cur = root, *fa = NULL;
            while(cur != NULL){
                fa = cur;
                if (cur->data == d) return;
                else if (d < cur->data) cur = cur->left;
                else cur = cur->right;
            }
            cur = new TreeNode(d, fa);
            if (d < fa->data) fa->left = cur;
            else fa->right = cur;

            fa->height = max(H(fa->left), H(fa->right)) + 1;

            TreeNode* grandFa = fa->father;

            while(grandFa != NULL){
                H(grandFa->left), H(grandFa->right)

                if (grandFa->left == fa){
                    if (fa->left == cur){
                        rightRotation(cur, fa, grandFa);

                    }else{

                    }
                }else{
                    if (fa->right == cur){
                    }else{

                    }
                }
            }


        }
    }
    bool find(int x){
    }
};
