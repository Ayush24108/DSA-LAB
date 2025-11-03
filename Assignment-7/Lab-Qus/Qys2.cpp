#include <iostream>
using namespace std;

void InputArray(int arr[],int n)
{
    for (int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
}


void OutputArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void SelectionSort(int arr[], int n) {
    int s = 0, e = n - 1;

    while (s<e) {
        int minIndex = s;
        int maxIndex = s;

        for (int i = s; i <= e; i++) {
            if (arr[i] < arr[minIndex])
                minIndex = i;
            if (arr[i] > arr[maxIndex])
                maxIndex = i;
        }

       
        swap(arr[s], arr[minIndex]);

       
        if (maxIndex == s)
            maxIndex = minIndex;

        swap(arr[e], arr[maxIndex]);

    
        s++;
        e--;
    }
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[1000];
    cout<<"Enter elemenst of arrays"<<endl;
    InputArray(arr,n);

    

    SelectionSort(arr, n);

    cout << "Sorted array is"<<endl;
    OutputArray(arr, n);

    return 0;
}
