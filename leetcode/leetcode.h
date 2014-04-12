#include<iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


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
void addNode(ListNode* &head, int x){
    ListNode *a = new ListNode(x);
    if (head == NULL){
        head = a;
    }else{
        a->next = head;
        head = a;
    }
}
void printList(ListNode* head){
    while(head != NULL){
        cout << head->val << ' ';
        head = head->next;
    }
    cout << endl;
}
