#ifndef PICKUP_ORDER_H
#define PICKUP_ORDER_H

#include<bits/stdc++.h>
#include "Restaurant.h"
#include "User.h"
#include "MenuItem.h"
#include "../strategies/PaymentStrategy.h"
using namespace std;

class PickupOrder : public Order{
public:
    PickupOrder() : Order() {} // calls base constructor
    string getType() override{
        return "pickup";
    }
    void setTime() override{
        time = !time;
    }
    int getTime() override{
        return time;
    }
    void setOrder(Restaurant * res, User * user, unordered_map<MenuItem*, int>items, PaymentStrategy * ps) override{
        this->res = res;
        this->user = user;
        this->items = items;
        this->ps = ps;
        cout<<endl<<"Congratuations, Your order is placed!"<<endl;
    }
};

#endif