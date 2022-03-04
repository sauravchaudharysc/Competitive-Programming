#include<bits/stdc++.h>
using namespace std;

int partition(int arr[],int low,int high){
    int pivot=low;
    int i=low;
    int j=high+1;
    
    do{
        do{
            i++;
        }while(i<high && arr[i]<arr[pivot]);
        do{
            j--;
        }while(arr[j]>arr[pivot]);
        if(i<j){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }while(i<j);
    
    if(pivot!=j){
        int temp=arr[pivot];
        arr[pivot]=arr[j];
        arr[j]=temp;
    }
    return j;
}

int top_element(stack<int>&st){
    int x= st.top();
    st.pop();
    return x;
}

void quickSort(int arr[],int low,int high){
    stack<int>st;
    st.push(low);
    st.push(high);
    while(!st.empty()){
        int high=top_element(st);
        int low=top_element(st);
        int pivot = partition(arr,low,high);
        if(low< (pivot-1)){
            st.push(low);
            st.push(pivot-1);            
        }
        if((pivot+1)<high){
            st.push(pivot+1);
            st.push(high);                        
        }
    }
}

void printArr(int arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        cout << arr[i] << " ";
}
 
int main()
{
    int arr[] = { 4, 3, 5, 2, 1, 3, 2, 3 };
    int n = sizeof(arr) / sizeof(*arr);
    quickSort(arr, 0, n - 1);
    printArr(arr, n);
    return 0;
}