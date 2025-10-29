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
void Length(int &length,Node*Tail)
{
    length=0;
    Node*temp=Tail->next;

   do
    {
        length++;
        temp=temp->next;
       
    } while(temp!=Tail->next);
}

void print(Node *Tail)
{
    Node*temp=Tail->next;

   do
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    } while(temp!=Tail->next);
    cout<<endl;

 
    
}

void InsertAtHead(Node*&Tail,int d)
{ 
    Node*NodeToInsert=new Node(d);

    if(Tail==NULL)
    {
        Tail=NodeToInsert;
        NodeToInsert->next=NodeToInsert;
        return;
    
    }

   
    NodeToInsert->next=Tail->next;
    Tail->next=NodeToInsert;

}

void InsertAtTail(Node*&Tail,int d)
{
    Node*NodeToInsert=new Node(d);
    if(Tail==NULL)
    {
          Tail=NodeToInsert;
          NodeToInsert->next=NodeToInsert;
        return;
    }

    

    NodeToInsert->next=Tail->next;
    Tail->next=NodeToInsert;
    Tail=NodeToInsert;
}

void InsertAtMiddle(Node *&Tail,int n,int pos,int length)
{  
    
    Node*NodeToInsert=new Node(n);
    if(Tail==NULL)
    {
          Tail=NodeToInsert;
          NodeToInsert->next=NodeToInsert;
        return;
    }

    else if(pos==1)
    {
        InsertAtHead(Tail,n);
    }

    else if(pos==length+1)
    {
        InsertAtTail(Tail,n);
    }



    Node*temp=Tail->next;
     int cnt=1;
    while(cnt<pos-1)
    {
        temp=temp->next;
        cnt++;
    }

    NodeToInsert->next=temp->next;

    temp->next=NodeToInsert;
    
}

void  DeleteAtBegining(Node*&Tail)
{
     Node*Head=Tail->next;
        if(Head==Tail)
        {
            delete Head;
            Tail=NULL;
            return;
        }

         
         Tail->next=Head->next;
         delete Head;
         return;
}

 void DeleteAtEnd(Node*&Tail){
     Node* temp = Tail->next; 
        while (temp->next != Tail) {
            temp = temp->next;
        }
        temp->next = Tail->next; 
        delete Tail;
        Tail = temp; 
        return;
 }

void Delete(Node*&Tail,int pos,int length)
{
     
     Node*temp=Tail->next;
   if(Tail==NULL)
    {
          cout<<"List is empty"<<endl;
        return;
    }

    if(pos==1)
    {
        DeleteAtBegining(Tail);
    }

    else if(pos==length)
    {
        DeleteAtEnd(Tail);
        return;
    }

   int cnt=1;
   while(cnt<pos-1)
   {
        temp=temp->next;
        cnt++;
   }

   Node*NodeToDelete=temp->next;

   temp->next=NodeToDelete->next;

   delete NodeToDelete;

  

}

void Search(Node* Tail, int key) {
    if (Tail == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = Tail->next;
    int pos = 1;
    bool found = false;

    do {
        if (temp->data == key) {
            cout << "Element " << key << " found at position " << pos << endl;
            found = true;
        }
        temp = temp->next;
        pos++;
    } while (temp != Tail->next);

    if (!found)
        cout << "Element not found\n";
}





int main ()
{

   

       Node *node1=new Node(10);
       Node *node2=new Node(20);
       Node *node3=new Node(30);
 
       node1->next=node2;
       node2->next=node3;
       node3->next=node1;

       Node *Head=node1;
       Node*Tail=node3;  
       
       
       int length;
    Length(length,Tail);

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
    InsertAtHead(Tail,5);
    print(Tail);
    Length(length,Tail);
        break;

        case 2:
        InsertAtTail(Tail,45);
    print(Tail);
    Length(length,Tail);

        break;

        case 3:
       
    int n,pos;
    cout<<"Enter poisition and number you want to enter "<<endl;
    cin>>pos>>n;
    
    InsertAtMiddle(Tail,n,pos,length);
    print(Tail);
    Length(length,Tail);

        break;

        case 4:
        int pos1;
    cout<<"Enter poisition you want to delete"<<endl;
    cin>>pos1;

     Length(length, Tail);
     Delete(Tail,pos1,length);
    print(Tail);

         break;

       
        case 5:
        int key;
                cout << "Enter value to search: ";
                cin >> key;
                Search(Tail, key);
       
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


       

       
       
}
