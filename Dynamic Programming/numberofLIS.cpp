class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        //isme kya scene hia ki count bhi krte raho kha kha s koi particular element mai koi subsequnce ara hai 
        //agr kahi s ara hai uski dp[j]+1 value same hai to usko uska count add on krdo 
        //fir sbse bada element nikalo us dp mai 
        //find ki kitni occurence hai uski fir kya kro aaek hi sht usko bhi cnt mai add krdo 
        int n = nums.size();
        //track rakho maxi kai
        int maxi = 0;
        vector<int>dp(n,1),count(n,1);
        for(int i = 0;i<n;i++)
        {
            for(int j =0;j<i;j++)
            {
                if(nums[j] < nums[i] && dp[i] < dp[j] +1)
                {
                    dp[i] = dp[j]+1;
                    count[i] = count[j];
                }
                //agr koi esa milta hai jisme value equal banri hai usme kya krna
                // hai u need to find out he occurence of it 
                else if(nums[j]<nums[i] && dp[i] == dp[j]+1)
                {
                    count[i] += count[j];
                }
            }
            maxi = max(dp[i],maxi);
        }
        int cnt= 0 ;
        for(int i =0;i<n;i++)
        {
            //yh kyu nescary tha agr koi or element mai bhi same length k ara ahi jo maximum hai to wo bhi banra hai 
            //  LIS to use bhi consider kro 
            
            if(dp[i]==maxi)
            {
                cnt += count[i];
            }
        }
        return cnt;
    }
};
