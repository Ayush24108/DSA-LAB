#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* next;
};

bool detectCycle(Node* head) {
    unordered_set<Node*> visited;

    while(head != NULL) {
        if(visited.count(head))
            return true;

        visited.insert(head);
        head = head->next;
    }
    return false;
}

int main() {
    Node* a = new Node{1, NULL};
    Node* b = new Node{2, NULL};
    Node* c = new Node{3, NULL};
    Node* d = new Node{4, NULL};

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = b;   

    if(detectCycle(a))
        cout << "Cycle Found";
    else
        cout << "No Cycle";

    return 0;
}
