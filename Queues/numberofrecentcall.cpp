https://leetcode.com/problems/number-of-recent-calls/

Concept: Sliding window (queue)

class RecentCounter {
    queue<int> q;
public:
    int ping(int t) {
        q.push(t);
        while (!q.empty() && q.front() < t - 3000)
            q.pop();
        return q.size();
    }
};
