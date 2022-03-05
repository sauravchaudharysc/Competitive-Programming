#include<iostream>
#include<cstring>
#include "hashtableoperatoroverload.h" //User defined class are defined like this
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
    //Search function adress return kar ra h islie iska type pointer hoga
    int *price=price_menu.search("Noodle");
    if(price==NULL){
        cout<<"Not Found";
    }else{
        cout<<"Price is "<<*price<<endl;
    }
    
    //insert
    price_menu["Dosa"]=60;
    //Update
    price_menu["Dosa"]+=10;
    //Search 
    cout<<"Price of Dosa ";
    cout<<price_menu["Dosa"];
}