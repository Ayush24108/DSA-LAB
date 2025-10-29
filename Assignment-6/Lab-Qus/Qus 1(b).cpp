
#include <iostream>
using namespace std;


class  Node
{

public:
     int data;
     Node *prev=NULL;
     Node* next=NULL;

     Node(int d)
     {
        this->data=d;
        this->prev=NULL;
        this->next=NULL;
     }
};

void print(Node *Head)
{
    Node*temp1=Head;
 
 
    cout<<"The given linked list is"<<endl;
    cout<<"NULL<-";

    while(temp1!=NULL)
    {
        cout<<temp1->data<<"<->";
        temp1=temp1->next;

       
    }
cout<<"NULL"<<endl;
}

void Size(Node*&Head,int &Length)
{
    Length=0;
    Node*temp=Head;

    while(temp!=NULL)
    {
        temp=temp->next;
        Length++;
    }
}

void InsertAtHead(Node *&Head,int d)
{
    Node*temp=new Node(d);

    temp->next=Head;
    temp->prev=NULL;

    Head->prev=temp;
    Head=temp;
     
}

void InsertAtTail(Node *&Tail,int d)
{
    Node*temp=new Node(d);
        
    temp->prev=Tail;
    temp->next=NULL;

    Tail->next=temp;
    Tail=temp;

}

void InsertAtMiddle(Node* &Head,int pos,int n,Node*&Tail,int length)
{
    Node*temp1=Head;
  
    if(pos==1)
    {
        InsertAtHead(Head,n);
    }


    if(pos==length+1)
    {
        InsertAtTail(Tail,n);
    }

     int cnt=1;
    while(cnt<=pos-1)
    {
         temp1=temp1->next;
       

         cnt++;
         
    }

    Node* NodeToInsert = new Node(n);
    NodeToInsert->next = temp1->next;
    NodeToInsert->prev = temp1;
    if (temp1->next != NULL) {
        temp1->next->prev = NodeToInsert;
    }
    temp1->next = NodeToInsert;



}

void DeleteAtbegining(Node*&Head)
{

    
         Node*temp=Head;
         Head=Head->next;

         if(Head!=NULL)
         {
                Head->prev=NULL;
         }
         delete temp;
         return;

}

void DeleteAtEnd(Node*&Tail)
{
    
           Node*temp=Tail;
           Tail=Tail->next;
           if(temp!=NULL)
           {
            Tail->next=NULL;
           }

           delete temp;
           return;

}

void Delete(Node *&Head,int pos1,Node *&Tail,int length)
{
    Node*temp=Head;
  

    if(pos1==1)
    {
        
         DeleteAtbegining(Head);
         return;
    }

    if(pos1==length)
    {
          DeleteAtEnd(Tail);
          return;
    }

    int cnt=1;
    while(cnt<pos1)
    {
         temp=temp->next;

         cnt++;
         
    }

    
temp->prev->next=temp->next;
temp->next->prev=temp->prev;
    

    delete temp;;
}

void Search(Node *head, int key) {
    if (head == NULL) {
        cout << "List is empty"<<endl;
        return;
    }

    Node *temp = head;
    int pos = 1;
    bool found = false;

    while (temp != NULL) {
        if (temp->data == key) {
            cout << "Element " << key << " found at position " << pos << endl;
            found = true;
            break;
        }
        temp = temp->next;
        pos++;
    }

    if (!found)
        cout << "Element not found"<<endl;
}





int main ()
{

    Node *node1=new Node(10);
    Node *node2=new Node(20);
    Node *node3=new Node(30);
    Node *node4=new Node(40);

    node1->prev=NULL;
    node1->next=node2;
    
    node2->prev=node1;
    node2->next=node3;

    node3->prev=node2;
    node3->next=node4;

    node4->prev=node3;
    node4->next=NULL;

    Node*Head=node1;
    Node*Tail=node4;


   int length=0;
   Size(Head,length);
   
    print(Head);

char choice;

    do{
        cout << "\nChoose an operation:\n";
        cout << "1. Insertion at begining\n";
        cout << "2. Insertion at end\n";
        cout << "3. Insertion at a poisition\n";
        cout << "4. Deletion \n";
        cout << "5. Search for a node and display its position from head.\n";
        cout << "6. Display all the node values.\n";
       

    

        cout << "Enter choice: ";

         int operation;
         cin>>operation;

      switch (operation)
      {
      case 1:
       InsertAtHead(Head,5);
    print(Head);
     Size(Head,length);

   
        break;

        case 2:
        InsertAtTail(Tail,45);
    print(Head);
    Size(Head,length);

        break;

        case 3:
       
    int pos,n;

    cout<<"At which poisition would you like to insert and what would you like to insert?"<<endl;
    cin>>pos>>n;

     InsertAtMiddle(Head,pos,n,Tail,length);
     print(Head);
     Size(Head,length);

        break;

        case 4:
      int pos1;
     cout<<"Which poisition would you like to delete"<<endl;
     cin>>pos1;


     Delete(Head,pos1,Tail,length);
     print(Head);

         break;

       
        case 5:
        int key;
                cout << "Enter value to search: ";
                cin >> key;
             Search(Head, key);

       
        break;

        case 6:
         print(Head);

        break;

      
      default:
        break;

       
      }
      
     cout<<endl;
      cout<<"Do you want to run another operation (yes/no)"<<endl;
      cin>>choice;
      
    }while(choice=='y'||choice=='Y');


       

       

   

    

     int pos1;
     cout<<"Which poisition would you like to delete"<<endl;
     cin>>pos1;


     Delete(Head,pos1,Tail,length);
     print(Head);



}


