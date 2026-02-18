class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        q.push({beginWord,1});      //strting word with the step
        set<string>st(wordList.begin(),wordList.end());
        st.erase(beginWord);

        while(!q.empty())
        {
            auto [s,step] = q.front();
            q.pop();

            if(s==endWord) return step;
            for(int i=0;i<s.size();i++)
            {
                char ch = s[i];
                for(char c = 'a'; c <= 'z' ; c++)
                {
                    s[i]=c;
                    if(st.find(s)!=st.end())
                    {
                        q.push({s,step+1});
                        st.erase(s);
                    }
                }
                s[i]=ch;
            }
        }
        return 0;
    }
};
