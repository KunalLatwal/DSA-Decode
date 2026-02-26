class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
            //usne kha ki phele 0 0 dalo fir usko process krne k bad aaek bar i+1,j fir j+1,i
            priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>>q;
            int n=nums1.size();
            int m=nums2.size();
            vector<vector<int>>res;
            int j=0;
            for(int i=0;i<nums1.size();i++)
            {
                //mtlb humne kya kra ki arr1 k sare elements daldiye or ab hume bs age k dekhna hia 
                //har row k first element push karoge to tum ebs right mai jane ki need hogi bs 
                //neche k dikt ni hai 
                //to fir push karo i,j isme i will keep chaning j same rahega
                
                q.push({nums1[i]+nums2[j],i,j});
            }
            while(k-- && !q.empty())
            {
                auto [sum,i,j] = q.top();
                res.push_back({nums1[i],nums2[j]});
                q.pop();
                if(j+1 < m)
                {
                    q.push({nums1[i]+nums2[j+1],i,j+1});
                }  
            }
            return res;
        }
};
