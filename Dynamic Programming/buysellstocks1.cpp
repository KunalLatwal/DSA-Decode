class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //phele kya kro tum 
        //assign the minimum to the first element 
        int mini = prices[0];
        int profit = INT_MIN;
        for(int i=0;i<prices.size();i++)
        {
            int cost = prices[i] - mini;
            profit = max(profit,cost);
            mini = min(mini,prices[i]);
        }
        return profit;
    }
};
