#include<bits/stdc++.h>
using namespace std;

void print(int [],int);
void merge_Sort(int*,int,int);
void quickSort(int*,int,int);
void heapify(int*,int,int);
void helperCountSort(int*,int,int);

/*Bubble Sort
Best Case & Worst Case:- O(n^2).
A simple optimization & for sorted array complexity will be O(n)
Sorting :- InPlace (sorted items occupy the same storage as the original ones & O(1) memory.)
Stable :- Yes (Sorts the identical elements in their same order.)*/
void bubbleSort(int arr[],int n){
    for(int i=0;i<n;i++){
        bool flag=1; //To optimize complexity in case of sorted array.
        for(int j=1;j<n-i;j++){
            if(arr[j]<arr[j-1]){
                int temp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
                flag=0;
            }
        }
        if(flag)break;
    }
    print(arr,n);
}

/*Selection Sort
Best Case & Worst Case:- O(n^2).
Sorting :- InPlace (sorted items occupy the same storage as the original ones.)
Stable :- No . 
Best sorting algorithm doesnt require more than n swaps.*/
void selectionSort(int arr[],int n){
    for(int i=0;i<n;i++){
      int k=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[k]){
                k=j;
            }
        }
        if(i!=k){
            int temp=arr[i];
            arr[i]=arr[k];
            arr[k]=temp;            
        }
    }
    print(arr,n);
}


/*Insertion Sort
Best Case :- O(n)
Worst Case :- O(n^2)
Sorting :- InPlace (sorted items occupy the same storage as the original ones.)
Stable :- Yes. 
Insertion sort is used when number of elements is small. It can also be useful
when input array is almost sorted, only few elements are misplaced in complete big array.*/
void insertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int temp=arr[i];
        bool flag=0;
        int j=i-1;
        for(;j>=0&&arr[j]>temp;j--){
            flag=1;
            arr[j+1]=arr[j];
        }
        if(flag)
        arr[j+1]=temp;
    }
    print(arr,n);
}



/*Merge Sort
Time Complexity :- O(nlogn)
Space :- O(n)
Algorithmic Paradigm :- Divide and Conquer
Sorting In Place:- No in a typical implementation
Stable: Yes
Merge sort is used for sorting linked list in O(nlogn) time. Unlike an array, 
in the linked list, we can insert items in the middle in O(1) extra space and 
O(1) time. Therefore, the merge operation of merge sort can be implemented without
extra space for linked lists.Merge Sort is better than quick sort in linked list because
quick sort requires  a lot of access. In a linked list to access i’th index, we have to 
travel each and every node from the head to i’th node as we don’t have a continuous block 
of memory. Therefore, the overhead increases for quicksort. Merge sort accesses data 
sequentially and the need of random access is low.*/
void mergeSort(int arr[],int n){
    merge_Sort(arr,0,n-1);
    print(arr,n);
}




/* QuickSort
Worst Case :- O(n^2).  If we consider above partition strategy where last element 
is always picked as pivot, the worst case would occur when the array is already 
sorted in increasing or decreasing order. So we use randomized quick sort.
Best Case :- O(nLogn)
Stable :- Not Stable
InPlace :- Yes,as it uses extra space only for storing recursive function calls
but not for manipulating the input. 
Quick Sort in its general form is an in-place sort (i.e. it doesn’t require any extra storage)
whereas merge sort requires O(N) extra storage, N denoting the array size which may be quite
expensive. Allocating and de-allocating the extra space used for merge sort increases the 
running time of the algorithm. Comparing average complexity we find that both type of sorts
have O(NlogN) average complexity but the constants differ. For arrays, merge sort loses due 
to the use of extra O(N) storage space.*/
void QuickSort(int arr[],int n){
    quickSort(arr,0,n-1);
    print(arr,n);
}




/*HeapSort
Time Complexity:-  Time complexity of heapify is O(Logn). Time complexity of createAndBuildHeap() is O(n) and the overall time complexity of Heap Sort is O(nLogn).
Stable :- No(Doesn’t sorts the identical elements in their same order.)
Sorting :- InPlace (sorted items occupy the same storage as the original ones.)
*/
void heapSort(int arr[],int n){
    for(int i=(n+1)/2;i>=0;i--){
        heapify(arr,i,n);
    }
    
    for(int i=n-1;i>=0;i--){
        int temp=arr[0];
        arr[0]=arr[i];
        arr[i]=temp;
        heapify(arr,0,i);
    }
    print(arr,n);
}


