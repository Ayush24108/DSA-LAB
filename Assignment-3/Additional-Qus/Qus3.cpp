#include <iostream>
using namespace std;


class Stack {
    int arr[1000];
    int topIndex;

public:
    Stack() { topIndex = -1; }

    void push(int x) {
        arr[++topIndex] = x;
    }

    void pop() {
        if (topIndex >= 0)
            topIndex--;
    }

    int top() {
        return arr[topIndex];
    }

    bool isEmpty() {
        return topIndex == -1;
    }
};


void nextGreaterElement(int arr[], int n) {
    int result[1000];
    Stack st;

   
    for (int i = n - 1; i >= 0; i--) {

       
        while (!st.isEmpty() && st.top() <= arr[i])
            st.pop();

       
        if (st.isEmpty())
            result[i] = -1;
        else
            result[i] = st.top();

      
        st.push(arr[i]);
    }


    cout << "Next Greater Elements"<<endl;
    for (int i = 0; i < n; i++)
        cout << result[i] << " ";
    cout << endl;
}


int main() {
    int arr[] = {4, 5, 2, 25};
    int n = sizeof(arr) / sizeof(arr[0]);

    nextGreaterElement(arr, n);
    return 0;
}
