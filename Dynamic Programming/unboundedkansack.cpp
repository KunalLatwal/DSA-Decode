#include<iostream>
#include<limits.h>

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // Write Your Code Here.
    //sari possiblities mai s u have to take the maximum one 
    //explore all the cases and profit avialble and then choose the largest one
    vector<int>dp(w+1,0);
    for(int i=0;i<=w;i++)
    {   
        if(weight[0]<=i)
        {
            int r = i/weight[0];
            dp[i] = profit[0] * r;
        }
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            int npick = dp[j];
            int pick = INT_MIN;
            
            if(j >= weight[i])
            {
                pick =  profit[i] + dp[j-weight[i]];
                //update to current s hora hai regardless dp s 

            }
            
            dp[j] = max(npick,pick);
        }
    }
    return dp[w];
}
