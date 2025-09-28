#include<bits/stdc++.h>
using namespace std;

class Cart;

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

class RestaurantManager{
    static RestaurantManager * rm;
    vector<Restaurant*>restaurants;
    RestaurantManager(){
        cout<<"Restaurant Manager created"<<endl;
    }
public:
    static RestaurantManager * getInstance(){
        return rm;
    }
    void addRestaurant(Restaurant * r){
        restaurants.push_back(r);
    }
    void removeRestaurant(Restaurant * r){
        int ind = -1;
        for(int i=0;i<restaurants.size();i++){
            if(restaurants[i]==r){
                ind = i;
                break;
            }
        }
        restaurants.erase(restaurants.begin() + ind);
    }
};
RestaurantManager* RestaurantManager::rm = new RestaurantManager();

class Cart{
    Restaurant * res=NULL;
    unordered_map<MenuItem*, int>items;
public:
    Cart(Restaurant * res){
        this->res = res;
    }
    void addItem(MenuItem * item, int cnt){
        if(!res->isItemInMenu(item)){
            cout<<"Item does not exist in menu of the restaurant"<<endl;
            return ;
        }
        items[item]=cnt;
    }
    unordered_map<MenuItem*, int> getCartItems(){
        return items;
    }
    int getPrice(){
        int tot = 0;
        for(auto it: items){
            tot+=(it.first->getPrice())*it.second;
        }
        return tot;
    }
    void removeItem(MenuItem * item){
        if(items[item]>0) items[item]--;
    }
    void viewCart(){
        cout<<endl<<"------------- SHOWING CART --------------------"<<endl;
        for(auto it: items){
            cout<<it.first->getName()<<" --> "<<it.second<<endl;
        }
    }
};

class PaymentStrategy;


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
class DeliveryOrder : public Order{
public:
    DeliveryOrder() : Order() {}
    string getType() override{
        return "delivery";
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
int Order::orderCount = 0;

// ORDER FACTORY
class OrderFactory{
public:
    virtual Order * createOrder(string type) = 0;
};
class CreateOrderNow : public OrderFactory{
public:
    Order * createOrder(string type) override{
        Order * order;
        if(type=="pickup") order= new PickupOrder();
        else if(type=="delivery") order = new DeliveryOrder();
        return order;
    }
};
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


//Payment Strategy
class PaymentStrategy{
public:
    virtual void pay() = 0;
};
class PayWithUPI : public PaymentStrategy{
public:
    void pay() override{
        cout<<"paid with upi"<<endl;
    }
};
class PayWithCreditCard : public PaymentStrategy{
public:
    void pay() override{
        cout<<"paid with credit card"<<endl;
    }
};
class PayWithNetBanking : public PaymentStrategy{
public:
    void pay() override{
        cout<<"paid with net banking"<<endl;
    }
};


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
