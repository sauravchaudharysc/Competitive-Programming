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
                delete next; //this cause recursive deletion.So we dont need iteration
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
  void rehash(){
      //Here we have a old table pointing to old table and a table pointing to new table
      Node<T>** oldTable=table;
      int oldTableSize=table_size; //Storing the old table size
      table_size=2*table_size; //Here it is twice but you can take nearest prime
      table =new Node<T>*[table_size];
      for(int i=0;i<table_size;i++){
          table[i]=NULL;
      }
      current_size=0;
      //Copying elements from old table to table
      for(int i=0;i<oldTableSize;i++){
          Node<T>*temp=oldTable[i];
          //Copying an one entire node linked list.
          while(temp!=NULL){
              //Here insert occurs in new table. Table pointer is the member of class
              //So it get inserted in new table
              insert(temp->key,temp->value); 
              temp=temp->next;
          }
          //Deletion of linked list
          if(oldTable[i]!=NULL){
              delete oldTable[i];
          }
      }
      //Coming out of this loop guarantess all linked list are deleted and element are copied
      delete [] oldTable;
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
        //Rehash
        float load_factor = current_size/(1.0*table_size);
        if(load_factor>0.7){
            rehash();
        }
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
    
    T* search(string key){
        //We will find the idx of key
        int idx=hashFn(key);
        Node<T>*temp= table[idx];
        while(temp!=NULL){
            if(temp->key==key){
                return &temp->value; //Here & is used because return type these is dereference
            }
            temp=temp->next;
        }
        
        return NULL; //Due to this we use return type T* instead of T
    }
    /*
    void erase(string key){
        //....
    }
    */
};