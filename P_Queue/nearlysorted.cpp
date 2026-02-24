class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code here
        priority_queue<int,vector<int>,greater<>>q;
        int j=0;
        //since ki jo aaek particular element hai wo max to max k + distance mai hai 
        for(int i=0;i<arr.size();i++)
        {
            q.push(arr[i]);
            if(q.size() > k)
            {
                arr[j++]=q.top();
                q.pop();
            }
        }
        while(!q.empty())
        {
            arr[j++]=q.top();
            q.pop();
        }
    }
};
