https://leetcode.com/problems/design-circular-queue/

Concept: Circular array + modulo

class MyCircularQueue {
    vector<int> arr;
    int front, rear, size;
public:
    MyCircularQueue(int k) {
        arr.resize(k);
        size = k;
        front = rear = -1;
    }

    bool enQueue(int value) {
        if (isFull()) return false;
        if (front == -1) front = 0;
        rear = (rear + 1) % size;
        arr[rear] = value;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        if (front == rear) front = rear = -1;
        else front = (front + 1) % size;
        return true;
    }

    int Front() {
        return isEmpty() ? -1 : arr[front];
    }

    int Rear() {
        return isEmpty() ? -1 : arr[rear];
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % size == front;
    }
};
