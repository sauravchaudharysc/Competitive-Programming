//Building Binary Tree From Preorder And Inorder
/*
If both Preorder and Inorder or Postorder or Inorder are given then you can generate an unique binary tree
But if any one of the Postorder or Preorder is given then multiple binary tree is generated
 
The zeroth element of the pre-order gives the root node.You need to search the zeroth index element of
Preorder in Inorder.Then the left part of Inorder gives the left sub-tree and right part of the Inorder 
gives the right sub-tree.

1. Pick one element from pre-order
2. Create a node
3. Search for the index of the node.
4. Make recursive call for the left subtree and right subtree.
    f(s,i-1) --> Left 
    f(i+1,e) --> Right
*/


#include <iostream>
#include<queue>
using namespace std;

class node{
    public:
        int data;
        node*left;
        node*right;

        node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};

void inorder(node* root){
    if(root){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

node* createTreeFromInaAndPre(int *in,int *pre,int s,int e,int &i){
    if(s>e){
        return NULL;
    }
    //Rec case
    node *root=new node(pre[i]);
    //We arent known to index of the ith element in inorder.
    int idx=-1;
    for(int j=s;j<=e;j++){
        if(in[j]==pre[i]){ 
            //element found
            idx=j;   
            break;
        }
    }    
    i++;
    root->left  = createTreeFromInaAndPre(in,pre,s,idx-1,i);
    root->right = createTreeFromInaAndPre(in,pre,idx+1,e,i);
    return root;
}

int main(){ 
    int in[]= {3,2,8,4,1,6,7,5};
    int pre[]={1,2,3,4,8,5,6,7};
    int n=8;
    int i=0;
    node *root =createTreeFromInaAndPre(in,pre,0,n-1,i);
    inorder(root);
}