/*Count Sort 
Time Complexity :- O(n)
Space :- Range of Data
Stable :- Depends on traversal. Traversal from end makes it stable.
Sorting In Place :- No
*/

void countSort(int arr[],int n){
    int maxEle=0;
    for(int i=0;i<n;i++){
        maxEle=max(maxEle,arr[i]);
    }
    
    int count[maxEle+1]={0};
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }
    
    for(int i=1;i<=maxEle;i++){
        count[i]+=count[i-1];
    }
    
    int output[n];
    
    for(int i=n-1;i>=0;i--){
        output[count[arr[i]]-1]=arr[i];
        --count[arr[i]];
    }
    print(output,n);
}

/*Radix Sort 
Time Complexity :- nLogb(n)
Space :- Range of Data
Stable :- Depends on traversal. Traversal from end makes it stable.
Sorting In Place :- No
*/

void radixSort(int arr[],int n){
    int maxEle=0;
    
    for(int i=0;i<n;i++){
        maxEle=max(maxEle,arr[i]);
    }
    
    for(int exp=1;maxEle/exp>0;exp*=10){
        helperCountSort(arr,n,exp);
    }
    print(arr,n);
}

void print(int arr[],int n){
    cout<<"\t";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    reverse(arr,arr+n);
}

int main(){
    int arr[]={12,1,13,2,4,3,15,6,0,9};
    int n=10;
    cout<<"The given unsorted array is :-";
    print(arr,n);
    cout<<endl;
    cout<<"The Sorted array is :-\n";
    bubbleSort(arr,n);
    selectionSort(arr,n);
    insertionSort(arr,n);
    mergeSort(arr,n);
    QuickSort(arr,n);
    heapSort(arr,n);
    countSort(arr,n);
    radixSort(arr,n);
}



void merger(int arr[],int low,int mid, int high){
    int temp[high-low+1];
    int i=low,j=mid+1;
    int k=0;
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
    
    for(int i=0; i<k; i++){
        arr[i+low]=temp[i];
    }
}

void merge_Sort(int arr[], int low,int high){
    if(low<high){
        int mid = (low+high)/2;
        merge_Sort(arr,low,mid);
        merge_Sort(arr,mid+1,high);
        merger(arr,low,mid,high);
    }
}

int partition(int arr[],int low,int high){
    int i=low,j=high+1;
    int pivot=low;
    do{
        do{
            i++;
        }while(i<j && arr[i]<arr[pivot]);
        
        do{
            j--;
        }while(arr[j]>arr[pivot]);
        if(i<j){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;  
        }
    }while(i<j);
    
    if(j!=pivot){
        int temp=arr[j];
        arr[j]=arr[pivot];
        arr[pivot]=temp;  
    }
    return j;
}

void quickSort(int arr[],int low,int high){
    if(low<high){
        //The pivot is partitioning index, arr[pi] is now at right place
        int pivot = partition(arr,low,high); 
        quickSort(arr,low,pivot-1);
        quickSort(arr,pivot+1,high);
    }
}

void heapify(int arr[],int i,int n){
    int largest=i;
    if(2*i+1<n && arr[2*i+1]>arr[largest]){
        largest=2*i+1;
    }
    if(2*i+2<n && arr[2*i+2]>arr[largest]){
        largest=2*i+2;
    }
    if(i!=largest){
        int temp=arr[i];
        arr[i]=arr[largest];
        arr[largest]=temp;
        heapify(arr,largest,n);
    }
}

void helperCountSort(int arr[],int n,int exp){
   int output[n];
   int i,count[10]={0};
   
   for(i = 0; i < n; i++){
       count[(arr[i] / exp) % 10]++;
   }

   for(i = 1; i < 10; i++){
       count[i]+=count[i-1];
   }   
    
   for(i = n-1; i>=0; i--){
       output[count[(arr[i]/exp)%10]-1]=arr[i];
       count[(arr[i]/exp)%10]--;
   }   
   for (i = 0; i < n; i++){
        arr[i] = output[i];
   }    
}