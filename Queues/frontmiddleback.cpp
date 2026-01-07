https://leetcode.com/problems/design-front-middle-back-queue/

Concept: Deque

class FrontMiddleBackQueue {
    deque<int> dq;
public:
    void pushFront(int val) {
        dq.push_front(val);
    }

    void pushMiddle(int val) {
        dq.insert(dq.begin() + dq.size()/2, val);
    }

    void pushBack(int val) {
        dq.push_back(val);
    }

    int popFront() {
        if (dq.empty()) return -1;
        int x = dq.front();
        dq.pop_front();
        return x;
    }

    int popMiddle() {
        if (dq.empty()) return -1;
        int idx = (dq.size()-1)/2;
        int x = dq[idx];
        dq.erase(dq.begin() + idx);
        return x;
    }

    int popBack() {
        if (dq.empty()) return -1;
        int x = dq.back();
        dq.pop_back();
        return x;
    }
};
