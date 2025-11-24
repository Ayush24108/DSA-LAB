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
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return -1;
        }
        return arr[front++];
    }

    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    bool isEmpty() {
        return front > rear;
    }

    int currentSize() {
        return rear - front + 1;
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
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (isEmpty()) return -1;
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};


int countStudents(Queue &students, Stack &sandwiches) {

    int rotations = 0;

    while (!students.isEmpty() && !sandwiches.isEmpty()) {

        int stud = students.getFront();
        int sand = sandwiches.peek();

        if (stud == sand) {
            students.dequeue();
            sandwiches.pop();
            rotations = 0;  
        }
        else {
   
            students.dequeue();
            students.enqueue(stud);
            rotations++;

            if (rotations == students.currentSize())
                break;
        }
    }

    return students.currentSize();  
}


int main() {
    int n = 4;

    Queue students(n);
    Stack sandwiches(n);


    students.enqueue(1);
    students.enqueue(1);
    students.enqueue(0);
    students.enqueue(0);

    
    sandwiches.push(1);
    sandwiches.push(0);
    sandwiches.push(1);
    sandwiches.push(0);

    cout << countStudents(students, sandwiches);

    return 0;
}
