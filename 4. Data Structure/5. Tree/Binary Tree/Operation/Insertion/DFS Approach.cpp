#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};


Node* CreateNode(int data)
{
	Node* newNode = new Node();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}


Node* InsertNode(Node* root,int x)
{
    if(x==-1){
        return NULL;
    }
    if(root==NULL){
        root=CreateNode(x);
    }
    cout<<"Enter -1 for no Left node"<<endl;
    cin>>x;
    root->left = InsertNode(root->left,x);
    
    cout<<"Enter -1 for no Right Child"<<endl;
    cin>>x;
    root->right=InsertNode(root->right,x);
    return root;
}

/* Inorder traversal of a binary tree */
void inorder(Node* temp)
{
	if (temp == NULL)
		return;

	inorder(temp->left);
	cout << temp->data << ' ';
	inorder(temp->right);
}

int main()
{
	Node* root = NULL;
	int x;
	cout<<"Enter the root"<<endl;
	cin>>x;
	root=InsertNode(root,x);
	cout << "Inorder traversal before insertion: ";
	inorder(root);
	cout << endl;

}
