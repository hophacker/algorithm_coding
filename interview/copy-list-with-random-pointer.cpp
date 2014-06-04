//http://www.mitbbs.com/article_t/JobHunting/32708493.html
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
private:
    map<RandomListNode*, RandomListNode*> mRR;
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) return NULL;
        RandomListNode* cur = new RandomListNode(head->label);
        mRR[head] = cur;
        cur->next = copyRandomList(head->next);
        cur->random = mRR[head->random];
        return cur;
    }
};
