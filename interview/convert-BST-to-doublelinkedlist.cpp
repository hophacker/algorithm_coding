#include<iostream>

using namespace std;



struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
    TreeNode(int x, TreeNode* l, TreeNode* r): val(x), left(l), right(r){}
};

TreeNode* convert(TreeNode* root){
    TreeNode *leftHead = NULL, *rightHead = NULL;


    if (root->left != NULL){
        leftHead = convert(root->left);
    }
    if (root->right != NULL){
        rightHead = convert(root->right);
    }

    root->left = root->right = root;

    if (leftHead != NULL){
        leftHead->left->right = root;
        root->left = leftHead->left;
    }else leftHead = root;

    if (rightHead != NULL){
        rightHead->left->right = leftHead;
        leftHead->left = rightHead->left;

        root->right = rightHead;
        rightHead->left = root;
    }

    return leftHead;
}


void printTree(TreeNode* cur){
    if (cur == NULL) return;
    cout << cur->val << ' ';

    if (cur->left == NULL) cout << "NULL" << ' ';
    else {
        cout << cur->left->val << ' ';
    }

    if (cur->right == NULL) cout << "NULL" << endl;
    else {
        cout << cur->right->val << endl;
    }
    printTree(cur->left);
    printTree(cur->right);
}

void printDoubleLinkedList(TreeNode* head){
    TreeNode* h = head;
    cout << h << endl;
    do{
        cout << head->left->val << ' ' << head->val << ' ' << head->right->val << endl;
        head = head->right;
        cout << head << endl;
    }while(head != h);
}

int main(){

    TreeNode* left = new TreeNode(3);
    TreeNode* right = new TreeNode(5);
    TreeNode* root = new TreeNode(4, left, right);
    printTree(root);
    TreeNode* head = convert(root);
    printDoubleLinkedList(head);
}
