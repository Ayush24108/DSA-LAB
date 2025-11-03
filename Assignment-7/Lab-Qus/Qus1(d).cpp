#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &a,int s,int e,int mid)
{
    int n1=mid-s+1;
    int n2=e-mid;
       vector<int> temp1(n1),temp2(n2);

       for(int i=0;i<n1;i++)
       {
        temp1[i]=a[s+i];

       }
        for (int j = 0; j < n2; j++){
        temp2[j] = a[mid + 1 + j];
        }

        int i=0,j=0,k=s;
        while(i<n1 && j<n2)
        {
            if(temp1[i]<temp2[j])
            {
                a[k]=temp1[i];
                i++;
            }
            else{
                a[k]=temp2[j];
                j++;
            }
            k++;
        }

        while(i<n1)
        {
            a[k]=temp1[i];
            i++;
            k++;
        }

        while(j<n2)
        {
            a[k]=temp2[j];
            j++;
            k++;
        }
        
}


void mergesort(vector<int> &a,int s,int e)
{
    if(s<e)
      {  int mid=s+(e-s)/2;

        mergesort(a,s,mid);
        mergesort(a,mid+1,e);


        merge(a,s,e,mid);


}
}

void print(vector<int>&a)
{
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }
}


int main ()
{
    vector<int> a={5,4,3,2,1};

    mergesort(a,0,a.size()-1);

    cout<<"Sorted array is"<<endl;
    print(a);

}
