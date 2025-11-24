#include<iostream>
using namespace std;

class Queue {
    int *arr;
    int front, rear, size;

public:
    Queue(int n) {
        size = n;
        arr = new int[n];
        front = 0;
        rear = -1;
    }

    void enqueue(int x) {
        if(rear == size-1) {
            cout << "Queue Overflow" << endl;
            return;
        }
        rear++;
        arr[rear] = x;
    }

    int dequeue() {
        if(front > rear) {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        int val = arr[front];
        front++;
        return val;
    }

    bool isEmpty() {
        return front > rear;
    }

    int getSize() {
        return rear - front + 1;
    }
};

void interleaveQueue(int arr[], int n) {
    Queue q1(n/2), q2(n/2), result(n);

    for(int i=0; i<n/2; i++) {
        q1.enqueue(arr[i]);
    }

    for(int i=n/2; i<n; i++) {
        q2.enqueue(arr[i]);
    }


    while(!q1.isEmpty() && !q2.isEmpty()) {
        result.enqueue(q1.dequeue());
        result.enqueue(q2.dequeue());
    }


    cout << "Interleaved Queue: ";
    while(!result.isEmpty()) {
        cout << result.dequeue() << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of elements : "<<endl;
    cin >> n;

    int arr[100];
    cout << "Enter elements:" << endl;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    interleaveQueue(arr, n);

    return 0;
}
