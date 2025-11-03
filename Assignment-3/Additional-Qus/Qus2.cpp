#include<iostream>


using namespace std;


class Stack{



    int *arr;
    int top;
    int size;
    int min;

    public:

    Stack(int n)
    {
        this->size=n;
        arr=new int[size];
        top=-1;
    }

    void push (int x)
    {
          if(top==size-1)
          {
            cout<<"Stack is full"<<endl;

          }

          else if(top==-1)
          { 
            top++;
            min=x;
           arr[top]=x; 
           
          }

          else {
            if(x>min)
            {
                top++;
                arr[top]=x;
            }

            else{

                int val=2*x-min;
                top++;
                arr[top]=val;
                min=x;

            }
          }

    }

    void pop()
    {
        if(top<=0)
        {
            cout<<"Stack is empty"<<endl;

        }
        
        int cur=arr[top];


       if(cur>min){

            top--;
        }

        else{

            min=2*min-cur;
            top--;
        }

    }

    int getmin()
    {
        return min;
    }
};



int main ()
{
    int n;

    cout<<"How many elements you want to enter"<<endl;

    cin>>n;

    Stack s(n);

    cout<<"Enter elements"<<endl;
    for(int i=0;i<n;i++)
    {
        int val;
        cin>>val;
        s.push(val);
    }
    
    cout<<"Minimum element is "<<s.getmin()<<endl;
    s.pop();
    cout<<"Now current minimum element is "<<s.getmin()<<endl;
    s.push(4);
    cout<<"Now current minimum element is "<<s.getmin()<<endl;



}
