//Rehash 
#include<iostream>
#include<cstring>
#include "hashtablerehash.h" //User defined class are defined like this
using namespace std;
int main(){
    HashTable<int> price_menu;
    price_menu.insert("Burger",110);
    price_menu.insert("Noodle",160);
    price_menu.insert("Pasta",130);
    price_menu.insert("Cake",1120);
    price_menu.insert("Old Monk",1200);
    price_menu.insert("Chips",10);
    price_menu.insert("Momo",100);
    price_menu.insert("Beer",180);
    price_menu.print();
}