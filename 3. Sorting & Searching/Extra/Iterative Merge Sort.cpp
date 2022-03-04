#include<bits/stdc++.h>
using namespace std;

void merger(int arr[],int low,int mid,int high){
    int i=low,j=mid+1,k=0;
    int temp[high-low+1];
    while(i<=mid && j<=high){
        if(arr[i]<arr[j]){
            temp[k++]=arr[i++];
        }else{
            temp[k++]=arr[j++];
        }
    }
    
    while(i<=mid){
        temp[k++]=arr[i++];
    }
    
    while(j<=high){
        temp[k++]=arr[j++];
    }    
    
    for(int i=0;i<k;i++){
        arr[i+low]=temp[i];
    }
}


void mergeSort(int arr[], int l, int r){
    int n=r;
    int curr_Size,arr_Size;
    for(curr_Size=1;curr_Size<=n;curr_Size*=2){
        for(int left_start=0;left_start<=n;left_start+=2*curr_Size){
            int mid=min(left_start+curr_Size-1,n); 
            int high=min(left_start+2*curr_Size-1,n);
            merger(arr,left_start,mid,high);
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
    int arr[] = { 4, 3, 5, 2, 1, 3, 2, 3,17 };
    int n = sizeof(arr) / sizeof(*arr);
    mergeSort(arr,0,n-1);
    printArr(arr, n);
    return 0;
}