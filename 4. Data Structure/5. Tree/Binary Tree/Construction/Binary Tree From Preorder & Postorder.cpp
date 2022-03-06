/* Using Pre-Order & Post-Order we get multiple binary tree. 
But for Full Binary Tree we can get unique binary tree.

1. Traverse the pre-order and starting node is the root node.
2. The successor of the root node in pre-order is the Left Child. 
3. Find that successor node index i, in the post-order.
4. Then (low,i) in the post order contains the element of left subtree
& (i+1,high-1) in the post order contains the element of right subtree.*/
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

Treenode* createTreeFromPreAndPost(int *pre,int *post,int &preIndex,int low,int high,int n){
    //Base Case
    if(low>high || preIndex>=n){
        return NULL;
    }
    
    //Rec case
    Treenode *root=new Treenode(pre[preIndex++]);
    //++ is done to point successor of root node

    if(low==high){
        return root;
    }
    
    //Find the root successor in the post order 
    int idx=-1;
    for(int j=low;j<=high;j++){
        if(post[j]==pre[preIndex]){ 
            //element found
            idx=j;   
            break;
        }
    }    
    
    if(idx!=-1){
        root->left  = createTreeFromPreAndPost(pre,post,preIndex,low,idx,n);
        root->right = createTreeFromPreAndPost(pre,post,preIndex,idx+1,high-1,n);        
    }
    return root;
}

int main(){ 
    int pre[] = {1, 2, 3,5,4};
    int post[] = {3,5,2, 4, 1}; 
    int n=5;
    int low=0;
    int high=n-1;
    int preIndex=0;
    Treenode *root = createTreeFromPreAndPost(pre,post,preIndex,low,high,n);
    inorder(root);
}