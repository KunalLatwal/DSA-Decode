//slight differnet apporach thn that of print all subsequneces

//with brute recursion 

int helper(int i,vector<int>&nums)
{
    if(i==0) return nums[0];  //can be accessed to maximize the sum
    if(i < 0) return 0;  //negative index handle
  
    int left = nums[i] + helper(i-2,nums);
    int right = 0 + helper(i-1,nums;

    return max(left,right);
}
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    return helper(n-1,nums);
}
//with memoization and cache
int helper(int i,vector<int>&nums,vector<int> &dp)
{
    if(i==0) return nums[0];  //can be accessed to maximize the sum
    if(i < 0) return 0;  //negative index handle

    if(dp[i]!= -1) return dp[i];

    int left = nums[i] + helper(i-2,nums,dp);
    int right = 0 + helper(i-1,nums,dp);

     return dp[i]=max(left,right);
}
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int>dp(n+1,-1);
    return helper(n-1,nums,dp);
}

//with tabulation

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int>dp(n+1,-1);
    dp[0] = nums[0]; 
  
    for(int i=1;i<nums.size();i++)
    {
        int left = nums[i];
        if(i>1) left += dp[i-2];
        int right = 0 + dp[i-1];

        dp[i] = max(left,right);
    }
    return dp[n-1];
}

//with space optimization

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    int prev = nums[0];
    int sprev = 0;   

    for(int i=1;i<nums.size();i++)
    {
        int left = nums[i];
        if(i>1) left += sprev;
        int right = 0 + prev;

        int curr = max(left,right);
        sprev = prev;
        prev = curr;
    }
    return prev;
}
