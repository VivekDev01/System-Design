#ifndef ORDER_H
#define ORDER_H

#include<bits/stdc++.h>
#include "Restaurant.h"
#include "User.h"
#include "MenuItem.h"
#include "../strategies/PaymentStrategy.h"
using namespace std;

// ORDER
class Order{
protected:
    static int orderCount;
    int id;
    Restaurant * res;
    User * user;
    unordered_map<MenuItem*, int>items;
    PaymentStrategy * ps;
    int time = 0;
public:
    Order() {  // centralize ID assignment
        id = ++orderCount;
    }
    virtual string getType() = 0;
    virtual ~Order(){};
    virtual void setTime() = 0;
    virtual int getTime() = 0;
    virtual void setOrder(Restaurant * res, User * user, unordered_map<MenuItem*, int>items, PaymentStrategy * ps) = 0;
};
int Order::orderCount = 0;


#endif