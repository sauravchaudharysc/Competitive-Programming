# Operation

### Insertion

**Follow Properties of Red Black Tree**

- If tree is empty, create newnode as root node with color black.
- If tree isn’t empty, create newnode as leaf node with color red.
- If parent of newnode is black then exit.
- If parent of newnode is red,then check the color of parents sibling of newnode.
  - If color is black or null then do suitable rotation & recolor.
  - if color is red then recolor (*both parent & it sibling*) & also check if parent ka parent of new node is not a root node then recolor it and recheck.

[Check Here](https://www.youtube.com/watch?v=qA02XWRTBdw&list=PLdo5W4Nhv31bbKJzrsKfMpo_grxuLl8LU&index=65)

### Deletion

#### Follow Properties of Red Black Tree

##### Step 1 

​		Perform BST Deletion(*During inorder sucessor replacement only value is replaced not color.*)

##### Step 2 :- The Element to be deleted reach leaf node.

​	Case 1 : If node to be deleted is red, just delete it.

​	Case 2 : If root is double black, just remove double black.

​	Case 3 : If node to be deleted is black(called as double black) & its sibling is black and both children of sibling are black.

      -	Remove the node
      -	Add Black to its Parent
        -	If parent is red then it becomes black. 
        -	If parent is black it becomes double black 
      -	Sibling becomes red
      -	If still double black exist then reapply cases.

​	 Case 4 : If node to be deleted is black(called as double black) & its sibling is red.

      - Swap Color of Parent & Sibling of node to be deleted.
      - Rotate parent in double black direction.
      - Reapply cases.

​	Case 5 : If node to be deleted is black(called as double black) & its sibling is black and sibling child which is far from db is black, but near child to db is red.	

      - Swap Color of DB sibling & it red child. DB sibling becomes red and its child become black.
      - Rotate the DB sibling in opposite direction of sibling.
      - Apply Case 6

​	Case 6 : If node to be deleted is black(called as double black) & its sibling is black and sibling child which is far from db is red, but near child to db is black.

      - Swap Color of DB sibling & it parent.
      - Rotate the parent in DB direction. 
      - Remove Double Black.
      - Change color of red child to black.

[Click Here](https://www.youtube.com/watch?v=w5cvkTXY0vQ&list=PLdo5W4Nhv31bbKJzrsKfMpo_grxuLl8LU&index=66)

