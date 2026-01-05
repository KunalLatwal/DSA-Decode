
🔗 https://leetcode.com/problems/minimum-window-substring/

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freq(256, 0);
        for(char c : t) freq[c]++;

        int cnt = t.size(), l = 0;
        int minLen = INT_MAX, start = 0;

        for(int r = 0; r < s.size(); r++) {
            if(freq[s[r]] > 0) cnt--;
            freq[s[r]]--;

            while(cnt == 0) {
                if(r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }
                freq[s[l]]++;
                if(freq[s[l]] > 0) cnt++;
                l++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
