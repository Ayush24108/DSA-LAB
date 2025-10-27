#include <iostream>
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
void print(Node* &head)
{
    Node*temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
    

}

void InsertAtHead(Node* &head,int d)
{
    Node *temp=new Node(d);
    temp->next=head;
    head=temp;
    print(head);
}

void InsertAtTail(Node* &tail,int d)
{
Node *temp=new Node(d);

    tail->next=temp;
    tail=temp;
  
}

void InsertAtMiddle(Node *&head,int poisition,int d)
{
Node *temp=head;

int cnt=1;
while(cnt<poisition-1)
{
    temp=temp->next;
    cnt++;
}
  Node *NodeToInsert=new Node(d);

  NodeToInsert->next=temp->next;
  temp->next=NodeToInsert;
}

void DeleteAtBegining (Node *&Head)
{
     Node *temp=Head;
         Head=Head->next;
         delete temp;
         return;

}

void DeleteAtEnd(Node*&tail,Node*&head){
    if (head->next == NULL) {
        delete head;
        head = NULL;
        tail = NULL;
        return;
    }

    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;
    tail = temp;



}


void DeleteAtMiddle(Node *&Head,int pos)
{

    if(pos==1)
    {
         DeleteAtBegining(Head);
    }

    
    Node *temp=Head;

    int cnt=1;
    while(cnt<pos-1)
    {
        temp=temp->next;
        cnt++;
    }

    Node *NodeToDelete=temp->next;
    temp->next =  NodeToDelete->next;
    delete NodeToDelete;



}

void Search(Node* head, int key) {
    int position = 1;
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            cout << "Element " << key << " found at position " << position << endl;
            return;
        }
        temp = temp->next;
        position++;
    }
    cout << "Element " << key << " not found in the list.\n";

    print(head);
}





int main ()
{
       Node *node1=new Node(10);

       cout<<node1->data<<endl;
       cout<<node1->next<<endl;

       Node *node2=new Node(20);
       Node *node3=new Node(30);
 
       node1->next=node2;
       node2->next=node3;

       Node *Head=node1;
       Node*tail=node3;

       char choice;
     

      do{
        cout << "\nChoose an operation:\n";
        cout << "1. Insertion at begining\n";
        cout << "2. Insertion at end\n";
        cout << "3. Insertion at a poisition\n";
        cout << "4. Deletion from begining\n";
        cout << "5. Deletion from end\n";
        cout << "6. Deletion from middle\n";
        cout << "7. Search for a node and display its position from head.\n";
        cout << "8. Display all the node values.\n";
       

    

        cout << "Enter choice: ";

         int operation;
         cin>>operation;

      switch (operation)
      {
      case 1:
       InsertAtHead(Head,5); 
       print(Head);
        break;

        case 2:
        InsertAtTail(tail,5);
       print(Head);
     
        break;

        case 3:
       int n,pos;
       cout<<"Enter the poisition and number to be inserted"<<endl;
       cin>>pos>>n;


        InsertAtMiddle(Head,pos,n);
      print(Head);

        break;

        case 4:
        DeleteAtBegining(Head);
         break;

        case 5:
        DeleteAtEnd(tail,Head);
        break;

        case 6:
        int pos;
       cout<<"Enter the poisition at which number should be deleted"<<endl;
        cin>>pos;
       DeleteAtMiddle(Head,pos);

       cout<<"After deletion"<<endl;
         print(Head);
       break;

        case 7:
        int key;
                cout << "Enter value to search: ";
                cin >> key;
                Search(Head, key);
       
        break;

        case 8:
         print(Head);

        break;

      
      default:
        break;

       
      }
      
     cout<<endl;
      cout<<"Do you want to run another operation (yes/no)"<<endl;
      cin>>choice;
      
    }while(choice=='y'||choice=='Y');


       

       
       
}
