#include<iostream>
using namespace std;

class Queue {
    char *arr;
    int front, rear, size;

public:
    Queue(int n) {
        size = n;
        arr = new char[n];
        front = 0;
        rear = -1;
    }

    void enqueue(char x) {
        if(rear == size-1) {
            return; 
        }
        rear++;
        arr[rear] = x;
    }

    void dequeue() {
        if(front > rear) {
            return;
        }
        front++;
    }

    char getFront() {
        if(front <= rear) {
            return arr[front];
        }
       
    }

    bool isEmpty() {
        return front > rear;
    }
};

void firstNonRepeating(string str) {
    int n = str.length();
    Queue q(n);
    int freq[26] = {0};   

    for(int i=0; i<n; i++) {
        char ch = str[i];

     
        freq[ch - 'a']++;

        q.enqueue(ch);

      
        while(!q.isEmpty() && freq[q.getFront() - 'a'] > 1) {
            q.dequeue();
        }

   
        if(q.isEmpty()) {
            cout << -1 << " ";
        }
        else {
            cout << q.getFront() << " ";
        }
    }
    cout << endl;
}

int main() {
    string str;
    cout << "Enter string: "<<endl;
    cin >> str;

    firstNonRepeating(str);

    return 0;
}
