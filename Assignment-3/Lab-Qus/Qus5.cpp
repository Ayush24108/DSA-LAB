#include <iostream>
using namespace std;

class Stack {
    int *arr;
    int top;
    int size;

public:
    Stack(int size) {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int val) {
        if (size - top > 1) {
            top++;
            arr[top] = val;
        }

        else{
            return;
        }
    }

    void pop() {
        if (top >= 0) {
            top--;
        }
        else{
            return;
        }
    }

    int peek() {
        if (top >= 0) {
            
            return arr[top];
        }
       
    }

    bool isEmpty() {
        return (top == -1);
    }

    int count() {
        return top + 1;
    }
};

bool isOperator(char c) {
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
    {
                return true;
    }

    else{
        return false;
    }
}

bool isValidPostfix(string str) {
    Stack st(str.length());

    for (int i = 0; i < str.length(); i++) {
        char c = str[i];

        if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) 
        {
                      st.push(1);
        }
        else if (isOperator(c)) {
          
            if (st.count() < 2) 
            { 
                return false;

            }
            st.pop();
            st.pop();
            st.push(1);
        } 
        else {
        
            return false;
        }
    }

    
    return (st.count() == 1);
}

int main() {
    string str;
    cout << "Enter expression: "<<endl;
    cin >> str;

    if (isValidPostfix(str))
        cout << "Valid Expression " <<endl;
    else
        cout << "Invalid Expression " <<endl;

    return 0;
}
