#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool arraysEqual(vector<int> a, vector<int> b) {
    if(a.size() != b.size()) return false;

    unordered_map<int,int> mp;

    for(int x=0;x<a.size();x++) mp[x]++;

    for(int x=0;x<b.size();x++) {
        if(mp[x] == 0) return false;
        mp[x]--;
    }
    return true;
}

int main() {
    vector<int> a = {1,2,5,4,0};
    vector<int> b = {2,4,5,0,1};

    if(arraysEqual(a,b))
        cout << "Equal Arrays";
    else
        cout << "Not Equal";

    return 0;
}
