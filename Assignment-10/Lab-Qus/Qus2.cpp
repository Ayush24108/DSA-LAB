#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> commonElements(vector<int> A, vector<int> B) {
    unordered_set<int> s(A.begin(), A.end());
    vector<int> result;

    for(int x=0;x<B.size();x++) {
        if(s.count(x)) {
            result.push_back(x);
            s.erase(x); 
        }
    }
    return result;
}

int main() {
    vector<int> A = {1, 2, 3, 4};
    vector<int> B = {3, 4, 5, 6};

    vector<int> ans = commonElements(A, B);

    cout << "Common elements: ";
    for(int x=0;x< ans.size();x++)
        cout << x << " ";

    return 0;
}
