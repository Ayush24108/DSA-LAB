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


void SelectionSort(int arr[],int n)
{
     for(int i=0;i<n-1;i++)
     {
        int MinIndex=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[MinIndex])
                MinIndex=j;
        }
        swap(arr[MinIndex],arr[i]);
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


    cout<<"Sorting by selection sort"<<endl;
           SelectionSort(arr,n);
           OutputArray(arr,n);

           
}

