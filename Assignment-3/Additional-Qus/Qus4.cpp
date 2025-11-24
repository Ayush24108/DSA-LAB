#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temps) {
    int n = temps.size();
    vector<int> answer(n, 0);
    stack<int> st; 

    for (int i = 0; i < n; i++) {
       
        while (!st.empty() && temps[i] > temps[st.top()]) {
            int idx = st.top();
            st.pop();
            answer[idx] = i - idx;   
        }
        st.push(i);  
    }
    return answer;
}

int main() {
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};

    vector<int> ans = dailyTemperatures(temperatures);

    cout << "Answer: ";
    for (int i=0;i<ans.size();i++)
        cout << i << " ";
    cout << endl;

    return 0;
}
