#include <iostream>
using namespace std;

class PriorityQueue {
public:
    int arr[100];
    int size;

    PriorityQueue() {
        size = 0;
    }

   
    void push(int value) {
        size++;
        arr[size] = value;
        int index = size;

     
        while (index > 1) {
            int parent = index / 2;
            if (arr[parent] < arr[index])
                swap(arr[parent], arr[index]);
            else 
                break;

            index = parent;
        }
    }


    void pop() {
        if (size == 0) {
            cout << "Priority Queue empty\n";
            return;
        }

        arr[1] = arr[size];
        size--;


        int index = 1;
        while (true) {
            int left = 2*index;
            int right = 2*index + 1;
            int largest = index;

            if (left <= size && arr[left] > arr[largest]) largest = left;
            if (right <= size && arr[right] > arr[largest]) largest = right;

            if (largest != index) {
                swap(arr[index], arr[largest]);
                index = largest;
            }
            else break;
        }
    }


    int top() {
        if (size == 0) {
            cout << "Priority Queue empty\n";
            return -1;
        }
        return arr[1];
    }

    bool empty() {
        return size == 0;
    }
};


int main() {
    PriorityQueue pq;

    pq.push(30);
    pq.push(10);
    pq.push(50);
    pq.push(40);

    cout << "Top element: " << pq.top() << endl;

    pq.pop();
    cout << "Top after pop: " << pq.top() << endl;

    return 0;
}
