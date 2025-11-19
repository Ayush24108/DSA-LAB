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

int preindex=0;

int Search(int in[], int s, int e, int value) {
    for (int i = s; i <= e; i++) {
        if (in[i] == value)
            return i;
    }
    return -1;
}

Node*BuildTree(Node*root,int in[9],int pre[9],int s,int e)
{

          
        if(s>e)
        {
            return NULL;
        }
        

        int rootvalue=pre[preindex++]; 
        root=new Node(rootvalue);

        int pivot=Search(in,s,e,rootvalue);

       

        root->left=BuildTree(root,in,pre,s,pivot-1);
        root->right=BuildTree(root,in,pre,pivot+1,e);

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

int main ()
{

    Node *root=NULL;

           int in[9]={1,2,3,4,5,6,7,8,9};
           int pre[9]={6,2,1,4,3,5,7,9,8};

          root= BuildTree(root,in,pre,0,8);

           levelOrderTraversal(root);


      


}
