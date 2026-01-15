
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool ok(vector<int>& p,int h,int k){
        long long t=0;
        for(int x:p) t+=(x+k-1)/k;
        return t<=h;
    }
    int minEatingSpeed(vector<int>& p,int h){
        int l=1,r=*max_element(p.begin(),p.end()),ans=r;
        while(l<=r){
            int m=l+(r-l)/2;
            if(ok(p,h,m)) ans=m,r=m-1;
            else l=m+1;
        }
        return ans;
    }
};
