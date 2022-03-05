# Traversal 

A Tree is traversed in two ways :

### 1. BFS or Level Order Traversal

### 2. DFS

- #### Preorder (Root-Left-Right)

- #### Inorder (Left-Root-Right)

- #### Postorder (Left-Right-Root)

**There are many tree question that can be solved using any of the above four traversals. Examples :- Size, Maximum , Minimum , Print Left View.**

 All four traversals require O(n) time as they visit every node exactly once.

### **How to Pick One?**

1. Extra Space can be one factor (Explained above)
2. Depth First Traversals are typically recursive and recursive code requires function call overheads.
3. The most important points is, BFS starts visiting nodes from root while DFS starts visiting nodes from leaves. So if our problem is to search something that is more likely to closer to root, we would prefer BFS. And if the target node is close to a leaf, we would prefer DFS.

