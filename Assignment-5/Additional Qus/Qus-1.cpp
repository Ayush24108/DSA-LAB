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

void print(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

Node* IntersectionNode(Node* headA, Node* headB) {
    if (headA == NULL || headB == NULL)
        return NULL;

    Node* ptr1 = headA;
    Node* ptr2 = headB;

  
    while (ptr1 != ptr2) {
        ptr1 = (ptr1 == NULL) ? headB : ptr1->next;
        ptr2 = (ptr2 == NULL) ? headA : ptr2->next;
    }

    return ptr1; 
}

int main() {
  
    Node* common1 = new Node(7);
    Node* common2 = new Node(8);
    Node* common3 = new Node(9);
    common1->next = common2;
    common2->next = common3;

  
    Node* headA = new Node(1);
    headA->next = new Node(2);
    headA->next->next = new Node(3);
    headA->next->next->next = common1; 


    Node* headB = new Node(4);
    headB->next = new Node(5);
    headB->next->next = common1;  

    cout << "List A: ";
    print(headA);
    cout << "List B: ";
    print(headB);

    Node* intersection = IntersectionNode(headA, headB);

    if (intersection)
        cout << "Intersection found at node with value: " << intersection->data << endl;
    else
        cout << "No intersection found." << endl;

    return 0;
}
