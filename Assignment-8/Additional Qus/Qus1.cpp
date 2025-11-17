#include<iostream>

using namespace std;


class Node{

    public:
    int data;
   Node*left;
   Node*right;

   Node(int d)
   {
    this->data=d;
    this->right=NULL;
    this->left=NULL;
   }


};


Node* buildTree(Node*root)
{

    int d;
    cout<<"Enter value to be inserted(-1 for no node)"<<endl;
    cin>>d;

    

if(d==-1)
{
   return NULL;
}

root=new Node(d);


cout<<"Enter value of left of "<<d<<endl;
  root->left=buildTree(root->left);

  cout<<"Enter value of right of "<<d<<endl;
  root->right=buildTree(root->right);


  return root;

}

bool isLeaf(Node* node)
{
    if(node!=NULL && node->left==NULL && node->right==NULL)
    {
        return true;
    }
    else{
        return false;
    }
}


int Sum(Node*root)
{
    int sum=0;

    if(root==NULL)
    {
        return 0;
    }

    if(isLeaf(root->left))
    {
        sum+=root->left->data;
    }

    else{
        sum+=Sum(root->left);
    }

    sum+=Sum(root->right);

    return sum;

    

}

int main ()
{
    Node*root=NULL;

    root=buildTree(root);

    cout<<"Sum of left leaf nodes is "<<Sum(root)<<endl;
}
