

<h2 align="center">Sorting</h2>

For sorting codes see Sorting.cpp & searching code see Searching.cpp

#### 1. Bubble Sort

**Best Case & Worst Case:-** O(n^2).
A simple optimization & for sorted array complexity will be O(n)

**Sorting :-** InPlace (sorted items occupy the same storage as the original ones.)

**Stable :-** Yes (Sorts the identical elements in their same order.)

------

#### 2. Selection Sort

**Best Case & Worst Case:-** O(n^2).

**Sorting :-** InPlace (sorted items occupy the same storage as the original ones.)

**Stable :-** No . 

Best sorting algorithm doesn’t require more than n swaps.

------

#### 3. Insertion Sort

**Best Case :-** O(n)
**Worst Case :-** O(n^2)

**Sorting :-** InPlace (sorted items occupy the same storage as the original ones.)

**Stable :-** Yes. 

Insertion sort is used when number of elements is small. It can also be useful
when input array is almost sorted, only few elements are misplaced in complete big array.

------

#### 4. Merge Sort

**Time Complexity :-** O(nlogn)

**Space:-** O(n)

**Algorithmic Paradigm:-** Divide and Conquer

**Sorting In Place:-** No in a typical implementation(Uses extra space to store sorted array.)

**Stable:-** Yes

Merge sort is used for sorting linked list in O(nlogn) time. Unlike an array,  in the linked list, we can insert items in the middle in O(1) extra space and O(1) time. Therefore, the merge operation of merge sort can be implemented without extra space for linked lists. Merge Sort is better than quick sort in linked list because quick sort requires  a lot of access. In a linked list to access i’th index, we have to  travel each and every node from the head to i’th node as we don’t have a continuous block of memory. Therefore, the overhead increases for quicksort. Merge sort accesses data sequentially and the need of random access is low.

------

#### 5. Quick Sort

**Worst Case :-** O(n^2).  If we consider above partition strategy where last element 
is always picked as pivot, the worst case would occur when the array is already 
sorted in increasing or decreasing order. So we use randomized quick sort.

**Best Case :-** O(nLogn)

**Stable :-** Not Stable

**Sorting :-** InPlace (sorted items occupy the same storage as the original ones.)

Quick Sort in its general form is an in-place sort (i.e. it doesn’t require any extra storage) whereas merge sort requires O(N) extra storage, N denoting the array size which may be quite expensive. Allocating and de-allocating the extra space used for merge sort increases the running time of the algorithm. Comparing average complexity we find that both type of sorts have O(NlogN) average complexity but the constants differ. For arrays, merge sort loses due to the use of extra O(N) storage space.

------

#### 6. Heap Sort

**Time Complexity:**-  Time complexity of heapify is O(Logn). Time complexity of createAndBuildHeap() is O(n) and the overall time complexity of Heap Sort is O(nLogn).

**Stable :- **No(Doesn’t sorts the identical elements in their same order.)

**Sorting :-** InPlace (sorted items occupy the same storage as the original ones.)

Heap sort is a comparison-based sorting technique based on Binary Heap data structure.

------

#### 7. Count Sort

**Time Complexity :-** O(n)

**Space :-** Range of Data

**Stable :-** Depends on traversal. Traversal from end makes it stable.

**Sorting In Place :-** No 

------

#### 8. Radix Sort

**Time Complexity :-** O(nlogbn)

**Space :-** Range of Data

**Stable :-** Depends on traversal. Traversal from end makes it stable.

**Sorting In Place :-** No 

What is running time of Radix Sort ?
Let there be d digits in input integers. Radix Sort takes O(d*(n+b)) time where n is the no of elements in array & b is the base for representing numbers. 

```
O(n)
for(i = 0; i < n; i++){
       count[(arr[i] / exp) % 10]++;
   }
O(b),for decimal base is 10
for(i = 1; i < 10; i++){
       count[i]+=count[i-1];
   }
So, O(n+b)   
```

 If k is the maximum possible value, then d would be O(logb(k)). So overall time complexity is O((n+b) * logb(k)). Which looks more than the time complexity of comparison-based sorting algorithms for a large k. Let us first limit k. Let k <= nc where c is a constant. In that case, the complexity becomes O(nLogb(n)). So if we make b==n then the complexity will be linear. 

-----





<h2 align="center">Searching</h2>

#### 1. Linear Search

Complexity :- O(n)

A simple approach is to do a **linear search**, i.e 

- Start from the leftmost element of arr[] and one by one compare x with each element of arr[]
- If x matches with an element, return the index.
- If x doesn’t match with any of elements, return -1

-----

#### 2. Binary Search

Complexity :- O(logn) 

**Works only sorted arrays.**

 We basically ignore half of the elements just after one comparison.

1. Compare x with the middle element.
2. If x matches with the middle element, we return the mid index.
3. Else If x is greater than the mid element, then x can only lie in the right half subarray after the mid element. So we iterate for the right half.
4. Else (x is smaller) iterate for the left half.

-----

#### 3. Jump Search 

Complexity : O(√n) 

**Works only sorted arrays.** The basic idea is to check fewer elements (than linear search) by jumping ahead by fixed steps or skipping some elements in place of searching all elements.

**What is the optimal block size to be skipped?** 
In the worst case, we have to do n/m jumps and if the last checked value is greater than the element to be searched for, we perform m-1 comparisons more for linear search. Therefore the total number of comparisons in the worst case will be ((n/m) + m-1). The value of the function ((n/m) + m-1) will be minimum when m = √n. Therefore, the best step size is m = **√n.**

*Binary Search is better than Jump Search, but Jump search has an advantage that we traverse back only once (Binary Search may require up to O(Log n) jumps, consider a situation where the element to be searched is the smallest element or just bigger than the smallest). So in a system where binary search is costly, we use Jump Search.*

-----

#### 4. Interpolation Search

Time Complexity: O(log2(log2 n)) for the average case, and O(n) for the worst case (when items are distributed exponentially)

The Interpolation Search is an improvement over Binary Search for instances, where the values in a sorted array are uniformly distributed. Binary Search always goes to the middle element to check. On the other hand, interpolation search may go to different locations according to the value of the key being searched. For example, if the value of the key is closer to the last element, interpolation search is likely to start search toward the end side.

**Interpolation algorithm is the same except the above partition logic.**

```c++
pos = low + (x - arr[low]) *(high - low)/(arr[high] - arr[low])
```

----

#### 5. Exponential Search 

Exponential Binary Search or Exponential Search is particularly useful for unbounded searches, where size of array is infinite.

**How to find the range where element may be present?** 
The idea is to start with subarray size 1, compare its last element with x, then try size 2, then 4 and so on. Once we find an index i (after repeated doubling of i), we know that the element must be present between i/2 and i Then we apply binary search between i/2 & i.

