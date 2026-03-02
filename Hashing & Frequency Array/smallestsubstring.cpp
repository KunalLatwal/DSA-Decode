// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string S) {
        // Code here
        int freq[3]={0};
        //kyuki 3 hi elements chaia thae to humne 3 size k hi banaya kya frequnecy array
        //fir calculate kra kya size of string 
        int n=S.size();
        //fri sbki frequency napi
        //jb ferquency sbki almost 1 hoaje to wo aaek valid windpw hai 
        //to fir usko kya kro uski len nikllo or age badho
        int l=0;int mini =INT_MAX;
        for(int r=0;r<n;r++)
        {
            freq[S[r]-'0']++;
            while(freq[0] > 0 && freq[1] > 0 && freq[2] >0)
            {
                mini=min(mini,r-l+1);
                //ab window ko shink krdo 
                freq[S[l]-'0']--;
                l++;
            }
        }
        return mini;
        
    }
};
