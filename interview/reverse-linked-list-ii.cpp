/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *curPre = NULL, *cur = head, *h = NULL, *t = NULL;
        for (int i = 0; i < m-1; i++) curPre = cur, cur = cur->next;
                
        h = t = cur;
        cur = cur->next;
        
        
        for (int i = m+1; i <= n; i++){
            ListNode* temp = cur->next;
            cur->next = h;
            h = cur;
            cur = temp;
        }
        
        t->next = cur;
        
        if (curPre) curPre->next = h;
        else head = h;
        
        return head;
    }
};
