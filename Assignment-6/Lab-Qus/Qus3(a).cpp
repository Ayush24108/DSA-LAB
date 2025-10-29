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

    
}
