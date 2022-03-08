# Splay trees

Splay Tree is *a self - adjusted Binary Search Tree in which every operation on element rearranges the tree so that the element is placed at the root position of the tree*. In a splay tree, every operation is performed at the root of the tree.

The main idea of splay tree is to bring the recently accessed item to root of the tree, this makes the recently searched item to be accessible in O(1) time if accessed again

### Advantage 

- No Extra information is stored.
- Fastest type of BST for many practical application. 
- Better performance because frequently accessed node will move nearer to root. So these are used in implementation of cache memory

### Disadvantage

- These aren’t strictly balanced tree. So the tree can be skewed and an operation can take linear time, O(n).



