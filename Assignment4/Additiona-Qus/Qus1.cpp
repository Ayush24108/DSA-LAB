#include <iostream>
using namespace std;

class Queue {
    string *arr;
    int front, rear, size;

public:
    Queue(int n) {
        size = n;
        arr = new string[n];
        front = 0;
        rear = -1;
    }

    void enqueue(string x) {
        if (rear == size - 1) {
            cout << "Queue Overflow\n";
            return;
        }
        rear++;
        arr[rear] = x;
    }

    string dequeue() {
        if (front > rear) {
            cout << "Queue Underflow\n";
            return "";
        }
        string val = arr[front];
        front++;
        return val;
    }

    bool isEmpty() {
        return front > rear;
    }
};

void generateBinary(int n) {
    Queue q(2*n);   

    q.enqueue("1");

    for (int i = 1; i <= n; i++) {
        string curr = q.dequeue();

        cout << curr << " ";

        q.enqueue(curr + "0");
        q.enqueue(curr + "1");
    }
}

int main() {
    int n = 2;
    generateBinary(n);
    return 0;
}
