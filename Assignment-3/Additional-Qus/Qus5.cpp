#include <iostream>
#include <vector>
#include <stack>
using namespace std;


int findNextSmallest(vector<int>& A, vector<bool>& used) {
    int smallest = -1;

    for (int i = 0; i < A.size(); i++) {
        if (!used[i]) { 
            if (smallest == -1 || A[i] < A[smallest]) {
                smallest = i;
            }
        }
    }
    return smallest;
}

bool canMakeSorted(vector<int> A) {
    int n = A.size();

  
    vector<int> target(n);
    vector<bool> used(n, false);

    for (int k = 0; k < n; k++) {
        int idx = findNextSmallest(A, used);
        target[k] = A[idx];
        used[idx] = true;
    }


    stack<int> S;
    int j = 0;  

    for (int i = 0; i < n; i++) {
        S.push(A[i]);


        while (!S.empty() && S.top() == target[j]) {
            S.pop();
            j++;
        }
    }

 
    while (!S.empty() && S.top() == target[j]) {
        S.pop();
        j++;
    }

    return (j == n);
}

int main() {
    vector<int> A = {3, 1, 2};

    if (canMakeSorted(A))
        cout << "YES, B can be sorted.\n";
    else
        cout << "NO, B cannot be sorted.\n";

    return 0;
}
