#include <cstdio>
#include <iostream>
using namespace std;
 
struct node {
    int data;
    struct node* next;
};
 

void push(struct node** head_ref, int new_data)
{
    struct node* new_node = new node;
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
 
void printList(struct node* node){
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
 
struct node* getTail(struct node* cur)
{
    while (cur != NULL && cur->next != NULL)
        cur = cur->next;
    return cur;
}
 
struct node* partition(struct node* head, struct node* end,
                       struct node** newHead,
                       struct node** newEnd)
{
    struct node* pivot = head;
    (*newHead)=pivot;
    struct node* prev=head,*curr=head->next,*tail=NULL;
    
    while(curr!=NULL){
        if(curr->data>pivot->data){
            prev=curr;
            tail = curr;
            curr=curr->next;
        }else{
            prev->next=curr->next;
            struct node* tmp = curr->next;
            curr->next=(*newHead);
            (*newHead)=curr;
            curr = tmp;
        }
    }
    
    if((*newHead)==NULL){
        (*newHead)=pivot;
    }
    (*newEnd)=tail;
    
    return pivot;
}
 
struct node* quickSortRecur(struct node* head,
                            struct node* end)
{
    //Zero Element && Single Element
    if(!head || head==end ){
        return head;
    }
    
    node *newHead=NULL,*newEnd=NULL;
    struct node* pivot = partition(head, end, &newHead, &newEnd);
    if(newHead!=pivot){
        struct node* tmp = newHead;
     
        //Finding node just Before Pivot
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;
        
        //Recur for the list Before Pivot
        newHead = quickSortRecur(newHead,tmp);
        
        //Find the tail of left part 
        tmp = getTail(newHead);
        //Join it with pivot 
        tmp->next = pivot;
    }
    
    //If Pivot isn't the Last Element 
    if(newEnd!=pivot){
        pivot->next= quickSortRecur(pivot->next,newEnd);
    }
    return newHead;
}
 
void quickSort(struct node** headRef)
{
    (*headRef)
        = quickSortRecur(*headRef, getTail(*headRef));
    return;
}
 
int main()
{
    struct node* a = NULL;
    push(&a, 5);
    push(&a, 20);
    push(&a, 4);
    push(&a, 3);
    push(&a, 30);
 
    cout << "Linked List before sorting \n";
    printList(a);
 
    quickSort(&a);
 
    cout << "Linked List after sorting \n";
    printList(a);
 
    return 0;
}