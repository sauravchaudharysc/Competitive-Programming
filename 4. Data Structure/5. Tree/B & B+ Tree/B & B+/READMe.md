# B- Tree

B-tree is a m-way search tree with some rules inorder to keep the height of B-Trees as low by putting maximum possible keys in a B-Tree node. Generally, the B-Tree node size is kept equal to the disk block size. Since the height of the B-tree is low so total disk accesses for most of the operations are reduced significantly compared to balanced Binary Search Trees like AVL Tree, Red-Black Tree, ..etc.

## Properties

1. All leaves are at same level.
2. Root can have minimum 1 children
3. Each node except root must have of m/2 keys
4. B-tree of degree m has maximum m-1 keys & m children
5. Number of children of a node is equal to the number of keys in it plus 1.
6. All leaf nodes must be at same level
7. The creation process is bottom up. 

# B+ Tree 

In B tree we have a record pointer from every node but in B+ tree we have record pointer from leaf node only. 

So here all the keys are present in the leaf node and copy of the keys are present in internal node. Properties of B tree must be satisfied.

The drawback of B-tree used for indexing, however is that it stores the data pointer (a pointer to the disk file block containing the key value), corresponding to a particular key value, along with that key value in the node of a B-tree. This technique, greatly reduces the number of entries that can be packed into a node of a B-tree, thereby contributing to the increase in the number of levels in the B-tree, hence increasing the search time of a record.

B+ tree eliminates the above drawback by storing data pointers only at the leaf nodes of the tree.

**Advantage –**
A B+ tree with ‘l’ levels can store more entries in its internal nodes compared to a B-tree having the same ‘l’ levels. This accentuates the significant improvement made to the search time for any given key. Having lesser levels and presence of Pnext pointers(At last level lead nodes a linked list is running) imply that B+ tree are very quick and efficient in accessing records from disks.

