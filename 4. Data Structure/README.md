# Data Structure

A data structure is a particular way of organizing data in computer so that it can be used effectively. 

## Linear Data Structure

### 1. Array 
Array is a data structure used to store homogeneous elements at contiguous location. The size of an array must be defined before storing data.

### 2. Linked List

A linear data structure (like arrays) where each element is a separate object. Each element (that is a node) of a list is comprised of two items - the data & a reference to the next node.

### 3. Stack

A **LIFO(Last In, First Out)** data structure. It supports two operation- push & pop. Both of them take place at the top of stack. It can be implemented by using both array & linked list. Used in :- Recursion(Call Stack), Reverse a word, Undo Operations

### 4. Queue

A **FIFO(First In, First Out)** data structure. It supports two operation- enqueue & dequeue. Enqueue is the process of adding element to the rear side & dequeue is the process of removing element from the front side. It can be implemented by using both array & linked list. Used in :- CPU Scheduling , Process Scheduling. 

### 5. Tree 

**A tree is a nonlinear data structure.**

#### 	a ) Binary Tree

​			A binary tree is a tree data structure in which each node has at most two children, which are referred as left child and right child. Used in :- File Structure , JavaScript DOM (hierarchical object).

#### 	b) Binary Search Tree

​			A binary search tree is a binary tree with the following additional properties : 

- Left Subtree of a node contains only nodes with keys less than the node’s key.
- Right Subtree of a node contains only nodes with keys greater than the node’s key.
- All the  subtree must also be a binary search tree.

#### 	c) Binary Heap

​		A binary heap is a binary tree with the following additional properties :

- It’s a complete binary tree. (All levels are completely filled or the last level has all keys from left).
- A binary heap is either max heap or min heap.

#### d) AVL Tree

​		AVL tree is a self-balancing Binary Search Tree (BST) where the difference between heights of left and right subtrees cannot be more than one for all nodes.

#### e) Red Black Tree

​		A red-black tree is a kind of self-balancing binary search tree where each node has an extra bit, and that bit is often interpreted as the color (red or black). These colors are used to ensure that the tree remains balanced during insertions and deletions. Although the balance of the tree is not perfect, but it is good enough to reduce the searching time and maintain it around O(log n) time, where n is the total number of elements in the tree.

#### f) Splay Tree

​		Splay Tree is *a self - adjusted Binary Search Tree in which every operation on element rearranges the tree so that the element is placed at the root position of the tree*. In a splay tree, every operation is performed at the root of the tree.

#### g) B & B+ Tree 

​		B-tree is a m-way search tree with some rules inorder to keep the height of B-Trees as low by putting maximum possible keys in a B-Tree node.

​		In B tree we have a record pointer from every node but in B+ tree we have record pointer from leaf node only.

### 6. Hashing 

Hashing is a technique or process of mapping keys, values into the hash table by using a hash function. It is done for faster access to elements. The efficiency of mapping depends on the efficiency of the hash function used.

**Hash Function :** A hash function is a function that takes a set of inputs of any arbitrary size and fits them into a table or other data structure that contains fixed-size elements. 

**Hash Table :** An array that stores pointer that maps key to value. 

There may be a case when hash function gives us a same value for different keys. In that case collision occurs and we need to handle it. 

Following are the ways to handle collision :- 

- Chaining

  The idea is to make each cell of the hash table point to a linked list and we make a chain of records for same hash function value.

- Open Addressing

  - Linear Probing :- Searching Linearly for empty space
  - Quadratic Probing 
  - Double Hashing

