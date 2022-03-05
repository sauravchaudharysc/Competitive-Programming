/*
Level Order Traversal II 
//Each Level Print in different line

//Input :- 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1 

1st Approach :- We can use queue to do so by making a pair of node and level.
2nd Approach :- After every level when it ends a NULL is pushed to indicate
that we need to change the line.Whenever we encounter the NUll. The Previous 
level is out of the queue. It means all the next level element are pushed out.
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
    q.push(NULL);
    while(!q.empty()){
        node *f= q.front();
        if(f==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
        cout<<f->data<<",";
        q.pop();
        if(f->left){
            q.push(f->left);
        }
        if(f->right){
            q.push(f->right);
        }
      }    
    }
    return;
}
int main(){
    node *root=buildTree();
    bfs(root);
}