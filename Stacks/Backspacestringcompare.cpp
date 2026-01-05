
Concept: Stack
Link: https://leetcode.com/problems/backspace-string-compare/

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> a,b;
        for(char c:s){
            if(c=='#'){ if(!a.empty()) a.pop(); }
            else a.push(c);
        }
        for(char c:t){
            if(c=='#'){ if(!b.empty()) b.pop(); }
            else b.push(c);
        }
        return a==b;
    }
};
