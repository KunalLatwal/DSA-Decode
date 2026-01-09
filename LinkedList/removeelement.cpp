🔗 https://leetcode.com/problems/remove-linked-list-elements/

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* curr = dummy;
        while(curr->next) {
            if(curr->next->val == val)
                curr->next = curr->next->next;
            else
                curr = curr->next;
        }
        return dummy->next;
    }
};
