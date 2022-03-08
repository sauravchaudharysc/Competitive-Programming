## Search Operation

The search operation in Splay tree does the standard BST search, in addition to search, it also splays (move a node to the root). If the search is successful, then the node that is found is splayed and becomes the new root. Else the last node accessed prior to reaching the NULL is splayed and becomes the new root.

#### Case 1 : If Node is Root

We simply return the root.

#### Case 2 : Node is child of root 

The node has no grandparent. Node is either left child then we do Zig and if node is right child then we do a zag. 

```
 				y                                     x
               / \     Zig (Right Rotation)          /  \
              x   T3   – - – - – - – - - ->         T1   y 
             / \       < - - - - - - - - -              / \
            T1  T2     Zag (Left Rotation)            T2   T3
```

#### Case 4 : Node has both parent and grandparent

**a) Zig-Zig and Zag-Zag**

```
Zig-Zig (Left Left Case):
       G                        P                           X       
      / \                     /   \                        / \      
     P  T4   rightRotate(G)  X     G     rightRotate(P)  T1   P     
    / \      ============>  / \   / \    ============>       / \    
   X  T3                   T1 T2 T3 T4                      T2  G
  / \                                                          / \ 
 T1 T2                                                        T3  T4 

Zag-Zag (Right Right Case):
  G                          P                           X       
 /  \                      /   \                        / \      
T1   P     leftRotate(G)  G     X     leftRotate(P)    P   T4
    / \    ============> / \   / \    ============>   / \   
   T2   X               T1 T2 T3 T4                  G   T3
       / \                                          / \ 
      T3 T4                                        T1  T2
```

**b) Zig-Zag and Zag-Zig** 

```
Zag-Zig (Left Right Case):
       G                        G                            X       
      / \                     /   \                        /   \      
     P   T4  leftRotate(P)   X     T4    rightRotate(G)   P     G     
   /  \      ============>  / \          ============>   / \   /  \    
  T1   X                   P  T3                       T1  T2 T3  T4 
      / \                 / \                                       
    T2  T3              T1   T2                                     

Zig-Zag (Right Left Case):
  G                          G                           X       
 /  \                      /  \                        /   \      
T1   P    rightRotate(P)  T1   X     leftRotate(G)    G     P
    / \   =============>      / \    ============>   / \   / \   
   X  T4                    T2   P                 T1  T2 T3  T4
  / \                           / \                
 T2  T3                        T3  T4  
```



## Insertion

Following are different cases to insert a key k in splay tree.
1) Root is NULL: We simply allocate a new node and return it as root.
2) Splay the given key k. If k is already present, then it becomes the new root. If not present, then last accessed leaf node becomes the new root.
3) If new root’s key is same as k, don’t do anything as k is already present.
4) Else allocate memory for new node and insert as we do in bst then splay & return new node as new root of tree.

## Delete

Following are the different cases to delete a key **k** from splay tree.

1. If **Root is NULL:** We simply return the root.
2. Else Splay the given key k. If k is present, then it becomes the new root. If not present, then last accessed leaf node becomes the new root.
3. If new root’s key is not same as **k**, then return the root as **k** is not present.
4. Else the key k is present.
   - Split the tree into two trees **Tree1** = root’s left subtree and **Tree2** = root’s right subtree and delete the root node.
   - Let the root’s of **Tree1** and **Tree2** be **Root1** and **Root2** respectively.
   - If **Root1** is NULL: Return **Root2**.
   - Else, Splay the inorder sucessor **Tree2**.
   - After the Splay procedure, make **Root1** as the left child of **Root2** and return **Root2**.