https://leetcode.com/problems/odd-even-linked-list/

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* odd = head;          // odd position
        ListNode* even = head->next;   // even position
        ListNode* evenHead = even;     // even list start

        while (even && even->next) {
            odd->next = even->next;    // odd -> next odd
            odd = odd->next;

            even->next = odd->next;    // even -> next even
            even = even->next;
        }

        odd->next = evenHead;          // join both lists
        return head;
    }
};
