## Operator Overloading
Here we will see operator overloading to make our hash table work easier.
<br>

#### Insert

price_menu["Dosa"]  = 60;
<br>

#### Update

price_menu["Dosa"] += 10;
<br>

#### Search

cout<<price_menu["Dosa"]<<endl;
<br>

I want to support these three operation in hash table.<br>
### What operators to overload and how ??<br>
First we check is the key is present or not. If not we simply create the new node where Dosa is
the key and some random garbage as the value. This node is returned by reference. The node is of data-type T. So to return it by reference we use &.If we don’t use & it will return
the copy of T and value cant be updated.<br>
<br>
check operatoverload.cpp