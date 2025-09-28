#ifndef RESTAURANT_H
#define RESTAURANT_H

#include<bits/stdc++.h>
using namespace std;
#include "MenuItem.h"


class Restaurant{
    static int RestaurantCount;
    string name;
    vector<MenuItem*>menu;
    int id;
    string address;
public:
    Restaurant(string name, string address, vector<MenuItem*>menu){
        this->name = name;
        this->address = address;
        this->menu = menu;
        id=++RestaurantCount;
    }
    vector<MenuItem*> getMenu(){
        cout<<endl<<"---------- Showing menu ----------------"<<endl;
        for(auto item: menu){
            cout<<item->getName()<<" --> "<<item->getPrice()<<endl;
        }
        return menu;
    }
    bool isItemInMenu(MenuItem * item){
        for(auto it: menu){
            if(it->getName()==item->getName()) return true;
        }
        return false;
    }
    string getAddress(){
        return address;
    }
};
int Restaurant::RestaurantCount=0;

#endif