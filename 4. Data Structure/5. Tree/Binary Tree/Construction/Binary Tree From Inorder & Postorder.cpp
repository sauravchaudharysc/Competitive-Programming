//Building Binary Tree From Postorder And Inorder
/*
If both Preorder and Inorder or Postorder and Inorder are given then you can generate an unique binary tree
But if Postorder amd Preorder is given then multiple binary tree is generated
 
The nth-1 element of the post-order gives the root node. You need to search the nth-1 element of post-order 
in Inorder. Then the left part of Inorder gives the left sub-tree and right part of the Inorder gives the 
right sub-tree.

1. Pick nth-1 element from post-order
2. Create a node
3. Search for the index i ,of the node.
4. Make recursive call for the right subtree and left subtree.
   f(i+1,e) --> Right
   f(s,i-1) --> Left 
*/


#include <iostream>
#include<queue>
using namespace std;

class Treenode{
    public:
        int data;
        Treenode*left;
        Treenode*right;

        Treenode(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};

void inorder(Treenode* root){
    if(root){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

Treenode* createTreeFromInaAndPost(int *in,int *post,int s,int e,int &i){
    if(s>e){
        return NULL;
    }
    //Rec case
    Treenode *root=new Treenode(post[i]);
    //We arent known to index of the ith element in inorder.
    int idx=-1;
    for(int j=s;j<=e;j++){
        if(in[j]==post[i]){ 
            //element found
            idx=j;   
            break;
        }
    }    
    i--;
    root->right = createTreeFromInaAndPost(in,post,idx+1,e,i);
    root->left  = createTreeFromInaAndPost(in,post,s,idx-1,i);
    return root;
}

int main(){ 
    int in[]= {9,3,15,20,7};
    int post[]={9,15,7,20,3};
    int n=5;
    int i=n-1;
    Treenode *root =createTreeFromInaAndPost(in,post,0,n-1,i);
    inorder(root);
}