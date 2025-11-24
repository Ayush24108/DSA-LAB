#include <iostream>
using namespace std;


void heapify(int arr[], int n, int i, bool maxHeap) {
    int extreme = i;  
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (maxHeap) {
        if (left < n && arr[left] > arr[extreme]) extreme = left;
        if (right < n && arr[right] > arr[extreme]) extreme = right;
    }
    else {
        if (left < n && arr[left] < arr[extreme]) extreme = left;
        if (right < n && arr[right] < arr[extreme]) extreme = right;
    }

    if (extreme != i) {
        swap(arr[i], arr[extreme]);
        heapify(arr, n, extreme, maxHeap);
    }
}


void heapSort(int arr[], int n, bool increasing = true) {
    bool maxHeap = increasing; 

    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i, maxHeap);


    for (int i = n-1; i >= 0; i--) {
        swap(arr[0], arr[i]);  
        heapify(arr, i, 0, maxHeap);
    }
}


void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}


int main() {
    int arr[] = {5, 1, 9, 3, 7, 2};
    int n = 6;

    cout << "Original Array: ";
    printArray(arr, n);

    heapSort(arr, n, true);
    cout << "Increasing Order: ";
    printArray(arr, n);

    heapSort(arr, n, false);
    cout << "Decreasing Order: ";
    printArray(arr, n);

    return 0;
}
