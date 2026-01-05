
🔗 https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mp(256, -1);
        int l = 0, ans = 0;
        
        for(int r = 0; r < s.size(); r++) {
            if(mp[s[r]] >= l)
                l = mp[s[r]] + 1;
                
            mp[s[r]] = r;
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};

