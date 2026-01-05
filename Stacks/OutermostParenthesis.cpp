
3️⃣ Remove Outermost Parentheses

Concept: Stack + depth tracking
Link: https://leetcode.com/problems/remove-outermost-parentheses/

class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string ans="";
        for(char c:s){
            if(c=='('){
                if(!st.empty()) ans+=c;
                st.push(c);
            }else{
                st.pop();
                if(!st.empty()) ans+=c;
            }
        }
        return ans;
    }
};
