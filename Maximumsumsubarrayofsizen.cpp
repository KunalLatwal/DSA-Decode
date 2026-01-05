
🔗 https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1

class Solution {
  public:
    long maximumSumSubarray(int K, vector<int> &Arr, int N) {
        long long sum = 0;
        for(int i = 0; i < K; i++)
            sum += Arr[i];
            
        long long ans = sum;
        
        for(int i = K; i < N; i++) {
            sum += Arr[i];
            sum -= Arr[i - K];
            ans = max(ans, sum);
        }
        return ans;
    }
};
