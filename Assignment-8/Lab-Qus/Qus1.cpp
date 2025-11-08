#include<iostream>
#include<queue>

using namespace std;

class Node{

    public:

    int data;
    Node* left;
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

    root=new Node(d);

    if(d==-1)
    {
        return NULL;
    }

    cout<<"Enter value of left of  "<< d <<endl;
    root->left=buildTree(root->left);

    cout<<"Enter data of right of "<< d <<endl;
    root->right=buildTree(root->right);

    return root;
}



void inorder(Node*root)
{
    if(root==NULL)
    {
        return;
    }

    
        inorder(root->left);
        cout<<root->data<<",";
        inorder(root->right);

    


}

void preorder(Node*root)
{
    if(root==NULL)
    {
        return;
    }

    cout<<root->data<<",";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<",";
}

int main ()
{

    Node*root=NULL;

    root=buildTree(root);

    
    cout<<"Inorder traversal is"<<endl;
    inorder(root);
    cout<<endl;

    cout<<"Preorder traversal is"<<endl;
    preorder(root);
    cout<<endl;

    cout<<"Postorder traversal is"<<endl;
    postorder(root);
}
