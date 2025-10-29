#include<iostream>

using namespace std;

class Node{

   public:
    int data;
    Node*next;

    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};

bool isCircular(Node*Head)
{
       Node *temp=Head->next;

       if(Head==NULL)
       {
        cout<<"List is empty"<<endl;
        return false;

       }

       while(temp!=NULL && temp!=Head)
       {
        temp=temp->next;
       }

       if(temp==Head)
       {
        return true;
       }

       else {
        return false;
       }

       
         

}



int main ()
{

    Node *node1=new Node(2);
    Node *node2=new Node(4);
    Node *node3=new Node(5);
    Node *node4=new Node(6);
    Node *node5=new Node(7);

    node1->next=node2;
    node2->next=node3;
    node3->next=node4;
    node4->next=node5;
    node5->next=node1;
  
    


Node*Head=node1;
   


    if(isCircular(Head))
    {
     cout<<"List is circular"<<endl;

    }

    else{
        cout<<"List is not ciruclar"<<endl;
    }

    
   
}
