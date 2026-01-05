
🔗 https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1

class Solution {
  public:
    int lenOfLongSubarr(int A[], int N, int K) {
        int i = 0, j = 0;
        long long sum = 0;
        int ans = 0;
        
        while(j < N) {
            sum += A[j];
            
            while(sum > K)
                sum -= A[i++];
                
            if(sum == K)
                ans = max(ans, j - i + 1);
                
            j++;
        }
        return ans;
    }
};
