#ifndef ORDER_FACTORY_H
#define ORDER_FACTORY_H

#include<bits/stdc++.h>
using namespace std;
#include "../models/Order.h"

class OrderFactory{
public:
    virtual Order * createOrder(string type) = 0;
};

#endif
