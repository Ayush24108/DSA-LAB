#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};

void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}


void InsertAtHead(Node* &head,int d)
{
    Node *temp=new Node(d);
    temp->next=head;
    head=temp;
   
}



void Reverse(Node*&Head)
{

    
  
    Node*prev=NULL;
    Node*Current=Head;
   Node*forward=Current->next;
    while(Current!=NULL)
    {
        
        forward=Current->next;
        
        Current->next=prev;
        prev=Current;
        Current=forward;

    }

    Head=prev;


}





int main ()
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


   cout<<"Initial linked list"<<endl;
   print(Head);


   Reverse(Head);

   cout<<"Reversed linked list is"<<endl;
   print(Head);
}
