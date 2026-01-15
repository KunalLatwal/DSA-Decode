
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> ps(n), ns(n), pg(n), ng(n);
        stack<int> st;

        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            ps[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()] > nums[i]) st.pop();
            ns[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();

        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()] <= nums[i]) st.pop();
            pg[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()] < nums[i]) st.pop();
            ng[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long res = 0;
        for(int i=0;i<n;i++){
            long long maxc = (long long)nums[i]*(i-pg[i])*(ng[i]-i);
            long long minc = (long long)nums[i]*(i-ps[i])*(ns[i]-i);
            res += maxc - minc;
        }
        return res;
    }
};
