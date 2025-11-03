#include <iostream>

using namespace std;



void InputArray(int arr[],int n)
{
    for (int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
}

void OutputArray(int arr[],int n)
{
    for (int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
}





void InsertionSort(int arr[],int n)
{  

    for(int i=1;i<n;i++)
    {
        int temp=arr[i],j=i-1;
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
        


}



int main()
{
    int n;
    cout<<"Enter size of array"<<endl;
    cin>>n;

    int arr[1000];

    cout<<"Enter elements if array"<<endl;
    InputArray(arr,n);


 
cout<<"Sorting by insertion sort"<<endl;
            InsertionSort(arr,n);
            OutputArray(arr,n);

}

