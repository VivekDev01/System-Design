#ifndef RESTAURANT_MANAGER_H
#define RESTAURANT_MANAGER_H

#include<bits/stdc++.h>
#include "../models/Restaurant.h"
using namespace std;


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

#endif