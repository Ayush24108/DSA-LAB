#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int mostFrequent(vector<int> arr) {
    unordered_map<int,int> freq;


    for(int i = 0; i < arr.size(); i++) {
        freq[arr[i]]++;
    }

    int ans = -1, maxFreq = 0;

    vector<int> keys;
    for(auto it = freq.begin(); it != freq.end(); it++) {
        keys.push_back(it->first);
    }

    for(int i = 0; i < keys.size(); i++) {
        int key = keys[i];
        int f = freq[key];

        if(f > maxFreq || (f == maxFreq && key > ans)) {
            maxFreq = f;
            ans = key;
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {1, 2, 2, 4, 1};
    cout << "Answer = " << mostFrequent(arr);
    return 0;
}
