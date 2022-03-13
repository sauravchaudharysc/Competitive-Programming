# Dynamic Programming 

If a directed graph is acyclic, dynamic programming can be applied to it. For example, we can efficiently solve the following problems concerning paths from a starting node to an ending node:

-  how many different paths are there?
-  what is the shortest/longest path?
-  what is the minimum/maximum number of edges in a path?
-  which nodes certainly appear in any path?

### To Find total no of ways from Node u to Node v

1. Extract the topological ordering of the graph.

2. Find the index *i* of the node u in the array.

3. Then simply traverse the array and update the count of path.

   ```c++
   path[u]=(path[st[i]]+path[u]);
   ```

The complete implementation is :

```cpp
#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll ans=0;
ll mod=1e9+7;

void dfsHelper(vector<ll>adj[],vector<bool>&visited,vector<ll>&st,ll src){
    visited[src]=1;
    for(auto u:adj[src]){
        if(!visited[u])
        dfsHelper(adj,visited,st,u);
    }
    st.push_back(src);
}


void dfs(vector<ll>adj[],ll n){
    vector<bool>visited(n+1,0);
    vector<ll>st;
    dfsHelper(adj,visited,st,1);
    reverse(st.begin(),st.end());
    ll z=st.size();
    ll i=0;
    while(st[i]!=1){
        i++;
    }
    vector<ll>path(n+1,0);
    path[1]=1;
    for(i;i<z;i++){
      if(st[i]==n)break;
        for(auto u:adj[st[i]]){
            path[u]=(path[st[i]]+path[u])%mod;
        }
    }
    cout<<path[n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,e;
    cin>>n>>e;
    vector<ll>adj[n+1];
    for(ll i=0;i<e;i++){
        ll a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    dfs(adj,n);
}
```

<div style="page-break-after: always; break-after: page;"></div>

### To Find Shortest or Longest Route From Node u to Node v

Simple BFS, suitable for shortest but in case of longest frequent updation. So we shift to topological sorting. 

Link to Problem https://cses.fi/problemset/task/1680/

Solution : https://cses.fi/paste/91a5d697e01fda611b79fe/

**Algorithm**

- If the destination node is reachable from the source node, that node will present in our topological ordering and using the ordering we can update the distance and get max distance.
- If the destination node isn’t reachable from the source node, that node willn’t be present in our topological ordering and hence the distance of that nodes remains 0 . And we can say it’s **IMPOSSIBLE **to reach.

## Extending Dijkstra’s Algorithm

A by-product of Dijkstra’s algorithm is a directed, acyclic graph that indicates the possible shortest route for each node from the starting node.

 Dynamic Programming can be applied to these graph and we can obtain these:

- what is the minimum price of such a route?
- how many minimum-price routes are there? 
- what is the minimum number of flights in a minimum-price route?
- what is the maximum number of flights in a minimum-price route?

