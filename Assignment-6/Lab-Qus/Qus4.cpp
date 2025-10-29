#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* next;
    Node* prev;

    Node(char d) {
        data = d;
        next = prev = NULL;
    }
};

void insertAtEnd(Node*& head, char d) {
    Node* newNode = new Node(d);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}


bool isPalindrome(Node* head) {
    if (head == NULL) return true;

    Node* tail = head;
    while (tail->next != NULL)
        tail = tail->next;

    while (head != tail && tail->next != head) {
        if (head->data != tail->data)
            return false;
        head = head->next;
        tail = tail->prev;
    }
    return true;
}


void printList(Node* head) {
    Node* temp = head;
    cout << "List: ";
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = NULL;

    string s;
    cout << "Enter characters "<<endl;
    cin >> s;


    for(int i=0;i<s.length();i++)
    {
        insertAtEnd(head,s[i]);
    }

    printList(head);

    if (isPalindrome(head))
        cout << " The list is a palindrome." << endl;
    else
        cout << " The list is not a palindrome." << endl;

   
}
