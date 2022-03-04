#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

typedef struct Node NODE;

void push(NODE** ,int);
void printList(NODE*);

void midPoint(NODE* source,NODE** i,NODE** j){
    NODE *slow,*fast;
    slow=source;
    fast=source->next;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    *i=source;
    *j=slow->next;
    slow->next=NULL;
}

NODE* SortedMerge(NODE* i,NODE* j){
    if(i==NULL) return j;
    if(j==NULL) return i;
    NODE* result=NULL;
    if(i->data<=j->data){
        result=i;
        result->next=SortedMerge(i->next,j);
    }else{
        result=j;
        result->next=SortedMerge(i,j->next);        
    }
    return result;
}

void mergeSort(NODE** headRef){
    NODE* head = *headRef;
    NODE* i; //Starting Index of First Array
    NODE* j; //Starting Index of Second Array
    
    //Single Element Ho to kya hi break karoge
    if(head==NULL || head->next==NULL){
        return;
    }
    //Split Array into two halves 
    midPoint(head,&i,&j);
    mergeSort(&i);
    mergeSort(&j);
    
    *headRef=SortedMerge(i,j);
}

int main(){
    NODE* head=NULL;
    push(&head,7);
    push(&head,6);
    push(&head,3);
    push(&head,2);
    push(&head,1);
    push(&head,5);
    push(&head,4);
    printList(head);
    mergeSort(&head);    
    printList(head);

}    


void push(NODE** head,int x){
    NODE* newNode=(NODE*)malloc(sizeof(NODE));
    newNode->data=x;
    newNode->next=(*head);
    *head=newNode;
}

void printList(NODE* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}