[Link to Question](https://cses.fi/problemset/task/1202/)

[Answer](https://cses.fi/paste/d71a5b1d9ba036951b7ed3/)

```c++
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
ll mod=1e9+7;
 
void dijkstra(vector<pair<ll,ll>>adj[],ll src,ll n){
    
    //To Store Min Path
    vector<ll>dist(n+1,0);
    
    //To Store Count of Minimum Price Routes
    vector<ll>routes(n+1,0);
    routes[1]=1;
    
    //To Store Minimum Number of Flight to reach nth Node
    vector<ll>minFlight(n+1,0);
    
    //To Store Maximum Number of Flight to reach nth Node
    vector<ll>maxFlight(n+1,0);
    
    for(ll i=1;i<=n;i++){
        dist[i]=LLONG_MAX; 
    }
    
    //Min Heap to Pick the Shortest Path Each Time
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
    
    
    //Initialise the first vertex distance as zero
    pq.push({0,src});
    
    while(!pq.empty()){
        pair<ll,ll> top = pq.top();
        pq.pop();
        ll weight = top.first;
        ll node = top.second;
        
        //If we already have the optimal path
        if(dist[node]<weight)continue;
        
        for(auto u:adj[node]){
                //If we have a better path to reach the current node
                if(dist[u.first]>weight+u.second){
                    dist[u.first]=weight+u.second;
                    //If we get a minimum distance, we need to remove old path count
                    //routes[u.first]=(routes[u.first]+routes[node])%mod;
                    routes[u.first]=(routes[node])%mod;
                    minFlight[u.first]=1+minFlight[node];
                    maxFlight[u.first]=1+maxFlight[node];
                    pq.push({dist[u.first],u.first});
                }else if(dist[u.first]==weight+u.second){
                    routes[u.first]=(routes[u.first]+routes[node])%mod;
                    minFlight[u.first]=min(minFlight[u.first],1+minFlight[node]);
                    maxFlight[u.first]=max(maxFlight[u.first],1+maxFlight[node]);
                }
        }
    }
    cout<<dist[n]<<" "<<routes[n]<<" "<<minFlight[n]<<" "<<maxFlight[n];    
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,e;
    cin>>n>>e;
    vector<pair<ll,ll>>adj[n+1];
    for(ll i=0;i<e;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    dijkstra(adj,1,n);
}
```

<div style="page-break-after: always; break-after: page;"></div>

## Successor Paths

As said earlier, a successor graph is that graph whose outdegree of each node is 1, so each node has a unique successor. A successor graph consist of one or more components, each of which contains one cycle and some paths that lead to it.

Successor graphs are sometimes called functional graphs. The reason for this is that any successor graph corresponds to a function that defines the edges of the graph.

For example, the function

|    x    | 1    | 2    | 3    | 4    | 5    | 6    | 7    | 8    | 9    |
| :-----: | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| succ(x) | 3    | 5    | 7    | 6    | 2    | 2    | 1    | 6    | 3    |

defines the following graph:

​	![image-20210226170817435](C:\Users\Saurav Chaudhary\AppData\Roaming\Typora\typora-user-images\image-20210226170817435.png)

Since each node of a successor graph has a unique successor, we can also define a function succ(x,k) that gives the node that we will reach if we begin at node x and walk k steps forward. For example, in the above graph succ(4,6) = 2, because we will reach node 2 by walking 6 steps from node 4:

![image-20210226171145864](C:\Users\Saurav Chaudhary\AppData\Roaming\Typora\typora-user-images\image-20210226171145864.png)

### Cycle Detection

Consider a successor graph that only contains a path that ends in a cycle. Suppose if we begin our walk at the starting node, **what is the first node in the cycle and how many nodes does the cycle contain?**

For example, in the graph

![image-20210226171906204](C:\Users\Saurav Chaudhary\AppData\Roaming\Typora\typora-user-images\image-20210226171906204.png)

A simple way to detect the cycle is to walk in the graph and keep track of all nodes that have been visited. Once a node is visited for the second time, we can conclude that the node is the first node in the cycle. This method works in O(n) time and also uses O(n) memory.

However, there are better algorithms for cycle detection. The time complexity of such algorithms is still O(n), but they only use O(1) memory. This is an important improvement if n is large. Floyd’s algorithm achieves these properties.

### Floyd’s Algorithm

Floyd’s algorithm walks forward in the graph using two pointers a and b. Both pointers begin at a node x that is the starting node of the graph. Then, on each turn, the pointer a walks one step forward and the pointer b walks two steps forward. The process continues until the pointers meet each other: 

**Finds Cycle**

```c++
slow = succ(x);
fast = succ(succ(x));
while (slow != fast) {
slow = succ(slow);
fast = succ(succ(fast));
}
```

**To Find First Node of Cycle**

```cpp
slow = x;
while(slow!=fast){
slow = succ(slow);
fast = succ(fast);
}
meet = slow;
```

**To get Length of Cycle**

```
fast = succ(slow);
length=1;
while(fast!=slow){
	fast = succ(fast);
	length++;
}
```



### Why Floyd Cycle Detection Algorithm works ?

![img](https://qph.fs.quoracdn.net/main-qimg-0f27f0c35a9e5b1998b05756c9a1533c-pjlq)

Let  x  be the distance from the start of the linked list to the node where the cycle starts. Let  y  be the distance from the node where the cycle starts to where the two pointers initially meetup.

When the turtle pointer and the hare pointer initially meetup, the turtle pointer has traveled a total distance of  x+y  and the hare pointer has traveled a total distance of  2(x+y) , because the hare pointer moves twice as quickly as the turtle pointer.

In the diagram above, the blue line is the distance the turtle pointer travels and the green line is the distance the hare pointer travels. Because the hare pointer travels an extra x+y distance, the distance from the node where the two pointers meetup initially to the start of the cycle is x+y−y=x. Thus, if you start the turtle pointer from the head and start the hare pointer from the meetup node, after x moves, they will both end up at the start of the cycle (the node you want to return).

