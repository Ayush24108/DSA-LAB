#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[100];
    cout << "Enter elements of array in sorted order"<<endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int key;
    cout << "Enter the number to find"<<endl;
    cin >> key;

    int s = 0, e = n - 1;
    bool found = false;

    while (s <= e) {
        int mid = s + (e - s) / 2;

        if (arr[mid] == key) {
            cout << "Element " << key << " found at index " << mid << endl;
            found = true;
            break;  
        } 
        else if (arr[mid] > key) {
            e = mid - 1;
        } 
        else {
            s = mid + 1;
        }
    }

    if (!found) {
        cout << "Element " << key << " not found in the array." << endl;
    }

    return 0;
}
