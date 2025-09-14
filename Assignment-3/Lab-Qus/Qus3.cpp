#include<iostream>

using namespace std;


class Stack{
 
 
    char *arr;
    int top;
    int size;


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

char peek()
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

int main ()
{

string str;
cout<<"Enter an expression"<<endl;

cin>>str;

Stack s(str.length()+1);

bool valid=true;
for(int i=0;i<str.length();i++)
{
   char ch=str[i];
    if(ch=='('||ch=='{'||ch=='[')
    {
            s.push(ch);
    }

    else{
  

        if(!s.isEmpty())
        {
        char top=s.peek();

              if( ( ch== ')' && top=='(') ||(ch=='}' && top=='{') || (ch==']' && top=='['))
              {
                s.pop();
              }

              else{
                valid=false;
              }

        }

        else{
           valid=false;
        }

    }
}

if(valid)
{
    cout<<"Valid parenthesis"<<endl;
}

else{
    cout<<"Not valid parenthesis"<<endl;
}





}
