#ifndef USER_H
#define USER_H

#include<bits/stdc++.h>
using namespace std;
#include "Cart.h"

class User{
    static int usersCount;
    int id;
    string name;
    string address;
    Cart * cart;
public:
    User(string name, string address){
        this->name = name;
        this->address = address;
        cart = nullptr;
        id=++usersCount;
    }
    int getId(){
        return id;
    }
    string getName(){
        return name;
    }
    string getAddress(){
        return address;
    }
    Cart * getCart(){
        return cart;
    }  
    void setCart(Cart * c){
        cart = c;
    }
};
int User::usersCount = 0;

#endif