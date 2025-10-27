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

Node* rotateLeft(Node* head, int k) {
    if (head == NULL || head->next == NULL || k == 0)
        return head;

 
    Node* temp = head;
    int len = 1;
    while (temp->next != NULL) {
        temp = temp->next;
        len++;
    }

  
    k = k % len;
    if (k == 0)
        return head;

   
    temp->next = head;

    Node* newTail = head;
    for (int i = 1; i < k; i++) {
        newTail = newTail->next;
    }

    Node* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}

int main() {
 
    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;

    for (int i = 2; i <= 5; i++) {
        insertAtTail(tail, i);
    }

    cout << "Original List:" << endl;
    print(head);

    int k;
    cout << "Enter rotation value k: ";
    cin >> k;

    head = rotateLeft(head, k);

    cout << "List after rotating left by " <<endl;
    print(head);

    return 0;
}
