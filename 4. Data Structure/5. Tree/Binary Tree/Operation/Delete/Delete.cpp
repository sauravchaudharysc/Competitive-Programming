#include <bits/stdc++.h>
using namespace std;

struct Node {
	int key;
	struct Node *left, *right;
};

struct Node* newNode(int key)
{
	struct Node* temp = new Node;
	temp->key = key;
	temp->left = temp->right = NULL;
	return temp;
};

void inorder(struct Node* temp)
{
	if (!temp)
		return;
	inorder(temp->left);
	cout << temp->key << " ";
	inorder(temp->right);
}


/* function to delete element in binary tree */
Node* deletion(struct Node* root, int key)
{
	if (root == NULL)
		return NULL;

	if (root->left == NULL && root->right == NULL) {
		if (root->key == key)
			return NULL;
		else
			return root;
	}

	queue<struct Node*> q;
	q.push(root);

	struct Node* temp;
	struct Node* prev;
	struct Node* key_node = NULL;

	while (!q.empty()) {
		temp = q.front();
		q.pop();

		if (temp->key == key)
			key_node = temp;

		if (temp->left){
		    prev=temp;
		    q.push(temp->left);
		}
			

		if (temp->right){
		    prev=temp;
		    q.push(temp->right);
		}
			
	}

	if (key_node != NULL) {
		int x = temp->key;
		key_node->key = x;
			if(prev->right==temp)
                prev->right=NULL;
            else 
                prev->left=NULL;
            delete(temp);    
	}
	return root;
}


int main()
{
	struct Node* root = newNode(10);
	root->left = newNode(11);
	root->left->left = newNode(7);
	root->left->right = newNode(12);
	root->right = newNode(9);
	root->right->left = newNode(15);
	root->right->right = newNode(8);

	cout << "Inorder traversal before deletion : ";
	inorder(root);

	int key = 11;
	root = deletion(root, key);

	cout << endl;
	cout << "Inorder traversal after deletion : ";
	inorder(root);

	return 0;
}
