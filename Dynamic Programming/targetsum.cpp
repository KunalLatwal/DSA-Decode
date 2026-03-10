//memoizaton 

class Solution {
public:

    //this function will help you return the number of subsets with target sum within ith index
    int helper(int i,int t,vector<int>&arr,vector<vector<int>>&dp)
    {
        //base cases 
        if(i==0)
        {
            if(t==0 && arr[0]==0) return dp[0][0] = 2;
            if(arr[0] == t || t==0)  return dp[i][t] = 1;
            else return dp[i][t] = 0;
        }

        if(dp[i][t]!=-1) return dp[i][t];

        int pick = 0;
        int unpick = helper(i-1,t,arr,dp);

        if(arr[i] <= t) pick = helper(i-1,t-arr[i],arr,dp);

        return dp[i][t] = pick + unpick;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0 ;
        for(int i : nums)
        {
            sum+=i;
        }
        if(sum < abs(target)) return 0;
        int n = nums.size();
        int t = (sum+target)/2;
        if((sum+target)%2!=0) return 0;

        vector<vector<int>>dp(n,vector<int>(t+1,-1));
        return helper(n-1,t,nums,dp);
    }
};
