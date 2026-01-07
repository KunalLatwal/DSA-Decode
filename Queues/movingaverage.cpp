https://leetcode.com/problems/moving-average-from-data-stream/

Concept: Fixed-size window

class MovingAverage {
    queue<int> q;
    int size;
    double sum = 0;
public:
    MovingAverage(int k) {
        size = k;
    }

    double next(int val) {
        q.push(val);
        sum += val;
        if (q.size() > size) {
            sum -= q.front();
            q.pop();
        }
        return sum / q.size();
    }
};
