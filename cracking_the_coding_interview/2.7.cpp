#include "leetcode.h"

int listSize(ListNode* head){
    int c = 0;
    while(head != NULL){
        c++, head = head->next;
    }
    return c;
}
bool check(ListNode*& head, int len){
    ListNode* h = head;

    if (len == 0) return true;
    else if (len == 1){
        head = head->next;
        return true;
    }else if (len == 2){
        if (head->val != head->next->val) return false;
        head = head->next->next;
        return true;
    }

    head = head->next;
    bool res = check(head, len-2);
    if (!res) return false;
    res = head->val == h->val;
    head = head->next;
    return res;
}
bool checkPalindrome(ListNode* head){
    int len = listSize(head);
    return check(head, len);
}
int main(){
    ListNode* head = new ListNode(1);
    addNode(head, 2);
    addNode(head, 2);
    addNode(head, 1);
    printList(head);
    cout << checkPalindrome(head) << endl;
}
