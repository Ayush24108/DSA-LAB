#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    vector<int> arr = {2, 3, 2, 4, 3, 2};
    unordered_map<int,int> freq;

    
    for(int i = 0; i < arr.size(); i++) {
        freq[arr[i]]++;
    }

   
    vector<int> keys;
    for(auto it = freq.begin(); it != freq.end(); it++) {
        keys.push_back(it->first);
    }

  
    cout << "Frequencies:" << endl;
    for(int i = 0; i < keys.size(); i++) {
        int key = keys[i];
        cout << key << " -> " << freq[key] << endl;
    }

    return 0;
}

