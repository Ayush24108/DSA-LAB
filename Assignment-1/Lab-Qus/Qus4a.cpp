#include<iostream>

using namespace std;

void CreateArray(int arr[],int n)
{
    cout<<"Enter elements of array"<<endl;
     for(int i=0;i<n;i++)
     {
        cin>>arr[i];
     }
}
void Display(int arr[],int n)
{
cout<<"Updated array is"<<endl;
      for(int i=0;i<n;i++)
      {
        cout<<arr[i]<<" ";
      }
}

void ReverseArray(int arr[],int n)
{
   int s=0;
   int e=n-1;

   while(s<=e)
   {
    swap(arr[s],arr[e]);
    s++;
    e--;
   }

   Display(arr,n);
}

int main ()
{
    int n;
    cout<<"Enter size of array"<<endl;
    cin>>n;

    int arr[100];

    CreateArray(arr,n);

    ReverseArray(arr,n);


}
