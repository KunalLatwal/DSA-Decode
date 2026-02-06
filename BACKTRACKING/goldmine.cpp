https://practice.geeksforgeeks.org/problems/gold-mine-problem2608/1

class Solution{
public:
    int dfs(vector<vector<int>>& mat, vector<vector<int>>& dp, int i, int j){
        int r=mat.size(), c=mat[0].size();
        if(i<0||i>=r||j>=c) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=mat[i][j]+max({
            dfs(mat,dp,i-1,j+1),
            dfs(mat,dp,i,j+1),
            dfs(mat,dp,i+1,j+1)
        });
    }

    int maxGold(int n, int m, vector<vector<int>> mat){
        vector<vector<int>> dp(n, vector<int>(m,-1));
        int ans=0;
        for(int i=0;i<n;i++)
            ans=max(ans,dfs(mat,dp,i,0));
        return ans;
    }
};
