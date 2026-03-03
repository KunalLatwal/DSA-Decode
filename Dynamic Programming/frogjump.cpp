//brutely with recursion 

int helper(int i,vector<int>&heights)
{
      //base case
      if(i==0) return 0;
      int left = helper(i-1,heights) + abs(heights[i]-heights[i-1]);
      if( i > 1 )
          right = helper(i-2,heights) + abs(heights[i] - heights[i-2]);

    return min(left,right);
}
int frogJump(int n, vector<int> &heights)
{
      return helper(n-1,heights);
}   


//memoization and cache

int helper(int i,vector<int>&heights,vector<int>&dp)
{
      //base case
      if(i==0) return 0;
      if(dp[i]!=-1) return dp[i];
      int left = helper(i-1,heights,dp) + abs(heights[i]-heights[i-1]);
      if( i > 1 )
          right = helper(i-2,heights,dp) + abs(heights[i] - heights[i-2]);

    return dp[i] = min(left,right);
}
int frogJump(int n, vector<int> &heights)
{
      vector<int>dp(n+1,-1);
      return helper(n-1,heights,dp);
}   


//tabulation without space optimaization

int frogJump(int n, vector<int> &heights)
{
    vector<int>dp(n+1,-1);
    dp[0] = 0;
    for(int i=1;i<=n;i++)
    {
        int fs = dp[i-1] + abs(heights[i]-heights[i-1]);
        int ss = INT_MAX;

        if(i>1) ss = dp[i-2] + abs(heights[i] - heights[i-2]);

        int dp[i] = min(fs,ss);
    }
    return dp[n-1];
}   



//space optimization

int frogJump(int n, vector<int> &heights)
{
    int prev = 0;
    int sprev = 0;
    for(int i=1;i<=n;i++)
    {
        int fs = prev + abs(heights[i]-heights[i-1]);
        int ss = INT_MAX;

        if(i>1) ss = sprev + abs(heights[i] - heights[i-2]);

        int curr = min(fs,ss);
        sprev = prev;
        prev = curr;
    }
    return curr;
}   
