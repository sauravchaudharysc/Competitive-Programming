# Spanning Trees

A spanning tree of a graph consist of all the nodes and some of the edges of the graph so that there exist a path between any two nodes. Like tree , spanning trees are connected and acyclic.

**Consider the following graph**

![image-20210223103532891](image-20210223103532891.png)

One spanning tree for the graph is as follows :

![image-20210223103616314](image-20210223103616314.png)



The weight of a spanning tree is the sum of its edge weights. For example, the weight of the spanning tree is 3+5+9+3+2=22.

## Minimum Spanning Tree

A **minimum spanning tree** is a spanning tree whose weight is as small as possible. The weight of a minimum spanning tree for the example graph is 20 and such tree can be constructed as follows:

![image-20210223104116010](C:\Users\Saurav Chaudhary\AppData\Roaming\Typora\typora-user-images\image-20210223104116010.png)

A **maximum spanning tree** is a spanning tree whose weight is as large as possible. The weight of a maximum spanning tree for the example graph is 32 and can be constructed as follows:

![image-20210223104244132](C:\Users\Saurav Chaudhary\AppData\Roaming\Typora\typora-user-images\image-20210223104244132.png)

> If graph is a **complete graph** with n vertices then total no of spanning tree is  n^(n-2) .
>
> If graph isn’t **complete graph** then we can use Kirchoff’s theorem to calculate spanning trees.

------