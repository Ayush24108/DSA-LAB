#include <iostream>
#include<queue>

using namespace std;

class Node{

    public:
    int data;
    Node*left;
    Node*right;

 Node(int data)
 {
    this->data=data;
    this->left=NULL;
    this->right=NULL;

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


bool isBSTUtil(Node* root, long long minVal, long long maxVal) {
    if (root == nullptr)
        return true;


    if (root->data <= minVal || root->data >= maxVal)
        return false;

  
    return isBSTUtil(root->left, minVal, root->data) &&
           isBSTUtil(root->right, root->data, maxVal);
}


bool isBST(Node* root) {
    return isBSTUtil(root, -100, 100);
}




int main ()
{
    Node*root=NULL;
    root=buildTree(root);




}
