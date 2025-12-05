#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool pairExists(vector<int> arr, int target) {
    unordered_set<int> s;

    for(int x=0;x<arr.size();x++) {
        int needed = target - x;
        if(s.count(needed)) return true;
        s.insert(x);
    }
    return false;
}

int main() {
    vector<int> arr = {0, -1, 2, -3, 1};
    int target = -2;

    if(pairExists(arr, target))
        cout << "Pair Exists";
    else
        cout << "No Pair";

    return 0;
}
