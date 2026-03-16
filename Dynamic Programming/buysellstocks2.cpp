class Solution {
public:

    int helper(int i,bool canbuy,vector<int>&prices,vector<vector<int>>&dp)
    {
        int n = prices.size();
        if(i == n) return 0;

        if(dp[i][canbuy] != -1) return dp[i][canbuy];

        int buy = 0;
        //explore possibilites 
        if(canbuy == true)
        {
            //mtlb stock buy hoskta hai 
            int ibought = -prices[i] + helper(i+1,false,prices,dp);
            int dontbuy = 0 + helper(i+1,true,prices,dp);

            buy = max(ibought,dontbuy);
        }
        int sell = 0;
        //sell tbhi hoga tbh kuch buy kra hai 
        if(canbuy == false) //mtlb kuch to karida hai 
        {
            int sellit = prices[i] + helper(i+1,true,prices,dp);
            int dontsell = 0 + helper(i+1,false,prices,dp);

            sell = max(sellit,dontsell);
        }
        //return maximum of all 
        return dp[i][canbuy] = max(sell,buy);
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return helper(0,true,prices,dp);
    }
};
