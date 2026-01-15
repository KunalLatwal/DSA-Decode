
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool ok(vector<int>& a,int t,int d){
        long long s=0;
        for(int x:a) s+=(x+d-1)/d;
        return s<=t;
    }
    int smallestDivisor(vector<int>& a,int t){
        int l=1,r=*max_element(a.begin(),a.end()),ans=r;
        while(l<=r){
            int m=l+(r-l)/2;
            if(ok(a,t,m)) ans=m,r=m-1;
            else l=m+1;
        }
        return ans;
    }
};
