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

void InsertAtHead(Node* &head,int d)
{
    Node *temp=new Node(d);
    temp->next=head;
    head=temp;
   
}

int FindMiddle(Node*Head,int n)
{
      if(n==0)
      {
        cout<<"List is empty<<endl;
      }

      if(n==1)
      {
        return Head->data;
      }

      Node*temp=Head;

    Node* slow = Head;
    Node* fast = Head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          
        fast = fast->next->next;    
    }

    return slow->data;

}


int main()
{

    Node*Head=NULL;

   int n,d;
   cout<<"Enter the no of nodes you wish to add"<<endl;
   cin>>n;

cout<<"Enter values"<<endl;
   for(int i=0;i<n;i++)
   {
    cin>>d;
    InsertAtHead(Head,d);

   }

   cout<<"Middle element is"<<FindMiddle(Head,n);

}
