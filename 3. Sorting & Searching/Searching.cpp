#include<bits/stdc++.h>
using namespace std;

int linearSearch(int arr[],int n,int x){
    for(int i=0;i<n;i++){
        if(arr[i]==x){
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[],int n,int x){
    int low=0,high=n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]==x)return mid;
        
        if(arr[mid]<x){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return -1;
}

int jumpSearch(int arr[],int n,int x){
    int step=sqrt(n);
    
    int prev=0;
    while(arr[step]<x){
        prev=step;
        step+=sqrt(n);
        if(step>=n)return -1;
    }
    
    while(arr[prev]<x){
        prev++;
        if(prev>=n)return -1;
    }
    
    if(arr[prev]==x)
    return prev;
    
    return -1;
}

int interpolationSearch(int arr[],int n,int x){
    int low=0,high=n-1;
    while(low<=high){
        int pos = low + (((double)(high-low)/(arr[high]-arr[low]))*(x-arr[low]));
        
        if(arr[pos]==x)return pos;
        
        if(arr[pos]<x){
            low = pos+1;
        }else{
            high = pos-1;
        }
    }
    return -1;
}

int main(){
    int arr[] = {2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34};
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
 
    int result1 = linearSearch(arr, n, x);
    int result2 = binarySearch(arr,n,x);
    int result3 = jumpSearch(arr,n,x);
    int result4 = interpolationSearch(arr,n,x);
    cout<<result1<<" "<<result2<<" "<<result3<<" "<<result4<<endl;
}