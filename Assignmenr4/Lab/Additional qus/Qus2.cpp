#include <iostream>
using namespace std;

class Queue {
public:
    int arr[100];
    int front, rear;

    Queue() {
        front = 0;
        rear = -1;
    }

    void enqueue(int x) {
        arr[++rear] = x;
    }

    int dequeue() {
        return arr[front++];
    }

    bool isEmpty() {
        return front > rear;
    }

    int size() {
        return rear - front + 1;
    }

    int frontElement() {
        return arr[front];
    }
};


int findMinIndex(Queue &q, int sortedIndex) {
    int min_index = -1;
    int min_value = 999999;

    int sz = q.size();

    for (int i = 0; i < sz; i++) {
        int curr = q.dequeue();

     
        if (i <= sortedIndex) {
            if (curr < min_value) {
                min_value = curr;
                min_index = i;
            }
        }

        q.enqueue(curr);
    }
    return min_index;
}


void moveMinToRear(Queue &q, int min_index) {
    int min_value;
    int sz = q.size();

    for (int i = 0; i < sz; i++) {
        int curr = q.dequeue();

        if (i == min_index) {
            min_value = curr;    
        } else {
            q.enqueue(curr);     
        }
    }


    q.enqueue(min_value);
}



void sortQueue(Queue &q) {
    int n = q.size();

    for (int i = 0; i < n; i++) {
        int min_index = findMinIndex(q, n - 1 - i);
        moveMinToRear(q, min_index);
    }
}

int main() {
    Queue q;
    q.enqueue(11);
    q.enqueue(5);
    q.enqueue(4);
    q.enqueue(21);

    sortQueue(q);


    while (!q.isEmpty()) {
        cout << q.dequeue() << " ";
    }
    return 0;
}
