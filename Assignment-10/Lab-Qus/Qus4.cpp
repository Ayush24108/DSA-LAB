#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int firstNonRepeating(vector<int> arr) {
    unordered_map<int,int> mp;

    for(int x =0;x< arr.size();x++)
        mp[x]++;

    for(int x=0;x<arr.size();x++)
        if(mp[x] == 1)
            return x;

    return -1;
}

int main() {
    vector<int> arr = {4, 5, 1, 2, 0, 4};

    int x = firstNonRepeating(arr);

    if(x == -1)
        cout << "No non-repeating element";
    else
        cout << "First non-repeating: " << x;

    return 0;
}
