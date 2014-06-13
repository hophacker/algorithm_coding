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
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *cur, *tail, *retHead = NULL, *retTail = NULL;
        int size = 0;
        cur = head;
        while(cur){
            size++;
            cur = cur->next;
        }
        while(size >= k){
            size -= k;
            
            for (int i = 0; i < k; i++){
                ListNode* temp = head->next;
                
                if (i == 0) cur = tail = head;
                else{
                    head->next = cur;
                    cur = head;
                }
                
                head = temp;
            }
            
            if (retHead) retTail->next = cur;
            else retHead = cur;
            
            retTail = tail;
        }
        if (retTail) retTail->next = head;
        else retHead = head;
        
        return retHead;
    }
};
