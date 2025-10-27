#include <iostream>
using namespace std;


class Node {
public:
    int coeff;   
    int pow; 
    Node* next;

    Node(int c, int p) {
        coeff = c;
        pow = p;
        next = NULL;
    }
};


void insert(Node*& tail, int coeff, int pow) {
    Node* temp = new Node(coeff, pow);
    tail->next = temp;
    tail = temp;
}


void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->coeff << "x^" << temp->pow;
        if (temp->next != NULL)
            cout << " + ";
        temp = temp->next;
    }
    cout << endl;
}


Node* addPolynomial(Node* poly1, Node* poly2) {
    Node* dummy = new Node(0, 0); 
    Node* tail = dummy;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->pow == poly2->pow) {
            int sumCoeff = poly1->coeff + poly2->coeff;
            if (sumCoeff != 0) 
                insert(tail, sumCoeff, poly1->pow);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        else if (poly1->pow > poly2->pow) {
            insert(tail, poly1->coeff, poly1->pow);
            poly1 = poly1->next;
        }
        else {
            insert(tail, poly2->coeff, poly2->pow);
            poly2 = poly2->next;
        }
    }

    while (poly1 != NULL) {
        insert(tail, poly1->coeff, poly1->pow);
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        insert(tail, poly2->coeff, poly2->pow);
        poly2 = poly2->next;
    }

    return dummy->next; 
}

int main() {
   
    Node* poly1 = new Node(5, 2);
    Node* tail1 = poly1;
    insert(tail1, 4, 1);
    insert(tail1, 2, 0);

   
    Node* poly2 = new Node(5, 1);
    Node* tail2 = poly2;
    insert(tail2, 5, 0);

    cout << "First polynomial: ";
    print(poly1);

    cout << "Second polynomial: ";
    print(poly2);

    Node* result = addPolynomial(poly1, poly2);
    cout << "\nResultant polynomial: ";
    print(result);

    return 0;
}
