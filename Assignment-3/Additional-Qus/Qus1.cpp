#include<iostream>


using namespace std;





class Stack
{

  int *arr;
  int size;
  int top;

public:

  
    Stack(int size)
    {
         this->size=size;
         arr=new int[size];
         top=-1;
    }


    void push(int n)
    {
        if(size-top>1)
        {
            top++;
            arr[top]=n;
        }

        else{
           return;
        }
    }

    void pop()
    {
       if(top>=0)
       {
        top--;
        
       }

       else{
       return;
       }
    }

 int peek()
  {
   if(top>=0)
   {
    return arr[top];
   }
  
  }

  bool isEmpty()
    {

        if(top==-1)
        {
            return true;
        }

        else{
            return false;
        }

    }

   
};

void Small(int A[], int n) {
    Stack s(n);
    int ans[100];   

    for(int i=0; i<n; i++) {
        while(!s.isEmpty() && s.peek() >= A[i]) {
            s.pop();
        }

        if(s.isEmpty()) {
            ans[i] = -1;
        }
        else {
            ans[i] = s.peek();
        }

        s.push(A[i]);
    }

    cout << "Nearest smaller to left:" << endl;
    for(int i=0; i<n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main ()
{

int arr[100];

int n;
cout<<"How many elements you wish to enter"<<endl;
cin>>n;


cout<<"Enter elements"<<endl;
for(int i=0;i<n;i++)
{
    cin>>arr[i];
}


Small(arr,n);



}
