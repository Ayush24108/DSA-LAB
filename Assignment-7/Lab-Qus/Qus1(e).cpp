#include<iostream>
#include<vector>

using namespace std;

int partition(int *arr,int s,int e)
{
    int pivot=arr[s];

    int count=0;
    for(int i=s+1;i<=e;i++)
    {
        if(arr[i]<pivot)
        {
            count++;
        }
    }

    int pivotindex=s+count;
    swap(arr[s],arr[pivotindex]);
    while(s<pivotindex && e>pivotindex)
    {
            while(arr[s]<pivot)
            {
                s++;
            }

            while (arr[e]>pivot)
            {
              e--;
            }
            if(s<pivotindex && e>pivotindex)
            {         swap(arr[s++],arr[e--]);
            
            }
            
            
    }
    return pivotindex;
}




void quicksort(int *arr,int s,int e)
{
    if(s>=e)
    {
        return ;

    }
    
    
    int p=partition(arr,s,e);

    quicksort(arr,s,p-1);
    quicksort(arr,p+1,e);

}

int main ()
{
    int arr[5]={2,1,0,6,9};

    quicksort(arr,0,4);

    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }
}
