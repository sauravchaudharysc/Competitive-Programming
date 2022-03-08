# Differences




| S.NO | B tree                                                       | B+ tree                                                      |
| :--- | :----------------------------------------------------------- | :----------------------------------------------------------- |
| 1.   | All internal and leaf nodes have data pointers               | Only leaf nodes have data pointers                           |
| 2.   | Since all keys are not available at leaf, search often takes more time. | All keys are at leaf nodes, hence search is faster and accurate.. |
| 3.   | No duplicate of keys is maintained in the tree.              | Duplicate of keys are maintained and all nodes are present at leaf. |
| 4.   | Insertion takes more time and it is not predictable sometimes. | Insertion is easier and the results are always the same.     |
| 5.   | Deletion of internal node is very complex and tree has to undergo lot of transformations. | Deletion of any node is easy because all node are found at leaf. |
| 6.   | Leaf nodes are not stored as structural linked list.         | Leaf nodes are stored as structural linked list.             |
| 7.   | No redundant search keys are present..                       | Redundant search keys may be present. **Reduntant because duplication is done** |

