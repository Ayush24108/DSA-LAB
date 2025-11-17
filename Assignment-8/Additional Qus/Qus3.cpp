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



int maxDepth(Node* root) {
    if (root == NULL)
        return 0;

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    return 1 + max(leftDepth, rightDepth);
}



int main ()
{
    Node *root=NULL;

    root=buildTree(root);

    cout<<" max depth of tree is "<<maxDepth(root)<<endl;
  


 
 

 






 

 




}
