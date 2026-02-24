class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        /*
        [12]
        [5,12]
        ab 787 aega to top khud hatega 
        [12,787]    ---->5
        ab 1 aega hi ni aega to khud hatjaega 
        [12,787]
        ab 23 aega to top s hatega 12 
        [23,787];
        to mtlb humne min heap operate krnege
        */
        
        priority_queue<int,vector<int>,greater<>>q;
        for(int i=0;i<arr.size();i++)
        {
            q.push(arr[i]);
            
            if(q.size() > k)
            {
                q.pop();
            }
        }
        vector<int>ans;
        while(!q.empty())
        {
            ans.push_back(q.top());
            q.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
