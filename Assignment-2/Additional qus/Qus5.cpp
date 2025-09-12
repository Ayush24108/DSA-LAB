#include<iostream>

using namespace std;


void Duplicate(int *arr,int n)
{
       for(int i=0;i<n;i++)
       {
        if(arr[i]==2)
        {
        for (int j=n-1;j>i;j--) {
                arr[j] = arr[j-1];
            }
        if (i+1<n) 
        {
            arr[i+1] = 2;
        }
            i++;
        }

        
       }
}
int main ()
{

    int arr[100];
    int n;

    cout<<"Enter size of array"<<endl;
    cin>>n;

    cout<<"Enter elements of array"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    Duplicate(arr,n);
    

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

}
