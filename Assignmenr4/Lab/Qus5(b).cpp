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

    int getFront() {
        if(front <= rear) return arr[front];
        return -1;
    }

    bool isEmpty() {
        return front > rear;
    }

    int length() {
        return rear - front + 1;
    }

    void reset() { front = 0; rear = -1; }
};


class Stack {
    Queue *q;
    int n;

public:
    Stack(int size) {
        n = size;
        q = new Queue(size);
    }

    void push(int x) {
        int sz = q->length();
        q->enqueue(x);

        
        for(int i=0; i<sz; i++) {
            int val = q->dequeue();
            q->enqueue(val);
        }
    }

    void pop() {
        if(q->isEmpty()) {
            cout<<"Stack Underflow"<<endl;
            return;
        }
        q->dequeue();
    }

    int top() {
        if(q->isEmpty()) {
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return q->getFront();
    }

    bool isEmpty() {
        return q->isEmpty();
    }
};


int main() {
    cout<<" Stack using One Queue "<<endl;

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
