/*Level Order Print Iterative
We can use queue to do so. Or we can simply call it BFS Traversal.
It complexity is O(N)

// Input :- 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1 

1.Take the root node. Push it in the Queue.
2.Pop the front node of queue and push the children of the poped node.
Repeat Step 2. TIll the queue doesnt become empty. For each pop print the node.
*/


#include<iostream>
#include<queue>
using namespace std;
class node{
    public:
        int data;
        node* left;
        node* right;
        
        node(int d){
            data=d;
            left=NULL;
            right=NULL;
        }
};

node* buildTree(){
    int d;
    cin>>d;
    //Encountering -1 means to return from that node
    if(d==-1){
        return NULL;
    }
    node* root=new node(d);
    root->left=buildTree();
    root->right=buildTree();
    return root;
}
void bfs(node *root){
    //I need the node in queue to contain it address
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        node *f= q.front();
        cout<<f->data<<",";
        q.pop();
        if(f->left){
            q.push(f->left);
        }
        if(f->right){
            q.push(f->right);
        }
    }
    return;
}
int main(){
    node *root=buildTree();
    bfs(root);
}