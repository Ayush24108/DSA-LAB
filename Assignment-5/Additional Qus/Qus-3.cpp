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

bool detectLoop(Node* head) {
    if (head == NULL || head->next == NULL)
    { 
        return false;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true; 
        }
    }
    return false; 
}

Node* getStartingNode(Node* head) {
    Node* slow = head;
    Node* fast = head;

    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow; 
}

void removeLoop(Node* head) {
    

    Node* startOfLoop = getStartingNode(head);

   
    Node* temp = startOfLoop;
    while (temp->next != startOfLoop) {
        temp = temp->next;
    }

 
    temp->next = NULL;

    cout << "Loop removed successfully." << endl;
}



int main ()
{

    Node*Node1=new Node(1);
    Node*Node2=new Node(7);
    Node *Node3=new Node(3);
   Node *Node4=new Node(6);
 
   Node*Head=Node1;

   Node4->next=Node2;


if(detectLoop(Head))
{
   removeLoop(Head);
}

  else{
    cout<<"No loop detected"<<endl;
  }




   





}
