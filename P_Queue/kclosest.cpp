class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // code here
        //k th closest mtlb kya hua jitna bada hai kyuki hum sqrt ni dalre hai bhai 
        // to jo jitna bada mtlb utan acha max heap use hoga 
        //kyu use hoga kyuki wo kya krega wo kya krega upr ki sari values hata dega jo maximum hogi 
        //aur sirf unko rkhega 
        //jo max K k bad aengei 
        priority_queue<tuple<int,int,int>>q;
        for(auto i : points)
        {
            int x = i[0];
            int y = i[1];
            
            int dis = pow(x,2)+pow(y,2);
            q.push({dis,x,y});
            if(q.size() > k)
            {
                q.pop();
            }
        }
        vector<vector<int>>ans;
        while(!q.empty())
        {
            auto [d,x,y] = q.top();
            q.pop();
            ans.push_back({x,y});
        }
        return ans;
    }
};
