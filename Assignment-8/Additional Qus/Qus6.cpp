#include<iostream>
#include<queue>

using namespace std;


class Node{

    public:
    int data;
    Node*right;
    Node*left;

    Node(int d)
    {
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

int postindex=8;


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

int Search(int in[9],int s,int e,int value)
{
    for(int i=s;i<=e;i++)
    {
        if(in[i]==value)
        {
            return i;
        }
    }
    return -1;
}

Node* BuildTree(Node*root,int in[9],int post[9],int s,int e)
{
    if(s>e)
    {
        return NULL;
    }

    int rootvalue=post[postindex--];
    root=new Node(rootvalue);

    int pivot=Search(in,s,e,rootvalue); 
    root->right=BuildTree(root,in,post,pivot+1,e);
    root->left=BuildTree(root,in,post,s,pivot-1);
   

    return root;


}



int main ()
{
    Node*root=NULL;


    int post[9]={1,3,5,4,2,8,9,7,6};
    int in[9]={1,2,3,4,5,6,7,8,9};

    root=BuildTree(root,in,post,0,8);

    levelOrderTraversal(root);


}
