class Solution {
  public:

    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<bool>>dp(n,vector<bool>(sum+1,false));
        for(int i=0;i<n;i++)
        {
            dp[i][0]=true;
            //jha jha target 0 wha wha answer bhi zero
        }
        if(arr[0] <= sum) dp[0][arr[0]]=true;
        //jhajha index zero hai or to target hai wo uske hi equal hai usme bhi true fill krdo bhai 
        
        for(int i=1;i<n;i++)
        {
            for(int t = 1 ;t <=sum; t++)      //is loop k mtlb hai 
            //ab taregt ki value mai iterate kro or find out other all values too
            
            {
                bool notake = dp[i-1][t];
                //just go for it , no such processing of it 
                
                bool take = false;
                
                if(arr[i] <= t) take = dp[i-1][t-arr[i]];
                
                dp[i][t] = notake || take;
            }
        }
        //since humne upr s neche ko strt kra tho answer khapada hoga ?
        //last row mai sum column mai 
        return dp[n-1][sum];
    }
};
