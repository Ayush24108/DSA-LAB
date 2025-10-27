#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data=data;
          this ->next=NULL;
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

int CountOcc(Node*Head,int key )
{
    Node*temp=Head;
    int count;

    while(temp!=NULL)
    {
        if(temp->data==key)
        {
            count++;
        }
        temp=temp->next;
    }

    return count;
}

void DeleteOcc(Node*&head,int key)
{
    while (head != NULL && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

  
    Node* current = head;
    Node* prev = NULL;

    while (current != NULL) {
        if (current->data == key) {
            prev->next = current->next;
            delete current;
            current = prev->next;
        } else {
            prev = current;
            current = current->next;
        }
    }
    
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

   print(Head);

int key;
cout<<"Enter key"<<endl;
cin>>key;

cout<<"Number of occurences of key are "<<CountOcc(Head,key)<<endl;


DeleteOcc(Head,key);

cout<<"Updated linked list is"<<endl;
print(Head);






}
