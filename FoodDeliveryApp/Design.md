# Restaurant Ordering System - UML Diagram

```mermaid
classDiagram

%% Singleton
class RestaurantManager {
    <<Singleton>>
    - restaurantList : Restaurant[]
    + addRestaurant()
    + removeRestaurant()
    + searchByLocation()
}

%% Models
class Restaurant {
    <<Model>>
    - menuItems : MenuItem[]
    - name : string
    - id : int
    - address : string
    + getter()
    + setter()
}

class MenuItem {
    <<Model>>
    - name : string
    - price : int
    - code : int
    + getter()
    + setter()
}

class User {
    <<Model>>
    - name : string
    - id : int
    - address : string
    - cart : Cart
    + getter()
    + setter()
}

class Cart {
    - Restaurant : Restaurant
    - items : MenuItem[]
    - totalPrice : int
    + addToCart(MenuItem)
    + clearCart()
}

%% Interfaces
class PaymentStrategy {
    <<Interface>>
    + pay()
}

class Order {
    <<Interface>>
    - id : int
    - restaurant : Restaurant
    - items : MenuItem[]
    - user : User
    - ps : PaymentStrategy
    + getType()
}

class OrderFactory {
    <<Interface>>
    + createOrder(type)
}

%% Payment Classes
class CrediCard {
    - attributes
    + pay()
}

class UPI {
    - attributes
    + pay()
}

class NetBanking {
    - attributes
    + pay()
}

%% Orders
class Delivery {
    + getType()
}

class Pickup {
    + getType()
}

%% Order Manager
class OrderManager {
    - orders : Order[]
    + addOrder()
    + deleteOrder()
}

%% Notification
class NotificationService {
    - attributes
    + notify()
}

%% Now Orders
class NowOrder {
    - attributes
    + createOrder(type)
}

%% Relationships
RestaurantManager "1" -- "many" Restaurant
Restaurant "1" -- "many" MenuItem
User "1" -- "1" Cart
Cart "1" -- "many" MenuItem
Cart "1" -- "1" Restaurant
Order "1" -- "1" Restaurant
Order "1" -- "many" MenuItem
Order "1" -- "1" User
Order <|.. Delivery
Order <|.. Pickup
PaymentStrategy <|.. CrediCard
PaymentStrategy <|.. UPI
PaymentStrategy <|.. NetBanking
OrderFactory <|.. NowOrder
OrderManager "1" -- "many" Order
