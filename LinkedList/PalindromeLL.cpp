https://leetcode.com/problems/palindrome-linked-list/

class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        while(head) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = reverse(slow);
        ListNode* first = head;

        while(second) {
            if(first->val != second->val)
                return false;
            first = first->next;
            second = second->next;
        }
        return true;
    }
};
