#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node*left;
        Node*right;

        Node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};

Node* insert(Node*,int);
Node* search(Node*,int);

Node* inorderSucessor(Node* root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}

Node* deleteNode(Node* root,int key){
    if(root==NULL){
        return NULL;
    }
    
    if(root->data>key){
        root->left=deleteNode(root->left,key);
    }else if(root->data<key){
        root->right=deleteNode(root->right,key);
    }else{
        //Only One Child or No Child
        if(root->left==NULL){
            Node* temp = root->right;
            free(root);
            return temp;
        }else if(root->right==NULL){
            Node* temp = root->left;
            free(root);
            return temp;
        }
        //Node with Two Child 
        
        //Find inorder sucessor
        Node* temp = inorderSucessor(root->right);
        root->data=temp->data;
        root->right=deleteNode(root->right,temp->data);
    }
    return root;
}

void inorder(Node* root){
    if(root){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

int main(){
    Node *root = new Node(5);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(8);
    Node *ans=search(root,4);
    if(ans){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }    
    root=insert(root,4);
    ans=search(root,4);
    if(ans){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    inorder(root);
    cout<<endl;
    root=deleteNode(root,4);
    inorder(root);
    cout<<endl;
    root=insert(root,18);
    root=insert(root,14);
    inorder(root);
}

Node* insert(Node* root,int key){
	if(root==NULL){
		return new Node(key);
	}
	if(key<root->data){
		root->left=insert(root->left,key);
	}else{
		root->right=insert(root->right,key);
	}
	return root;
}

Node* search(Node* root,int key){
	if(root==NULL || root->data==key){
		return root;
	}
	if(key<root->data){
		return search (root->left,key);
	}
	return search(root->right,key);
}

