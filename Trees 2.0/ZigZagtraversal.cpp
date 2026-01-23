https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;

        queue<TreeNode*> q;
        q.push(root);
        int level = 0;

        while(!q.empty()) {
            int n = q.size();
            vector<int> temp;

            for(int i = 0; i < n; i++) {
                TreeNode* node = q.front(); q.pop();
                temp.push_back(node->val);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            if(level % 2 == 1)
                reverse(temp.begin(), temp.end());

            ans.push_back(temp);
            level++;
        }
        return ans;
    }
};
