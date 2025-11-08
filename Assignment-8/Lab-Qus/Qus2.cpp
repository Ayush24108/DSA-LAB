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


void SearchRec(Node* root, int key) {
    if (root == NULL)
     {
       cout << "Element not found" << endl;
        return;
    }

    if (key == root->data) {
        cout << "Element found" << endl;
        return;
    }
    else if (key < root->data)
        SearchRec(root->left, key);
    else
        SearchRec(root->right, key);
}


Node* Minimum(Node*root){

    Node*min=root;

    while(min && min->left!=NULL)
    {
        min=min->left;
    }

    return min;

}

Node* Maximum(Node*root)
{

    Node *max=root;
    while(max && max->right!=NULL)
    {
        max=max->right;
    }
    return max;
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

Node* Predecessor(Node* root, Node* x) {
    if (x->left != NULL)
        return Maximum(x->left);

    Node* predecessor = NULL;
    while (root != NULL) {
        if (x->data > root->data) {
            predecessor = root;
            root = root->right;
        } else if (x->data < root->data)
            root = root->left;
        else
            break;
    }
    return predecessor;
}


int main ()
{

    Node*root=NULL;

    root=buildTree(root);

    levelOrderTraversal(root);

    int key;
    cout<<"Enter the number to be searched"<<endl;
    cin>>key;

    Search(root,key);

    SearchRec(root,key);

    Node* min=Minimum(root);
    cout<<"Min of tree is "<<min->data<<endl;

    Node* max=Maximum(root);
    cout<<"Max of tree is "<<max->data<<endl;

    cout<<"Enter the node of which you want to find inorder successor"<<endl;
    int n;
    cin>>n;

    Node *d=Search(root,n);
   
    

    Node*suc=Successor(root,d);

    cout<<"Inorder successor of "<<n<<" is "<<suc->data<<endl;


    cout<<"Enter the node of which you want to find inorder predecessor"<<endl;
    int x;
    cin>>x;

    Node*y=Search(root,x);


    Node*pre=Predecessor(root,y);

    cout<<"inorder Predecessor of "<<x<<" is "<<pre->data<<endl;








}
