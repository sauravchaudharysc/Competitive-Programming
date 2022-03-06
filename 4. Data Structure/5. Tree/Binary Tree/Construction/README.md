# Binary Tree Construction

## 1. Using Pre-Order & Inorder

The zeroth element of the pre-order gives the root node.  You need to search the zeroth index element of Preorder in Inorder. Then the left part of Inorder gives the left sub-tree and right part of the Inorder gives the right sub-tree.

1. Pick one element from pre-order
2. Create a node
3. Search for the index i ,of the node.
4. Make recursive call for the left subtree and right subtree.
    f(s,i-1) --> Left 
    f(i+1,e) --> Right

## 2. Using Post-Order & Pre-Order

The nth-1 element of the post-order gives the root node. You need to search the nth-1 element of post-order in Inorder. Then the left part of Inorder gives the left sub-tree and right part of the Inorder gives the right sub-tree.

1. Pick nth-1 element from post-order
2. Create a node
3. Search for the index i ,of the node.
4. Make recursive call for the right subtree and left subtree.
    f(i+1,e) --> Right
    f(s,i-1) --> Left 

## 3. Using Pre-Order & Post-Order

