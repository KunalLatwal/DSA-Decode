https://leetcode.com/problems/validate-binary-search-tree/

🧠 Intuition

Har node ko ek valid range do (min, max).

class Solution {
public:
    bool solve(TreeNode* root, long long low, long long high) {
        if(!root) return true;

        if(root->val <= low || root->val >= high)
            return false;

        return solve(root->left, low, root->val) &&
               solve(root->right, root->val, high);
    }

    bool isValidBST(TreeNode* root) {
        return solve(root, LLONG_MIN, LLONG_MAX);
    }
};
