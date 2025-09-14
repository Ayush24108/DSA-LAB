#include<iostream>

using namespace std;


class Stack
{

  char *arr;
  int size;
  int top;
public:

  
    Stack(int size)
    {
         this->size=size;
         arr=new char[size];
         top=-1;
    }
   
    void push(char ch)
    {
        if(size-top>1)
    {
       top++;
       arr[top]=ch;
    }    

    else{
        cout<<"Stack is full"<<endl;

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

  char peek()
  {
   if(top>=0)
   {
    return arr[top];
   }
  
  }

};

int main ()
{

    string str="DataStructure";


    Stack s(str.length()+1);


    for(int i=0;i<str.length();i++)
    {
        char ch=str[i];
        s.push(ch);

    }

string ans="";

while(!s.isEmpty())
{
     char ch= s.peek();
     ans.push_back(ch);

     s.pop();

}

cout<<"Reversed string is "<<ans<<endl;
}
