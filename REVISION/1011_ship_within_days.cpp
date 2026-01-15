
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool ok(vector<int>& w,int d,int cap){
        int days=1,load=0;
        for(int x:w){
            if(x>cap) return false;
            if(load+x>cap) days++,load=0;
            load+=x;
        }
        return days<=d;
    }
    int shipWithinDays(vector<int>& w,int d){
        int l=1,r=accumulate(w.begin(),w.end(),0),ans=r;
        while(l<=r){
            int m=l+(r-l)/2;
            if(ok(w,d,m)) ans=m,r=m-1;
            else l=m+1;
        }
        return ans;
    }
};
