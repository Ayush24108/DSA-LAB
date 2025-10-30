#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void splitCircularList(Node* head, Node*& head1, Node*& head2) {
    if (head == NULL)
        return;

    Node *slow = head, *fast = head;


    while (fast->next != head && fast->next->next != head) {
        fast = fast->next->next;
        slow = slow->next;
    }

 
    if (fast->next->next == head)
        fast = fast->next;

    head1 = head;
    head2 = slow->next;


    slow->next = head1;

   
    fast->next = head2;
}


void printCircular(Node* head) {
    if (head == NULL) return;

    Node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
   
}

int main() {
    Node* node1= new Node(1);
    Node* node2=new Node(2);
    Node* node3=new Node(3);
    Node* node4=new Node(4);
    Node* node5=new Node(5);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next=node1;

    Node*head=node1;


    Node *head1 = NULL, *head2 = NULL;

    splitCircularList(head, head1, head2);

    cout << "First half: ";
    printCircular(head1);

    cout << "Second half: ";
    printCircular(head2);
}
