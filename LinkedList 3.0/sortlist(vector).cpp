https://leetcode.com/problems/sort-list/

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> v;
        for(ListNode* t = head; t; t = t->next)
            v.push_back(t->val);

        sort(v.begin(), v.end());

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        for(int x : v) {
            tail->next = new ListNode(x);
            tail = tail->next;
        }
        return dummy->next;
    }
};
