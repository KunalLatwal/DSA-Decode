class Solution {
public:

    bool compare(string &a, string &b)
    {
        int i=0;
        int j=0;
        int n = a.size();
        int m = b.size();

        if(a.size() != b.size()+1) return false;
        while(i<n && j<m)
        {
            if(a[i]==b[j])
            {
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        return j==m;
    }

    static bool cmp(string &a,string &b)
    {
        return a.size() < b.size();
    }
    
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        //ab sort krdo 
        int n = words.size();
        vector<int>dp(n,1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                //ab compare krdo 
                if(compare(words[i],words[j]) && dp[i] < dp[j]+1)
                {
                    dp[i] = dp[j]+1;
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};
