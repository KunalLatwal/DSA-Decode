class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //deque s yh o(n) mai hojaega solve 
        //kyuki usme dono hi end mai add or pop hoskta hai 
        //so maintain krenge monotnic decreasing property
        //isme kya hoga ki hum make sure krenge ki front mai hamesha hi bada element rahhe
        //bada rahega to vector mai answer jaega through front 
        //add kha s hoga through back 
        //monotonic properties kha p full fill hongi at the back 
        deque<int>dq;
        //isme sirf track hoga indexs k 
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
        {
            while(!dq.empty() && dq.front() <= i-k)
            {
                //humko ni chaia yh mc launde
                dq.pop_front();
            }
            //ab banegi monotonic conditions
            while(!dq.empty() && nums[dq.back()] <= nums[i])
            {
                dq.pop_back();
            }

            dq.push_back(i);

            //ab valid conditon for window check hogi
            if(i >= k-1)
            {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};
