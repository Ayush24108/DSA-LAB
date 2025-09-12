#include<iostream>

using namespace std;

void print(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

 void BubbleSort(int arr[],int n)
 {
    

    for(int i=0;i<n-1;i++)
    {
        bool flagVariable=false;
        for(int j=0;j<n-i-1;j++)
        {
          
            if(arr[j]>arr[j+1])
            {  
                flagVariable=true;
                swap(arr[j],arr[j+1]);
            }

            
        }
        if(!flagVariable)
        {
            break;
        }
    } 
    print(arr,n);
 }



int main ()
{

    int arr[]={1,2,3,5,4};

  int n=5;

    BubbleSort(arr,n);
}
