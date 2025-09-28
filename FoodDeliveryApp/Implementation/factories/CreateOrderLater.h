#ifndef CREATE_ORDER_H
#define CREATE_ORDER_H

#include<bits/stdc++.h>
using namespace std;
#include "OrderFactory.h"
#include "../models/Order.h"
#include "../models/PickupOrder.h"
#include "../models/DeliveryOrder.h"

class CreateOrderLater : public OrderFactory{
public:
    Order * createOrder(string type) override{
        Order * order;
        if(type=="pickup") order= new PickupOrder();
        else if(type=="delivery") order = new DeliveryOrder();
        order->setTime();
        return order;
    }
};

#endif