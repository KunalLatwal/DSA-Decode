https://leetcode.com/problems/rotate-list/

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0) return head;

        ListNode* curr = head;
        int n = 1;
        while(curr->next) {
            curr = curr->next;
            n++;
        }

        k %= n;
        if(k == 0) return head;

        curr->next = head; // make circular

        int steps = n - k;
        while(steps--) curr = curr->next;

        ListNode* newHead = curr->next;
        curr->next = NULL;
        return newHead;
    }
};
