#include<iostream>
#include<queue>
#include<vector>

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

vector<int> levelOrderTraversal(Node*root)
{

    vector<int>ans;

    queue<Node*>q;
    q.push(root);
  
    while(!q.empty())
    {
        int size=q.size();
 for(int i = 0; i < size; i++) {
            Node* temp = q.front();
            q.pop();

            if(i==size-1){
                ans.push_back(temp->data);
            }
        
         
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
    return ans;
}






int main()
{
    Node*root=NULL;

    root=buildTree(root);

    vector<int>ans=levelOrderTraversal(root);

    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }


}
