#include<iostream>


using namespace std;


int Distinct(int arr[],int n)
{
  int count=0;

  for(int i=0;i<n;i++)
  {
   if(arr[i]!=arr[i+1])
   {
    count++;
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


    int count=Distinct(arr,n);

    cout<<"Total number of distinct elements are "<<count<<endl;
}
