<h1 align="center">Morris Traversal</h1>

Using Morris Traversal, we can traverse the tree without using stack and recursion. The idea of Morris Traversal is based on Threaded Binary Tree.

![1](1.png)

## PreOrder

```c++
1. Initialize current as root
2. While current is not NULL
	if(current->left==NULL)
		Print(current->data);
		current=current->right;
	else
        predecessor=current->left; //Inorder Predecessor
        while (predecessor->right && predecessor->right != current)
                 predecessor = predecessor->right;
		//Print & make Current as right child of inorder predecessor
        if(predecessor->right==NULL){
            Print(current->data);
                predecessor->right=current;
                current=current->left
            }else{
                predecessor->right=NULL;
                current=current->right;
            }			
```

## InOrder

```c++
1. Initialize current as root
2. While current is not null
	if(current->left==NULL)
		Print(current->data);
		current=current->right;
	else
    	predecessor=current->left; //Inorder Predecessor
        while (predecessor->right && predecessor->right != current)
                 predecessor = predecessor->right;
    	if(predecessor->right==NULL){
    		predecessor->right=current;
    		current=current->left
    	}else{
    		predecessor->right=NULL;
    		Print(current->data);
    		current=current->right;
    	}			
```



<hr>

## PostOrder

```c++
1. Initialize current as root
2. Initialize a vector
2. While current is not NULL
	if(current->right==NULL)
		vector.push(current->data);
		current=current->left;
	else
        successor=current->right; //Inorder sucessor
        while (succcessor->left && successor->left != current)
                 successor = successor->left;
		//Print & make Current as left child of inorder successor
        if(successor->left==NULL){
            vector.push(current->data);
                successor->left=current;
                current=current->right
            }else{
                successor->left=NULL;
                current=current->left;
            }			
```

