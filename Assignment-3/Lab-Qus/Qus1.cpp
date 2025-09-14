#include<iostream>


using namespace std;

class Stack{
   int *arr;
    int top;
    int size;

    
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
            cout<<"Stack overflow"<<endl;
        }
    }

    void pop()
    {
       if(top>=0)
       {
        top--;
        
       }

       else{
        cout<<"Stack is empty<<"<<endl;
       }
    }

    int peek()
    {
          if(top>=0)
          {
            return arr[top];
          }
    else{
    cout<<"Stack is empty"<<endl;
    return -1;
                   }
    }

    void Display()
    {
       while(!isEmpty())
        {
            cout<<peek()<<endl;
            pop();
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

    bool isFull()
    {
        if(top==size)
        {
            return true;
        }

        else{
            return false;
        }
    }
};

int main ()
{
      
     
     Stack S(5);

      char choice;
     

      do{
        cout << "\nChoose an operation:"<<endl;
        cout << "1. push"<<endl;
        cout << "2. pop"<<endl;
        cout << "3. isEmpty"<<endl;
        cout << "4. isFull"<<endl;
        cout << "5. Display"<<endl;
        cout << "6. peek"<<endl;
       

         int operation;
         cin>>operation;

      switch (operation)
      {
      case 1:
      int n;
      cout<<"Which element would you like to insert"<<endl;
      cin>>n;
      S.push(n);
        break;

        case 2:
       S.pop();
        break;

        case 3:
        if(S.isEmpty())
        cout<<"Stack is empty"<<endl;
        break;

        case 4:
      if(S.isFull())
      {
        cout<<"Stack is full"<<endl;
      }

        break;

        case 5:
        S.peek();
        break;

        case 6:
        S.peek();
        break;
      
      default:
      cout<<"Wrong choice"<<endl;
        break;

       
      }
      
     cout<<endl;
      cout<<"Do you want to run another operation (yes/no)"<<endl;
      cin>>choice;
      
    }while(choice=='y'||choice=='Y');




}
