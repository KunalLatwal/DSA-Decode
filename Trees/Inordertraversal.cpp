https://leetcode.com/problems/binary-tree-inorder-traversal/

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;

        vector<int> left = inorderTraversal(root->left);
        ans.insert(ans.end(), left.begin(), left.end());

        ans.push_back(root->val);

        vector<int> right = inorderTraversal(root->right);
        ans.insert(ans.end(), right.begin(), right.end());

        return ans;
    }
};
