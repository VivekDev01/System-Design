#include<bits/stdc++.h>

using namespace std;

class Shape{
public:
    virtual double getArea() = 0;
    virtual double getVolume() = 0;
    ~Shape(){};
};

class Rectangle : public Shape{
    double height=0;
    double width=0;
public:
    Rectangle(double height, double width){
        this->height= height;
        this->width = width;
    }
    double getArea(){
        cout<<"Area of square: "<<height * width<<endl;
        return height * width;
    }
    double getVolume(){ // here getVolume method is imposed on Rectangle (ISP Violated)
        throw logic_error("Volume cannot be calculated");
    }
};


class Cube : public Shape{
    double side = 0;
public:
    Cube(double side){
        this->side= side;
    }
    double getArea(){
        cout<<"Area of cube: "<<side*side*6<<endl;
        return side* side *6;
    }
    double getVolume(){
        cout<<"Volume of Cube: "<<side * side * side<<endl;
        return side * side * side;
    }
};

int main(){
    Shape * rec = new Rectangle(4.2, 5.3);
    rec->getArea();
    // rec->getVolume();

    cout<<"----------X------------X-----------"<<endl;

    Shape * cube = new Cube(4.2);
    cube->getArea();
    cube->getVolume();
}