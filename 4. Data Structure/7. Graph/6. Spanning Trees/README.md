# Spanning Trees

A spanning tree of a graph consist of all the nodes and some of the edges of the graph so that there exist a path between any two nodes. Like tree , spanning trees are connected and acyclic.

**Consider the following graph**

![image-20210223103532891](image-20210223103532891.png)

One spanning tree for the graph is as follows :

![image-20210223103616314](image-20210223103616314.png)



The weight of a spanning tree is the sum of its edge weights. For example, the weight of the spanning tree is 3+5+9+3+2=22.

## Minimum Spanning Tree

A **minimum spanning tree** is a spanning tree whose weight is as small as possible. The weight of a minimum spanning tree for the example graph is 20 and such tree can be constructed as follows:

![image-20210223104116010](image-20210223104116010.png)

A **maximum spanning tree** is a spanning tree whose weight is as large as possible. The weight of a maximum spanning tree for the example graph is 32 and can be constructed as follows:

![image-20210223104244132](image-20210223104244132.png)

> If graph is a **complete graph** with n vertices then total no of spanning tree is  n^(n-2) .
>
> If graph isn’t **complete graph** then we can use Kirchoff’s theorem to calculate spanning trees.

------

These two algorithm are used to find minimum spanning trees :- 

[1. Kruskal’s Algorithm](Kruskal's%20Algorithm)

[2. Prims Algorithm](Prim's%20Algorithm)

# Important 

**Prims and Kruskal’s Algorithm doesn’t work for directed graph.**

### Why Prims Fail for directed graph ?

Prim’s algorithm assumes that all vertices are connected and we choose any arbitrary node and start constructing tree. But in a directed graph, every node is not reachable from every other node. So, Prim’s algorithm fails due to this reason.

<img src="https://media.geeksforgeeks.org/wp-content/cdn-uploads/20200320001817/Untitled-Diagramksh.png" alt="img" style="zoom: 19%;" />

### Why Kruskal’s Algorithm fails for directed graph ?

In Kruskal’s algorithm, In each step, it is checked that if the edges form a cycle with the spanning-tree formed so far. But Kruskal's Algorithm Union find method to detect cycle fails for directed graph. So, Kruskal’s don’t take consider some edges due to which Kruskal’s Algorithm fails for directed graph.

![img](https://media.geeksforgeeks.org/wp-content/cdn-uploads/20200320002247/Untitled-Diagramksjd.png)

### When should we use Prims or Kruskal ?

**We should use Kruskal** when the graph is sparse, i.e. small number of edges,like E=O(V),when the edges **are** already sorted or if **we can** sort them in linear time. **We should use Prim** when the graph is dense, i.e number of edges is high ,like E=O(V²).