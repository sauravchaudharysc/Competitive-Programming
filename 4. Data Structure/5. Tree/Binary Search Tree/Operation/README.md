# Operation

### Insertion

We start searching for position of the new key following the BST properties. Wherever we find the root to be null. We insert the new key at that position.

```c++
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
```

### Searching

```c++
Node* search(Node* root,int key){
	if(root==NULL || root->data==key){
		return root;
	}
	if(key<root->data){
		return search (root->left,key);
	}
	return search(root->right,key);
}
```

**Time Complexity:** The worst-case time complexity of search and insert operations is O(h) where h is the height of the Binary Search Tree. In the worst case the height of a skewed tree may become n and the time complexity of search and insert operation may become O(n). 

### Deletion

