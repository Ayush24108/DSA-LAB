#include <iostream>
#include<vector>

using namespace std;


class Node{
 
    public:
    int data;
    Node*right;
    Node*left;

    Node(int d){

        this->data=d;
        this->right=NULL;
        this->left=NULL;
    }
};



vector<Node*>BuildBST(int s,int e)
{
    vector<Node*>ans;

   if(s>e)
   { 
    ans.push_back(NULL);
    return ans;
   }

   for(int i=s;i<=e;i++)
   {
            vector<Node*>left=BuildBST(s,i-1);
            vector<Node*>right=BuildBST(i+1,e);


     for (int l = 0; l < left.size(); l++) {
     for (int r = 0; r < right.size(); r++) {
        Node* root = new Node(i);
        root->left = left[l];
        root->right = right[r];
        ans.push_back(root);
           }
    }
   
   }
   return ans;

}


vector<Node*> BuildTree(int n){

    

        return BuildBST(1,n);
    
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



int main ()
{


    int n;
    cout<<"Enter no of nodes"<<endl;
    cin>>n;

    vector<Node*> result=BuildTree(n);



    cout<<"Total no of bst formed are "<<result.size()<<endl;

    for(int i=0;i<result.size();i++)
    { 
        cout<<"BST "<<i+1<<endl;


      preorder(result[i]);
      cout<<endl;

    }


}
