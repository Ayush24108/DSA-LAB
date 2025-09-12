#include<iostream>

using namespace std;

int Difference(int arr[],int n,int k)
{
    int count=0;
         for(int i=0;i<n;i++)
         {
            for(int j=i+1;j<n;j++)
            {
                if(arr[i]-arr[j]==k || arr[j]-arr[i]==k)
                {
                    count++;
                }
            }
         }
         return count;
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

    int k;

    cout<<"What is the absolute difference you would like to search"<<endl;
    cin>>k;

    int count=Difference(arr,n,k);

    cout<<"Total pairs in array with given differenceare "<<count<<endl;

}
