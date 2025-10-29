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
void Size(int &length,Node*Tail)
{
    length=0;
    Node*temp=Tail->next;

   do
    {
        length++;
        temp=temp->next;
       
    } while(temp!=Tail->next);
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
       
       int length=0;

       Size(length,Tail);
       
}
