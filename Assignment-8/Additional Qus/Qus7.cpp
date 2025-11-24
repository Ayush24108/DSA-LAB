#include <iostream>
using namespace std;


class Node {
public:
    int data;
    Node* left;   
    Node* right;  
    Node(int d) {
        data = d;
        left = right = NULL;
    }
};


Node* buildTree(Node*root)
{
    int d;
    cout<<"Enter value"<<endl;
    cin>>d;

    if(d==-1)
    {
        return NULL;
    }

    root=new Node(d);

    cout<<"Enter value of left of  "<< d <<endl;
    root->left=buildTree(root->left);

    cout<<"Enter data of right of "<< d <<endl;
    root->right=buildTree(root->right);

    return root;
}



void bstToDLL(Node* root, Node*& head) {
    static Node* prev = NULL;

    if (!root) return;


    bstToDLL(root->left, head);

   
    if (prev == NULL)
        head = root;        
    else {
        prev->right = root;
        root->left = prev;
    }
    prev = root;

    bstToDLL(root->right, head);
}


Node* mergeDLL(Node* head1, Node* head2) {
    Node* head = NULL;
    Node* last = NULL;

    while (head1 && head2) {
        Node* nextNode;

        if (head1->data < head2->data) {
            nextNode = head1;
            head1 = head1->right;
        } else {
            nextNode = head2;
            head2 = head2->right;
        }

        if (!head) { 
            head = nextNode;
            last = nextNode;
        } else {
            last->right = nextNode;
            nextNode->left = last;
            last = nextNode;
        }
    }


    Node* rem = (head1) ? head1 : head2;
    while (rem) {
        last->right = rem;
        rem->left = last;
        last = rem;
        rem = rem->right;
    }

    return head;
}


void print(Node* head) {
    Node* curr = head;
    cout << "Sorted Doubly Linked List: ";
    while (curr) {
        cout << curr->data << " ";
        curr = curr->right;
    }
    cout << endl;
}


int main() {
    Node* root1 = NULL;
    Node* root2 = NULL;

 
   root1=buildTree(root1);
    
   root2=buildTree(root2);

   
    Node* head1 = NULL;
    Node* head2 = NULL;
    bstToDLL(root1, head1);


    bstToDLL(nullptr, head2);
    bstToDLL(root2, head2);

 
    Node* mergedHead = mergeDLL(head1, head2);

   
    print(mergedHead);

    return 0;
}
