#include<iostream>
#include<vector>

using namespace std;
vector<vector<int>> Multiply(vector<vector<int>> &a,vector<vector<int>> &b)
{ 
    vector<vector<int>> temp(a.size(),vector<int>(b[0].size()));

    for(int i=0;i<a.size();i++)
    {
        for(int j=0;j<b[0].size();j++)
        {
           for(int k=0;k<b.size();k++)
           {
            temp[i][j]+=a[i][k]*b[k][j];
           }
        }
    }

    return temp;
}

void EnterNumbers( vector<vector<int>> &matrix)
{
    int n=matrix.size();
    int m=matrix[0].size();

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>matrix[i][j];
        }
    }
}
    

int main ()
{
    int n,m;

    cout<<"Enter rows and columns of matrix 1"<<endl;
    cin>>n>>m;

    vector<vector<int>> a(n,vector<int> (m));

    EnterNumbers(a);

    int p,q;

    cout<<"Enter rows and columns of matrix 2"<<endl;
    cin>>p>>q;

    vector<vector<int>> b(p,vector<int> (q));

    EnterNumbers(b);

    vector<vector<int>> c=Multiply(a,b);

    cout<<"Matrix Multiplication is"<<endl;
    for(int i=0;i<c.size();i++)
    {
        for(int k=0;k<c[0].size();k++)
        {
            cout<<c[i][k]<<" ";
        }
        cout<<endl;
    }
}
