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

bool Search(Node* root,int x){
    if(root==NULL){
        return 0;
    }
    if(root->data==x){
        //Update here if required
        return true;
    }
    bool res1 = Search(root->left,x);
    bool res2 = Search(root->right,x);
    return res1||res2;
}

Node* InsertNode(Node*,int);

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
    key = 16;
    root = InsertNode(root, key);
    key = 17;
    root = InsertNode(root, key);
    key = 18;
    root = InsertNode(root, key);
    key = 8;
    root = InsertNode(root, key);
    //inorder(root);   
    cout<<Search(root,8)<<endl;
    cout<<Search(root,80)<<endl;
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
