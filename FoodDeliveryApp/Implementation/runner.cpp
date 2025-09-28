#include<bits/stdc++.h>
using namespace std;

#include "models/User.h"
#include "models/Cart.h"
#include "models/MenuItem.h"
#include "models/Restaurant.h"
#include "managers/RestaurantManager.h"
#include "strategies/PayWithUPI.h"
#include "factories/CreateOrderNow.h"


int main(){
    User * user1 = new User("Vivek", "HRBR");
    User * user2 = new User("ankit", "HSR");
    // cout<<user1->getId()<<endl;
    // cout<<user2->getId()<<endl;

    vector<MenuItem*>menu;
    menu.push_back(new MenuItem("idli", 30));
    menu.push_back(new MenuItem("vada", 30));
    menu.push_back(new MenuItem("tea", 20));

    Restaurant * res = new Restaurant("7Plates", "HRBR", menu);
    
    RestaurantManager * rm = RestaurantManager::getInstance();
    rm->addRestaurant(res);

    res->getMenu();
    Cart * cart1 = new Cart(res);
    cart1->addItem(new MenuItem("tea", 20), 2);

    user1->setCart(cart1);
    cart1->viewCart();

    OrderFactory * orderNow = new CreateOrderNow();
    Order * order = orderNow->createOrder("delivery");
    PaymentStrategy * ps = new PayWithUPI();
    order->setOrder(res, user1, cart1->getCartItems(), ps);
    
}
