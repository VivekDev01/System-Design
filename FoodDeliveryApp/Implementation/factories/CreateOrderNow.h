#ifndef ORDER_NOW_FACTORY_H
#define ORDER_NOW_FACTORY_H

#include<bits/stdc++.h>
using namespace std;
#include "../models/Order.h"
#include "../models/PickupOrder.h"
#include "../models/DeliveryOrder.h"
#include "OrderFactory.h"

class CreateOrderNow : public OrderFactory{
public:
    Order * createOrder(string type) override{
        Order * order;
        if(type=="pickup") order= new PickupOrder();
        else if(type=="delivery") order = new DeliveryOrder();
        return order;
    }
};

#endif