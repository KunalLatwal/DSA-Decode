class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));

        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                for(int l=0;l<k;l++){

                    int sell=0,buy=0;
                    if(j==0)//mtlb u can buy the stuff
                    {
                        buy = max(-prices[i] + dp[i+1][1][l] , 0 + dp[i+1][0][l]);
                    }
                    else{

                        if(l<k)
                        sell = max(prices[i] + dp[i+1][0][l+1] , 0 + dp[i+1][1][l]);
                    }

                    dp[i][j][l] = max(sell,buy);
                }
            }
        }
        return dp[0][0][0];
    }
};
