#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next) cout << " <-> ";
        temp = temp->next;
    }
    cout << endl;
}

Node* reverseInGroups(Node* head, int k) {
    if (!head) return NULL;

    Node* current = head;
    Node* next = NULL;
    Node* newHead = NULL;
    int count = 0;


    while (current && count < k) {
        next = current->next;
        current->next = current->prev;
        current->prev = next;
        head = current; 
        current = next;
        count++;
    }

    
    if (next != NULL) {
        Node* restHead = reverseInGroups(next, k);
      
        newHead = head;
        Node* tail = newHead;
        while (tail->next != NULL)
            tail = tail->next;
    }

    return head;
}

Node* reverseKGroup(Node* head, int k) {
    if (!head || k <= 1) return head;

    Node* current = head;
    Node* newHead = NULL;
    Node* groupPrevTail = NULL;

    while (current) {
        int count = 0;
        Node* groupHead = current;

  
        Node* temp = current;
        while (temp && count < k) {
            temp = temp->next;
            count++;
        }

    
        Node* prev = NULL;
        Node* next = NULL;

        if (count > 0) {
            int i = 0;
            while (current && i < count) {
                next = current->next;
                current->next = prev;
                current->prev = next;
                prev = current;
                current = next;
                i++;
            }
        }

        if (newHead == NULL)
            newHead = prev;

        if (groupPrevTail != NULL) {
            groupPrevTail->next = prev;
            prev->prev = groupPrevTail;
        }

        groupPrevTail = groupHead;
    }

    return newHead;
}

int main() {

    Node* head = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);
    Node* n7 = new Node(7);

    head->next = n2; n2->prev = head;
    n2->next = n3; n3->prev = n2;
    n3->next = n4; n4->prev = n3;
    n4->next = n5; n5->prev = n4;
    n5->next = n6; n6->prev = n5;
    n6->next = n7; n7->prev = n6;

    cout << "Original DLL"<<endl;
    print(head);

    int k = 3;
    head = reverseKGroup(head, k);

    cout << "\nAfter reversing in groups of " << k << endl;
    print(head);

    return 0;
}
