https://leetcode.com/problems/remove-nth-node-from-end-of-list/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* fast = head;
        ListNode* slow = head;

        for (int i = 0; i < n; i++)
            fast = fast->next;

        if (fast == NULL) {
            ListNode* del = head;
            head = head->next;
            delete del;
            return head;
        }

        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* del = slow->next;
        slow->next = del->next;
        delete del;

        return head;
    }
};
