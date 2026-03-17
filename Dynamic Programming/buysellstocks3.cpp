class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(5,0));
        //last s strt krte hai 

        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<4;j++)
            {
                int buy=0,sell = 0;
                if(j%2==0)
                {
                    int buykrlo = -prices[i] + dp[i+1][j+1];
                    int mtkro = 0 + dp[i+1][j];

                    buy = max(buykrlo,mtkro);
                    dp[i][j] = buy;
                }
                else
                {
                    //mtlb yh sell ki state hai 
                    int sellkrdo = prices[i] + dp[i+1][j+1];
                    int sellmtkro = 0 + dp[i+1][j];

                    sell = max(sellkrdo,sellmtkro); 
                    dp[i][j] = sell;
                }
            }
        }
        return dp[0][0];        //konsi state hai yh jb humre pass kuch ni tha buy krskte hai or transaction 0 hai or index 0 hai
    }
};
