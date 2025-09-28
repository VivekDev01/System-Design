#ifndef PAYMENT_NETBANKING_STRATEGY_H
#define PAYMENT_NETBANKING_STRATEGY_H

#include<bits/stdc++.h>
#include "PaymentStrategy.h"
using namespace std;

class PayWithNetBanking : public PaymentStrategy{
public:
    void pay() override{
        cout<<"paid with net banking"<<endl;
    }
};

#endif