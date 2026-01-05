
🔗 https://www.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1

class Solution {
  public:
    int search(string pat, string txt) {
        vector<int> freq(26, 0);
        for(char c : pat)
            freq[c - 'a']++;
            
        int cnt = pat.size();
        int i = 0, j = 0, ans = 0;
        
        while(j < txt.size()) {
            if(freq[txt[j] - 'a'] > 0)
                cnt--;
            freq[txt[j] - 'a']--;
            
            if(j - i + 1 == pat.size()) {
                if(cnt == 0)
                    ans++;
                    
                freq[txt[i] - 'a']++;
                if(freq[txt[i] - 'a'] > 0)
                    cnt++;
                i++;
            }
            j++;
        }
        return ans;
    }
};
