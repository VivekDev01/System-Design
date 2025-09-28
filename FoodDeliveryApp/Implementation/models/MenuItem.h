#ifndef MENUITEM_H
#define MENUITEM_H

#include<bits/stdc++.h>
using namespace std;

class MenuItem{
    static int MenuItemCount;
    int price;
    string name;
    int  code;
public:
    MenuItem(string name, int price){
        this->name = name;
        this->price = price;
        code = ++MenuItemCount;
    }
    string getName(){
        return name;
    }
    int getPrice(){
        return price;
    }
};
int MenuItem::MenuItemCount = 0;


#endif