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




void BubbleSort(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            if(arr[j]<arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
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


   

   cout<<"Sorting by Bubble sort"<<endl;
            BubbleSort(arr,n);
      OutputArray(arr,n);
}
            

}



