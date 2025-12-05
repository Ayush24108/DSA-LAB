#include <iostream>
#include <unordered_set>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

bool hasDuplicate(Node* root) {
    if(root == NULL) return false;

    unordered_set<int> s;
    stack<Node*> st;
    st.push(root);

    while(!st.empty()) {
        Node* temp = st.top();
        st.pop();

        if(s.count(temp->data))
            return true;

        s.insert(temp->data);

        if(temp->left) st.push(temp->left);
        if(temp->right) st.push(temp->right);
    }
    return false;
}

int main() {
    Node* root = new Node{1, NULL, NULL};
    root->left = new Node{2, NULL, NULL};
    root->right = new Node{3, NULL, NULL};
    root->left->left = new Node{2, NULL, NULL}; 

    if(hasDuplicate(root))
        cout << "Duplicate Found";
    else
        cout << "No Duplicate";

    return 0;
}
