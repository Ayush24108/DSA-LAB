#include <iostream>
using namespace std;

class Stack {
    char *arr;
    int top;
    int size;

public:
    Stack(int size) {
        this->size = size;
        arr = new char[size];
        top = -1;
    }

    void push(char ch) {
        if (size - top > 1) {
            top++;
            arr[top] = ch;
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

    char peek() {
        if (top >= 0) 
        {
            return arr[top];
        }
       
    }

    bool isEmpty() {
        return (top == -1);
    }
};


int precedence(char c) {
    if (c == '^') return 3;
    else if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    else return -1;
}

string Postfix(string str) {
    Stack s(str.length());
    string result = "";

    for (int i = 0; i < str.length(); i++) {
        char c = str[i];

  
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            result += c;
        }
      
        else if (c == '(') {
            s.push(c);
        }
      
        else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                char ch= s.peek();
                result=ch;
                s.pop();
            }
            s.pop(); 
        }
        
        else {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(c)) {
                result += s.peek();
                s.pop();
            }
            s.push(c);
        }
    }


    while (!s.isEmpty()) {
        result += s.peek();
        s.pop();
    }

    return result;
}

int main() {
    string str;
    cout << "Enter  expression: ";
    cin >> str;

    cout << "POSTFIX expression: " << Postfix(str) << endl;
    return 0;
}
