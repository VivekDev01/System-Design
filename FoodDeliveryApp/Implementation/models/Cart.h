#ifndef CART_H
#define CART_H

#include<bits/stdc++.h>
#include "Restaurant.h"
#include "MenuItem.h"
using namespace std;

class Cart{
    Restaurant * res=NULL;
    unordered_map<MenuItem*, int>items;
public:
    Cart(Restaurant * res){
        this->res = res;
    }
    void addItem(MenuItem * item, int cnt){
        if(!res->isItemInMenu(item)){
            cout<<"Item does not exist in menu of the restaurant"<<endl;
            return ;
        }
        items[item]=cnt;
    }
    unordered_map<MenuItem*, int> getCartItems(){
        return items;
    }
    int getPrice(){
        int tot = 0;
        for(auto it: items){
            tot+=(it.first->getPrice())*it.second;
        }
        return tot;
    }
    void removeItem(MenuItem * item){
        if(items[item]>0) items[item]--;
    }
    void viewCart(){
        cout<<endl<<"------------- SHOWING CART --------------------"<<endl;
        for(auto it: items){
            cout<<it.first->getName()<<" --> "<<it.second<<endl;
        }
    }
};

#endif // CART_H