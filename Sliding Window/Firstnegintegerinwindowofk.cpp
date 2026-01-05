
🔗 https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

class Solution {
  public:
    vector<long long> printFirstNegativeInteger(long long int A[],
        long long int N, long long int K) {
        
        deque<long long> dq;
        vector<long long> ans;
        
        for(int i = 0; i < N; i++) {
            if(A[i] < 0)
                dq.push_back(i);
                
            if(i >= K - 1) {
                while(!dq.empty() && dq.front() <= i - K)
                    dq.pop_front();
                    
                if(dq.empty())
                    ans.push_back(0);
                else
                    ans.push_back(A[dq.front()]);
            }
        }
        return ans;
    }
};

