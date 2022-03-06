#include<bits/stdc++.h>
using namespace std;

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
}