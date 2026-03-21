class Solution {
  public:
    vector<int> getLIS(vector<int>& arr) {
        // Code here
        //LIS can be printed by following requirents dp array and the parent or hash array 
        //parent array is used to know from where is the current subsequence coming from 
        //if in any state dp[i] < dp[j]+1 that means ,j index is the parent for i index 
        //so just assign parent[i] = j and backtrack in order to recieve the LIS also make sure to 
        //sort it 
        int n = arr.size();
        vector<int>dp(n,1);
        vector<int>hash(n,0);
        for(int i=0;i<n;i++)
        {
            hash[i] = i ;
        }
        //ab yaha s game kro jo dp[j]+1 value greter hai usko assign krdo i of hash mai 
        for(int i =0;i<n;i++)
        {
            for(int j =0;j<i;j++)
            {
                if(arr[j] < arr[i] && dp[i] < dp[j]+1)
                {
                    //agr purane wale k value bada hai too 
                    dp[i]=dp[j]+1;
                    hash[i] = j;
                    //direct updation on the hash table
                }
            }
        }
        //now u nee to baktrack the answer ! how can u 
        //find the index with highest value as the length for the LIS
        int index = max_element(dp.begin(),dp.end()) - dp.begin();
        vector<int>ans;
        ans.push_back(arr[index]);
        while(hash[index]!=index)
        {
            index = hash[index];
            ans.push_back(arr[index]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
