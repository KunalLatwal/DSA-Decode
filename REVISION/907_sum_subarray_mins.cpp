
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> ps(n), ns(n);
        stack<int> st;

        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            ps[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
            ns[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long ans = 0, mod = 1e9+7;
        for(int i=0;i<n;i++){
            long long left = i - ps[i];
            long long right = ns[i] - i;
            ans = (ans + arr[i]*left*right)%mod;
        }
        return ans;
    }
};
