//headerfile
#include<iostream>
#include<cstring>
using namespace std;
/*Implementation Of Hash Map*/
/*So we have to create a node. It must have a key , value and a next pointer.*/
template<typename T>
class Node{
    public:
        string key;
        T value;
        Node<T>*next;
        
        Node(string key,T val){
            this->key=key;
            value=val;
            next=NULL;
        }
        //Destructor
        ~Node(){
            if(next!=NULL){
                //Destructor of next node and so on.
                delete next;
            }
        }
};
template<typename T>
class HashTable{
    Node<T>** table; //A pointer to the table. Because its pointers to an array of pointers
    int current_size;
    int table_size;
  int hashFn(string key){
      int idx=0;
      int p=1;
      for(int i=0;i<key.length();i++){
          idx=idx+(key[i]*p)%table_size;
          idx=idx%table_size;
          p=(p*27)%table_size; //Here we do so that p never reaches a very large value which may cause overflow.
      }
      return idx;
  }  
public:
    HashTable(int ts=7){
        table_size=ts;
        table= new Node<T>*[table_size]; //An array of pointers.So two star because it is a pointer which points a pointer.Data size of each bucket in array.
        current_size=0;
        for(int i=0;i<table_size;i++){
            table[i]=NULL;
        }
    }
    void insert(string key, T value){
        //Insertion at head of linked list.
        int idx= hashFn(key);
        Node<T>*n = new Node<T>(key,value);   
        n->next=table[idx]; 
        table[idx]=n;
        current_size++;
    }
    void print(){
        for(int i=0;i<table_size;i++){
            cout<<"Bucket "<<i<<" ->";
            //To Print Linked List
            Node<T>*temp=table[i];
            while(temp!=NULL){
                cout<<temp->key<<" -> ";
                temp=temp->next;
            }
            cout<<endl;
        }
    }
    /*
    T search(string key){
        //....
    }
    void erase(string key){
        //....
    }
    */
};