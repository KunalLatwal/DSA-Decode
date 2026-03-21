class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //use recursion to find out the length 
        int n = nums.size();
        int maxi = -1e9;
        vector<int>dp(n+1,1);
        for(int i = 0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j] < nums[i] && dp[i] < dp[j]+1)
                {
                    dp[i] = dp[j]+1;
                }
            }
            maxi = max(maxi,dp[i]);
        }
        return maxi;
    }
};
