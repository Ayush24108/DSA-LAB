#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* build(int arr[], int n) {
    Node* head = NULL;
    Node* tail = NULL;

    for(int i=0;i<n;i++) {
        Node* temp = new Node{arr[i], NULL};
        if(head == NULL) {
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }
    return head;
}

void printList(Node* head) {
    while(head) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    int A[] = {10, 15, 4, 20};
    int B[] = {8, 4, 2, 10};

    Node* head1 = build(A, 4);
    Node* head2 = build(B, 4);

    unordered_set<int> s1, s2;

    for(Node* p=head1; p; p=p->next) s1.insert(p->data);
    for(Node* p=head2; p; p=p->next) s2.insert(p->data);

    unordered_set<int> inter, uni = s1;

    for(int x : s2) {
        uni.insert(x);
        if(s1.count(x)) inter.insert(x);
    }

    cout << "Intersection: ";
    for(int x : inter) cout << x << " ";

    cout << "\nUnion: ";
    for(int x : uni) cout << x << " ";

    return 0;
}
