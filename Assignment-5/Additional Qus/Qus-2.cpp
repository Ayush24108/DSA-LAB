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
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}


void insertAtTail(Node*& tail, int data) {
    Node* temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

Node* reverseKGroup(Node* head, int k) {
    if (head == NULL)
        return NULL;

    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    int count = 0;


    Node* check = head;
    for (int i = 0; i < k; i++) {
        if (check == NULL) {
            return head; 
        }
        check = check->next;
    }


    while (curr != NULL && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if (next != NULL) {
        head->next = reverseKGroup(next, k);
    }

    
    return prev;
}

int main() {

    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;

 
    for (int i = 2; i <= 8; i++) {
        insertAtTail(tail, i);
    }

    cout << "Original list:" << endl;
    print(head);

    int k;
    cout << "Enter group size K: ";
    cin >> k;

    head = reverseKGroup(head, k);

    cout << "List after reversing in groups of " <<endl;
    print(head);

    return 0;
}
