#include<iostream>


using namespace std;

int LinearSearch(int arr[],int n,int key){

    bool found=false;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==key)
        {
            found=true;
            return i;
        }
    }
    if(!found)
    {
        cout<<"Element "<<key<<" not found"<<endl;
    }

    
}

int BinarySearch(int arr[],int n,int key)
{
 
    int s=0;
    int e=n-1;

    while (s<=e)
    {
        int mid=s+(e-s)/2;

        if(arr[mid]>key)
        {
            e--;

        }

        if(arr[mid]<key)
        {
            s++;
        }

        if(arr[mid]==key)
        {
            return mid;
        }
    }
    

}


int main ()
{
  int arr[5]={1,2,3,4,5};

  int n=5;

  int key;
  cout<<"Enter the no to be searched"<<endl;
  cin>>key;


  int linearIndex=LinearSearch(arr,n,key);
  cout<<"Search in linear time at index "<<linearIndex<<endl; 

  int BinaryIndex=BinarySearch(arr,n,key);
  cout<<"Search in Binary time at index "<<BinaryIndex<<endl; 

  
}
