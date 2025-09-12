#include<iostream>

using namespace std;


void Diagonal(int arr[100][100],int n,int m)
{

    int x;

    for(int i=0;i<n;i++)
    {
          for(int j=0;j<m;j++)
          {
            if(i==j)
            {
                cout<<"Enter an element"<<endl;
                cin>>x;
                arr[i][j]=x;
            }

            else{
                arr[i][j]=0;
            }
          }
    }

cout<<"Diagonal matrix is"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    
}

void TriDiagonal(int arr[100][100],int n,int m)
{

    int x,y,z;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i==j)
            {
                cout<<"Enter element for main diagonal"<<endl;
                cin>>x;
                arr[i][j]=x;
               
            }

            else if(i-j==1){
               cout<<"Enter elements for subdiagonal"<<endl;
               cin>>y;
               arr[i][j]=y;
            }

            else if(j-i==1)
            {
                cout<<"Enter element for superdiagonal"<<endl;
                cin>>z;
                arr[i][j]=z;
            }

            else{
                arr[i][j]=0;
            }
        }
    }

    cout<<"Tridiagonal matrix is"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
      {
           cout<<arr[i][j]<<" ";
      }
             cout<<endl;

    }

}

int main ()
{

    int n,m;

    int arr[100][100];


    cout<<"Enter no of rows and columns"<<endl;
    cin>>n>>m;

    
  
    Diagonal(arr,n,m);

    TriDiagonal(arr,n,m);


}
