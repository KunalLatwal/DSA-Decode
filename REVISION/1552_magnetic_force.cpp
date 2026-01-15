
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool ok(vector<int>& p,int m,int dist){
        int cnt=1,last=p[0];
        for(int i=1;i<p.size();i++){
            if(p[i]-last>=dist) cnt++,last=p[i];
        }
        return cnt>=m;
    }
    int maxDistance(vector<int>& p,int m){
        sort(p.begin(),p.end());
        int l=1,r=p.back()-p[0],ans=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(ok(p,m,mid)) ans=mid,l=mid+1;
            else r=mid-1;
        }
        return ans;
    }
};
