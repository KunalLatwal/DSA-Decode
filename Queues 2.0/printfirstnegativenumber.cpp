https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

vector<long long> printFirstNegativeInteger(long long arr[],
long long n, long long k) {

    queue<int> q;
    vector<long long> ans;

    for(int i = 0; i < n; i++) {
        if(arr[i] < 0) q.push(i);

        if(i >= k - 1) {
            while(!q.empty() && q.front() < i - k + 1)
                q.pop();

            if(q.empty()) ans.push_back(0);
            else ans.push_back(arr[q.front()]);
        }
    }
    return ans;
}
