#include <iostream>
using namespace std;

class Queue {
public:
    int *arr;
    int front, rear, size;

    Queue(int n) {
        size = n;
        arr = new int[n];
        front = 0;
        rear = -1;
    }

    void enqueue(int x) {
        if (rear == size - 1) {
            cout << "Queue Overflow\n";
            return;
        }
        arr[++rear] = x;
    }

    int dequeue() {
        if (front > rear) {
            cout << "Queue Underflow\n";
            return -1;
        }
        return arr[front++];
    }

    bool isEmpty() {
        return front > rear;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }
};


class Stack {
public:
    int *arr;
    int top, size;

    Stack(int n) {
        size = n;
        arr = new int[n];
        top = -1;
    }

    void push(int x) {
        if (top == size - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }

    int pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (top == -1) return -1;
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};


bool canBeSorted(Queue &q, int n) {
    Stack st(n);
    int expected = 1;

    while (!q.isEmpty()) {
        int front = q.getFront();
        q.dequeue();

        if (front == expected) {
            expected++;
        }
        else {
            if (!st.isEmpty() && st.peek() < front)
                return false;

            st.push(front);
        }

        while (!st.isEmpty() && st.peek() == expected) {
            st.pop();
            expected++;
        }
    }

    while (!st.isEmpty()) {
        if (st.peek() != expected)
            return false;
        st.pop();
        expected++;
    }

    return true;
}


int main() {
    int n = 5;
    Queue q(n);

    q.enqueue(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    if (canBeSorted(q, n))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
