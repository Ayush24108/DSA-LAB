#include<iostream>

using namespace std;

void EnterElements(int arr[100][100],int n,int m)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
}

void Display(int arr[100][100],int n,int m)
{
    cout<<"Transposed matrix is"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
           cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
void TransposeMatrix(int arr[100][100],int n,int m)
{
       int temp[100][100];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            temp[i][j]=arr[j][i];
        }
    }


    Display(temp,n,m);
}

int main() {
    int n, m;
    cout << "Enter number of rows and columns of Matrix:" << endl;
    cin >> n >> m;

    int arr[100][100];
    EnterElements(arr, n, m);
    TransposeMatrix(arr, n, m);
}
