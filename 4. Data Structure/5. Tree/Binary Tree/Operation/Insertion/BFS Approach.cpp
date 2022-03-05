#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* CreateNode(int x){
    Node* newNode = new Node();
    newNode->data=x;
    newNode->left=newNode->right=NULL;
    return newNode;
}

Node* InsertNode(Node* root,int x){
    if(root==NULL){
        root=CreateNode(x);
        return root;
    }
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp->left==NULL){
          temp->left=CreateNode(x);
          return root;
        }else{
            q.push(temp->left);
        }
        if(temp->right==NULL){
          temp->right=CreateNode(x);
          return root;            
        }else{
            q.push(temp->right);            
        }        
    }
    return root;
}

void inorder(Node* temp){
    if (temp == NULL)
        return;
 
    inorder(temp->left);
    cout << temp->data << ' ';
    inorder(temp->right);
}

int main(){
    Node* root = CreateNode(10);
    int key = 12;
    root = InsertNode(root, key);
    key = 14;
    root = InsertNode(root, key);
    inorder(root);    
}    