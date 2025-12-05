#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool containsDuplicate(vector<int> arr) {
    unordered_set<int> s;

    for(int x=0;x<arr.size();x++) {
        if(s.find(x) != s.end())
            return true;
        s.insert(x);
    }
    return false;
}

int main() {
    vector<int> arr = {1, 2, 3, 1};

    if(containsDuplicate(arr))
        cout << "Duplicate Found";
    else
        cout << "No Duplicate";

    return 0;
}
