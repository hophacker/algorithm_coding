#include "leetcode.h"

ListNode* removeMiddle(ListNode* head){
    if (!head) return head;
    else if (!head->next){
        free(head);
        return NULL;
    }
    ListNode *h1 = head, *h2 = head->next->next->next;
    while(h2 != NULL){
        h1 = h1->next;
        h2 = h2->next->next;
    }
    h2 = h1->next;
    h1->next = h1->next->next;
    return head;
}
int main(){
    ListNode* head = new ListNode(1);
    addNode(head, 2);
    addNode(head, 3);
    printList(head);
    head = removeMiddle(head);
    printList(head);
}
