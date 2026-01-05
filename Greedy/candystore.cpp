
https://www.geeksforgeeks.org/problems/shop-in-candy-store1145/1

class Solution {
public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        sort(prices.begin(), prices.end());
        int n = prices.size();

        int minCost = 0, maxCost = 0;

        // min cost
        for(int i=0, j=n-1; i<=j; i++, j-=k)
            minCost += prices[i];

        // max cost
        for(int i=n-1, j=0; i>=j; i--, j+=k)
            maxCost += prices[i];

        return {minCost, maxCost};
    }
