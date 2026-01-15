
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n=h.size();
        vector<int> ps(n), ns(n);
        stack<int> st;

        for(int i=0;i<n;i++){
            while(!st.empty() && h[st.top()]>=h[i]) st.pop();
            ps[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && h[st.top()]>h[i]) st.pop();
            ns[i]=st.empty()?n:st.top();
            st.push(i);
        }

        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,h[i]*(ns[i]-ps[i]-1));
        }
        return ans;
    }
};
