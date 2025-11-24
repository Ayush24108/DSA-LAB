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
            cout<<"Queue Overflow"<<endl;
            return;
        }
        rear++;
        arr[rear] = x;
    }

    int dequeue() {
        if(front > rear) {
            cout<<"Queue Underflow"<<endl;
            return -1;
        }
        int val = arr[front];
        front++;
        return val;
    }

    bool isEmpty() {
        return front > rear;
    }

    int getFront() {
        if(front <= rear) return arr[front];
        return -1;
    }

    void reset() { front = 0; rear = -1; } 
};


class Stack {
    Queue *q1, *q2;
    int n;

public:
    Stack(int size) {
        n = size;
        q1 = new Queue(size);
        q2 = new Queue(size);
    }

    void push(int x) {
    
        q2->enqueue(x);

        while(!q1->isEmpty()) {
            q2->enqueue(q1->dequeue());
        }

     
        Queue *temp = q1;
        q1 = q2;
        q2 = temp;
        q2->reset(); 
    }

    void pop() {
        if(q1->isEmpty()) {
            cout<<"Stack Underflow"<<endl;
            return;
        }
        q1->dequeue();
    }

    int top() {
        if(q1->isEmpty()) {
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return q1->getFront();
    }

    bool isEmpty() {
        return q1->isEmpty();
    }
};


int main() {
    cout<<"Stack using Two Queues "<<endl;

    Stack st(10);

    st.push(10);
    st.push(20);
    st.push(30);

    cout<<"Top: "<<st.top()<<endl; 
    st.pop();
    cout<<"Top after pop: "<<st.top()<<endl;
    st.pop();
    cout<<"Top after another pop: "<<st.top()<<endl; 
    st.pop();
    st.pop(); 

    return 0;
}
