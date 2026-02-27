class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //max heap s hojaega 
        priority_queue<pair<int,int>>q;
        vector<int>ans;

        for(int i=0;i<nums.size();i++)
        {
            //phele push krdo element fir dekhlenge
            q.push({nums[i],i});

            //ab bari ati hai window dekhne ki sbse important
            //agr jo top k element k index agr bhar hai to use hatao q.pop() krke
            
            while(!q.empty() && q.top().second <= i-k)

            //ab yaha pe if lagane k koi mtlb ni hai kuyki hoskta hai ki second bada element jo ye
            //wo bhi window k na ho to main baat yh hai ki kya kro while lagap to yh kya kregga window ko 
            //window conditions ko satisfied hi rkhega beta 

            {
                q.pop();
            }

            if(i>=k-1)
            {
                ans.push_back(q.top().first);
            }
        }
        return ans;
    }
};
