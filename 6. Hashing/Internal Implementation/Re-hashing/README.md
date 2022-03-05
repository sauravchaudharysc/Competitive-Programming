## Rehashing
Lets understand what is Rehashing and why it is needed.
Suppose you have a table of 10 buckets. And you insert 20 element then there is a chance
of collision. One way is to increase the table size as element increases.
<br>
So we can define a load factor.

### Load Factor = ratio of(CS/TS)
If Load Factor becomes greater than threshold(0.75) then this is the time to increase the bucket size. So we are going to find the next prime number which is near to double of size of old hash table. All the previous element in the old table must be rehashed.

Steps Involved:-
    1. Calculate Load Factor. 
    {
        If LF>threshold {
            1.Create a new table of size 2*oldsize.
            2.Shift elements from old table to new table
            3.Delete old table.
        }
    }

We need to rehash everything because table size has changed. We cant extend once the table size is allocated. So we need to create a new table and rehash it. And this is going to be expensive operation. And it is at least going to take time O(N).