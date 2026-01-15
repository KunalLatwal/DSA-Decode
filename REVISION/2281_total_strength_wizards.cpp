
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalStrength(vector<int>& a) {
        const int MOD = 1e9+7;
        int n=a.size();
        vector<int> L(n), R(n);
        stack<int> st;

        for(int i=0;i<n;i++){
            while(!st.empty() && a[st.top()]>=a[i]) st.pop();
            L[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && a[st.top()]>a[i]) st.pop();
            R[i]=st.empty()?n:st.top();
            st.push(i);
        }

        vector<long long> pref(n+1), pref2(n+2);
        for(int i=0;i<n;i++){
            pref[i+1]=(pref[i]+a[i])%MOD;
            pref2[i+2]=(pref2[i+1]+pref[i+1])%MOD;
        }

        long long ans=0;
        for(int i=0;i<n;i++){
            long long lc=i-L[i], rc=R[i]-i;
            long long sr=(pref2[R[i]+1]-pref2[i+1]+MOD)%MOD;
            long long sl=(pref2[i+1]-pref2[L[i]+1]+MOD)%MOD;
            long long total=(sr*lc%MOD - sl*rc%MOD + MOD)%MOD;
            ans=(ans + a[i]*total)%MOD;
        }
        return ans;
    }
};
