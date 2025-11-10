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


void levelOrderTraversal(Node*root)
{
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        Node*temp=q.front();
        
        q.pop();

        if(temp==NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else{
            
            cout<<temp->data<<" ";


            if(temp->left)
            {
                q.push(temp->left);
            }

            if(temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}


Node* Insert(Node*root,int x)
{
    

    if(root==NULL)
    {
        return new Node(x);
    }

    else if(x>root->data)
    {
        root->right=Insert(root->right,x);
    }

    else if(x<root->data)
    {
        root->left=Insert(root->left,x);
    }

    else{
        cout<<"Value is already there"<<endl;
    }
}

Node* Search(Node* root, int key) {
    
    
    Node* curr = root;


    while (curr != NULL) {

        if (key == curr->data) {

            cout << "Element found" << endl;
            return curr;

        } 
        else if (key < curr->data)
        {
            curr = curr->left;
        }
        else
            curr = curr->right;
    }
    cout << "Element not found" << endl;
    return NULL;
}

Node* Minimum(Node*root){

    Node*min=root;

    while(min && min->left!=NULL)
    {
        min=min->left;
    }

    return min;

}

Node* Successor(Node* root, Node* x) {
 
    if (x->right != NULL)
        return Minimum(x->right);


    Node* successor = NULL;
    while (root != NULL) {
        if (x->data < root->data) {
            successor = root;
            root = root->left;
        }
        else if (x->data > root->data)
            root = root->right;
        else
            break;
    }
    return successor;
}



Node *Delete(Node *root,int x){

     
    if(x<root->data)
    {
        root->left=Delete(root->left,x);

    }

    else if(x>root->data)
    {
        root->right=Delete(root->right,x);

    }

    else{

        Node*Nodetodelete=root;

        if(Nodetodelete->right==NULL && Nodetodelete->left==NULL)
        {
            delete Nodetodelete;
            return NULL;
        }

        if (Nodetodelete->left == NULL) {
            
            Node* temp = Nodetodelete->right;
            delete Nodetodelete;
            return temp;
        } else if (Nodetodelete->right == NULL) {
           
            Node* temp = Nodetodelete->left;
            delete Nodetodelete;
            return temp;
        }


        else{
            Node*suc=Minimum(Nodetodelete->right);

            Nodetodelete->data=suc->data;

           Nodetodelete->right=Delete(Nodetodelete->right,suc->data);

        

            

        }

        return root;

    }

    
   

}

int maxDepth(Node* root) {
    if (root == NULL)
        return 0;

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    return 1 + max(leftDepth, rightDepth);
}

int minDepth(Node* root) {
    if (root == NULL)
        return 0;

   
    if (root->left == NULL)
        return 1 + minDepth(root->right);
    if (root->right == NULL)
        return 1 + minDepth(root->left);

    return 1 + min(minDepth(root->left), minDepth(root->right));
}


int main ()
{
    Node *root=NULL;

    root=buildTree(root);

    cout<<"Current max depth of tree is "<<maxDepth(root)<<endl;
    cout<<"Current min depth of tree is "<<minDepth(root)<<endl;
    levelOrderTraversal(root);

 int n;
 cout<<"Enter the value you want to insert"<<endl;
 cin>>n;

 root=Insert(root,n);
 cout<<"Updated max depth of tree is "<<maxDepth(root)<<endl;
 cout<<"updated min depth of tree is "<<minDepth(root)<<endl;
 levelOrderTraversal(root);


 

 cout<<"Enter data to be deleted"<<endl;
 int x;
 cin>>x;
 root=Delete(root,x);
 cout<<"Updated max depth of tree is "<<maxDepth(root)<<endl;
 cout<<"Updated min depth of tree is "<<minDepth(root)<<endl;
 levelOrderTraversal(root);









 

 




}
