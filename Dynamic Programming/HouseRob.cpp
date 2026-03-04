
//brute recussion
class Solution {
public:
    int helper(int n,vector<int>&nums,vector<int>&dp)
    {
        if(n==0) return nums[0];
        if(n < 0 ) return 0;

        int pick = nums[n] + helper(n-1,nums);
        int unpick = 0 + helper(n-1,nums);

        return max(pick,unpick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        return helper(n-1,nums);
    }
}



//Memoization + cache
class Solution {
public:
    int helper(int n,vector<int>&nums,vector<int>&dp)
    {
        if(n==0) return nums[0];
        if(n < 0 ) return 0;

        if(dp[n]!=-1) return dp[n];

        int pick = nums[n] + helper(n-1,nums,dp);
        int unpick = 0 + helper(n-1,nums,dp);

        return dp[i] = max(pick,unpick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return helper(n-1,nums,dp);
    }
};


//tabulation 
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        dp[0] = nums[0];

        for(int i=1;i<n;i++)
        {
            int pick = nums[i];
            if(i>1) pick += dp[i-2];
            int unpick = 0 + dp[i-1];

            dp[i] = max(pick,unpick);
        }
        return dp[n-1];
    }
};



//space optimization
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;

        for(int i=1;i<n;i++)
        {
            int pick = nums[i];
            if(i>1) pick += prev2;
            int unpick = 0 + prev;

            int curr = max(pick,unpick);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};
