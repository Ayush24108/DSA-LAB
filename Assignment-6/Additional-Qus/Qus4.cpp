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


void fixRandomPointer(Node* head) {
    if (!head) return;

    Node* curr = head;

    while (curr && curr->next) {
        if (curr->next->prev != curr) {
            cout << " Mistake found between " << curr->data << " and " << curr->next->data << endl;

            Node* temp = curr->next;
            while (temp && temp->prev != curr) {
                temp = temp->next;
            }

            
            curr->next = temp;
            if (temp) temp->prev = curr;

            cout << " Fixed link after node " << curr->data << endl;
            return;
        }
        curr = curr->next;
    }

    cout << "List fully correct"<<endl;
}

int main() {

    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);

    node1->next = node2; node2->prev = node1;
    node2->next = node3; node3->prev = node2;
    node3->next = node4; node4->prev = node3;
    node4->next = node5; node5->prev = node4;

    Node*Head=node1;


    node3->next = Head;

    cout << "List before correction"<<endl;
    print(Head);

    fixRandomPointer(Head);

    cout << "\nlist After correction"<<endl;
    print(Head);

    return 0;
}
