https://leetcode.com/problems/odd-even-linked-list/

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return head;

        vector<int> odd, even;
        ListNode* temp = head;
        int pos = 1;

        while (temp) {
            if (pos % 2 == 1)
                odd.push_back(temp->val);
            else
                even.push_back(temp->val);
            pos++;
            temp = temp->next;
        }

        temp = head;
        int i = 0;
        for (int x : odd) temp->val = x, temp = temp->next;
        for (int x : even) temp->val = x, temp = temp->next;

        return head;
    }
};
