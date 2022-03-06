#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left, *right;
 
    TreeNode(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

void preorder(TreeNode* root){
    stack<TreeNode*>st;
    st.push(root);
    while(!st.empty()){
        TreeNode* top = st.top();
        st.pop();
        while(top!=NULL){
            cout<<top->data<<" ";
            if(top->right){
                st.push(top->right);
            }
            top=top->left;
        }
    }
}

void inorder(TreeNode* root){
    stack<TreeNode*>st;
    if(root==NULL)return ;
    st.push(root);
    while(!st.empty()){
        while(root && root->left!=NULL){
                st.push(root->left);
            root=root->left;
        }
        root=st.top();
        cout<<root->data<<" ";
        st.pop();
        if(root->right!=NULL){
            st.push(root->right);
        }
        root=root->right;
    }
}

//Two Stack Approach 
void postorder(TreeNode*root){
    stack<TreeNode*>st;
    stack<int>ans;
    st.push(root);
    while(!st.empty()){
        TreeNode* top = st.top();
        st.pop();
        while(top!=NULL){
            ans.push(top->data);
            if(top->left){
                st.push(top->left);
            }
            top=top->right;
        }
    }
    
    while(!ans.empty()){
        cout<<ans.top()<<" ";
        ans.pop();
    }
}

//Single Stack Approach 
void postorderI(TreeNode* root){
    if(root==NULL)return;
    stack<TreeNode*>st;
    
    do{
        while(root){
            //Push root right child and then root in stack
            if(root->right){
                st.push(root->right);
            }
            st.push(root);
            //Move Left
            root=root->left;
        }
        //Pop an item from stack
        root = st.top();
        st.pop();
        //If root has a right child and right of root on top of stack 
          //Pop top of stack 
          //Insert root 
          //Move to right 
        if(root->right && !st.empty() && st.top()==root->right){
            st.pop();
            st.push(root);
            root=root->right;
        }else{
            //After Print Make Root NULL, so it goes to another  
            cout<<root->data<<" ";
            root=NULL;
        }
    }while(!st.empty());
}


int main()
{
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(40);
    root->left->left->left = new TreeNode(70);
    root->left->right = new TreeNode(50);
    root->right->left = new TreeNode(60);
    root->left->left->right = new TreeNode(80);
 
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    postorderI(root);
    return 0;
}