#include<bits/stdc++.h>
using namespace std;

void countSort(int arr[],int n){
    int minele=arr[0],maxele=arr[0];
    
    for(int i=0; i<n;i++){
        minele = min(minele,arr[i]);
        maxele = max(maxele,arr[i]);
    }
    int range = maxele-minele+1;
    int count[range]={0};
    int output[n];
    int addition=abs(minele);
    for(int i=0; i<n; i++){
        count[arr[i]+addition]++;
    }
    for(int i=1; i<range; i++){
        count[i]+=count[i-1];
    }
    for(int i=n-1; i>=0; i--){
        output[count[arr[i]+addition]-1]=arr[i];
        --count[arr[i]+addition];
    }
     for(int i=n-1; i>=0; i--){
        arr[i]=output[i];
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
    int arr[] = {-5,-3,1,-9,18,-2,7,10,-4};
    int n = sizeof(arr) / sizeof(*arr);
    countSort(arr, n);
    printArr(arr, n);
    return 0;
}