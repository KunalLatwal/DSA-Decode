https://leetcode.com/problems/add-two-numbers/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int carry = 0;
        ListNode* head = NULL;
        ListNode* tail = NULL;

        while (l1 || l2 || carry) {

            int sum = carry;

            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            ListNode* node = new ListNode(sum % 10);

            if (!head) {
                head = node;
                tail = node;
            } else {
                tail->next = node;
                tail = tail->next;
            }
        }

        return head;
    }
};
