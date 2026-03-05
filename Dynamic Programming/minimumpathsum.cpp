#include <bits/stdc++.h> 

int minSumPath(vector<vector<int>> &grid) {
    
    //use paramters that are changing in function i.e. row and col coordinate
    // do stuff that are required  // moves
    //take required that can be min max sum count
    //or optimise krdo 
    int row = grid.size();
    int col = grid[0].size();
    vector<vector<int>>dp(row,vector<int>(col,-1));
    dp[0][0]=grid[0][0];

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(i==0 && j==0) continue;
            
            else{
                int left = 1e8;
                int up = 1e8;
                if(i>0) up = grid[i][j] + dp[i-1][j];
                if(j>0) left = grid[i][j] + dp[i][j-1];

                dp[i][j] = min(left,up);
            }
        }
    }
    return dp[row-1][col-1];

}
