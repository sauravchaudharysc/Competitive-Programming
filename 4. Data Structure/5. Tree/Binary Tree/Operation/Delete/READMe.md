# Deletion in a Binary Tree

Given a binary tree, to delete a node we replace it with rightmost bottom node and delete the rightmost bottom node.

### Algorithm 

1. Starting from root, find the rightmost bottom node in binary tree and the node which we want to delete. Also store the parent of rightmost bottom node.
2. Replace the rightmost bottom node with the node to be deleted.
3. Then update the path from parent to rightmost node to NULL. Delete the rightmost bottom node.



